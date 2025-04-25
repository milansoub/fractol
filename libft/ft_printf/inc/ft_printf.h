/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoubrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:37:48 by msoubrou          #+#    #+#             */
/*   Updated: 2023/11/15 17:01:20 by msoubrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../libft.h"
# include <stdarg.h>
# include <unistd.h>
# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

int		ft_printf(const char *s, ...);
int		process_param(const char *s, va_list *list);
int		process_char(va_list *list);
int		process_string(va_list *list);
int		process_pointer(va_list *list);
int		process_decimal(va_list *list);
int		process_int(va_list *list);
int		process_uint(va_list *list);
int		process_hex(va_list *list, char upper);
int		process_percent(void);
int		ft_print_hex(unsigned int n, char upper);
int		ft_print_pointer(void *p);
int		ft_print_uint(unsigned int n);

#endif
