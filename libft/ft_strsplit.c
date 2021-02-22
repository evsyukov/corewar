/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidoque <mnidoque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:33:41 by mnidoque          #+#    #+#             */
/*   Updated: 2019/09/19 20:14:21 by mnidoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter(char const *s, char c)
{
	size_t words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char		*word_in(char *word, char c)
{
	char *start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void		words_del(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
}

static char		**words_in(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	if ((words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1))))
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = word_in(s, c)))
				{
					words_del(words, i);
					return (NULL);
				}
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	if (!s || !(line = ft_strdup((char *)s)))
		return (NULL);
	words = words_in(line, c, counter(line, c));
	free(line);
	return (words);
}
