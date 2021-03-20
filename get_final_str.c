#include "asm.h"

char	*get_final_str(t_asm *asm_node)
{
	char	*str;
	size_t	index;
	size_t	len_code_instrs;

	str = ft_strnew(asm_node->len_final_cor);
	index = 0;
	len_code_instrs = asm_node->counter_bytes;
	fill_value_to_hex(str, COREWAR_EXEC_MAGIC, index, SIZE_MAGIC);
	index += SIZE_MAGIC;
	ft_memcpy(&(str[index]), asm_node->header.prog_name, PROG_NAME_LENGTH);
	index += PROG_NAME_LENGTH;
	index += SIZE_NULL_SEP;
	fill_value_to_hex(str, len_code_instrs, index, SIZE_LEN_CODE);
	index += SIZE_LEN_CODE;
	ft_memcpy(&(str[index]), asm_node->header.comment, COMMENT_LENGTH);
	index += COMMENT_LENGTH;
	index += SIZE_NULL_SEP;
	ft_memcpy(&(str[index]), asm_node->hex_code, len_code_instrs);
	return (str);
}
