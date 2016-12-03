package repository.jpa;

import java.util.Collection;

import javax.persistence.TypedQuery;

import org.springframework.stereotype.Repository;

import repository.ArtistRepository;
import domain.Person;
import domain.Artist;

@Repository
public class JpaArtistRepository extends JpaBaseRepository<Artist, Long> implements ArtistRepository {
	
	
}