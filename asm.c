#include "asm.h"

// DEBUG for printf
#include <stdio.h>
unsigned long ml = 0;
unsigned long fr = 0;

void	do_main(char *file_name)
{
	t_asm	asm_node;

	init_asm(&asm_node);
	parse(&(asm_node.token_list), file_name);

	// DEBUG
	print_token_list(&(asm_node.token_list));
	// DEBUG

	parse_tokens(&asm_node);
	parse_instr_list(&asm_node);
}

int		main(int argc, char **argv)
{
//	if (!check_args(argc, argv))
//	{
//		ft_putstr("Usage: ./asm filename.s\n");
//		return (0);
//	}
	do_main("ex.s");
//	do_main(argv[1]);

	// DEBUG
	printf("\nMalloc:%lu Free:%lu\n",ml, fr);
	return (0);
}
