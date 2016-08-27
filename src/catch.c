#include "../inc/fdf.h"
#include "../inc/rota.h"
#include <signal.h>

/*
*
*	prevent ctrl+c for free data before exit
*
*/
static void	free_mlx(t_fdf *map)
{
	ft_putendl("free mlx :");
	ft_putendl("\tfree img");
	mlx_destroy_image(map->win.mlx, map->win.img);
	ft_putendl("\tfree win");
	free(map->win.win);
	ft_putendl("\tfree mlx");
	free(map->win.mlx);

}
void	free_data_list()
{
	t_fdf		*map;
	char		*address;
	int		fd_add;
	static int	isok = 0;

	if (isok)
		exit(0);	
	address = NULL;
	address = ft_memalloc(sizeof(long));
	fd_add = open("./address", O_RDWR);
	get_next_line(fd_add, &address);
	ft_putendl(address);
	map = (void*) ft_atoll(address); 	
	list_mod(map, free_elem);
	free(map->coord);
	free_mlx(map);
	free(address);
	address = NULL;
	isok = 1;
	exit(0);
}

static void sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putendl("ctrl+c protection, all item free and exit");
		free_data_list();
	}
	if (signo == SIGSEGV)
	{
		ft_putendl("Segfault Protection !, all item free and exit");
		free_data_list();
	}
}

void	setup_catch()
{
	if (signal(SIGSEGV, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
}
