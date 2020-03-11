/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_basicft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:51:37 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 16:06:18 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		ft_pf_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int		ft_pf_hexnbrlen(unsigned long nbr)
{
	int i;

	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 15)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int		ft_pf_unbrlen(unsigned long nbr)
{
	int i;

	i = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int		ft_pf_nbrlen(long nbr)
{
	int i;

	i = 1;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int		ft_pf_atoi(char **str)
{
	int	result;

	result = 0;
	while (**str >= '0' && **str <= '9')
	{
		result = (result * 10) + (**str - '0');
		(*str)++;
	}
	(*str)--;
	return (result);
}
