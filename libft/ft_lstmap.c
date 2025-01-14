/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:34:51 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/16 09:34:55 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	list = ft_lstnew(f(lst->content));
	if (!list)
		return (0);
	temp = list;
	lst = lst->next;
	while (lst)
	{
		list->next = ft_lstnew(f(lst->content));
		if (!list->next)
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		list = list->next;
		lst = lst->next;
	}
	list->next = NULL;
	return (temp);
}
