package repository;

import java.util.Collection;

import domain.Album;
import domain.Artist;
import domain.Playlist;
import domain.Song;

public interface AlbumRepository extends BaseRepository<Album, Long> {

	Collection<Song> findSongsByAlbumId(Long albumId);

	Collection<Artist> findArtistByAlbumId(Long albumId);
	
	boolean save(Album album);
	void remove(Album album);
}
