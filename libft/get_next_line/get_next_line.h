/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:21:58 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/11 13:15:53 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 256
# endif
# include <malloc.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_reader
{
	long long int	index;
	size_t			save_size;
	char			*save_buffer;
	char			buffer[BUFFER_SIZE];
}				t_reader;

char			*get_next_line(int fd);
char			*process_remaining_data(t_reader *reader);
void			save_data(t_reader *reader, size_t n);

long long int	get_newline_index(char *buffer, size_t size);
char			*ft_ndup(char *buffer, size_t n, char is_str);
void			trim_save(t_reader *reader, size_t index);
char			*ft_ncat(char *b1, size_t size, char *b2, size_t n);

#endif
