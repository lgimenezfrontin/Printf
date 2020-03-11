/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_adr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:51:43 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:05:50 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	ft_pf_adr3(t_flags *flags, int *ret, unsigned long output)
{
	if (flags->zero == 1 && flags->precision == -1)
		*ret = *ret + ft_pf_putstr("0x");
	while (flags->widthdiff > 2)
	{
		if (flags->zero == 1 && flags->precision == -1)
			ft_pf_putstr("0");
		else
			ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
	if (flags->zero == 0 || (flags->zero == 1 && flags->precision != -1))
		*ret = *ret + ft_pf_putstr("0x");
	while (flags->precidiff > 0)
	{
		ft_pf_putstr("0");
		flags->precidiff--;
		(*ret)++;
	}
	if (!(output == 0 && flags->precision == 0))
		*ret = *ret + ft_pf_putadr(output);
}

static void	ft_pf_adr2(t_flags *flags, int *ret, unsigned long output)
{
	*ret = *ret + ft_pf_putstr("0x");
	while (flags->precidiff > 0)
	{
		ft_pf_putstr("0");
		flags->precidiff--;
		(*ret)++;
	}
	if (!(output == 0 && flags->precision == 0))
		*ret = *ret + ft_pf_putadr(output);
	while (flags->widthdiff > 2)
	{
		ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
}

int			ft_pf_adr(va_list args, t_flags *flags)
{
	void	*output;
	int		ret;

	output = va_arg(args, void*);
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
		ft_pf_adr2(flags, &ret, (unsigned long)output);
	else
		ft_pf_adr3(flags, &ret, (unsigned long)output);
	return (ret);
}
