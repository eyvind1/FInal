package repository.jpa;

import org.springframework.stereotype.Repository;

import repository.UsuarioRepository;
import domain.Usuario;

@Repository
public class JpaUsuarioRepository extends JpaBaseRepository<Usuario, Long> implements UsuarioRepository{

}
