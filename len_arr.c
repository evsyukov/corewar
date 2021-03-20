#include "asm.h"

static size_t	get_len_row(t_instr_row *instr_row)
{
	size_t	len_row;
	t_token	*token;

	len_row = 1;
	if (instr_row->instr.is_code_types_exist == 1)
		++len_row;
	token = instr_row->arg_list.begin;
	len_row += instr_row->arg_list.num_args;
	return (len_row);
}

size_t			get_len_arr(t_asm *asm_node)
{
	size_t		len_arr;
	t_instr_row	*instr_row;

	len_arr = 0;
	instr_row = asm_node->instr_list.begin;
	while (instr_row != NULL)
	{
		len_arr += get_len_row(instr_row);
		instr_row = instr_row->next;
	}
	return (len_arr);
}
