/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:22:56 by lgimenez          #+#    #+#             */
/*   Updated: 2019/11/29 20:45:28 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>

# include <unistd.h>

typedef	struct	s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			precision;
	int			arglen;
	int			widthdiff;
	int			precidiff;
}				t_flags;

int				ft_printf(const char *str, ...);
void			ft_pf_flagsinit(t_flags *flags);
int				ft_pf_parsing(char **str, va_list args, t_flags *flags);
int				ft_pf_parseflags(char **str, va_list args, t_flags *flags);
int				ft_pf_parsetype(char **str, va_list args, t_flags *flags);
int				ft_pf_char(va_list args, t_flags *flags);
int				ft_pf_str(va_list args, t_flags *flags);
int				ft_pf_int(va_list args, t_flags *flags);
int				ft_pf_uint(va_list args, t_flags *flags);
int				ft_pf_hex(va_list args, t_flags *flags);
int				ft_pf_uphex(va_list args, t_flags *flags);
int				ft_pf_adr(va_list args, t_flags *flags);
int				ft_pf_percent(t_flags *flags);
int				ft_pf_strlen(char *s1);
int				ft_pf_nbrlen(long nbr);
int				ft_pf_unbrlen(unsigned long nbr);
int				ft_pf_hexnbrlen(unsigned long nbr);
int				ft_pf_atoi(char **str);
void			ft_pf_putchar(char c, int *ret);
int				ft_pf_putstr(char *str);
int				ft_pf_putnbr(int nbr);
int				ft_pf_putunbr(unsigned int nbr);
int				ft_pf_puthex(unsigned int u);
int				ft_pf_putuphex(unsigned int u);
int				ft_pf_putadr(unsigned long adr);

#endif
