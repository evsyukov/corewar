#include "asm.h"

size_t	*create_arr_bytes(t_asm *asm_node)
{
	size_t	*bytes;
	size_t	num_bytes;
	size_t	index;

	num_bytes = asm_node->instr_list.num_bytes;
	if ((bytes = (size_t *)malloc(sizeof(size_t) * num_bytes)) == NULL)
		return (NULL);
	index = 0;
	while (index < num_bytes)
		bytes[index++] = 0;
	return (bytes);
}

void	parse_instr_list(t_asm *asm_node)
{
	t_instr_row	*instr_row;

	asm_node->bytes = create_arr_bytes(asm_node);
	instr_row = asm_node->instr_list.begin;
	while (instr_row != NULL)
	{
		// TO DO
		instr_row = instr_row->next;
	}
}
