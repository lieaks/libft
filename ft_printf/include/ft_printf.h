/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:21:57 by dly               #+#    #+#             */
/*   Updated: 2022/12/20 15:20:42 by dly              ###   ########.fr       */
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
	int	error;
}		t_sc;

void		ft_print_char(int c, t_sc *sc);
void		ft_print_hex(unsigned int n, char c, t_sc *sc);
void		ft_print_nbr(int n, t_sc *sc);
void		ft_print_ptr(unsigned long long ptr, t_sc *sc);
void		ft_print_str(char *str, t_sc *sc);
void		ft_print_unsigned(unsigned int n, t_sc *sc);
int			ft_len_nb(unsigned long long ptr, char *base);
int			ft_itoa_base(unsigned long long ptr, char *base);
int			is_in_charset(char format, char *charset);
const char	*is_format(const char *format, t_sc *sc);
const char	*ft_search_arg(va_list arg, const char *format, t_sc *sc);
const char	*ft_read_txt(const char *format, t_sc *sc);
int			ft_printf(const char *format, ...);

#endif
