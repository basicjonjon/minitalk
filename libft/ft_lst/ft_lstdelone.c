/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:39:33 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:58 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*tempsnext;

	tempsnext = lst->next;
	del(lst->content);
	free(lst);
	lst = tempsnext;
}
