/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:42:19 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:42:21 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message)
{
	ft_printf("ERROR\n%s\n", message);
	return (0);
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
