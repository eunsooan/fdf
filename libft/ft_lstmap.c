/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:25:25 by ean               #+#    #+#             */
/*   Updated: 2021/11/19 10:32:42 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#define SUCCESS 1
#define FAILURE 0

static int	make_lst(t_list **head, t_list *lst, void *(*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	int		state;

	if (!lst)
		return (NULL);
	ret = NULL;
	state = make_lst(&ret, lst, f);
	if (state == FAILURE)
		ft_lstclear(&ret, del);
	return (ret);
}

static int	make_lst(t_list **head, t_list *lst, void *(*f)(void *))
{
	t_list	*curr;
	t_list	*new;

	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
			return (FAILURE);
		if (*head == NULL)
		{
			*head = new;
			curr = *head;
		}
		else
		{
			curr->next = new;
			curr = curr->next;
		}
		if (!(curr->content))
			return (FAILURE);
		lst = lst->next;
	}
	return (SUCCESS);
}
