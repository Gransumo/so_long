/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_used.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:42:04 by gcastro-          #+#    #+#             */
/*   Updated: 2023/04/12 03:42:05 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COM_USED_H
# define COM_USED_H

# include "libft/libft.h"
# include "Printf/ft_printf.h"

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

int		error(char *message);
void	*null_error(char *message);
void	print_warning(char	*message);

#endif
