/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:29:59 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/25 19:01:43 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_flags	flags
	int		result;

	flags = (t_flags){0};
	result = check_flags(argc, argv, &flags);
	if (result == -1)
	{
		printf("Error en flags\n");
		return (1);
	}
	printf("Flags procesadas hasta índice: %d\n", result);
	printf("bench: %d\n", flags.bench);
	printf("simple: %d\n", flags.simple);
	printf("medium: %d\n", flags.medium);
	printf("complex: %d\n", flags.complex);
	printf("adaptive: %d\n", flags.adaptive);
	return (0);
}
