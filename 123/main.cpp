#include <stdio.h>
#include <string.h>
#include <string>
      #include <stdlib.h>
      #include <string.h>
      #include <sys/types.h>
      #include <sys/ipc.h>
      #include <sys/sem.h>
      #include <sys/shm.h>
#include <iostream>
using namespace std;
      #define SHMSIZ sizeof(int)      /* size of shmem buffer = int   */
      #define NCYCLS 20               /* number of runs               */
      #define STIME  3                /* max computing time           */

      int glvar = 0;                  /* global variable              */
      int *data;                      /* shared memory data           */


      /* Semaphore code                                               */

      int ps;                         /* screen semaphore             */
      #define KEY 0x123456            /* fixed semaphore key          */

      /* Remove semaphore s                                           */
      void dest_sem(int s)
      {
        if (semctl(s, 0, IPC_RMID, NULL) < 0) {
          perror("remove semaphore");
          exit(1);
        }
      }

      /* Create semaphore with inititial value v                      */
      int init_sem(int v)
      {
        int s;                /* semaphore id                         */
        union semun {         /* see manual semctl(2)                 */
          int val;            /* here: val needed                     */
          struct semid_ds *buf;
          ushort *array;
        } a;

        /* create semaphore                                           */
        s = semget(KEY, 1, 0600|IPC_CREAT);
        if (s < 0) {
          perror("create semaphore");
          exit(1);
        }
        /* set initial semaphore value                                */
        a.val = v;
        if (semctl(s, 0, SETVAL, a) < 0) {
          perror("set semaphore value");
          dest_sem(s);
          exit(1);
        }
        return(s);
      }

      /* Semaphore operation P or wait                                */
      void P(int s)
      {
        struct sembuf op[1];

        op[0].sem_num = 0;
        op[0].sem_op  = -1;   /* counter value -1 => wait             */
       op[0].sem_flg = 0;
        (void) semop(s, op, 1);
      }

      /* Semaphore operation V or signal                              */
      void V(int s)
      {
        struct sembuf op[1];

        op[0].sem_num = 0;
        op[0].sem_op  = 1;    /* counter value 1 => signal            */
        op[0].sem_flg = 0;
        semop(s, op, 1);
      }


      /* Do some output on stderr                                     */
      void print(char * s, int n, int i1, int i2)
      {
        char buf[128];
        int i;

        sprintf(buf, "%s cycle=%d glvar=%d data=%d", s, n, i1, i2);
        for(i = strlen(buf); i < 80; i++)
          buf[i] = ' ';
        buf[i] = '\0';
       P(ps);
       if(*s == 'P')
         fprintf(stderr, "\033[34m\033[42m");
       else
         fprintf(stderr, "\033[32m\033[44m");
       fprintf(stderr, buf);
       fprintf(stderr, "\033[m\017\n");
       V(ps);
     }


     /* Producer: set and print global and shared memory variable    */
     void producer()
     {
       int i, c;

       srand(time(NULL));
       for (i = 0; i < NCYCLS; i++) {
         glvar++;
         *data = glvar * glvar;
         print("Producer", i+1, glvar, *data);
         sleep(rand() % STIME);
       }
     }

     /* Consumer: get and print global and shared memory variable    */
     void consumer()
     {
       int i;

       srand(time(NULL));
       for (i = 0; i < NCYCLS; i++) {
         print("Consumer", i+1, glvar, *data);
         sleep(rand() % STIME);
       }
     }


     int main(int argc, char *argv[])
    {
       key_t key;            /* dynamic shmem key                    */
       int shmid;            /* shmem id                             */
       int r;                /* result from wait()                   */

       /* make the shared memory key                                 */
       if ((key = ftok("shm-demo.c", 'R')) == -1) {
         perror("ftok");
         return(1);
       }

       /* connect to/possibly create the segment                     */
       if ((shmid = shmget(key, SHMSIZ, 0644|IPC_CREAT)) == -1) {
         perror("shmget");
         return(1);
       }

       /* attach to the shmem segment to get a pointer to it         */
       data = (int *) shmat(shmid, (void *) 0, 0);
       if (data == (int *) -1) {
         perror("shmat");
         return(1);
      }

       ps = init_sem(1);     /* init screen semapore                 */

       *data = 0;            /* initial shmem data value             */

       switch (fork()) {     /* create child process                 */
         case -1:
           perror("fork");
           return(1);
         default:            /* parent: producer                     */
           producer();
           break;
         case 0:             /* child: consumer                      */
           consumer();
           exit(0);
       }

       /* wait for terminating child                                 */
       while (wait(&r) >= 0)
         ;

       /* detach from the shmem segment                              */
       if (shmdt((char *) data) == -1) {
         perror("shmdt");
         return(1);
       }
       /* remove shmem segment                                       */
       if (shmctl(shmid, IPC_RMID, NULL) < 0) {
         perror("shmctl");
         return(1);
       }

       dest_sem(ps);         /* remove semaphore                     */

       return(0);
     }
