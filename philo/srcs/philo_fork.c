/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:15:33 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/07 13:26:23 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	init_fork(t_fork *fork, int id)
{
	fork->owner = NULL;
	fork->id = id;
}

t_fork	*create_fork(void *owner, int id)
{
	t_fork	*fork;

	fork = (t_fork *)ft_calloc(1, sizeof(t_fork));
	if (fork)
	{
		init_fork(fork, id);
		if (owner)
			fork->owner = owner;
	}
	return (fork);
}

t_fork	**create_fork_array(int n)
{
	int		i;
	t_fork	**forks;

	forks = (t_fork **)ft_calloc(n + 1, sizeof(t_fork *));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < n)
	{
		forks[i] = create_fork(NULL, i + 1);
		i++;
	}
	forks[i] = NULL;
	return (forks);
}

// Place the forks in-between each philosophers.
void	assign_forks(t_fork **forks, t_dlst *philos)
{
	t_philo	*philo_right;
	t_philo	*philo;
	int		i;

	if (!forks || !philos || !philos->content)
		return ;
	i = 0;
	while (forks[i] && philos)
	{
		philo = (t_philo *)philos->content;
		if (philos->next)
		{
			philo_right = philos->next->content;
			philo_right->left_fork = forks[i];
		}
		philo->right_fork = forks[i++];
		philos = philos->next;
	}
}
