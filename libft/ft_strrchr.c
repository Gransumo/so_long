/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:43:29 by gcastro-          #+#    #+#             */
/*   Updated: 2021/11/17 18:43:29 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	*p;

	p = (char *)s;
	x = ft_strlen ((char *)s);
	if ((char)c == '\0')
		return (&p[x]);
	while (x >= 0)
	{
		if (p[x] == (char)c)
			return (&p[x]);
		x--;
	}
	return (0);
}
