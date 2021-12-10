/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:42:18 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/10 16:21:26 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/includes/libft.h"

# define PHILO_N 5
# define PHILO_T_DIE 150
# define PHILO_T_EAT 50
# define PHILO_T_SLEEP 100
# define PHILO_N_EAT -1

typedef pthread_mutex_t		t_mutex;
typedef struct timeval		t_time;
typedef struct s_diner		t_diner;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;

enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
};

enum e_mutex
{
	M_PRINT,
	M_FORK
};

struct s_diner
{
	int			philo_n;
	int			philo_t_die;
	int			philo_t_eat;
	int			philo_t_sleep;
	int			philo_n_eat;
	int			diner_done;
	t_fork		**all_forks;
	t_time		start_time;
	t_philo		**philos;
	t_mutex		*mutex;
	pthread_t	thread;
};

struct s_philo
{
	int			id;
	int			state;
	t_fork		*right_fork;
	t_fork		*left_fork;
	int			times_eaten;
	t_time		time_sleep;
	t_time		time_eat;
	t_time		time_death;
	pthread_t	thread;
	t_time		start;

};

struct s_fork
{
	int		id;
	void	*owner;
};

/* Philosophers */
void	init_philo_array(t_philo **arr, int philo_n);
void	init_philo(t_philo *philo, int id);
t_philo	*create_philo(int id);

/* Philosophers' state changes */
void	philo_manager(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_die(t_philo *philo);
void	philo_print_state(t_philo *philo, int state);

/* Diner */
t_diner	*get_diner(void);
void	init_diner(t_diner *diner);
void	*philo_dinertime(void *philo_ptr);
void	*waiter_dinertime(void *diner_ptr);
void	print_diner_info(t_diner *diner);
int		is_allowed_to_eat(t_diner *diner, t_philo *philo);
int		is_diner_done(t_diner *diner);
int		diner_ask_for_forks(t_diner *diner, t_philo *philo);

/* Time utilities */
long	get_ms_time_since(t_time since);
t_time	get_start_time(void);

/* Threads functions */
void	start_philo_threads(t_philo **philos);
void	start_diner_thread(t_diner *diner);
void	thread_cooldown(void);

/* Mutex */
t_mutex	*get_mutex(int type);
void	init_mutexes(void);
void	destroy_mutexes(void);

/* Forks */
void	init_fork(t_fork *fork, int id);
t_fork	*create_fork(void *owner, int id);
t_fork	**create_fork_array(int n);
void	assign_forks(t_fork **forks, t_philo **philos);

#endif