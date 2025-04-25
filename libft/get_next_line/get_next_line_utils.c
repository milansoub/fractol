/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:32:24 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 14:33:20 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long long int	get_newline_index(char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			return ((long long int)i);
		++i;
	}
	return (-1);
}

char			*ft_ndup(char *buffer, size_t n, char is_str)
{
	size_t	i;
	char	*dup;

	i = 0;
	if (is_str)
		dup = malloc(n + 1);
	else
		dup = malloc(n);
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = buffer[i];
		++i;
	}
	if (is_str)
		dup[i] = 0;
	return (dup);
}

void			trim_save(t_reader *reader, size_t index)
{
	char	*new_data;
	size_t	new_size;

	if (index + 1 == reader->save_size)
	{
		reader->save_size = 0;
		free(reader->save_buffer);
		reader->save_buffer = NULL;
		return ;
	}
	new_size = reader->save_size - index - 1;
	new_data = ft_ndup(reader->save_buffer + index + 1, new_size, 0);
	if (reader->save_buffer)
	{
		free(reader->save_buffer);
		reader->save_buffer = NULL;
	}
	reader->save_buffer = new_data;
	reader->save_size = new_size;
}

void			save_data(t_reader *reader, size_t n)
{
	char	*new_save;

	new_save = ft_ncat(reader->save_buffer, reader->save_size, reader->buffer, n);
	if (reader->save_size)
	{
		free(reader->save_buffer);
		reader->save_buffer = NULL;
	}
	reader->save_buffer = new_save;
	reader->save_size += n;
}

char	*ft_ncat(char *b1, size_t size, char *b2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	new_buffer = malloc(size + n + 1);
	if (!new_buffer)
		return (NULL);
	while (i < size)
	{
		new_buffer[i] = b1[i];
		++i;
	}
	while (j < n)
	{
		new_buffer[i + j] = b2[j];
		++j;
	}
	new_buffer[i + j] = 0;
	return (new_buffer);
}
