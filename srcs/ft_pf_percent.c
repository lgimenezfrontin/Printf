/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:02:08 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:07:36 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	ft_pf_percent3(t_flags *flags, int *ret)
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
	ft_pf_putchar('%', ret);
}

static void	ft_pf_percent2(t_flags *flags, int *ret)
{
	ft_pf_putchar('%', ret);
	while (flags->widthdiff > 0)
	{
		ft_pf_putstr(" ");
		flags->widthdiff--;
		(*ret)++;
	}
}

int			ft_pf_percent(t_flags *flags)
{
	int		ret;

	flags->arglen = 1;
	flags->widthdiff = flags->width - flags->arglen;
	ret = 0;
	if (flags->minus)
		ft_pf_percent2(flags, &ret);
	else
		ft_pf_percent3(flags, &ret);
	return (ret);
}
