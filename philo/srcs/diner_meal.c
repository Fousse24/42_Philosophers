/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_meal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/14 14:23:08 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	set_next_meal(t_diner *diner, t_philo *philo)
{
	if (!diner || !philo)
		return ;
	if (get_t_eat() < get_t_sleep())
		philo->next_meal += get_t_eat() + get_t_sleep();
	else
		philo->next_meal += get_t_eat() * 2;
	if (philo->id == diner->next_odd_id)
	{
		diner->next_odd_id--;
		if (diner->next_odd_id == 0)
			diner->next_odd_id = diner->philo_n;
		philo->next_meal += get_t_eat();
		if (get_t_eat() < get_t_sleep())
			philo->next_meal -= get_t_sleep() - get_t_eat();
	}
}

int	get_meal(t_diner *diner, t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(get_mutex(M_MEAL));
	pthread_mutex_lock(get_mutex(M_FORK));
	if (is_allowed_to_eat(diner, philo))
	{
		// if (!diner->odd_philo)
		// if (diner->odd_philo == philo)
		// 	diner->odd_philo = NULL;
		

		give_forks(philo);
		
		ret = 1;
	}
	pthread_mutex_unlock(get_mutex(M_FORK));
	pthread_mutex_unlock(get_mutex(M_MEAL));
	return (ret);
}
