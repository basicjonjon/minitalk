/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:50:45 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:53 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const	void *mem1, const void *mem2, size_t n)
{
	size_t				i;
	unsigned const char	*t1;
	unsigned const char	*t2;

	i = 0;
	t1 = mem1;
	t2 = mem2;
	if (n == 0)
		return (0);
	while (i < n - 1 && t1[i] == t2[i])
		i++;
	return (t1[i] - t2[i]);
}
