#include "asm.h"

static size_t	get_num_bytes(t_instr_row *instr_row, t_type_token type_token)
{
	size_t	num_bytes;
	size_t	index_hard_table;

	num_bytes = 0;
	index_hard_table = instr_row->instr.code_instr - 1;
	if (type_token == REGISTER)
		num_bytes = 1;
	else if (type_token == DIRECT || type_token == DIRECT_LABEL)
		num_bytes = T_DIR_SIZES[index_hard_table];
	else if (type_token == INDIRECT || type_token == INDIRECT_LABEL)
		num_bytes = IND_SIZE;
	else
		print_error_and_exit();
	return (num_bytes);
}

static t_token	*args_add_arg(t_instr_row *instr_row, t_token *token)
{
	size_t	num_arg;
	size_t	num_args;
	size_t	num_bytes_from_arg;

	if (instr_row == NULL && token == NULL)
		return (NULL);
	num_arg = 1;
	num_args = instr_row->arg_list.num_args;
	num_bytes_from_arg = 0;
	instr_row->arg_list.begin = token;
	while (num_arg <= num_args)
	{
		num_bytes_from_arg = get_num_bytes(instr_row, token->type_token);
		instr_row->arg_list.num_bytes += num_bytes_from_arg;
		token = token->next;
		if (token->type_token == SEPARATOR)
			token = token->next;
		++num_arg;
	}
	instr_row->arg_list.end = token->prev;
	return (token);
}

t_token			*parse_arg_list(t_instr_row *instr_row, t_token *token)
{
	token = args_add_arg(instr_row, token);
	instr_row->num_bytes = 1 + instr_row->instr.is_code_types_exist
		+ instr_row->arg_list.num_bytes;
	return (token);
}
