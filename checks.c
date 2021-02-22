#include "asm.h"

int			is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

size_t		skip_whitespaces(const char *line, size_t index)
{
	while (is_whitespace(line[index]) == 1)
		++index;
	return (index);
}

static int	check_extension(char *file_name, char *extention)
{
	unsigned	len_file_name;
	unsigned	len_ext;
	unsigned	index;

	len_file_name = ft_strlen(file_name);
	len_ext = ft_strlen(extention);
	if (len_file_name <= len_ext)
		return (0);
	index = 0;
	while (index < len_ext)
	{
		if (file_name[len_file_name - len_ext + index] != extention[index])
			return (0);
		++index;
	}
	return (1);
}

int			check_args(int argc, char **argv)
{
	if (argc != 2 || !check_extension(argv[1], ".s"))
		return (0);
	return (1);
}
