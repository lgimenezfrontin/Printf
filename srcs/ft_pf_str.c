/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:51:03 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:07:42 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	ft_pf_str3(t_flags *flags, int *ret, char *output)
{
	while (flags->widthdiff > 0)
	{
		if (flags->zero == 1)
			ft_pf_putstr("0");
		else
			ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
	if (flags->precision == -1 || flags->precision >= ft_pf_strlen(output))
		*ret = *ret + ft_pf_putstr(output);
	else
	{
		while (flags->arglen)
		{
			ft_pf_putchar(*output, ret);
			output++;
			flags->arglen--;
		}
	}
}

static void	ft_pf_str2(t_flags *flags, int *ret, char *output)
{
	if (flags->precision == -1 || flags->precision >= ft_pf_strlen(output))
		*ret = *ret + ft_pf_putstr(output);
	else
	{
		while (flags->arglen)
		{
			ft_pf_putchar(*output, ret);
			output++;
			flags->arglen--;
		}
	}
	while (flags->widthdiff > 0)
	{
		ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
}

int			ft_pf_str(va_list args, t_flags *flags)
{
	char	*output;
	int		ret;

	output = va_arg(args, char*);
	if (output == NULL)
		output = "(null)";
	if (flags->precision == -1 || flags->precision >= ft_pf_strlen(output))
		flags->arglen = ft_pf_strlen(output);
	else
		flags->arglen = flags->precision;
	flags->widthdiff = flags->width - flags->arglen;
	ret = 0;
	if (flags->minus)
		ft_pf_str2(flags, &ret, output);
	else
		ft_pf_str3(flags, &ret, output);
	return (ret);
}
