package service;

import java.util.Collection;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import domain.Album;
import repository.AlbumRepository;

@Service
public class AlbumService {

	@Autowired
	AlbumRepository AlbumRepository;
	
	@Transactional
	public void save(Album album) {
		if (album.getId() == null) {
			AlbumRepository.persist(album);
		} else {
			AlbumRepository.merge(album);
		}
	}

	public Album get(Long id) {
		return AlbumRepository.find(id);
	}

	public Collection<Album> getAll() {
		return AlbumRepository.findAll();
	}
}
