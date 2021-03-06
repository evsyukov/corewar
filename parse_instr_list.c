#include "asm.h"

t_byte		*create_node_arr()
{
	t_byte	*node_arr;

	if ((node_arr = (t_byte *)malloc(sizeof(t_byte))) == NULL)
		return (NULL);
	node_arr->value = 0;
	node_arr->num_bytes = 0;
	return (node_arr);
}

t_byte		**create_arr_bytes(t_asm *asm_node)
{
	t_byte	**arr;
	size_t	len_arr;
	size_t	index;

	len_arr = get_len_arr(asm_node);
	if ((arr = (t_byte **)malloc(sizeof(t_byte *) * len_arr)) == NULL)
		return (NULL);
	index = 0;
	while (index < len_arr)
		arr[index++] = create_node_arr();
	return (arr);
}

// TO DO заполнение массива
static void make_some_staff(t_asm *asm_node, t_instr_row *instr_row,
							t_token *token)
{
	size_t			index_hard_tables;
	t_type_token	type_token;

	index_hard_tables = instr_row->instr.code_instr - 1;
	type_token = token->type_token;
	if (type_token == REGISTER)
	{
		asm_node->arr[asm_node->index_arr]->value = instr_row->instr.code_instr;
		asm_node->arr[asm_node->index_arr]->num_bytes = 1;
	}
	else if (type_token == DIRECT)
	{
		// TO DO DIRECT
	}
	else if (type_token == DIRECT_LABEL)
	{
		// TO DO DIRECT_LABEL
	}
	else if (type_token == INDIRECT)
	{
		// TO DO INDIRECT
	}
	else if (type_token == INDIRECT_LABEL)
	{
		// TO DO INDIRECT_LABEL
	}
	++(asm_node->index_arr);
}

static void	fill_arr(t_asm *asm_node, t_instr_row *instr_row)
{
	size_t	num_arg;
	t_token	*token;

	num_arg = 0;
	token = instr_row->arg_list.begin;
	while (num_arg < instr_row->arg_list.num_args)
	{
		make_some_staff(asm_node, instr_row, token);
		if (token->type_token == SEPARATOR)
			token = token->next;
		token = token->next;
		++num_arg;
	}
}

void		parse_instr_list(t_asm *asm_node)
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
