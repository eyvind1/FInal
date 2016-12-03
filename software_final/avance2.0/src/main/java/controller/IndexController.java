package controller;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.CookieValue;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class IndexController {

	@RequestMapping("/")
	String home(ModelMap model,
			@CookieValue(value="loggedIn", defaultValue="0") String AuthCookie) {
		if(AuthCookie == "0"){
			return "redirect:login";
		}
		return "index";
	}

}
