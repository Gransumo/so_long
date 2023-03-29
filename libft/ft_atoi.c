/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <gcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:03:22 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 20:04:03 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	var_int[2];

	var_int[0] = 0;
	var_int[1] = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			var_int[1]++;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		var_int[0] = (var_int[0] * 10) + (*str - '0');
		str++;
	}
	if (var_int[1] % 2 != 0)
		var_int[0] = -var_int[0];
	return (var_int[0]);
}
