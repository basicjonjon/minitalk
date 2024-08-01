/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:43:47 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/31 20:33:46 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_countnbsize_base(int n, char *base)
{
	int		i;
	long	num;
	int		base_len;

	i = 0;
	num = n;
	base_len = ft_strlen(base);
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int n, char *base)
{
	long	num;
	int		i;
	char	*res;
	int		base_len;

	num = n;
	base_len = ft_strlen(base);
	i = ft_countnbsize_base(n, base);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	if (n < 0)
		num *= -1;
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i--] = (num % base_len) + 48;
		num /= base_len;
	}
	return (res);
}
