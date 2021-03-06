#include "asm.h"

size_t		get_num_bytes_from_arg(t_instr_row *instr_row,
									 t_type_token	type_token)
{
	size_t	num_bytes;
	size_t	index_hard_table;

	num_bytes = 0;
	index_hard_table = instr_row->instr.code_instr - 1;
	if (type_token == REGISTER)
		num_bytes = 1;
	else if (type_token == DIRECT || type_token == DIRECT_LABEL)
		num_bytes = T_DIR_SIZES[index_hard_table];
	else if (type_token == INDIRECT || type_token == INDIRECT_LABEL)
		num_bytes = IND_SIZE;
	else
		print_error_and_exit();
	return (num_bytes);
}

int			is_num_from_ind(const char *str, size_t	index)
{
	if (str[index] == '-')
		++index;
	if (str[index] == '\0')
		return (0);
	while (str[index] != '\0' && ft_isdigit(str[index]))
		++index;
	if (str[index] == '\0')
		return (1);
	return (0);
}

static int	is_valid_label_char(char c)
{
	size_t	index;

	index = 0;
	while (LABEL_CHARS[index] != '\0')
	{
		if (c == LABEL_CHARS[index])
			return (1);
		++index;
	}
	return (0);
}

int 		is_label(const char *str, size_t len)
{
	size_t	index;

	if (str[len - 1] != LABEL_CHAR)
		return (0);
	index = 0;
	while (index < len - 1)
	{
		if (!is_valid_label_char(str[index]))
			return (0);
		++index;
	}
	return (1);
}

int			is_word_from_to(const char *str,
					size_t from_inclusive, size_t to_exclusive)
{
	size_t index;

	index = from_inclusive;
	while (index < to_exclusive && str[index] != '\0')
	{
		if (!ft_isalpha(str[index]))
			return (0);
		++index;
	}
	return (1);
}

int			is_instr(const char *str)
{
	size_t	index;

	index = 0;
	while (index < NUM_OF_INSTR)
	{
		if (!ft_strcmp(str, INSTRS[index]))
			return (1);
		++index;
	}
	return (0);
}

char		*char_to_string(char c)
{
	char *str;

	if ((str = (char *)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char 		*type_to_string(t_type_token type)
{
	if (type == 0)
		return ("UNKNOWN");
	else if (type == 1)
		return ("NAME");
	else if (type == 2)
		return ("COMMENT");
	else if (type == 3)
		return ("INSTRUCTION");
	else if (type == 4)
		return ("STRING");
	else if (type == 5)
		return ("LABEL");
	else if (type == 6)
		return ("SEPARATOR");
	else if (type == 7)
		return ("REGISTER");
	else if (type == 8)
		return ("DIRECT");
	else if (type == 9)
		return ("DIRECT_LABEL");
	else if (type == 10)
		return ("INDIRECT");
	else if (type == 11)
		return ("INDIRECT_LABEL");
	else if (type == 12)
		return ("NEW_LINE");
	else if (type == 13)
		return ("END");
	return ("WRONG TYPE INPUT");
}
