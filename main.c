#include "get_next_line.h"
#include <fcntl.h>
int main(int ac, char **av)
{
	int kk;
	int fd;
	char *str = NULL;
	
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_putendl("--- TEST AVEC FICHIER ---");
		while ((kk = get_next_line(fd, &str)))
		{
			ft_putstr("line : ");
			ft_putendl(str);
			ft_memdel((void **)&str);
		}
		ft_putendl("-------------------------\n");
		ft_putendl("--- TEST MAUVAIS FICH ---");
		av[1] = "grossesFessesQuiPuent";
		ft_putstr("gnl retourne : ");
		ft_putnbr(get_next_line(fd, &str));
		ft_memdel((void **)&str);
		ft_putendl("\n-------------------------\n");
		close(fd);
		ft_putendl("--- TEST AVEC CLAVIER ---");
		fd = 0;
		ft_putendl("Tapez la chaine a afficher : ");
		get_next_line(fd, &str);
		ft_putstr("La chaine retournee est : ");
		ft_putendl(str);
		ft_memdel((void **)&str);
		ft_putendl("-------------------------\n");
	}
	return (0);
}
