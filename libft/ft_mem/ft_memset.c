/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:08:31 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:51 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *mem, int value, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = mem;
	while (i < n)
		p[i++] = value;
	return (mem);
}
