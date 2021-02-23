#include "asm.h"

t_token		*handle_name(t_asm *asm_node, t_token *token)
{
	size_t len;

	if (token == NULL || token->next == NULL
	|| token->next->type_token != STRING)
		print_error_and_exit();
	token = token->next;
	len = ft_strlen(token->str);
	if (len > PROG_NAME_LENGTH)
		print_error_and_exit();
	ft_strncpy(asm_node->header.prog_name, token->str, len);
	asm_node->set_header += 1;
	return (token->next);
}

t_token		*handle_comment(t_asm *asm_node, t_token *token)
{
	size_t len;

	if (token == NULL || token->next == NULL
		|| token->next->type_token != STRING)
		print_error_and_exit();
	token = token->next;
	len = ft_strlen(token->str);
	if (len > COMMENT_LENGTH)
		print_error_and_exit();
	ft_strncpy(asm_node->header.comment, token->str, len);
	asm_node->set_header += 2;
	return (token->next);
}

t_token		*parse_header(t_asm *asm_node)
{
	t_token_list	*token_list;
	t_token			*token;
	size_t 			count;

	token_list = &(asm_node->token_list);
	token = token_list->begin;
	count = 2;
	while (count--)
	{
		while (token->type_token == NEW_LINE)
			token = token->next;
		if (token->type_token == NAME
			&& (asm_node->set_header == 0 || asm_node->set_header == 2))
			token = handle_name(asm_node, token);
		else if (token->type_token == COMMENT
			&& (asm_node->set_header == 0 || asm_node->set_header == 1))
			token = handle_comment(asm_node, token);
		else
			print_error_and_exit();
	}
	return (token);
}

size_t		get_index(char *str)
{
	int	index;

	index = 0;
	while (index < NUM_OF_INSTR)
	{
		if (!ft_strcmp(INSTRS[index], str))
			return (index);
		++index;
	}
	return (-1);
}

t_instr_row	*create_instr_row(char *str, size_t index)
{
	t_instr_row	*instr_row;

	if ((instr_row = (t_instr_row *)malloc(sizeof(t_instr_row))) == NULL)
		print_error_and_exit();
	init_instr_row(instr_row, str, index);
	return (instr_row);
}

void		instrs_add(t_instr_list *instr_list, t_instr_row *instr_row)
{
	if (instr_list == NULL || instr_row == NULL)
		return;
	if (instr_list->end == NULL)
	{
		instr_list->begin = instr_row;
		instr_list->end = instr_row;
		instr_row->next = NULL;
		instr_row->prev = NULL;
		instr_list->num_instrs += 1;
		instr_list->num_bytes += instr_row->num_bytes;
		return;
	}
	instr_list->end->next = instr_row;
	instr_row->prev = instr_list->end;
	instr_list->end = instr_row;
	instr_row->next = NULL;
	instr_list->num_instrs += 1;
	instr_list->num_bytes += instr_row->num_bytes;
}

t_token		*handle_instr_row(t_asm *asm_node, t_token *token)
{
	int			index;
	t_instr_row	*instr_row;

	if ((index = get_index(token->str)) == -1)
		print_error_and_exit();
	instr_row = create_instr_row(token->str, index);
	token = parse_instr_row(instr_row, token); // файл parse_tokens.c
	instrs_add(&(asm_node->instr_list), instr_row);
	return (token);
}

t_token		*parse_code(t_asm *asm_node, t_token *token)
{
	t_hash	*node;
	size_t	counter_bytes;

	if (asm_node->token_list.end->type_token != END)
		print_error_and_exit();
	while (token->type_token == NEW_LINE)
		token = token->next;
	counter_bytes = 0;
	while (token->type_token != END)
	{
		if (token->type_token == LABEL)
		{
			node = assign_to_table(asm_node->h_table, token->str);
			node->value = counter_bytes;
			token = token->next;
		}
		if (token->type_token == INSTRUCTION)
			token = handle_instr_row(asm_node, token);
		else
			print_error_and_exit();
		while (token->type_token == NEW_LINE)
			token = token->next;
	}
	return (token);
}

void		parse_tokens(t_asm *asm_node)
{
	t_token	*token;

	token = parse_header(asm_node);
	token = parse_code(asm_node, token);
}
