package repository.jpa;

import java.util.Collection;
import java.util.List;

import javax.persistence.TypedQuery;

import org.springframework.stereotype.Repository;

import repository.PlaylistRepository;
import domain.Playlist;

@Repository
public class JpaPlaylistRepository extends JpaBaseRepository<Playlist, Long> implements PlaylistRepository {
	
	
}
