/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/14 00:42:07 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	give_forks(t_philo *philo)
{
	philo->left_fork->owner = philo;
	philo->right_fork->owner = philo;
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
		philos++;
	}
	if (philo->state == SLEEPING || philo->state == DEAD)
			return (0);
	if (philo->left_fork->owner || philo->right_fork->owner)
		return (0);
	return (1);
}

int	get_meal(t_diner *diner, t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(get_mutex(M_MEAL));
	pthread_mutex_lock(get_mutex(M_FORK));
	if (is_allowed_to_eat(diner, philo))
	{
		give_forks(philo);
		ret = 1;
	}
	pthread_mutex_unlock(get_mutex(M_FORK));
	pthread_mutex_unlock(get_mutex(M_MEAL));
	return (ret);
}
