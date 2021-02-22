#include "asm.h"

void 	free_token(t_token *token)
{
	free(token->str);
	free(token);
	token = NULL;
}

void	free_token_list(t_token_list *token_list)
{
	t_token	*token;
	t_token	*token_for_del;

	token = token_list->begin;
	while (token != NULL)
	{
		token_for_del = token;
		token = token->next;
		free_token(token_for_del);
	}
	token_list->begin = NULL;
	token_list->end = NULL;
}
