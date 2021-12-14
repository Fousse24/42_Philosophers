/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/14 13:46:13 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int		philo_is_odd(t_philo *philo)
{
	t_diner *diner;
	t_philo	**philos;

	diner = get_diner();
	if (!diner | !philo | !diner->philos | diner->philo_n % 2 != 1)
		return (0);
	philos = diner->philos;
	while (*philos)
	{
		if ((*philos)->times_eaten > philo->times_eaten)
			return (0);
		philos++;
	}
	return (1);
}

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
