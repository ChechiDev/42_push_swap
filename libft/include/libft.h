/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:47:35 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/19 18:41:40 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

typedef struct s_list
{
	long			content;
	struct s_list	*next;
}	t_list;

/* Libft functions */
int		ft_strcmp(char *s1, char *s2);

/* lists */
t_list	*ft_lstnew(long content);
#endif
