#include "asm.h"

char	*get_cor_file_name(char *file_name)
{
	char	*cor_file_name;
	size_t	len_file_name;
	size_t	len_cor_file_name;

	len_file_name = ft_strlen(file_name);
	len_cor_file_name = len_file_name + 2;
	cor_file_name = (char *)malloc(sizeof(char) * (len_cor_file_name + 1));
	if (cor_file_name == NULL)
		print_error_and_exit();
	ft_memcpy(cor_file_name, file_name, len_cor_file_name - 3);
	ft_memcpy(&(cor_file_name[len_cor_file_name - 3]), "cor", 3);
	cor_file_name[len_cor_file_name] = '\0';
	return (cor_file_name);
}
