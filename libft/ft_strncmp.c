/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:46:32 by gcastro-          #+#    #+#             */
/*   Updated: 2021/11/17 18:46:32 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	i = 0;
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (n > 0 && c1[i] != '\0' && c2[i] != '\0')
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (c1[i] - c2[i]);
}

int	ft_strcmp_end(const char *s, const char *final)
{
	int	i;
	int	j;

	i = (ft_strlen (s) - ft_strlen(final));
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i++] != final[j++])
			return (0);
	}
	return (1);
}
