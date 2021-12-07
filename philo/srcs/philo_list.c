/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:17:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/06 14:13:53 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// initialize the values of a philosopher object
void	init_philo(t_philo *philo, int id)
{
	if (!philo)
		return ;
	philo->id = id;
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->times_eaten = 0;
	philo->time_left = PHILO_T_DIE;
	philo->state = THINKING;
}

// create and initialize a philosopher object
t_philo	*create_philo(int id)
{
	t_philo	*philo;

	philo = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	init_philo(philo, id);
	return (philo);
}

void	init_philo_list(t_dlst **list, int philo_n)
{
	int	i;

	if (!list || philo_n < 1)
		return ;
	*list = NULL;
	i = 1;
	while (i <= philo_n)
		ft_dlst_add_back(list, ft_dlst_new_node(create_philo(i++)));
	link_head_tail(list);
}
