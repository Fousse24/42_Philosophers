/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/13 17:42:27 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

/* set the current time of every threads */
t_time	*get_diner_time()
{
	t_diner	*diner;

	diner = get_diner();
	if (diner)
		return (&diner->cur_time);
	return (NULL);
}

void	give_forks(t_philo *philo)
{
	philo->left_fork->owner = philo;
	philo->right_fork->owner = philo;
}

void	fork_check(t_diner *diner)
{
	t_philo **philos;

	if (!diner)
		return ;
	philos = diner->philos;
	while (philos && *philos)
	{
		if (!pthread_mutex_lock(get_mutex(M_FORK)))
		{
			if (diner_ask_for_forks(diner, *philos))
			{
				copy_time(&diner->cur_time, &(*philos)->time_eat);
				give_forks(*philos);	
			}
			pthread_mutex_unlock(get_mutex(M_FORK));
		}
		philos++;
	}
}

int	is_allowed_to_eat(t_diner *diner, t_philo *philo)
{
	t_philo	**philos;

	if (!diner || !philo || !diner->philos)
		return (0);
	philos = diner->philos;
	while (*philos)
	{
		if (philo->times_eaten > (*philos)->times_eaten)
			return (0);
		if (philo->state == SLEEPING || philo->state == DEAD)
			return (0);
		philos++;
	}
	return (1);
}

int	diner_ask_for_forks(t_diner *diner, t_philo *philo)
{
	if (is_allowed_to_eat(diner, philo))
	{
		if (!philo->left_fork->owner && !philo->right_fork->owner)
			return (1);
	}
	return (0);
}
