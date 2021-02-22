/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:12:50 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/22 20:35:47 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	//char			a;
	char			*p;
	unsigned int	u;

	p = 0;
	u = 4294967295;

	//printf("\nPRINTF: esta imprimiendo: \nun caracter: %c\nun string: %s\nun puntero: %p\ndos integros decimales: %i, %d\nun unsigned int: %u\nun hexadecimal en minus y el mismo en mayus: %x, %X\ny para terminar un %%\n", 'a', "hola caracola", p, 8, 3, u, 123, 123);
	//ft_printf("\nFT_PRINTF: esta imprimiendo: \nun caracter: %c\nun string: %s\nun puntero: %p\ndos integros decimales: %i, %d\nun unsigned int: %u\nun hexadecimal en minus y el mismo en mayus: %x, %X\ny para terminar un %%\n", 'a', "hola caracola", p, 8, 3, u, 123, 123);

	printf("'Hello %5p'\n", p);
	ft_printf("'Hello %5p'\n", p);
	//system("leaks prueba");
	return (0);
}
