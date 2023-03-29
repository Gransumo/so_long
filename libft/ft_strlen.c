/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <gcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:35:51 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:15:31 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i])
		i++;
	return (i);
}

int	ft_strlen_linemap(const char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i] && c[i] != '\n')
		i++;
	return (i);
}
