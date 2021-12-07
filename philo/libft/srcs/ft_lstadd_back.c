/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:24:55 by sfournie          #+#    #+#             */
/*   Updated: 2021/11/24 11:44:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	if (new_lst != NULL)
	{
		if (*lst == NULL)
			*lst = new_lst;
		else
			ft_lstlast(*lst)->next = new_lst;
	}
}
