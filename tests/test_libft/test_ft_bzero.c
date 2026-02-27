/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:25:13 by sperez-l          #+#    #+#             */
/*   Updated: 2026/02/27 10:29:46 by sperez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	buf[5];

	printf("=== TEST ft_bzero ===\n\n");

	/* Caso 1: zerear todo el buffer */
	memset(buf, 0xFF, sizeof(buf));
	ft_bzero(buf, 5);
	printf("Caso 1 - Zerear 5 bytes:\n");
	printf("buf[0]=%d buf[4]=%d (esperado: 0 0)\n\n", buf[0], buf[4]);

	/* Caso 2: zerear solo los primeros 3, el resto intacto */
	memset(buf, 0xFF, sizeof(buf));
	ft_bzero(buf, 3);
	printf("Caso 2 - Zerear 3 de 5 bytes:\n");
	printf("buf[2]=%d buf[3]=%d (esperado: 0 -1)\n\n",
		buf[2], (signed char)buf[3]);

	/* Caso 3: n==0, no debe modificar nada */
	memset(buf, 0xAB, sizeof(buf));
	ft_bzero(buf, 0);
	printf("Caso 3 - n=0, no toca nada:\n");
	printf("buf[0]=%d (esperado: -85)\n\n", (signed char)buf[0]);
	return (0);
}
