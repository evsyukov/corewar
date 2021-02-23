#include "asm.h"

void 	init_token_list(t_token_list *token_list)
{
	token_list->begin = NULL;
	token_list->end = NULL;
}

void	init_instr_row(t_instr_row *instr_row, char *str, size_t index)
{
	instr_row->instr.name_instr = str;
	instr_row->instr.code_instr = index + 1;
	instr_row->instr.num_args = NUM_ARGS[index];
	instr_row->instr.set_first_arg = 0;
	instr_row->instr.set_second_arg = 0;
	instr_row->instr.set_third_arg = 0;
	if (NUM_ARGS[index] >= 1)
		instr_row->instr.set_first_arg = SET_FIRST_ARG[index];
	if (NUM_ARGS[index] >= 2)
		instr_row->instr.set_second_arg = SET_SECOND_ARG[index];
	if (NUM_ARGS[index] == 3)
		instr_row->instr.set_third_arg = SET_THIRD_ARG[index];
	instr_row->instr.is_code_types_exist = IS_CODE_TYPES[index];
	instr_row->instr.size_t_dir = T_DIR_SIZES[index];

	instr_row->arg_list.num_args = NUM_ARGS[index];
	instr_row->arg_list.num_bytes = 0;
	instr_row->arg_list.begin = NULL;
	instr_row->arg_list.end = NULL;

	instr_row->num_bytes = 0;
//	instr_row->num_bytes = 1 + instr_row->instr.is_code_types_exist
//		+ instr_row->arg_list.num_bytes;
	instr_row->next = NULL;
	instr_row->prev = NULL;
}

void	init_asm(t_asm *asm_node)
{
	asm_node->file_name_cor = NULL;

	asm_node->header.magic = COREWAR_EXEC_MAGIC;
	ft_memset(asm_node->header.prog_name, '\0', PROG_NAME_LENGTH);
	asm_node->header.prog_size = 0;
	ft_memset(asm_node->header.comment, '\0', COMMENT_LENGTH);

	asm_node->set_header = 0;

	asm_node->token_list.begin = NULL;
	asm_node->token_list.end = NULL;

	asm_node->h_table = hash_table_init();

	asm_node->instr_list.num_instrs = 0;
	asm_node->instr_list.num_bytes = 0;
	asm_node->instr_list.begin = NULL;
	asm_node->instr_list.end = NULL;
}
