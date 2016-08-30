#include "../inc/fdf.h"
#include "../inc/rota.h"
#include <signal.h>
#include <mlx.h>
#include <stdlib.h>
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
	int		fd_add;
	static int	isok = 0;

	ft_putendl("free data begin");

	if (isok)
		exit(0);
	map = (t_fdf *) get_data_add(0);
	list_mod(map, free_elem);
	ft_putendl("free_data_mlx");
	free_mlx(map);
	isok = 1;
	exit(0);
}

static void sig_handler(int signo)
{
		ft_putendl("sig catch");
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
	if (signo == SIGABRT)
	{
		ft_putendl("SIGABRT Protection !, all item free and exit");
		exit(0);
	}
}

void	setup_catch()
{
	if (signal(SIGSEGV, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
	if (signal(SIGABRT, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
}