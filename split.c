/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaroshu <myaroshu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:10:10 by myaroshu          #+#    #+#             */
/*   Updated: 2025/12/21 14:30:23 by myaroshu         ###   ########.fr       */
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

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
	{
		++cursor;
	}
	while (s[cursor + len] != c && s[cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (s[cursor] != c && s[cursor])
	{
		next_word[i++] = s[cursor++];
	}
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *s, char c)
{
	int		count;
	char	**split;
	int		result;

	result = 0;
	count = ft_wordcount(s, c);
	if (!count)
		return (NULL);
	split = malloc(sizeof(char *) * (size_t)(count) + 2);
	if (!split)
		return (NULL);
	while (count-- >= 0)
	{
		if (result == 0)
		{
			split[result] = malloc(sizeof(char));
			if (!split[result])
				return (NULL);
			split[result++][0] = '\0';
			continue ;
		}
		split[result++] = get_next_word(s, c);
	}
	split[result] = NULL;
	return (split);
}
