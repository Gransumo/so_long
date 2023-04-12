/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>					+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:55:47 by gcastro-          #+#    #+#             */
/*   Updated: 2022/09/14 21:19:42 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int		ft_charmap_linecounter(char **s);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *c);
int		ft_strlen_linemap(const char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp_end(const char *s, const char *final);
#endif
