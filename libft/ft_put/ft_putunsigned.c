/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:38:28 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:28:46 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_nbsize(unsigned int n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
	return (ft_nbsize(n));
}
