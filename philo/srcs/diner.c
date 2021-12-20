/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/19 19:55:09 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	init_diner(t_diner *diner)
{
	if (!diner)
		return ;
	diner->philo_n = -1;
	diner->philo_n_eat = -1;
	diner->t_die = -1;
	diner->t_eat = -1;
	diner->t_sleep = -1;
	diner->n_meal = 0;
	diner->diner_done = 0;
	diner->next_odd_id = -1;
	diner->time_eaten = 0;
	diner->all_forks = NULL;
	diner->philos = NULL;
}

void	diner_first_service(t_diner *diner)
{
	t_philo	**philos;
	t_philo	*philo;

	if (!diner || !diner->philos)
		return ;
	philos = diner->philos;
	while (*philos && diner->n_meal > 0)
	{
		philo = *philos;
		if (philo->id % 2 != 1 || diner->philo_n == 1)
		{
			philo->next_meal = diner->cur_meal;
			diner->n_meal--;
		}
		else
			philo->next_meal = diner->cur_meal + get_t_eat();
		philos++;
	}
	diner->n_meal = diner->philo_n;
	diner->next_meal = diner->cur_meal + get_t_eat();
	if (*philos)
	{
		(*philos)->next_meal = diner->next_meal + get_t_eat();
		diner->next_odd_id = diner->philo_n - 1;
	}
}

int	is_diner_done(t_diner *diner)
{
	t_philo	**philos;

	if (diner)
		philos = diner->philos;
	if (!diner || !philos)
		return (-1);
	while (*philos)
	{
		if ((*philos)->state == DEAD)
			return (1);
		philos++;
	}
	return (0);
}

t_diner	*get_diner(void)
{
	static t_diner	*diner;

	if (!diner)
	{
		diner = (t_diner *)ft_calloc(1, sizeof(t_diner));
		init_diner(diner);
	}
	return (diner);
}

void	free_diner(t_diner *diner)
{
	if (diner)
	{
		if (diner->philos)
			ft_free_array((void **)diner->philos, free);
		if (diner->all_forks)
		{
			ft_free_array((void **)diner->all_forks, fork_clear);
		}
		free(diner);
	}
}
