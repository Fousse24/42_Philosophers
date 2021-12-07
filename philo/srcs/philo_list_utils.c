/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:17:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:17 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// link the first and last
void	link_head_tail(t_dlst **list)
{
	t_dlst	*tail;

	if (!list || !*list)
		return ;
	tail = ft_dlst_get_tail(*list);
	if (tail)
	{
		tail->next = *list;
		(*list)->prev = tail;
	}
}

t_dlst	*get_philo_node(t_dlst *lst, int id)
{
	t_philo	*philo;
	int		last_id;

	if (!lst)
		return (NULL);
	while (lst)
	{
		philo = (t_philo *)lst->content;

		if (philo && philo->id == id)
			return (lst);
		else if (philo->id < last_id)
			break;
		lst = lst->next;
	}
	return (NULL);
}

t_philo	*get_philo(t_dlst *lst, int id)
{
	t_philo	*philo;
	
	lst = get_philo_node(lst, id);
	if (lst && lst->content)
		return ((t_philo *)lst->content);
	return (NULL);
}
