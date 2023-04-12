/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charmap_linecounter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:46:22 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:46:23 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_charmap_linecounter(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i] != 0)
		i++;
	return (i);
}
