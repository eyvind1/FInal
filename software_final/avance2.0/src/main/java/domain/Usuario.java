package domain;
import java.util.Collection;
import java.util.List;

import javax.persistence.Column;
import javax.persistence.ElementCollection;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.OneToOne;
import javax.persistence.SequenceGenerator;

import domain.Person;

@Entity
public class Usuario implements BaseEntity<Long>{
	
	@Id
	@SequenceGenerator(name = "usuario_id_generator", sequenceName = "usuario_id_seq", allocationSize = 1)
	@GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "usuario_id_generator")
	private Long id;
	
	@ManyToOne
	@JoinColumn(name = "person")
	private Person user;
	
	@Column
	private String email;
	
	@Column
	private String password;
	
	@ElementCollection
	@Column
	private List<Song> lastPlayed;
	
	@Column
	private String status; //'activo', 'inactivo'
		
	@ManyToMany
	@JoinTable(name = "user_playlist")
	private Collection<Playlist> playlists;
	
	@ManyToMany
	@JoinTable(name = "user_followers")
	private Collection<Usuario> seguidores;
	

	public Usuario(){}


	public String getEmail() {
		return email;
	}

	


	public Person getUser() {
		return user;
	}



	public void setUser(Person user) {
		this.user = user;
	}



	public String getPassword() {
		return password;
	}



	public void setPassword(String password) {
		this.password = password;
	}



	public List<Song> getLastPlayed() {
		return lastPlayed;
	}



	public void setLastPlayed(List<Song> lastPlayed) {
		this.lastPlayed = lastPlayed;
	}



	public String getStatus() {
		return status;
	}



	public void setStatus(String status) {
		this.status = status;
	}



	public Collection<Playlist> getPlaylists() {
		return playlists;
	}



	public void setPlaylists(Collection<Playlist> playlists) {
		this.playlists = playlists;
	}



	public Collection<Usuario> getSeguidores() {
		return seguidores;
	}



	public void setSeguidores(Collection<Usuario> seguidores) {
		this.seguidores = seguidores;
	}



	public void setEmail(String email) {
		this.email = email;
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
