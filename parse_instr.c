#include "asm.h"

static int	is_valid_num_args(t_instr_row *instr_row, t_token *token)
{
	size_t	num_args;
	int		is_sep;

	num_args = 0;
	is_sep = 0;
	token = token->next;
	while (token->type_token != NEW_LINE)
	{
		if (is_sep == 0 && token->type_token != SEPARATOR)
		{
			++num_args;
			is_sep = 1;
		}
		else if (is_sep == 1 && token->type_token == SEPARATOR)
			is_sep = 0;
		else
			print_error_and_exit();
		token = token->next;
	}
	if (is_sep == 0 || num_args != instr_row->instr.num_args)
		return (0);
	return (1);
}

static int	is_valid_type_args(t_instr_row *instr_row, t_token *token)
{
	size_t	count;
	size_t	code;

	token = token->next;
	count = 1;
	while (count <= instr_row->instr.num_args)
	{
		if (token->type_token == REGISTER)
			code = 1;
		if (token->type_token == DIRECT || token->type_token == DIRECT_LABEL)
			code = 2;
		if (token->type_token == INDIRECT
		|| token->type_token == INDIRECT_LABEL)
			code = 4;
		if (count == 1 && !(instr_row->instr.set_first_arg & code))
			return (0);
		if (count == 2 && !(instr_row->instr.set_second_arg & code))
			return (0);
		if (count == 3 && !(instr_row->instr.set_third_arg & code))
			return (0);
		++count;
		token = token->next->next;
	}
	return (1);
}

static int	is_valid_instr_row(t_instr_row *instr_row, t_token *token)
{
	if (!is_valid_num_args(instr_row, token))
		return (0);
	if (!is_valid_type_args(instr_row, token))
		return (0);
	return (1);
}

t_token		*parse_instr_row(t_instr_row *instr_row, t_token *token)
{
	if (!is_valid_instr_row(instr_row, token))
		print_error_and_exit();
	token = token->next;
	token = parse_arg_list(instr_row, token);
	return (token);
}
