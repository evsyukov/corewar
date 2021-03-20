#include "asm.h"

static t_byte	**create_arr_bytes(t_asm *asm_node)
{
	t_byte	**arr;
	size_t	len_arr;
	size_t	index;
	t_byte	*node_arr;

	len_arr = get_len_arr(asm_node);
	asm_node->len_arr = len_arr;
	if ((arr = (t_byte **)malloc(sizeof(t_byte *) * len_arr)) == NULL)
		print_error_and_exit();
	index = 0;
	while (index < len_arr)
	{
		if ((node_arr = (t_byte *)malloc(sizeof(t_byte))) == NULL)
			print_error_and_exit();
		node_arr->value = 0;
		node_arr->num_bytes = 0;
		arr[index++] = node_arr;
	}
	return (arr);
}

static	size_t	get_code(t_token *token)
{
	if (token->type_token == INDIRECT || token->type_token == INDIRECT_LABEL)
		return (3);
	else if (token->type_token == DIRECT || token->type_token == DIRECT_LABEL)
		return (2);
	else if (token->type_token == REGISTER)
		return (1);
	return (0);
}

static	void	handle_code(t_asm *asm_node, t_instr_row *instr_row)
{
	size_t	value;
	size_t	num_arg;
	t_token	*token;
	size_t	shift;
	size_t	code;

	num_arg = 0;
	token = instr_row->arg_list.begin;
	value = 0;
	shift = 6;
	while (num_arg < instr_row->arg_list.num_args)
	{
		if (token->type_token == SEPARATOR)
			token = token->next;
		if ((code = get_code(token)) == 0)
			print_error_and_exit();
		value += code << shift;
		shift -= 2;
		token = token->next;
		++num_arg;
	}
	asm_node->arr[asm_node->index_arr]->value = value;
	asm_node->arr[asm_node->index_arr]->num_bytes = 1;
	++(asm_node->index_arr);
}

static void		fill_arr(t_asm *asm_node, t_instr_row *instr_row)
{
	size_t	num_arg;
	t_token	*token;
	size_t	index_hard_tables;

	asm_node->arr[asm_node->index_arr]->value = instr_row->instr.code_instr;
	asm_node->arr[asm_node->index_arr]->num_bytes = 1;
	++(asm_node->index_arr);
	index_hard_tables = instr_row->instr.code_instr - 1;
	if (IS_CODE_TYPES[index_hard_tables] == 1)
		handle_code(asm_node, instr_row);
	num_arg = 0;
	token = instr_row->arg_list.begin;
	while (num_arg < instr_row->arg_list.num_args)
	{
		if (token->type_token == SEPARATOR)
			token = token->next;
		get_bytes(asm_node, instr_row, token);
		token = token->next;
		++(asm_node->index_arr);
		++num_arg;
	}
}

void			parse_instr_list(t_asm *asm_node)
{
	t_instr_row	*instr_row;

	asm_node->arr = create_arr_bytes(asm_node);
	instr_row = asm_node->instr_list.begin;
	while (instr_row != NULL)
	{
		fill_arr(asm_node, instr_row);
		instr_row = instr_row->next;
	}
}
