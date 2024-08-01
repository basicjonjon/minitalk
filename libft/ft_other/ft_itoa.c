/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:43:47 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:50 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_countnbsize(int n)
{
	int		i;
	long	num;

	i = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		i = 1;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	int		i;
	char	*res;

	num = n;
	i = ft_countnbsize(n);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	if (n < 0)
		num *= -1;
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i--] = (num % 10) + 48;
		num /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

// int main(void)
// {
// 	printf("%s", ft_itoa(42));
// }