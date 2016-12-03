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

import domain.Person;

@Entity
public class Artist implements BaseEntity<Long> {
	@Id
	@SequenceGenerator(name = "artist_id_generator", sequenceName = "artist_id_seq", allocationSize = 1)
	@GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "artist_id_generator")
	private Long id;
	
	@Column(length = 64)
	private String nombre;
	
	@ManyToMany
    @JoinTable(name="person_artist")
	private Collection<Person> grupo;

	@ManyToMany
    @JoinTable(name="artist_album")
	private Collection<Album> albums;

	
	public String getNombre() {
		return this.nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Collection<Person> getGrupo() {
		return grupo;
	}

	public void setGrupo(Collection<Person> grupo) {
		this.grupo = grupo;
	}
	
	
	
	public Collection<Album> getAlbums() {
		return albums;
	}

	public void setAlbums(Collection<Album> albums) {
		this.albums = albums;
	}

	@Override
	public Long getId() {
		return this.id;
	}

	@Override
	public void setId(Long id) {

		this.id = id;
	}
	

}
