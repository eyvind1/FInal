package domain;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.SequenceGenerator;


@Entity
public class Song implements BaseEntity<Long> {

	@Id
	@SequenceGenerator(name = "song_id_generator", sequenceName = "song_id_seq", allocationSize = 1)
	@GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "song_id_generator")
	private Long id;
	
	@Column(length = 64)
	private String nombre;
	
	@Column(length = 2000)
	private String letra;
	
	@Column(nullable = false)
	private Date fecha = new Date();
	
	
	
	@ManyToOne
	@JoinColumn(name = "album")
	private Album album;
	
	
	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public String getLetra() {
		return letra;
	}

	public void setLetra(String letra) {
		this.letra = letra;
	}

	public Date getFecha() {
		return fecha;
	}

	public void setFecha(Date fecha) {
		this.fecha = fecha;
	}
	
	public Album getAlbum() {
		return album;
	}

	public void setAlbum(Album album) {
		this.album = album;
	}

	@Override
	public Long getId() {
		// TODO Auto-generated method stub
		
		return this.id;
	}

	@Override
	public void setId(Long id) {
		// TODO Auto-generated method stub
		this.id = id;
		
	}

}
