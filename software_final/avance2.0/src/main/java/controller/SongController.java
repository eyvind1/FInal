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
public class SongController {

	@Autowired
	SongService songService;
	
	@Autowired
	AlbumService albumService;

	@RequestMapping(value = "/song", method = RequestMethod.POST)
	String saveSong(@ModelAttribute Song song, ModelMap model) {
		System.out.println("saving: " + song.getId());
		songService.save(song);
		return showsong(song.getId(), model);
	}
	@RequestMapping(value = "/add-song", method = RequestMethod.GET)
	String addNewSong(@RequestParam(required = false) Long id, ModelMap model) {
		Song song = id == null ? new Song() : songService.get(id);
		model.addAttribute("song", song);
		return "add-song";
	}

	@RequestMapping(value = "/song", method = RequestMethod.GET)
	String showsong(@RequestParam(required = false) Long id, ModelMap model) {
		if (id != null) {
			Song song = songService.get(id);
			model.addAttribute("song", song);
			return "song";
		} else {
			Collection<Song> songs = songService.getAll();
			model.addAttribute("songs", songs);
			return "songs";
		}
	}
	
	@RequestMapping(value = "/songs", method = RequestMethod.GET)
	String showsongs(@RequestParam(required = false) Long id, ModelMap model) {

		if (id != null) {
			Song song = songService.get(id);
			model.addAttribute("song", song);
			System.out.println(song.getAlbum().getTitle());
			return "song";
		} else {
			Collection<Song> songs = songService.getAll();		
			
			model.addAttribute("songs", songs);
			return "songs";
			
		}
		
	}
	

}
