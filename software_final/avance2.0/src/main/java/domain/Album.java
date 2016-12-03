package domain;

import java.util.Collection;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.SequenceGenerator;

@Entity
public class Album implements BaseEntity<Long> {

	@Id
	@SequenceGenerator(name = "album_id_generator", sequenceName = "album_id_seq", allocationSize = 1)
	@GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "album_id_generator")
	private Long id;

	@Column(unique = true, nullable = false, updatable = false, length = 64)
	private String title;

	@Column(nullable = false)
	private Date created = new Date();
	
	@ManyToMany
	@JoinTable(name = "album_songs")
	private Collection<Song> songs;
	
	
	@ManyToOne
	@JoinColumn(name = "artist")
	private Artist artist;
	
	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public Date getCreated() {
		return created;
	}

	public void setCreated(Date created) {
		this.created = created;
	}

	public Collection<Song> getSongs() {
		return songs;
	}

	public void setSongs(Collection<Song> songs) {
		this.songs = songs;
	}



	public Collection<Song> getCanciones() {
		return songs;
	}

	public void setCanciones(Collection<Song> songs) {
		this.songs = songs;
	}
	
	
	
	public Artist getArtist() {
		return artist;
	}

	public void setArtist(Artist artist) {
		this.artist = artist;
	}

	public Album(){
		
	}

	public Album(String title) {
		this.title = title;
	}
	
	@Override
	public Long getId() {
		return id;
	}

	@Override
	public void setId(Long id) {
		this.id = id;
	}
	

	

}
