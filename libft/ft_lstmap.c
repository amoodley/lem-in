/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:46:56 by amoodley          #+#    #+#             */
/*   Updated: 2017/11/14 09:52:17 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*res_start;

	if (lst == NULL)
		return (NULL);
	res_start = f(lst);
	lst = lst->next;
	res = res_start;
	while (lst)
	{
		res->next = f(lst);
		res = res->next;
		lst = lst->next;
	}
	res = NULL;
	return (res_start);
}
