/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:08:10 by ean               #+#    #+#             */
/*   Updated: 2021/11/17 17:15:06 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*temp;

	if (!lst || !(*lst) || !del)
		return ;
	p = *lst;
	while (p)
	{
		temp = p;
		p = p->next;
		(*del)(temp->content);
		free(temp);
	}
	*lst = NULL;
}
