package repository.jpa;

import java.util.Collection;

import javax.persistence.TypedQuery;

import org.springframework.stereotype.Repository;

import repository.AlbumRepository;
import domain.Album;
import domain.Artist;
import domain.Playlist;
import domain.Song;

@Repository
public class JpaAlbumRepository extends JpaBaseRepository<Album, Long> implements AlbumRepository {
	
	@Override
	public Collection<Song> findSongsByAlbumId(Long albumId) {
		String jpaQuery = "Select s from song s join album_songs on s.id = album_songs.songs where album_songs.album = :albumtId";
		TypedQuery<Song> query = entityManager.createQuery(jpaQuery, Song.class);
		query.setParameter("albumId", albumId);
		return query.getResultList();
	}	//select a from artist a join artist_album on a.id = artist_album.artist where artist_album.album = 1;
	@Override
	public Collection<Artist> findArtistByAlbumId(Long albumId) {
		String jpaQuery = "select a from artist a join artist_album on a.id = artist_album.artist where artist_album.album = :albumtId";
		TypedQuery<Artist> query = entityManager.createQuery(jpaQuery, Artist.class);
		query.setParameter("albumId", albumId);
		return query.getResultList();
	}
	@Override
	public boolean save(Album album) {
		// TODO Auto-generated method stub
		return false;
	}
	
}