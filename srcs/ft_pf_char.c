/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_adrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:32:23 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:06:28 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	ft_pf_char3(t_flags *flags, int *ret, int output)
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
	ft_pf_putchar(output, ret);
}

static void	ft_pf_char2(t_flags *flags, int *ret, int output)
{
	ft_pf_putchar(output, ret);
	while (flags->widthdiff > 0)
	{
		ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
}

int			ft_pf_char(va_list args, t_flags *flags)
{
	char	output;
	int		ret;

	output = va_arg(args, int);
	flags->arglen = 1;
	flags->widthdiff = flags->width - flags->arglen;
	ret = 0;
	if (flags->minus)
		ft_pf_char2(flags, &ret, output);
	else
		ft_pf_char3(flags, &ret, output);
	return (ret);
}
