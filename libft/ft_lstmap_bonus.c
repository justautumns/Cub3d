/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmeyil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:51:45 by mehmeyil          #+#    #+#             */
/*   Updated: 2023/09/15 18:32:08 by mehmeyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*yeni;
	t_list	*sec;

	if (!lst || !f)
		return (NULL);
	yeni = NULL;
	while (lst)
	{
		sec = ft_lstnew(f(lst->content));
		if (!sec)
		{
			ft_lstclear(&yeni, del);
			return (NULL);
		}
		ft_lstadd_back(&yeni, sec);
		lst = lst->next;
	}
	return (yeni);
}
