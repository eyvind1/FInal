//package domain;
//
//import java.util.Collection;
//
//import javax.persistence.Column;
//import javax.persistence.Entity;
//import javax.persistence.GeneratedValue;
//import javax.persistence.GenerationType;
//import javax.persistence.Id;
//import javax.persistence.JoinTable;
//import javax.persistence.ManyToMany;
//import javax.persistence.SequenceGenerator;
//
//@Entity
//public class Person implements BaseEntity<Long> {
//
//	@Id
//	@SequenceGenerator(name = "person_id_generator", sequenceName = "person_id_seq", allocationSize = 1)
//	@GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "person_id_generator")
//	private Long id;
//
//	@Column(length = 64)
//	private String Nombre;
//
//	@Column(length = 64)
//	private String Apellido;
//
//	@Column(nullable = false, length = 10)
//	private char sexo;
//
//	public Person(String nombre2, String apellido2, char sexo2) {
//		// TODO Auto-generated constructor stub
//		this.Nombre = nombre2;
//		this.Apellido = apellido2;
//		this.sexo = sexo2;
//	}
//
//	public Person(){}
//	@Override
//	public Long getId() {
//		return id;
//	}
//
//	@Override
//	public void setId(Long id) {
//		this.id = id;
//	}
//
//	public String getNombre() {
//		return Nombre;
//	}
//
//	public void setNombre(String nombre) {
//		Nombre = nombre;
//	}
//
//	public String getApellido() {
//		return Apellido;
//	}
//
//	public void setApellido(String apellido) {
//		Apellido = apellido;
//	}
//
//	public char getSexo() {
//		return sexo;
//	}
//
//	public void setSexo(char sexo) {
//		this.sexo = sexo;
//	}
//
//}



package domain;

import java.util.Collection;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.SequenceGenerator;

@Entity
public class Person implements BaseEntity<Long> {

	@Id
	@SequenceGenerator(name = "person_id_generator", sequenceName = "person_id_seq", allocationSize = 1)
	@GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "person_id_generator")
	private Long id;

	@Column(length = 64)
	private String firstName;

	@Column(length = 64)
	private String lastName;


	@Override
	public Long getId() {
		return id;
	}

	@Override
	public void setId(Long id) {
		this.id = id;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}


}
