package service;

import java.util.Collection;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import repository.ArtistRepository;
import domain.Artist;
import domain.Person;

@Service
public class ArtistService {

	@Autowired
	ArtistRepository artistRepository;
	
	@Transactional
	public void save(Artist artist) {
		if (artist.getId() == null) {
			artistRepository.persist(artist);
		} else {
			artistRepository.merge(artist);
		}
	}

	public Artist get(Long id) {
		return artistRepository.find(id);
	}
	

	public Collection<Artist> getAll() {
		return artistRepository.findAll();
	}
}
