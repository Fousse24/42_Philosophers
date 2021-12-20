/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/19 20:03:45 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	give_forks(t_philo *philo)
{
	philo->timestamp = philo->next_meal - time_to_long(get_start_time());
	change_fork_owner(philo->left_fork, philo);
	philo_print_state(philo, FORK);
	change_fork_owner(philo->right_fork, philo);
	philo_print_state(philo, FORK);
}

int	is_allowed_to_eat(t_diner *diner, t_philo *philo)
{
	if (!diner || !philo)
		return (0);
	if (philo->times_eaten > diner->time_eaten)
		return (0);
	if (philo->state == SLEEPING || philo->state == DEAD)
		return (0);
	if (!philo->left_fork || !philo->right_fork)
		return (0);
	if (philo->left_fork->owner || philo->right_fork->owner)
		return (0);
	return (1);
}

// Place the forks in-between each philosophers.
void	assign_forks(t_fork **forks, t_philo **philos)
{
	t_philo	*philo_right;
	int		i;
	int		size;

	if (!forks || !philos)
		return ;
	size = ft_array_size((void **)philos);
	i = 0;
	philo_right = NULL;
	while (size > 0 && forks[i] && philos[i])
	{
		if (i == size - 1 && size > 1)
			philo_right = philos[0];
		else if (size != 1)
			philo_right = philos[i + 1];
		if (philo_right)
			philo_right->left_fork = forks[i];
		philos[i]->right_fork = forks[i];
		i++;
	}
}
