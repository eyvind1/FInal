package domain;

import java.sql.Timestamp;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToOne;
import javax.persistence.SequenceGenerator;

import domain.Song;
import domain.Usuario;

@Entity
public class ListenLog implements BaseEntity<Long>{
	
	@Id
	@SequenceGenerator(name = "log_id_generator", sequenceName = "log_id_seq", allocationSize = 1)
	@GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "log_id_generator")
	private Long id;
	
	@ManyToOne
	private Song song;
	
	@ManyToOne
	private Usuario usuario;
	
	@Column(nullable=false)
	private Timestamp timestamp;
	
	public ListenLog(Song _cancion, Usuario _usuario){
		this.song = _cancion;
		this.usuario = _usuario;
		Date date = new Date();
		this.timestamp = new Timestamp(date.getTime());
		
	}
	
	public Song getCancion() {
		return song;
	}
	public void setCancion(Song song) {
		this.song = song;
	}
	public Usuario getUsuario() {
		return usuario;
	}
	public void setUsuario(Usuario usuario) {
		this.usuario = usuario;
	}
	public Timestamp getTimestamp() {
		return timestamp;
	}
	public void setTimestamp(Timestamp timestamp) {
		this.timestamp = timestamp;
	}

	@Override
	public Long getId() {
		return this.id;
	}

	@Override
	public void setId(Long id) {
		this.id = id;
	}

	public Song getSong() {
		return song;
	}

	public void setSong(Song song) {
		this.song = song;
	}
	
}
