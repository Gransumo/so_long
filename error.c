#include "so_long.h"

int	error(char *message)
{
	ft_printf("ERROR\n%s\n", message);
	return(0);
}

void	*null_error(char *message)
{
	ft_printf("ERROR\n%s\n", message);
	return (NULL);
}

void	print_warning(char	*message)
{
	ft_printf("WARNING: %s\n", message);
}
