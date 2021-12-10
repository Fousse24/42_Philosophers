/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:06:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/09 20:12:59 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_eat(t_philo *philo)
{
	philo->state = EATING;
	gettimeofday(&philo->time_death, NULL);
	gettimeofday(&philo->time_eat, NULL);
	philo->left_fork->owner = philo;
	philo->right_fork->owner = philo;
	philo->times_eaten++;
	philo_print_state(philo, EATING);
}

void	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	philo_print_state(philo, THINKING);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	philo->left_fork->owner = NULL;
	philo->right_fork->owner = NULL;
	gettimeofday(&philo->time_sleep, NULL);
	philo_print_state(philo, SLEEPING);
}

void	philo_die(t_philo *philo)
{
	philo_print_state(philo, DEAD);
	philo->state = DEAD;
}

void	philo_print_state(t_philo *philo, int state)
{
	long long	timestamp;

	if (!philo)
		return ;
	timestamp = get_ms_time_since(get_start_time());
	while (pthread_mutex_lock(get_mutex(M_PRINT)))
		thread_cooldown();
	printf("\n");
	if (state == THINKING)
		printf("%lld %d is thinking", timestamp, philo->id);
	else if (state == SLEEPING)
		printf("%lld %d is sleeping", timestamp, philo->id);
	else if (state == EATING)
		printf("%lld %d is eating", timestamp, philo->id);
	else if (state == DEAD)
		printf("%lld %d died", timestamp, philo->id);
	pthread_mutex_unlock(get_mutex(M_PRINT));
}
