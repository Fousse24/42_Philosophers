/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/09 19:56:18 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

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
