/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:47:35 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/27 10:28:18 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
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
void	ft_putnbr_fd(int n, int fd);
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *p, size_t i);
char	**ft_split(char const *s, char c);

/* lists */
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(long content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
long	ft_atol(char *argv_char);

#endif
