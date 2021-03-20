#include "asm.h"

static int32_t	get_value_from_label(t_asm *asm_node, t_instr_row *instr_row,
								char *str)
{
	t_hash	*hash;
	size_t	num_begin_byte;
	size_t	value;

	if ((hash = hash_query(asm_node->h_table, str)) == NULL)
		print_error_and_exit();
	num_begin_byte = instr_row->num_begin_byte;
	value = hash->value;
	return (value - num_begin_byte);
}

static size_t	handle(t_asm *asm_node, t_instr_row *instr_row,
						t_token *token)
{
	size_t			len;
	char			*node_str;
	t_type_token	type_token;
	size_t			index;
	size_t			value;

	len = ft_strlen(token->str);
	index = 0;
	type_token = token->type_token;
	if (type_token == DIRECT || type_token == INDIRECT_LABEL)
		index = 1;
	if (type_token == DIRECT_LABEL)
		index = 2;
	if ((node_str = ft_strsub(token->str, index, len - index)) == NULL)
		print_error_and_exit();
	if (type_token == DIRECT_LABEL || type_token == INDIRECT_LABEL)
		value = (size_t)get_value_from_label(asm_node, instr_row, node_str);
	else
		value = ft_atoi(node_str);
	return (value);
}

static size_t	get_register_code(char *str)
{
	size_t	result;
	char	*str_sub;
	size_t	len;

	len = ft_strlen(str);
	if ((str_sub = ft_strsub(str, 1, len - 1)) == NULL)
		print_error_and_exit();
	result = ft_atoi(str_sub);
	return (result);
}

void			get_bytes(t_asm *asm_node, t_instr_row *instr_row,
						t_token *token)
{
	t_type_token	type_token;
	size_t			value;
	size_t			num_bytes;
	size_t			index_hard_tables;

	type_token = token->type_token;
	index_hard_tables = instr_row->instr.code_instr - 1;
	if (type_token == REGISTER)
	{
		value = get_register_code(token->str);
		num_bytes = 1;
	}
	else
	{
		value = handle(asm_node, instr_row, token);
		if (type_token == DIRECT || type_token == DIRECT_LABEL)
			num_bytes = T_DIR_SIZES[index_hard_tables];
		if (type_token == INDIRECT || type_token == INDIRECT_LABEL)
			num_bytes = IND_SIZE;
	}
	asm_node->arr[asm_node->index_arr]->value = value;
	asm_node->arr[asm_node->index_arr]->num_bytes = num_bytes;
}
