/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/19 17:25:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	give_forks(t_philo *philo)
{
	philo->timestamp = philo->next_meal - time_to_long(get_start_time());
	philo->left_fork->owner = philo;
	philo_print_state(philo, FORK);
	philo->right_fork->owner = philo;
	philo_print_state(philo, FORK);
}

int	is_allowed_to_eat(t_diner *diner, t_philo *philo)
{
	t_philo	**philos;

	if (!diner || !philo || !diner->philos)
		return (0);
	philos = diner->philos;
	if (philo->times_eaten > diner->time_eaten)
		return (0);
	if (philo->state == SLEEPING || philo->state == DEAD)
		return (0);
	if (philo->left_fork->owner || philo->right_fork->owner)
		return (0);
	return (1);
}
