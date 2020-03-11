/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:31:31 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:07:28 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	ft_pf_precisionwildcard(va_list args, t_flags *flags)
{
	int	output;

	output = va_arg(args, int);
	if (output >= 0)
		flags->precision = output;
}

static void	ft_pf_widthwildcard(va_list args, t_flags *flags)
{
	int	output;

	output = va_arg(args, int);
	if (output < 0)
	{
		flags->minus = 1;
		flags->width = -output;
	}
	else
		flags->width = output;
}

int			ft_pf_parseflags(char **str, va_list args, t_flags *flags)
{
	if (**str == '-')
		flags->minus = 1;
	else if (**str == '0')
		flags->zero = 1;
	else if (**str >= '1' && **str <= '9')
		flags->width = ft_pf_atoi(str);
	else if (**str == '*')
		ft_pf_widthwildcard(args, flags);
	else if (**str == '.')
	{
		(*str)++;
		if (**str >= '0' && **str <= '9')
			flags->precision = ft_pf_atoi(str);
		else if (**str == '*')
			ft_pf_precisionwildcard(args, flags);
		else
		{
			flags->precision = 0;
			(*str)--;
		}
	}
	else
		return (-1);
	return (0);
}

int			ft_pf_parsetype(char **str, va_list args, t_flags *flags)
{
	if (**str == 'c')
		return (ft_pf_char(args, flags));
	else if (**str == 's')
		return (ft_pf_str(args, flags));
	else if (**str == 'p')
		return (ft_pf_adr(args, flags));
	else if (**str == 'd')
		return (ft_pf_int(args, flags));
	else if (**str == 'i')
		return (ft_pf_int(args, flags));
	else if (**str == 'u')
		return (ft_pf_uint(args, flags));
	else if (**str == 'x')
		return (ft_pf_hex(args, flags));
	else if (**str == 'X')
		return (ft_pf_uphex(args, flags));
	else if (**str == '%')
		return (ft_pf_percent(flags));
	return (0);
}

int			ft_pf_parsing(char **str, va_list args, t_flags *flags)
{
	int	ret;
	int	tmp;

	ret = 0;
	(*str)++;
	while (!(**str == 'c' || **str == 's' || **str == 'p'
			|| **str == 'd' || **str == 'i' || **str == 'u'
			|| **str == 'x' || **str == 'X' || **str == '%'))
	{
		if ((tmp = ft_pf_parseflags(str, args, flags)) == -1)
			return (-1);
		else
			ret = ret + tmp;
		(*str)++;
	}
	if ((tmp = ft_pf_parsetype(str, args, flags)) == -1)
		return (-1);
	else
		ret = ret + tmp;
	return (ret);
}
