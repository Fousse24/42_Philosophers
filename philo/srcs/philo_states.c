/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:06:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/09 18:41:46 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_manager(t_philo *philo)
{
	if (get_ms_time_since(philo->time_death) <= PHILO_T_DIE)
			philo_die(philo);
	else
	{
		if (philo->state == SLEEPING)
		{
			if (get_ms_time_since(philo->time_sleep) <= PHILO_T_SLEEP)
				philo_think(philo);
		}
		else if (philo->state == EATING)
		{
			if (get_ms_time_since(philo->time_eat) <= PHILO_T_EAT)
				philo_sleep(philo);
		}
		else if (philo->state == THINKING)
		{
			if (!pthread_mutex_lock(get_mutex(M_FORK)))
			{	
				if (diner_ask_for_forks(philo, get_diner()))
					philo_eat(philo);
				pthread_mutex_unlock(get_mutex(M_FORK));
				thread_cooldown();
			}
		}
	}
}

void	philo_eat(t_philo *philo)
{
	philo->state = EATING;
	gettimeofday(&philo->time_death, NULL);
	gettimeofday(&philo->time_eat, NULL);
	philo->left_fork->owner = philo;
	philo->right_fork->owner = philo;
	philo->times_eaten++;
	philo_print_state(philo);
	
}

void	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	philo->left_fork->owner = NULL;
	philo->right_fork->owner = NULL;
	philo_print_state(philo);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	gettimeofday(&philo->time_sleep, NULL);
	philo_print_state(philo);
}

void	philo_die(t_philo *philo)
{
	philo_print_state(philo);
	philo->state = DEAD;
}


void	philo_print_state(t_philo *philo)
{
	long long	timestamp;
	
	if (!philo)
		return ;
	timestamp = get_ms_time_since(get_start_time()) / 1000;
	while (pthread_mutex_lock(get_mutex(M_PRINT)))
		thread_cooldown();
	printf("\n");
	if (philo->state == THINKING)
		printf("%lld %d is thinking", timestamp, philo->id);
	else if (philo->state == SLEEPING)
		printf("%lld %d is sleeping", timestamp, philo->id);
	else if (philo->state == EATING)
		printf("%lld %d is eating", timestamp, philo->id);
	else if (philo->state == DEAD)
		printf("%lld %d died", timestamp, philo->id);
	pthread_mutex_unlock(get_mutex(M_PRINT));
}
