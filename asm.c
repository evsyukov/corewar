#include "asm.h"

unsigned long ml = 0;
unsigned long fr = 0;

void	output_to_cor_file(t_asm *asm_node, char *final_arr, char *file_cor)
{
	int fd;

	fd = open(file_cor, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		print_error_and_exit();
	// TO DO чек на то что в файл успешно прошла запись
	write(fd, final_arr, asm_node->len_final_cor);
	// TO DO чек на то что файл успешно закрылся
	close(fd);
}

void	do_main(char *file_name)
{
	t_asm	asm_node;
	char	*final_arr;

	init_asm(&asm_node, file_name);
	parse(&(asm_node.token_list), file_name);
	// DEBUG
	print_token_list(&(asm_node.token_list));
	// DEBUG
	parse_tokens(&asm_node);
	parse_instr_list(&asm_node);
	// DEBUG
	print_arr(&asm_node);
	// DEBUG
	assemble_arr_hex(&asm_node);
	final_arr = get_final_str(&asm_node);
	output_to_cor_file(&asm_node, final_arr, get_cor_file_name(file_name));
}

int		main(int argc, char **argv)
{
	if (!check_args(argc, argv))
	{
		ft_putstr("Usage: ./asm filename.s\n");
		return (0);
	}
	do_main(argv[1]);
	// DEBUG
//	do_main("ex.s");
	// DEBUG
//	print_malloc_free();
	return (0);
}
