/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:17:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/10 18:53:17 by sfournie         ###   ########.fr       */
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
	philo->timestamp = 0;
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->times_eaten = 0;
	philo->time_sleep = get_start_time();
	philo->time_eat = get_start_time();
	philo->time_death = get_start_time();
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
}
