
int	ft_charmap_linecounter(char **map)
{
	int i;

	if (!map)
		return (0);
	i = 0;
	while (map[i] != 0)
		i++;
	return (i);
}