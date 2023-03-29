/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:44:39 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:44:40 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	len_num(int n)
{
	int		num_len;
	long	x;

	x = n;
	num_len = 0;
	if (x < 0)
	{
		x *= -1;
		num_len++;
	}
	while (x / 10 > 0)
	{
		num_len++;
		x /= 10;
	}
	return (num_len + 1);
}

char	*ft_itoa(int n)
{
	int		i;
	long	x;
	char	*s1;

	x = n;
	i = len_num (x) - 1;
	s1 = malloc (sizeof (char) * (len_num (n) + 1));
	if (!s1)
		return (0);
	if (n == 0)
		s1[0] = '0';
	if (n < 0)
	{
		s1[0] = '-';
		x *= -1;
	}
	while (x > 0)
	{
		s1[i] = (x % 10) + '0';
		x /= 10;
		i--;
	}
	s1[len_num(n)] = '\0';
	return (s1);
}
