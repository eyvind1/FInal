package service;

import java.util.Collection;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import domain.Playlist;
import repository.PlaylistRepository;

@Service
public class PlayListService {
	@Autowired
	PlaylistRepository playlistRepository;
	
	@Transactional
	public void save(Playlist playlist) {
		if (playlist.getId() == null) {
			playlistRepository.persist(playlist);
		} else {
			playlistRepository.merge(playlist);
		}
	}

	public Playlist get(Long id) {
		return playlistRepository.find(id);
	}


	public Collection<Playlist> getAll() {
		return playlistRepository.findAll();

	}
	
}
