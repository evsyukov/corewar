#include "asm.h"

static size_t	calc_num_bytes_by_token(t_instr_row *instr_row,
									t_type_token type_token, size_t num_arg)
{
	size_t	num_bytes;
	size_t	set_arg;

	num_bytes = 0;
	if (num_arg == 1)
		set_arg = instr_row->instr.set_first_arg;
	if (num_arg == 2)
		set_arg = instr_row->instr.set_second_arg;
	if (num_arg == 3)
		set_arg = instr_row->instr.set_third_arg;
	if (type_token == REGISTER)
		num_bytes += set_arg & 1;
	if (type_token == DIRECT || type_token == DIRECT_LABEL)
		num_bytes += set_arg & 2;
	if (type_token == INDIRECT || type_token == INDIRECT_LABEL)
		num_bytes += set_arg & 4;
	return (num_bytes);
}

//static size_t	calc_num_bytes(t_instr_row *instr_row, t_token *token)
//{
//	size_t num_bytes;
//
//	num_bytes = 0;
//	if (instr_row->arg_list.num_args >= 1)
//	{
//		num_bytes += calc_num_bytes_by_token(instr_row, token->type_token);
//	}
//		num_bytes += (instr_row->instr.set_first_arg & 1)
//			+ instr_row->instr.size_t_dir * (instr_row->instr.set_first_arg & 2)
//			+ IND_SIZE * (instr_row->instr.set_first_arg & 4);
//	if (instr_row->arg_list.num_args >= 2)
//		num_bytes += (instr_row->instr.set_second_arg & 1)
//			+ instr_row->instr.size_t_dir * (instr_row->instr.set_second_arg & 2)
//			+ IND_SIZE * (instr_row->instr.set_second_arg & 4);
//	if (instr_row->arg_list.num_args >= 3)
//		num_bytes += (instr_row->instr.set_third_arg & 1)
//			+ instr_row->instr.size_t_dir * (instr_row->instr.set_third_arg & 2)
//			+ IND_SIZE * (instr_row->instr.set_third_arg & 4);
//	return (num_bytes);
//}

t_token			*args_add_arg(t_instr_row *instr_row,
						t_token *token, size_t num_args)
{
	size_t	counter;

	if (instr_row == NULL && token == NULL || num_args == 0)
		return NULL;
	counter = 1;
	instr_row->arg_list.begin = token;
	while (counter <= num_args)
	{
		instr_row->arg_list.num_bytes +=
			calc_num_bytes_by_token(instr_row, token->type_token, counter);
		token = token->next;
		if (token->type_token == SEPARATOR)
			token = token->next;
		++counter;
	}
	instr_row->arg_list.end = token->prev;
	return (token);
}

t_token			*parse_arg_list(t_instr_row *instr_row, t_token *token)
{
	token = args_add_arg(instr_row,
					  token, instr_row->arg_list.num_args);
	instr_row->num_bytes = 1 + instr_row->instr.is_code_types_exist
		+ instr_row->arg_list.num_bytes;
	return (token);
}
