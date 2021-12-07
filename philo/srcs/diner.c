/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/07 13:44:56 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

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

void	init_diner(t_diner *diner)
{
	if (!diner)
		return ;
	diner->philo_n = PHILO_N;
	diner->philo_n_eat = PHILO_N_EAT;
	diner->philo_t_die = PHILO_T_DIE;
	diner->philo_t_eat = PHILO_T_EAT;
	diner->philo_t_sleep = PHILO_T_SLEEP;
	diner->all_forks = NULL;
	diner->start_time = get_start_time();
	diner->diner_done = 0;
	diner->philo_list = NULL;
}

void	print_diner_info(t_diner *diner)
{
	t_dlst	*philos;
	t_philo	*philo;
	t_philo	*next_philo;
	int		i;

	if (!diner || !diner->philo_list)
		return ;
	philos = diner->philo_list;
	i = 0;
	while (philos && i++ < diner->philo_n)
	{
		philo = (t_philo *)philos->content;
		if (!philos->next)
			break;
		printf("Philo %d has :\n", philo->id);
		printf("philo %d to his left ", ((t_philo *)philos->prev->content)->id);
		printf("and philo %d to his right\n", ((t_philo *)philos->next->content)->id);
		printf("fork %d to his left ", philo->left_fork->id);
		printf("and fork %d to his right\n\n", philo->right_fork->id);
		philos = philos->next;
	}
	printf("There is %d philosophers ", diner->philo_n);
}
