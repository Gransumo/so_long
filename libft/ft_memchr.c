/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:42:58 by gcastro-          #+#    #+#             */
/*   Updated: 2021/11/17 18:42:58 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(register const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	z;

	p = (unsigned char *)s;
	z = (unsigned char) c;
	while (n > 0)
	{
		if (*p == z)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
