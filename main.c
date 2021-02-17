#include "ft_printf.h"

int main()
{
	//char	*a;
	//printf("Escapas los %*.5f ?", 26, 45.34);
	//printf("como gestionas los hexadecimales: %x", 15);
	//ft_putstr_fd("Hola caracola", 1);

	//ft_printf("Hola caracola %c", 'a');


	//-----------------------itoa_base

	printf("Resultado itoa_base: %s\n", ft_itoa_base(123, "0123456789ABCDEF"));
	return (0);
}
