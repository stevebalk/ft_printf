/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:02:44 by sbalk             #+#    #+#             */
/*   Updated: 2023/05/18 14:18:07 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It's nessecary to use del on the return value of (*f) 
// because it could return a malloced void pointer

static int	fill_list(t_list *lst, void *(*f)(void *),
						void (*del)(void *), t_list *new_lst, t_list *new_node)
{
	void	*new_content;

	while (lst)
	{
		new_content = f(lst->content);
		new_node->next = ft_lstnew(new_content);
		if (new_node->next == NULL)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_node = new_node->next;
		lst = lst->next;
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_content = f(lst->content);
	new_lst = ft_lstnew(new_content);
	if (new_lst == NULL)
	{
		del(new_content);
		return (NULL);
	}
	new_node = new_lst;
	lst = lst->next;
	if (fill_list(lst, f, del, new_lst, new_node) == 0)
		return (NULL);
	return (new_lst);
}
