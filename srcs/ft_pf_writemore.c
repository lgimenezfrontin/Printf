/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_writemore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:45:46 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:08:07 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_pf_putadr(unsigned long adr)
{
	int	ret;

	ret = 0;
	if (adr > 15)
	{
		ret = ret + ft_pf_putadr(adr / 16);
		ret = ret + ft_pf_putadr(adr % 16);
	}
	else if (adr < 10)
		ft_pf_putchar((adr + '0'), &ret);
	else
	{
		adr == 10 ? ft_pf_putchar('a', &ret) : 0;
		adr == 11 ? ft_pf_putchar('b', &ret) : 0;
		adr == 12 ? ft_pf_putchar('c', &ret) : 0;
		adr == 13 ? ft_pf_putchar('d', &ret) : 0;
		adr == 14 ? ft_pf_putchar('e', &ret) : 0;
		adr == 15 ? ft_pf_putchar('f', &ret) : 0;
	}
	return (ret);
}

int	ft_pf_putuphex(unsigned int u)
{
	int	ret;

	ret = 0;
	if (u > 15)
	{
		ret = ret + ft_pf_putuphex(u / 16);
		ret = ret + ft_pf_putuphex(u % 16);
	}
	else if (u < 10)
		ft_pf_putchar((u + '0'), &ret);
	else
	{
		u == 10 ? ft_pf_putchar('A', &ret) : 0;
		u == 11 ? ft_pf_putchar('B', &ret) : 0;
		u == 12 ? ft_pf_putchar('C', &ret) : 0;
		u == 13 ? ft_pf_putchar('D', &ret) : 0;
		u == 14 ? ft_pf_putchar('E', &ret) : 0;
		u == 15 ? ft_pf_putchar('F', &ret) : 0;
	}
	return (ret);
}

int	ft_pf_puthex(unsigned int u)
{
	int	ret;

	ret = 0;
	if (u > 15)
	{
		ret = ret + ft_pf_puthex(u / 16);
		ret = ret + ft_pf_puthex(u % 16);
	}
	else if (u < 10)
		ft_pf_putchar((u + '0'), &ret);
	else
	{
		u == 10 ? ft_pf_putchar('a', &ret) : 0;
		u == 11 ? ft_pf_putchar('b', &ret) : 0;
		u == 12 ? ft_pf_putchar('c', &ret) : 0;
		u == 13 ? ft_pf_putchar('d', &ret) : 0;
		u == 14 ? ft_pf_putchar('e', &ret) : 0;
		u == 15 ? ft_pf_putchar('f', &ret) : 0;
	}
	return (ret);
}
