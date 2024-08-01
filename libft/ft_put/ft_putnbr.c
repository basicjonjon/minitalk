/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:40:42 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:28:49 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_nbsize(long long n)
{
	int			i;
	long long	cpy_n;

	i = 0;
	cpy_n = n;
	if (n < 0)
	{
		cpy_n *= -1;
		i = 1;
	}
	while (cpy_n > 0)
	{
		i++;
		cpy_n /= 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	cpy_n;

	cpy_n = n;
	if (cpy_n == 0)
	{
		return (ft_putchar('0'));
	}
	if (n < 0)
	{
		cpy_n *= -1;
		ft_putchar('-');
	}
	if (cpy_n >= 10)
	{
		ft_putnbr(cpy_n / 10);
	}
	ft_putchar((cpy_n % 10) + 48);
	return (ft_nbsize(n));
}
