/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:35:12 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/26 16:41:29 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_options	*options;
	t_flag_opt	opts[2];

	printf("=== TEST check_options ===\n\n");
	options = malloc(sizeof(t_options));
	options->options = opts;
	printf("-- Solo BENCH -> valido (no es algoritmo)\n");
	opts[0] = BENCH;
	options->count = 1;
	printf("Resultado: %d (esperado: 1)\n\n", check_options(&options));
	printf("-- Solo SIMPLE -> valido\n");
	opts[0] = SIMPLE;
	options->count = 1;
	printf("Resultado: %d (esperado: 1)\n\n", check_options(&options));
	printf("-- BENCH + COMPLEX -> valido (1 algoritmo + bench)\n");
	opts[0] = BENCH;
	opts[1] = COMPLEX;
	options->count = 2;
	printf("Resultado: %d (esperado: 1)\n\n", check_options(&options));
	printf("-- SIMPLE + MEDIUM -> invalido (2 algoritmos)\n");
	opts[0] = SIMPLE;
	opts[1] = MEDIUM;
	options->count = 2;
	printf("Resultado: %d (esperado: 0)\n\n", check_options(&options));
	free(options);
	return (0);
}
