#include "asm.h"

t_hash				**hash_table_init(void)
{
	size_t	i;
	t_hash	**hash_table;

	i = 0;
	MFAIL((hash_table = malloc(sizeof(t_hash*) * TABLE_SIZE)));
	while (i < TABLE_SIZE)
	{
		hash_table[i] = NULL;
		i++;
	}
	return (hash_table);
}

static unsigned int	calc_hash(const char *node_name)
{
	unsigned long int	value;
	unsigned int		i;

	value = 0;
	i = 0;
	while (node_name[i])
		value = value * HASH_MULT + node_name[i++];
	return (value % TABLE_SIZE);
}

t_hash				*assign_to_table(t_hash **table, char *node_name)
{
	t_hash			*new;
	unsigned int	hash_val;
	t_hash			*node;

	hash_val = calc_hash(node_name);
	MFAIL((new = malloc(sizeof(t_hash))));
	new->node_name = node_name;
	new->next = NULL;
	new->prev = NULL;
	if (table[hash_val] == NULL)
		table[hash_val] = new;
	else
	{
		node = table[hash_val];
		while (node->next)
			node = node->next;
		node->next = new;
	}
	return (new);
}

void				free_hash_table(t_hash **h_table)
{
	size_t	i;
	t_hash	*node;
	t_hash	*next;

	i = 0;
	while (i < TABLE_SIZE)
	{
		if (h_table[i])
		{
			node = h_table[i];
			while (node)
			{
				next = node->next;
				FCNT(free(node->node_name));
				FCNT(free(node));
				node = next;
			}
		}
		i++;
	}
	FCNT(free(h_table));
}

t_hash				*hash_query(t_hash **h_table, char *node_name)
{
	t_hash			*node;
	unsigned int	hash_val;

	hash_val = calc_hash(node_name);
	if (h_table[hash_val] == NULL)
		return (NULL);
	node = h_table[hash_val];
	while (node)
	{
		if (ft_strequ(node_name, node->node_name))
			return (node);
		node = node->next;
	}
	return (NULL);
}
