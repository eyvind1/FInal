package com.example.servicio;

import javax.transaction.Transactional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.example.dominio.Album;
import com.example.dominio.Artista;
import com.example.repositorio.AlbumRepositorio;
import com.example.repositorio.ArtistaRepositorio;

public class ArtistaServiceImpl implements ArtistaService{
	
	ArtistaRepositorio artistaRepositorio;
	AlbumRepositorio albumRepositorio;
	
	@Autowired
	public ArtistaServiceImpl(ArtistaRepositorio ar, AlbumRepositorio alr){
		this.artistaRepositorio = ar;
		this.albumRepositorio = alr;
	}

}
