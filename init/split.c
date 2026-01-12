/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaroshu <myaroshu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:10:10 by myaroshu          #+#    #+#             */
/*   Updated: 2026/01/11 16:48:49 by myaroshu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wordcount(const char *s, char c)
{
	int	count_words;
	int	word;

	count_words = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			count_words++;
		}
		else if (*s == c)
		{
			word = 0;
		}
		s++;
	}
	return (count_words);
}

char	*get_next_word(char const *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[*cursor + len] != c && s[*cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (i < len)
	{
		next_word[i++] = s[(*cursor)++];
	}
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;
	int		cursor;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	cursor = 0;
	while (i < words)
	{
		res[i] = get_next_word(s, c, &cursor);
		if (!res[i])
		{
			free_matrix(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv)
		return ;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}
