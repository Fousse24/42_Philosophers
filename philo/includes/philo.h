/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:14:03 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 19:51:19 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

# define ERROR_ARGN 0
# define ERROR_ARGV 1
# define ERROR_NP 2
# define MAX_ARGN 5
# define THREAD_CD 60

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
	FORK,
	DEAD
};

enum e_mutex
{
	M_PRINT,
	M_FORK,
	M_MEAL,
	M_PHILO
};

struct s_diner
{
	int			philo_n;
	long long	t_die;
	long long	t_eat;
	long long	t_sleep;
	int			n_meal;
	int			philo_n_eat;
	int			diner_done;
	t_fork		**all_forks;
	t_time		start_time;
	long long	start_time_usec;
	long long	cur_meal;
	long long	next_meal;
	int			time_eaten;
	int			next_odd_id;
	t_philo		**philos;
	pthread_t	thread;
};

struct s_philo
{
	int			id;
	int			state;
	int			is_odd;
	long long	timestamp;
	t_fork		*right_fork;
	t_fork		*left_fork;
	int			times_eaten;
	long long	thread_cd;
	long long	next_sleep;
	long long	next_think;
	long long	cur_meal;
	long long	next_meal;
	long long	next_death;
	long long	next_action;
	pthread_t	thread;

};

struct s_fork
{
	int		id;
	void	*owner;
};

/* Philosophers */
void		init_philo_array(t_philo **arr, int philo_n);
void		init_philo(t_philo *philo, int id);
t_philo		*create_philo(int id);

/* Philosophers' state changes */
void		philo_state_manager(t_philo *philo);
void		philo_change_state(t_philo *philo, int state, long long stamp);
void		philo_print_state(t_philo *philo, int state);
void		philo_set_next_act(t_philo *philo, long long time);
int			philo_can_act(t_philo *philo);

/* Diner */
t_diner		*get_diner(void);
void		init_diner(t_diner *diner);
void		free_diner(t_diner *diner);
int			is_allowed_to_eat(t_diner *diner, t_philo *philo);
int			is_diner_done(t_diner *diner);
t_time		*get_diner_time(void);
void		diner_first_service(t_diner *diner);
void		set_next_meal(t_diner *diner, t_philo *philo);
int			get_meal(t_diner *diner, t_philo *philo);

/* Time utilities */
long long	get_time_since(t_time since);
long long	get_cur_time(void);
long long	get_time_between(t_time early, t_time later);
t_time		get_start_time(void);
long long	time_to_long(t_time time);
t_time		long_to_time(long long ms);
void		copy_time(t_time *src, t_time *dest);
long long	create_t_stamp(t_time time, int offset, int pre_offset);

/* Time limits for philosophers states */
long long	get_t_sleep(void);
long long	get_t_eat(void);
long long	get_t_die(void);
int			get_n_philo(void);
int			get_n_eat(void);

/* Threads functions */
void		start_philo_threads(t_philo **philos);
void		start_diner_thread(t_diner *diner);
void		*philo_dinertime(void *philo_ptr);
void		*waiter_dinertime(void *diner_ptr);

/* Mutex */
t_mutex		*get_mutex(int type);
void		init_mutexes(void);
void		destroy_mutexes(void);

/* Forks */
void		init_fork(t_fork *fork, int id);
t_fork		*create_fork(void *owner, int id);
t_fork		**create_fork_array(int n);
void		assign_forks(t_fork **forks, t_philo **philos);
void		give_forks(t_philo *philo);

/* Utils */
void		*ft_calloc(size_t num, size_t size);
int			ft_array_size(void **arr);
void		*ft_free_array(void **ptr, void (f)(void *));

/* Parse */
int			ft_isdigit(int c);
int			ft_isnumber(char *s);
int			ft_atoi(const char *nptr);
char		**ft_split(char const *s, char c);
int			parse_argv(int argn, char **argv);

#endif