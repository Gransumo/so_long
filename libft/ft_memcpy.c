/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <gcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:13:31 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:07:28 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*aux_d;
	unsigned char	*aux_s;

	i = 0;
	aux_d = (unsigned char *)dest;
	aux_s = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		aux_d[i] = aux_s[i];
		i++;
		n--;
	}
	return (dest);
}
