/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:21:57 by dly               #+#    #+#             */
/*   Updated: 2022/11/30 16:48:49 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_print_char(int c, int *test);
int		ft_print_hex(unsigned int n, char input, int *test);
int		ft_print_nbr(int n, int *test);
int		ft_print_percent(void);
int		ft_print_ptr(unsigned long long ptr, int *test);
int		ft_print_str(char *str, int *test);
int		ft_print_unsigned(unsigned int n, int *test);
int		ft_len_hex_ullong(unsigned long long ptr);
void	ft_write_hex(unsigned long long ptr, char a_or_A);
int		ft_search_arg(va_list arg, char input, int *test);
int		ft_read_txt(const char *input, int *count, int *i);
int		ft_printf(const char *input, ...);

#endif
