/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/14 00:18:22 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	init_diner(t_diner *diner)
{
	if (!diner)
		return ;
	diner->philo_n = PHILO_N;
	diner->philo_n_eat = PHILO_N_EAT;
	diner->t_die = PHILO_T_DIE * 1000;
	diner->t_eat = PHILO_T_EAT * 1000;
	diner->t_sleep = PHILO_T_SLEEP * 1000;
	diner->all_forks = NULL;
	diner->n_meal = diner->philo_n / 2;
	diner->diner_done = 0;
	diner->philos = NULL;
}

void	diner_first_service(t_diner *diner)
{
	t_philo **philos;
	t_philo	*philo;

	if (!diner || !diner->philos)
		return;
	philos = diner->philos;
	while (*philos && diner->n_meal > 0)
	{
		philo = *philos;
		if (philo->id % 2 != 1)
		{
			philo->next_meal = diner->cur_meal;
			diner->n_meal--;
		}
		else
			philo->next_meal = diner->cur_meal + get_t_eat();
		philos++;
	}
	diner->n_meal = diner->philo_n / 2;
	diner->next_meal = diner->cur_meal + get_t_eat();
	if (*philos)
		(*philos)->next_meal = diner->next_meal + get_t_eat();
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
