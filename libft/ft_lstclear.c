/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:33:47 by mrios-he          #+#    #+#             */
/*   Updated: 2024/07/16 09:33:55 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	while (list)
	{
		temp = list->next;
		ft_lstdelone(list, del);
		list = temp;
	}
	*lst = NULL;
}
