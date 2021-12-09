/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/07 18:43:37 by sfournie         ###   ########.fr       */
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
	diner->philos = NULL;
}

void	print_diner_info(t_diner *diner)
{
	t_philo	**philos;
	int		size;
	int		i;

	if (!diner)
		return ;
	philos = diner->philos;
	size = ft_array_size((void **)philos);
	i = 0;
	while (philos && philos[i])
	{
		printf("Philo %d has :\n", philos[i]->id);
		if (i == 0)
			printf("philo %d to his left ", philos[size - 1]->id);
		else
			printf("philo %d to his left ", philos[i - 1]->id);
		if (i == size - 1)
			printf("philo %d to his right ", philos[0]->id);
		else
			printf("philo %d to his right ", philos[i + 1]->id);
		printf("\nfork %d to his left ", philos[i]->left_fork->id);
		printf("and fork %d to his right\n\n", philos[i]->right_fork->id);
		i++;
	}
	printf("There is %d philosophers ", diner->philo_n);
}
