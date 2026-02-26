/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:36:08 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/26 15:42:03 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

long	ft_atol(char *argv_char);

int	main(void)
{
	printf("=== TEST get_sign (via ft_atol) ===\n\n");

	printf("Sin signo:\n");
	printf("'42'  -> %ld (esperado: 42)\n",  ft_atol("42"));
	printf("'-42' -> %ld (esperado: -42)\n", ft_atol("-42"));
	printf("'+42' -> %ld (esperado: 42)\n",  ft_atol("+42"));

	printf("\nWhitespace:\n");
	printf("'  42'  -> %ld (esperado: 42)\n",  ft_atol("  42"));
	printf("'  -42' -> %ld (esperado: -42)\n", ft_atol("  -42"));

	printf("\nSolo signo sin digitos:\n");
	printf("'-' -> %ld (esperado: 0)\n", ft_atol("-"));
	printf("'+' -> %ld (esperado: 0)\n", ft_atol("+"));

	return (0);
}
