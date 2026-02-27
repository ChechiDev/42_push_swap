/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:34:10 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/27 10:34:55 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	**res;

	printf("=== TEST ft_split ===\n\n");
	/* Caso 1: separacion normal */
	res = ft_split("3 1 2", ' ');
	printf("Caso 1 - '3 1 2' por ' ':\n");
	printf("res[0]=%s res[1]=%s res[2]=%s (esperado: 3 1 2)\n\n",
		res[0], res[1], res[2]);
	free(res[0]); free(res[1]); free(res[2]); free(res);

	/* Caso 2: delimitadores multiples seguidos */
	res = ft_split("a,,b", ',');
	printf("Caso 2 - 'a,,b' por ',':\n");
	printf("res[0]=%s res[1]=%s (esperado: a b)\n\n", res[0], res[1]);
	free(res[0]); free(res[1]); free(res);

	/* Caso 3: cadena vacia -> NULL */
	res = ft_split("", ' ');
	printf("Caso 3 - cadena vacia:\n");
	printf("res=%p (esperado: NULL)\n\n", (void *)res);

	/* Caso 4: puntero NULL -> NULL */
	res = ft_split(NULL, ' ');
	printf("Caso 4 - NULL:\n");
	printf("res=%p (esperado: NULL)\n\n", (void *)res);

	/* Caso 5: sin delimitador en la cadena, un solo token */
	res = ft_split("push_swap", ' ');
	printf("Caso 5 - 'push_swap' sin delimitador:\n");
	printf("res[0]=%s (esperado: push_swap)\n\n", res[0]);
	free(res[0]); free(res);
	return (0);
}
