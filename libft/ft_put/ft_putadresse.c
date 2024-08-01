/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadresse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:25:59 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:28:54 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putadresse(void *a, char *base)
{
	unsigned long long	cpy_n;
	int					baselen;
	int					i;

	baselen = ft_strlen(base);
	i = 0;
	cpy_n = (unsigned long long)a;
	if (!a)
		return (ft_putstr("(nil)"));
	if (cpy_n >= (unsigned long long)baselen)
		i = ft_putadresse((void *)(cpy_n / baselen), base);
	else
	{
		ft_putstr("0x");
		i += 2;
	}
	ft_putchar(base[cpy_n % baselen]);
	return (++i);
}
