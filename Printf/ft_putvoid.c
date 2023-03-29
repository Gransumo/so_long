/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:02:23 by gcastro-          #+#    #+#             */
/*   Updated: 2022/06/03 13:02:25 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putvoid(unsigned long s, t_args *ln)
{
	ln -> len += write(1, "0x", 2);
	ft_putnbr_base_p (s, "0123456789abcdef", ln);
}
