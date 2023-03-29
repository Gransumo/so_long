/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:43:12 by gcastro-          #+#    #+#             */
/*   Updated: 2021/11/17 18:43:12 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*aux_d;
	unsigned char	*aux_s;
	size_t			i;

	i = n - 1;
	aux_d = (unsigned char *)dest;
	aux_s = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (i + 1 > 0)
	{
		aux_d[i] = aux_s[i];
		i--;
	}
	return (dest);
}
