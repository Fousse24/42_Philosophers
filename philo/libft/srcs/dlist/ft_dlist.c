/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:23:14 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/24 16:24:43 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"dlist.h"

// $node becomes the head of $dlst
void	ft_dlst_add_front(t_dlst **dlst, t_dlst *node)
{
	if (*dlst == NULL)
		*dlst = node;
	else
	{
		(*dlst)->prev = node;
		*dlst = node;
	}
}

// $node becomes the tail of $dlst
void	ft_dlst_add_back(t_dlst **dlst, t_dlst *node)
{
	t_dlst	*temp;

	if (*dlst == NULL)
		*dlst = node;
	else
	{
		temp = *dlst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
	}
}

/* 
*	Free all the nodes and their content in $dlst.
*	$del is the function used to delete/free the content.
*	
*	If $del is NULL, it will not free any of the contents,
*	but will still free all node pointers.
*/
void	*ft_dlst_clear(t_dlst *dlst, void *(del)(void *))
{
	if (dlst == NULL)
		return (NULL);
	if (dlst->next)
		ft_dlst_clear(dlst->next, del);
	if (del)
		del(dlst->content);
	ft_free(dlst);
	return (NULL);
}

/*
*	Malloc and return a new dlst with the same structure as $dlst.
*	$iter is used to change/copy the content of the each original nodes.
*	
*	If something goes wrong, the new dlst is cleared and NULL is returned.
*/
t_dlst	*ft_dlst_iter(t_dlst *dlst, void *(iter)(void *), void *(del)(void *))
{
	t_dlst	*new_lst;
	t_dlst	*new_node;
	void	*content;

	new_lst = NULL;
	if (dlst == NULL)
		return (NULL);
	while (dlst != NULL && dlst->content != NULL)
	{
		content = iter(dlst->content);
		if (content == NULL)
			return (ft_dlst_clear(new_lst, del));
		new_node = ft_dlst_new_node(content);
		ft_dlst_add_back(&new_lst, new_node);
		dlst = dlst->next;
	}
	return (new_lst);
}
