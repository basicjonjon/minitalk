/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:18:42 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:28:41 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int static	ft_isset(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
		if (c == set[i++])
			return (1);
	return (0);
}

static int	ft_strrlenset(const char *s, const char *set)
{
	int	i;

	i = (int)ft_strlen(s) - 1;
	while (ft_isset(s[i], set) && i > 0)
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		y;
	int		end;
	char	*res;

	i = 0;
	y = 0;
	end = ft_strrlenset(s1, set);
	while (i < end && ft_isset(s1[i], set))
		i++;
	res = malloc(sizeof(char) * ((end - i) + 1));
	if (!res)
	{
		return (0);
	}
	while (i < end)
	{
		res[y] = s1[i];
		i++;
		y++;
	}
	res[y] = '\0';
	return (res);
}
