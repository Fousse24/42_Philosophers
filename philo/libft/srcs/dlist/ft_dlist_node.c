/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:24:54 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/24 16:24:56 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"dlist.h"

// Return a malloced node with $content as its content.
t_dlst	*ft_dlst_new_node(void *content)
{
	t_dlst	*node;

	node = (t_dlst *)malloc(sizeof(t_dlst));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*
*	Unlink and free $node from a double list.
*	It will link the previous and next nodes if needed.
*
*	if $node is the head of $dlst, the head of $dlst
*	will become the next node in that list.
*/
void	*ft_dlst_clear_node(t_dlst **dlst, t_dlst *node, void *(del)(void *))
{
	if (dlst != NULL && *dlst == node)
		*dlst = (*dlst)->next;
	if (node == NULL)
		return (node);
	if (del && node->content)
		del(node->content);
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	return (ft_free(node));
}

/*
*	Unlink $node from a double list, and return it.
*	It will link the previous and next nodes if needed.
*
*	if $node is the head of $dlst, the head of $dlst
*	will become the next node in that list.
*/
t_dlst	*ft_dlst_unlink_node(t_dlst **dlst, t_dlst *node)
{
	if (dlst != NULL && *dlst == node)
		*dlst = (*dlst)->next;
	if (node == NULL)
		return (node);
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
