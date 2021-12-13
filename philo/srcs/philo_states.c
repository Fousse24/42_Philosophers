/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:06:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/13 17:42:56 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_state_manager(t_philo *philo)
{
	if (philo->state == SLEEPING)
	{
		if (get_time_between(philo->time_sleep, philo->start) >= get_t_sleep())
			philo_change_state(philo, THINKING);
	}
	while (philo->state == THINKING)
	{
		if (philo->left_fork->owner == philo && philo->right_fork->owner == philo)
		{
			philo_change_state(philo, EATING);
			copy_time(&philo->time_eat, &philo->time_death);
		}
		else if (get_time_between(philo->time_death, philo->start) >= get_t_die())
			philo_change_state(philo, DEAD);
	}
	if (philo->state == EATING)
	{
		if (get_time_between(philo->time_eat, philo->start) >= get_t_eat())
			philo_change_state(philo, SLEEPING);
	}
	if (get_time_between(philo->time_eat, philo->start) >= get_t_die())
		philo_change_state(philo, DEAD);
}

void	philo_change_state(t_philo *philo, int state)
{
	t_time	*state_time;

	if (!philo)
		return ;
	state_time = &philo->start;
	philo->state = state;
	if (state == EATING)
	{
		state_time = &philo->time_eat;
		philo->times_eaten++;
	}
	else if (state == SLEEPING)
	{
		state_time = &philo->time_sleep;
		philo->left_fork->owner = NULL;
		philo->right_fork->owner = NULL;
	}
	if (state != EATING)
		set_to_current_time(philo, state_time, 0);
	// philo->timestamp = create_t_stamp(*state_time);
	philo->timestamp = get_time_between(get_start_time(), *state_time);
	philo_print_state(philo, state);
}

void	philo_print_state(t_philo *philo, int state)
{
	if (!philo)
		return ;
	while (pthread_mutex_lock(get_mutex(M_PRINT)))
		thread_cooldown();
	printf("\n");
	if (state == THINKING)
		printf("%lld %d is thinking", philo->timestamp / 1000, philo->id);
	else if (state == SLEEPING)
		printf("%lld %d is sleeping", philo->timestamp / 1000, philo->id);
	else if (state == EATING)
		printf("%lld %d is eating", philo->timestamp / 1000, philo->id);
	else if (state == DEAD)
		printf("%lld %d died", philo->timestamp / 1000, philo->id);
	if (state != DEAD)
		pthread_mutex_unlock(get_mutex(M_PRINT));
}
