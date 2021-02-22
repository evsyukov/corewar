#include "asm.h"

void print_token(t_token *token)
{
	if (token == NULL)
		return;
	ft_putstr(token->str);
	write(1, " [", 2);
	ft_putstr(type_to_string(token->type_token));
	write(1, "]", 1);
}

void print_token_list(t_token_list *token_list)
{
	t_token	*token;

	token = token_list->begin;
	while (token != NULL)
	{
		print_token(token);
		write(1, "\n", 1);
		token = token->next;
	}
}
