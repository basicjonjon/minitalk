/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:32:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/07/29 22:26:55 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;
	void	*element;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		element = f(lst->content);
		new_element = ft_lstnew(element);
		if (!new_element)
		{
			del(element);
			ft_lstclear(&new_lst, (*del));
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, new_element);
		lst = lst->next;
	}
	return (new_lst);
}
