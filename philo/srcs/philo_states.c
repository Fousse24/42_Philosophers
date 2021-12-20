/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:06:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/19 20:06:30 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_state_manager(t_philo *philo)
{
	long long	time;

	time = get_cur_time();
	pthread_mutex_lock(get_mutex(M_PHILO));
	if (time >= philo->next_death)
	{
		if (philo->next_death <= philo->next_action)
		{
			philo_change_state(philo, DEAD, philo->next_death);
			return ;
		}
	}
	if (philo->state == SLEEPING && time >= philo->next_think)
		philo_change_state(philo, THINKING, philo->next_think);
	if (philo->state == THINKING && time >= philo->next_meal)
	{
		pthread_mutex_unlock(get_mutex(M_PHILO));
		if (get_meal(get_diner(), philo) && time >= philo->next_meal)
			philo_change_state(philo, EATING, philo->next_meal);
		pthread_mutex_lock(get_mutex(M_PHILO));
	}
	if (philo->state == EATING && time >= philo->next_sleep)
		philo_change_state(philo, SLEEPING, philo->next_sleep);
	pthread_mutex_unlock(get_mutex(M_PHILO));
}

void	philo_set_next_act(t_philo *philo, long long time)
{
	if (!philo)
		return ;
	philo->next_action = time;
	if (philo->next_death < time)
		philo->next_action = philo->next_death;
}

void	philo_change_state(t_philo *philo, int state, long long stamp)
{
	philo->state = state;
	philo->timestamp = stamp - time_to_long(get_start_time());
	if (state == EATING)
	{
		philo->next_sleep = philo->next_meal + get_t_eat();
		philo->next_death = philo->next_meal + get_t_die();
		set_next_meal(get_diner(), philo);
		philo_set_next_act(philo, philo->next_sleep);
		philo->times_eaten++;
	}
	else if (state == SLEEPING)
	{
		philo->next_think = philo->next_sleep + get_t_sleep();
		philo_set_next_act(philo, philo->next_think);
		philo->left_fork->owner = NULL;
		philo->right_fork->owner = NULL;
	}
	else if (state == THINKING)
		philo_set_next_act(philo, philo->next_meal);
	philo_print_state(philo, state);
}

void	philo_print_state(t_philo *philo, int state)
{
	if (!philo)
		return ;
	pthread_mutex_lock(get_mutex(M_PRINT));
	if (state == THINKING)
		printf("%lld %d is thinking", philo->timestamp / 1000, philo->id);
	else if (state == SLEEPING)
		printf("%lld %d is sleeping", philo->timestamp / 1000, philo->id);
	else if (state == EATING)
	{
		printf("%lld %d is eating", philo->timestamp / 1000, philo->id);
		if (get_diner()->time_eaten == get_diner()->philo_n_eat)
			get_diner()->diner_done = 1;
	}
	else if (state == FORK)
		printf("%lld %d has taken a fork", philo->timestamp / 1000, philo->id);
	else if (state == DEAD)
	{
		printf("%lld %d died", philo->timestamp / 1000, philo->id);
		get_diner()->diner_done = 1;
	}
	printf("\n");
	if (state != DEAD && !get_diner()->diner_done)
		pthread_mutex_unlock(get_mutex(M_PRINT));
}
