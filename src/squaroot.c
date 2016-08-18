int		ft_squaroot(float a)
{
	float	j, i, x1, x2;
	i = 0;

	if (a == 0)
		return 0;	
	while ((i * i) < a)
	{
		i+=0.1f;
	}
	x1 = i;
	j = 0;
	while (j<10)
	{
		j++;
		x2 = a;
		x2 /= x1;
		x2 += x1;
		x2 /= 2;
		x1 = x2;
	}
	return (x2);
}
