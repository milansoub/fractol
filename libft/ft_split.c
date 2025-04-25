/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:54:02 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 12:54:03 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>

static size_t	ft_count_split(const char *s, char c)
{
	size_t	i;
	size_t	count;
	char	new_str;

	i = 0;
	count = 0;
	new_str = 1;
	while (s[i] != 0)
	{
		if (s[i] != c && new_str)
		{
			new_str = 0;
			++count;
		}
		else if (s[i] == c)
			new_str = 1;
		++i;
	}
	return (count);
}

static void	free_split(char	**split, size_t	n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		++i;
	}
	free(split);
}

static char	add_split(char **split, size_t *index, const char *st, size_t *s)
{
	split[*index] = malloc(*s + 1);
	if (split[*index] == NULL)
	{
		free_split(split, *index);
		return (0);
	}
	ft_strlcpy(split[*index], st, *s + 1);
	*s = 0;
	*index += 1;
	return (1);
}

static void	init(size_t ijcb[4], const char *s, char c)
{
	ijcb[0] = 0;
	ijcb[1] = 0;
	ijcb[2] = ft_count_split(s, c);
	ijcb[3] = 0;
}

char	**ft_split(const char *s, char c)
{
	size_t	ijcb[4];
	char	**split;

	init(ijcb, s, c);
	split = malloc((ijcb[2] + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (s[ijcb[0]] != 0)
	{
		if (s[ijcb[0]] == c && ijcb[3] != 0)
		{
			if (!add_split(split, &ijcb[1], s + ijcb[0] - ijcb[3], &ijcb[3]))
				return (NULL);
		}
		else if (s[ijcb[0]] != c)
			++ijcb[3];
		++ijcb[0];
	}
	if (ijcb[3] != 0)
	{
		if (!add_split(split, &ijcb[1], s + ijcb[0] - ijcb[3], &ijcb[3]))
			return (NULL);
	}
	split[ijcb[1]] = NULL;
	return (split);
}
