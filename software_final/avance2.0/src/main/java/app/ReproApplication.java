package app;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.orm.jpa.EntityScan;
import org.springframework.context.annotation.Import;

import config.WebConfig;
import domain.BaseEntity;

@Import(WebConfig.class)
@EnableAutoConfiguration
@EntityScan(basePackageClasses=BaseEntity.class)
public class ReproApplication {
	
	public static void main(String[] args) throws Exception {
		SpringApplication.run(ReproApplication.class, args);
	}
}
