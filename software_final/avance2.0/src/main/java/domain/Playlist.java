package domain;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Random;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.SequenceGenerator;

import domain.Usuario;
import domain.Song;

@Entity
public class Playlist implements BaseEntity<Long>{

	@Id
	@SequenceGenerator(name = "playlist_id_generator", sequenceName = "playlist_id_seq", allocationSize = 1)
	@GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "playlist_id_generator")
	private Long id;
	
	@Column(length=128, nullable=false, updatable=false)
	private String titulo;
	
	@Column
	private Date fecha_creacion;
	
	@ManyToMany
	@JoinTable(name="playlist_songs")
	private List<Song> songs;
	
	@ManyToOne
	@JoinColumn(name = "usuario")
	private Usuario creador;
		
	
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public List<Song> getSongs() {
		return this.songs;
	}
	public void setSongs(List<Song> songs) {
		this.songs = songs;
	}
	public Usuario getCreador() {
		return creador;
	}
	public void setCreador(Usuario creador) {
		this.creador = creador;
	}
	public Date getFecha_creacion() {
		return fecha_creacion;
	}
	public void setFecha_creacion(Date fecha_creacion) {
		this.fecha_creacion = fecha_creacion;
	}
	
	
}
