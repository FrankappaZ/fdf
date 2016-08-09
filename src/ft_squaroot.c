int		squareroot(int a)
{
	int	x;

	x = 1;
	while (x * x < a)
		x++;
	return (x);
}
