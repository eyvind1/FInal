package controller;

import java.util.Collection;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

import service.SongService;
import domain.Song;

import service.AlbumService;
import domain.Album;

@Controller
public class AlbumController {

	@Autowired
	SongService songService;
	
	@Autowired
	AlbumService albumService;

	@RequestMapping(value = "/album", method = RequestMethod.POST)
	String saveAlbum(@ModelAttribute Album album, ModelMap model) {
		System.out.println("saving: " + album.getId());
		albumService.save(album);
		return showalbum(album.getId(), model);
	}
	@RequestMapping(value = "/add-album", method = RequestMethod.GET)
	String addNewAlbum(@RequestParam(required = false) Long id, ModelMap model) {
		Album album = id == null ? new Album() : albumService.get(id);
		model.addAttribute("album", album);
		return "add-album";
	}

	@RequestMapping(value = "/album", method = RequestMethod.GET)
	String showalbum(@RequestParam(required = false) Long id, ModelMap model) {
		if (id != null) {
			Album album = albumService.get(id);
			model.addAttribute("album", album);
			return "album";
		} else {
			Collection<Album> albums = albumService.getAll();
			model.addAttribute("albums", albums);
			return "albums";
		}
	}
	
	@RequestMapping(value = "/albums", method = RequestMethod.GET)
	String showalbums(@RequestParam(required = false) Long id, ModelMap model) {

		if (id != null) {
			Album album = albumService.get(id);
			model.addAttribute("album", album);
			return "album";
		} else {
			Collection<Album> albums = albumService.getAll();		
			
			model.addAttribute("albums", albums);
			return "albums";
			
		}
		
	}
	

}
