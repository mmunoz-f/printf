/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:12:50 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/23 18:05:25 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	printf("PRINTF:\n\nEsto es una prueba");
	printf("Con strings:\n%s\n%10s\n%.*s\n%-20.4s\n\n", "Hola caracola", "Hola caracola", 4, "Hola caracola", "Hola caracola");
	ft_printf("FT_PRINTF:\n\nEsto es una prueba");
	ft_printf("Con strings:\n%s\n%10s\n%.*s\n%-20.4s\n\n", "Hola caracola", "Hola caracola", 4, "Hola caracola", "Hola caracola");
	system("leaks prueba");
	return (0);
}
