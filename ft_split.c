/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beergin <beergin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 23:49:34 by beergin           #+#    #+#             */
/*   Updated: 2024/10/19 13:14:54 by beergin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_word_counter(const char *s, char control)
{
	unsigned int	word;

	word = 0;
	while (*s)
	{
		if (*s == control)
			s++;
		else
		{
			while (*s != control && *s)
				s++;
			word++;
		}
	}
	return (word);
}

static unsigned int	ft_charlen(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	arr = (char **)malloc((ft_word_counter(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	a = -1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			arr[++a] = (char *)malloc((ft_charlen(s, c) + 1) * sizeof(char));
			if (!arr[a])
				return (free_all(arr));
			j = 0;
			while (*s && *s != c)
				arr[a][j++] = *s++;
			arr[a][j] = '\0';
		}
	}
	arr[++a] = NULL;
	return (arr);
}
