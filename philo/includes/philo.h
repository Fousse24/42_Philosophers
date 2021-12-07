/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:42:18 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/07 13:59:09 by sfournie         ###   ########.fr       */
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
# define PHILO_T_DIE 300
# define PHILO_T_EAT 50
# define PHILO_T_SLEEP 100
# define PHILO_N_EAT -1

typedef pthread_mutex_t		p_mutex;
typedef struct timeval		t_time;
typedef enum philo_state	e_state;
typedef struct s_diner		t_diner;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;

enum philo_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
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
	t_dlst		*philo_list;
	p_mutex		*mutex;
	pthread_t	thread;
};

struct s_philo
{
	int			id;
	e_state 	state;
	t_fork		*right_fork;
	t_fork		*left_fork;
	int			times_eaten;
	int			time_left;
	pthread_t	thread;

};

struct s_fork
{
	int		id;
	void	*owner;
};

/* Philosophers's list and nodes initialization */
void	init_philo_list(t_dlst **list, int philo_n);
void	init_philo(t_philo *philo, int id);
t_philo	*create_philo(int id);
void	link_head_tail(t_dlst **list);
t_dlst	*get_philo_node(t_dlst *lst, int id);
t_philo	*get_philo(t_dlst *lst, int id);

/* Diner */
t_diner	*get_diner(void);
void	init_diner(t_diner *diner);
void	*philo_dinertime(void *philo_ptr);
void	*waiter_dinertime(void *diner_ptr);
void	print_diner_info(t_diner *diner);

/* Time utilities */
long long	get_ms_time_since(t_time since);
t_time		get_start_time(void);

/* Threads functions */
void	start_philo_threads(t_dlst *philo_list);
void	start_diner_thread(t_diner *diner);

/* Forks */
void	init_fork(t_fork *fork, int id);
t_fork	*create_fork(void *owner, int id);
t_fork	**create_fork_array(int n);
void	assign_forks(t_fork **forks, t_dlst *philos);


#endif