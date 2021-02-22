#include "asm.h"

static void			tokens_add_tokens(t_token_list *token_list, t_token *token)
{
	if (token == NULL)
		return;
	if (token_list->end == NULL)
	{
		token_list->begin = token;
		token->prev = NULL;
		while (token->next != NULL)
			token = token->next;
		token_list->end = token;
		return;
	}
	token_list->end->next = token;
	token->prev = token_list->end;
	while (token->next != NULL)
		token = token->next;
	token_list->end = token;
	token->next = NULL;
}

static t_token		*create_token(char *str_token, t_type_token type)
{
	t_token	*token;

	if ((token = (t_token *)malloc(sizeof(t_token))) == NULL)
		print_error_and_exit();
	token->str = str_token;
	token->type_token = type;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

static t_type_token	get_type_token(char *str)
{
	t_type_token	type;
	size_t 			len;

	len = ft_strlen(str);
	type = UNKNOWN;
	if (str == NULL)
		return (type);
	if (len == 1 && str[0] == SEPARATOR_CHAR)
		type = SEPARATOR;
	else if (!ft_strcmp(str, NAME_CMD_STRING))
		type = NAME;
	else if (!ft_strcmp(str, COMMENT_CMD_STRING))
		type = COMMENT;
	else if (len >= 2 && len <= 3 && str[0] == 'r' && is_num_from_ind(str, 1))
		type = REGISTER;
	else if (is_num_from_ind(str, 0))
		type = INDIRECT;
	else if (len >= 2 && str[0] == LABEL_CHAR)
		type = INDIRECT_LABEL;
	else if (len >= 3 && str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
		type = DIRECT_LABEL;
	else if (len >= 2 && str[0] == DIRECT_CHAR)
		type = DIRECT;
	else if (is_instr(str))
		type = INSTRUCTION;
	else if (is_label(str, len))
		type = LABEL;
	else if (len >= 2 && str[0] == '"' && str[len - 1] == '"')
//	&& (is_word_from_to(str, 1, len) || len == 2))
		type = STRING;
	return (type);
}

void				parse_by_sep(char *str, t_token_list *tokens)
{
	t_type_token	type;
	size_t			index;
	size_t 			curr_index;
	char 			*str_sub;

	index = 0;
	curr_index = 0;
	while (str[index] != '\0')
	{
		while (str[curr_index] != SEPARATOR_CHAR && str[curr_index] != '\0')
			++curr_index;
		str_sub = ft_strsub(str, index, curr_index - index);
		type = get_type_token(str_sub);
		tokens_add_tokens(tokens, create_token(str_sub, type));
		if (str[curr_index] == SEPARATOR_CHAR)
		{
			tokens_add_tokens(tokens, create_token(char_to_string(SEPARATOR_CHAR), SEPARATOR));
			++curr_index;
		}
		index = curr_index;
	}
}

size_t				get_string(const char *line, size_t start_index)
{
	size_t	index;

	index = start_index + 1;
	while (line[index] != '\0' && line[index] != '"')
		++index;
	if (line[index] == '"')
		++index;
	return (index);
}

static t_token_list	*get_token_list(const char *line, size_t *curr_index)
{
	size_t			start_ind_token;
	size_t			len_token;
	char			*str_token;
	t_token_list 	*token_list;

	start_ind_token = *curr_index;
	if ((token_list = (t_token_list *)malloc(sizeof(t_token_list))) == NULL)
		print_error_and_exit();
	init_token_list(token_list);
	if (line[start_ind_token] == '"')
		*curr_index = get_string(line, start_ind_token);
	else
		while (line[*curr_index] != '\0' && !is_whitespace(line[*curr_index]))
			++(*curr_index);
	len_token = *curr_index - start_ind_token;
	if (len_token != 0)
	{
		str_token = ft_strsub(line, start_ind_token, len_token);
		parse_by_sep(str_token, token_list);
		free(str_token);
	}
	return (token_list);
}

static void			parse_line(t_token_list *token_list, const char *line)
{
	size_t			index;
	t_token_list	*new_list;

	index = 0;
	while (line[index] != '\0')
	{
		index = skip_whitespaces(line, index);
		if (line[index] == COMMENT_CHAR || line[index] == '\0')
			break;
		new_list = get_token_list(line, &index);
		tokens_add_tokens(token_list, new_list->begin);
		free(new_list);
	}
}

void				parse(t_token_list *token_list, char *file_name)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		print_error_and_exit();
	while ((ret = get_next_line(fd, &line)))
	{
		parse_line(token_list, line);
		tokens_add_tokens(token_list, create_token(ft_strdup("NEW_LINE"), NEW_LINE));
		free(line);
		line = NULL;
	}
	close(fd);
	tokens_add_tokens(token_list, create_token(ft_strdup("END"), END));
}
