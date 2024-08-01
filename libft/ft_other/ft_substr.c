/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:14:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:30:57 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	y;
	char	*nstr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	nstr = malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	i = start;
	y = 0;
	while (y < len)
		nstr[y++] = s[i++];
	nstr[y] = '\0';
	return (nstr);
}
