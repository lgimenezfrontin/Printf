/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:49:26 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:07:20 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	ft_pf_int3(t_flags *flags, int *ret, int output)
{
	if (flags->zero == 1 && flags->precision == -1)
	{
		output < 0 ? ft_pf_putchar('-', ret) : 0;
		while (flags->widthdiff > 0)
		{
			*ret = *ret + ft_pf_putstr("0");
			flags->widthdiff--;
		}
	}
	else
	{
		while (flags->widthdiff > 0)
		{
			*ret = *ret + ft_pf_putstr(" ");
			flags->widthdiff--;
		}
		output < 0 ? ft_pf_putchar('-', ret) : 0;
	}
	while (flags->precidiff > 0)
	{
		*ret = *ret + ft_pf_putstr("0");
		flags->precidiff--;
	}
	if (!(output == 0 && flags->precision == 0))
		*ret = *ret + ft_pf_putnbr(output);
}

static void	ft_pf_int2(t_flags *flags, int *ret, int output)
{
	output < 0 ? ft_pf_putchar('-', ret) : 0;
	while (flags->precidiff > 0)
	{
		*ret = *ret + ft_pf_putstr("0");
		flags->precidiff--;
	}
	if (!(output == 0 && flags->precision == 0))
		*ret = *ret + ft_pf_putnbr(output);
	while (flags->widthdiff > 0)
	{
		ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
}

int			ft_pf_int(va_list args, t_flags *flags)
{
	int		output;
	int		ret;

	output = va_arg(args, int);
	flags->arglen = ft_pf_nbrlen((long)output);
	flags->precidiff = flags->precision - flags->arglen;
	if (flags->precidiff > 0)
		flags->widthdiff = flags->width - flags->precision;
	else
		flags->widthdiff = flags->width - flags->arglen;
	if (output < 0)
		flags->widthdiff--;
	else if (output == 0 && flags->precision == 0)
		flags->widthdiff++;
	ret = 0;
	if (flags->minus)
		ft_pf_int2(flags, &ret, output);
	else
		ft_pf_int3(flags, &ret, output);
	return (ret);
}
