/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:06:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/10 19:07:42 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_eat(t_philo *philo)
{
	philo->state = EATING;
	set_to_current_time(philo, &philo->time_death, get_t_die());
	set_to_current_time(philo, &philo->time_eat, get_t_eat());
	philo->left_fork->owner = philo;
	philo->right_fork->owner = philo;
	philo->times_eaten++;
	philo_print_state(philo, EATING);
}

void	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	philo->timestamp = get_time_between(get_start_time(), philo->start);
	philo_print_state(philo, THINKING);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	philo->left_fork->owner = NULL;
	philo->right_fork->owner = NULL;
	set_to_current_time(philo, &philo->time_sleep, get_t_sleep());
	philo_print_state(philo, SLEEPING);
}

void	philo_die(t_philo *philo)
{
	philo->timestamp = get_time_between(get_start_time(), philo->start);
	philo_print_state(philo, DEAD);
	philo->state = DEAD;
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
