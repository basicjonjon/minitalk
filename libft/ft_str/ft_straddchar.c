/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:05:55 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/31 18:37:06 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*create_str_char(char c)
{
	char	*res;

	res = malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*ft_straddchar(char *s1, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!c)
	{
		if (!s1)
			return (NULL);
		return (ft_strdup(s1));
	}
	if (!s1)
		return (create_str_char(c));
	res = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (res == NULL)
		return (free(s1), NULL);
	while (s1[i++] != '\0')
		res[i] = s1[i];
	res[i++] = c;
	res[i] = '\0';
	return (free(s1), res);
}
