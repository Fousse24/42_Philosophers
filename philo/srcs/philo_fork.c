/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:15:33 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/07 18:39:23 by sfournie         ###   ########.fr       */
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
void	assign_forks(t_fork **forks, t_philo **philos)
{
	t_philo	*philo_right;
	int		i;
	int		size;

	if (!forks || !philos)
		return ;
	size = ft_array_size((void **)philos);
	i = 0;
	while (size > 0 && forks[i] && philos[i])
	{
		if (i == size - 1)
			philo_right = philos[0];
		else
			philo_right = philos[i + 1];
		philo_right->left_fork = forks[i];
		philos[i]->right_fork = forks[i];
		i++;
	}
}
