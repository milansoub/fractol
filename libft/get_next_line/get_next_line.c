/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:22:59 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 17:44:09 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*process_remaining_data(t_reader *reader)
{
	char	*line;

	line = NULL;
	if (!reader->save_buffer)
	{
		reader->save_size = 0;
		return (NULL);
	}
	reader->index = get_newline_index(reader->save_buffer, reader->save_size);
	if (reader->index == -1)
		return (NULL);
	// If \n in remaining data
	line = ft_ndup(reader->save_buffer, reader->index + 1, 1);
	trim_save(reader, reader->index);
	return (line);
}

char	*process_eof(t_reader *reader)
{
	if (reader->save_buffer)
	{
		free(reader->save_buffer);
		reader->save_buffer = NULL;
	}
	reader->save_size = 0;
	reader->index = -1;
	return (NULL);
}

char	*process_line(t_reader *reader, size_t size)
{
	char	*line;
	size_t	temp_size;
	if (reader->index == -1)
	{
		save_data(reader, size);
		line = ft_ndup(reader->save_buffer, reader->save_size, 1);
		if (reader->save_buffer)
		{
			free(reader->save_buffer);
			reader->save_buffer = NULL;
		}
		reader->save_size = 0;
		return (line);
	}
	line = ft_ncat(reader->save_buffer, reader->save_size, reader->buffer, reader->index + 1);
	temp_size = reader->save_size;
	save_data(reader, size);
	trim_save(reader, temp_size + reader->index);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_reader	reader;
	char			*line;
	size_t			size;

	if (fd < 0)
		return (NULL);
	line = process_remaining_data(&reader);
	if (line)
		return (line);
	// IF NO /n IN REMAINING DATA CONTINUE READING
	size = read(fd, reader.buffer, BUFFER_SIZE);
	reader.index = get_newline_index(reader.buffer, size);
	while (reader.index == -1 && size == BUFFER_SIZE)
	{
		save_data(&reader, size);
		size = read(fd, reader.buffer, BUFFER_SIZE);
		reader.index = get_newline_index(reader.buffer, size);
	}
	// EOF
	if (size == 0)
		return (process_eof(&reader));
	return (process_line(&reader, size));
}


/*
int main()
{
#include <fcntl.h>
#include <stdio.h>
	int fd = open("test.file", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		//getchar();
		free(line);
	}
	close(fd);
	return 0;
}*/
