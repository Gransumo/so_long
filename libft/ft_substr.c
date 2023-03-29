/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <gcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:36:55 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:51:09 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*x;

	if (!s)
		return (0);
	if (start >= (size_t)ft_strlen (s))
		return (ft_strdup("\0"));
	else
	{
		if (len > (size_t)ft_strlen (s))
			len = ft_strlen (s);
		x = malloc (len + 1);
		if (x == NULL)
			return (0);
		ft_strlcpy (x, s + start, len + 1);
		return (x);
	}
}
