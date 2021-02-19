#include "ft_printf.h"

int	main(void)
{
	char			a;
	char			*p;
	unsigned int	u;

	p = &a;
	u = 4294967295;

	printf("\nPRINTF: esta imprimiendo: \nun caracter: %c\nun string: %s\nun puntero: %p\ndos integros decimales: %i, %d\nun unsigned int: %u\nun hexadecimal en minus y el mismo en mayus: %x, %X\ny para terminar un %%\n", 'a', "hola caracola", p, 8, 3, u, 123, 123);
	//ft_printf("\nFT_PRINTF: esta imprimiendo: \nun caracter: %c\nun string: %s\nun puntero: %p\ndos integros decimales: %i, %d\nun unsigned int: %u\nun hexadecimal en minus y el mismo en mayus: %x, %X\ny para terminar un %%\n", 'a', "hola caracola", p, 8, 3, u, 123, 123);
	printf("%1-26-59866i", 1);
	return (0);
}
