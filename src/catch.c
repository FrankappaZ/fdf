#include "../inc/fdf.h"
#include "../inc/rota.h"
#include <signal.h>

/*
*
*	prevent ctrl+c for free data before exit
*
*/

//extern t_fdf	*g_map;

void	free_data_list(t_fdf *map)
{
	list_mod(map, &free_elem);

}

static void sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putendl("SIGINT catch");
		free_data_list(NULL);
	}
	if (signo == SIGSEGV)
		ft_putendl("SIGSEGV catch");
}

void	setup_catch(t_fdf *map)
{
	if (signal(SIGSEGV, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
}
