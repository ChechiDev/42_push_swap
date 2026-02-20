/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:47:35 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/20 11:33:04 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_list
{
	long			content;
	struct s_list	*next;
}	t_list;

/* Libft functions */
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr(int n, int fd);
int		ft_strcmp(char *s1, char *s2);

/* lists */
t_list	*ft_lstnew(long content);
#endif
