package com.example.servicio;

import java.util.List;
import javax.transaction.Transactional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.example.dominio.Cancion;
import com.example.dominio.Playlist;
import com.example.dominio.Usuario;
import com.example.repositorio.CancionRepositorio;
import com.example.repositorio.PlaylistRepositorio;
import com.example.repositorio.UsuarioRepositorio;

@Service
public class UsuarioServiceImpl implements UsuarioService {


	UsuarioRepositorio usuarioRepositorio;
	PlaylistRepositorio playlistRepositorio;
	CancionRepositorio cancionRepositorio;
	
	@Autowired
	public UsuarioServiceImpl(UsuarioRepositorio ur, PlaylistRepositorio pr, CancionRepositorio cr){
		this.usuarioRepositorio = ur;
		this.playlistRepositorio = pr;
		this.cancionRepositorio = cr;
	}
	
	public Usuario crearUsuario(String username,String nombres, String apellidoPaterno, String apellidoMaterno, String email, String password){
		Usuario usuario = new Usuario(username,nombres,apellidoPaterno,apellidoMaterno,email,password);
		usuarioRepositorio.save(usuario);
		return usuario;
	}
	
	public void updateUsuario(Usuario usuario) {
        usuarioRepositorio.save(usuario);
    }
	
	public Usuario getUsuario(Integer ID_usuario) {
        return usuarioRepositorio.findOne(ID_usuario);
    }
	

	
	
}
