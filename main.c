#include "ft_printf.h"

int	main(void)
{
	char			a;
	char			*p;
	unsigned int	u;

	p = &a;
	u = 4294967295;
	printf("\n\nPRINTF: esto es un caracter: %c\n", 'a');
	ft_printf("FT_PRINTF: esto es un caracter: %c\n\n", 'a');
	printf("PRINTF: esto es un string: %s\n", "Hola caracola");
	ft_printf("FT_PRINTF: esto es un string: %s\n\n", "Hola caracola");
	printf("PRINTF: esto es un puntero: %p\n", p);
	ft_printf("FT_PRINTF: esto es un puntero: %p\n\n", p);
	printf("PRINTF: esto es un integro: %i\n y este otro %d\n", 1, 3);
	ft_printf("FT_PRINTF: esto es un integro: %i\n y este otro %d\n\n", 1, 3);
	printf("PRINTF: esto es una impresion a secas\n");
	ft_printf("FT_PRINTF: esto es una impresion a secas\n\n");
	printf("PRINTF: esto es un unsigned int: %u\n", u);
	ft_printf("FT_PRINTF: esto es un unsigned int: %u\n\n", u);
	printf("PRINTF: esto es un hexadecimal en minus: %x\n", 123);
	ft_printf("FT_PRINTF: esto es un hexadecimal en minus: %x\n\n", 123);
	printf("PRINTF: esto es un hexadecimal en mayus: %X\n", 123);
	ft_printf("FT_PRINTF: esto es un hexadecimal en mayus: %X\n\n", 123);
	printf("PRINTF: esto es un porcentaje %% y este otro %%?");
	ft_printf("FT_PRINTF: esto es un porcentaje %% y este otro%%?\n\n");
	return (0);
}
