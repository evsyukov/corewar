#include "asm.h"

static int	is_valid_num_args(t_instr_row *instr_row, t_token *token)
{
	size_t	num_args;

	num_args = 0;
	while (token->type_token != NEW_LINE)
	{
		++num_args;
		token = token->next;
	}
	if (num_args != instr_row->instr.num_args)
		return (0);
	return (1);
}

static int	is_valid_type_args(t_instr_row *instr_row, t_token *token)
{

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

	return (token);
}
