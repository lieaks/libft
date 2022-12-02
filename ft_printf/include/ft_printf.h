/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:21:57 by dly               #+#    #+#             */
/*   Updated: 2022/12/02 12:47:17 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_sc
{
	int	count;
	int	len;
}		t_sc;

void		ft_print_char(int c, int *arg_count);
void		ft_print_hex(unsigned int n, char c, int *arg_count);
void		ft_print_nbr(int n, int *arg_count);
void		ft_print_percent(int *arg_count);
void		ft_print_ptr(unsigned long long ptr, int *arg_count);
void		ft_print_str(char *str, int *arg_count);
void		ft_print_unsigned(unsigned int n, int *arg_count);
int			ft_len_nb(unsigned long long ptr, char *base);
int			ft_itoa_base(unsigned long long ptr, char *base);
const char	*ft_search_arg(va_list arg, const char *format, t_sc *sc);
const char	*ft_read_txt(const char *format, t_sc *sc);
int			ft_printf(const char *format, ...);

#endif
