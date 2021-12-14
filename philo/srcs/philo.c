/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:17:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/14 00:47:56 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// initialize the values of a philosopher object
void	init_philo(t_philo *philo, int id)
{
	t_time	*start_time;

	if (!philo)
		return ;
	if (get_diner())
	philo->id = id;
	philo->is_odd = 1;
	philo->timestamp = 0;
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->times_eaten = 0;
	philo->next_death = 0;
	philo->next_think = 0;
	philo->next_meal = 0;
	philo->next_sleep = 0;
	philo->next_action = 0;
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

t_philo	*get_philo(t_philo **philos, int id)
{
	while (philos && *philos)
	{
		if ((*philos)->id == id)
			return (*philos);
		philos++;
	}
	return (NULL);
}

void	init_philo_array(t_philo **arr, int philo_n)
{
	int	i;

	if (!arr || philo_n <= 0)
		return ;
	*arr = NULL;
	i = 0;
	while (i < philo_n)
	{
		arr[i] = create_philo(i + 1);
		i++;
	}
	arr[i] = NULL;
}
