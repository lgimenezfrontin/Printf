/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_uphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:48:11 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:07:54 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	ft_pf_uphex3(t_flags *flags, int *ret, unsigned int output)
{
	while (flags->widthdiff > 0)
	{
		if (flags->zero == 1 && flags->precision == -1)
			ft_pf_putstr("0");
		else
			ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
	while (flags->precidiff > 0)
	{
		ft_pf_putstr("0");
		flags->precidiff--;
		(*ret)++;
	}
	if (!(output == 0 && flags->precision == 0))
		*ret = *ret + ft_pf_putuphex(output);
}

static void	ft_pf_uphex2(t_flags *flags, int *ret, unsigned int output)
{
	while (flags->precidiff > 0)
	{
		ft_pf_putstr("0");
		flags->precidiff--;
		(*ret)++;
	}
	if (!(output == 0 && flags->precision == 0))
		*ret = *ret + ft_pf_putuphex(output);
	while (flags->widthdiff > 0)
	{
		ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
}

int			ft_pf_uphex(va_list args, t_flags *flags)
{
	unsigned int	output;
	int				ret;

	output = va_arg(args, unsigned int);
	flags->arglen = ft_pf_hexnbrlen((unsigned long)output);
	flags->precidiff = flags->precision - flags->arglen;
	if (flags->precidiff > 0)
		flags->widthdiff = flags->width - flags->precision;
	else
		flags->widthdiff = flags->width - flags->arglen;
	if (output == 0 && flags->precision == 0)
		flags->widthdiff++;
	ret = 0;
	if (flags->minus)
		ft_pf_uphex2(flags, &ret, output);
	else
		ft_pf_uphex3(flags, &ret, output);
	return (ret);
}
