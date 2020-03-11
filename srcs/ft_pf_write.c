/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:47:29 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:08:00 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_pf_putchar(char c, int *ret)
{
	write(1, &c, 1);
	(*ret)++;
}

int		ft_pf_putstr(char *str)
{
	int	ret;

	ret = 0;
	if (str)
	{
		while (*str)
		{
			ft_pf_putchar(*str, &ret);
			str++;
		}
	}
	return (ret);
}

int		ft_pf_putunbr(unsigned int nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 9)
	{
		ret = ret + ft_pf_putnbr(nbr / 10);
		ret = ret + ft_pf_putnbr(nbr % 10);
	}
	else
		ft_pf_putchar((nbr + '0'), &ret);
	return (ret);
}

int		ft_pf_putnbr(int nbr)
{
	unsigned int	u;
	int				ret;

	ret = 0;
	u = nbr;
	if (nbr < 0)
		u = -nbr;
	if (u > 9)
	{
		ret = ret + ft_pf_putnbr(u / 10);
		ret = ret + ft_pf_putnbr(u % 10);
	}
	else
		ft_pf_putchar((u + '0'), &ret);
	return (ret);
}
