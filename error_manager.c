#include "asm.h"

void	print_error_and_exit(void)
{
	ft_putstr_fd("Some error detected !!!", 2);
	exit(1);
}

void	err_exit(void)
{
	write(1, "ERROR\n", 6);
	exit(1);
}
