#include "asm.h"

static size_t	get_value(int32_t value, size_t num_bytes)
{
	size_t	v;

	if (num_bytes == 1)
		v = (uint8_t)value;
	else if (num_bytes == 2)
		v = (uint16_t)value;
	else if (num_bytes == 4)
		v = (uint32_t)value;
	else
		print_error_and_exit();
	return (v);
}

void			assemble_arr_hex(t_asm *asm_node)
{
	char	*hex;
	size_t	index_arr;
	size_t	index_bytes;
	size_t	num_bytes;
	int32_t	value;

	if ((hex = ft_strnew(asm_node->counter_bytes)) == NULL)
		print_error_and_exit();
	index_arr = 0;
	index_bytes = 0;
	while (index_arr < asm_node->len_arr)
	{
		num_bytes = asm_node->arr[index_arr]->num_bytes;
		value = get_value(asm_node->arr[index_arr]->value, num_bytes);
		fill_value_to_hex(hex, value, index_bytes, num_bytes);
		index_bytes += num_bytes;
		++index_arr;
	}
	asm_node->hex_code = hex;
}
