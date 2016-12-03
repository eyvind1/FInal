package repository.jpa;

import java.util.Collection;

import javax.persistence.TypedQuery;

import org.springframework.stereotype.Repository;

import repository.SongRepository;
import domain.Song;



@Repository
public class JpaSongRepository extends JpaBaseRepository<Song, Long> implements SongRepository {	
}