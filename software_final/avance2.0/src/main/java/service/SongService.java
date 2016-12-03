package service;

import java.util.Collection;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import domain.Song;
import repository.SongRepository;

@Service
public class SongService {

	@Autowired
	SongRepository songRepository;
	
	@Transactional
	public void save(Song song) {
		if (song.getId() == null) {
			songRepository.persist(song);
		} else {
			songRepository.merge(song);
		}
	}

	public Song get(Long id) {
		return songRepository.find(id);
	}

	public Collection<Song> getAll() {
		return songRepository.findAll();
	}
}
