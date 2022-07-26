/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 05:22:48 by thzeribi          #+#    #+#             */
/*   Updated: 2021/01/01 13:07:23 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*begin;
	t_list			*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	begin = ft_lstnew(f((void *)tmp->content));
	if (!begin)
	{
		ft_lstclear(&begin, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f((void *)lst->content));
		if (!tmp)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, tmp);
		lst = lst->next;
	}
	return (begin);
}
