/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:40:34 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:08:22 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_pf_flagsinit(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->arglen = 0;
	flags->widthdiff = 0;
	flags->precidiff = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		ret;
	int		tmp;

	if (!str)
		return (-1);
	va_start(args, str);
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_pf_flagsinit(&flags);
			if ((tmp = ft_pf_parsing((char**)&str, args, &flags)) == -1)
				return (-1);
			else
				ret = ret + tmp;
		}
		else
			ft_pf_putchar(*str, &ret);
		str++;
	}
	va_end(args);
	return (ret);
}
