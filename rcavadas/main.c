#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int ret;
	char *str;
	int fd1;
	int fd2;

	if (argc == 1)
	{
		fd1 = 0;
		fd2 = -3;
	}
	else if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = 42;
	}
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
	}
	ft_putendl("first file");
	str = NULL;
	for (int i = 0; i < 3; i++)
	{
		ret = get_next_line(fd1, &str);
		if (ret == 1)
			ft_putendl(str);
		else if (ret == 0)
			ft_putendl("file ended");
		else if (ret == -1)
			ft_putendl("error");
		else
			ft_putendl("bad return");
		if (ret == 1)
			free(str);

	}
	ft_putendl("\nsecond file");
	for (int i = 0; i < 4; i++)
	{
		ret = get_next_line(fd2, &str);
		if (ret == 1)
			ft_putendl(str);
		else if (ret == 0)
			ft_putendl("file ended");
		else if (ret == -1)
			ft_putendl("error");
		else
			ft_putendl("bad return");
		if (ret == 1)
			free(str);
	}
	ft_putendl("\nfirst file");
	for (int i = 0; i < 7; i++)
	{
		ret = get_next_line(fd1, &str);
		if (ret == 1)
			ft_putendl(str);
		else if (ret == 0)
			ft_putendl("file ended");
		else if (ret == -1)
			ft_putendl("error");
		else
			ft_putendl("bad return");
		if (ret == 1)
			free(str);
	}
	return (0);
}