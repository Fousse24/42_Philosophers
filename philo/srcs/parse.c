/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:26 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/16 19:42:25 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	parse_error(int error_code)
{
	if (error_code == ERROR_ARGN)
	{
		printf("Arguments invalid : too many or not enough arguments\n");
		printf("\nPhilosophers program takes 4 to 5 arguments :\n");
		printf("1 - number_of_philosophers :\n");
		printf("2 - time_to_die: :\n");
		printf("3 - time_to_eat :\n");
		printf("4 - time_to_sleep :\n");
		printf("1 - number_of_times_each_philosopher_must_eat (optional) :\n");
		printf("\nExample : ./philo 4 401 100 200 10\n");
	}
	if (error_code == ERROR_ARGV)
	{
		printf("Arguments invalid : non-numerical arguments detected\n");
		printf("\nOnly positive numerical arguments are allowed.\n");
		printf("A number must only contain digits (no signs nor spaces\n)");
	}
	if (error_code == ERROR_NP)
		printf("Arguments invalid : must have at least 1 philosopher\n");
	return (0);
}

static int	set_options(int *args_int, int argn)
{
	int		i;
	t_diner	*diner;

	diner = get_diner();
	if (!diner || !args_int)
		return (0);
	i = 0;
	if (args_int[0] == 0)
		return (parse_error(ERROR_NP));
	diner->philo_n = args_int[0];
	diner->t_die = args_int[1] * 1000;
	diner->t_sleep = args_int[2] * 1000;
	diner->t_eat = args_int[3] * 1000;
	if (argn == 5)
		diner->philo_n_eat = args_int[4];
	diner->n_meal = diner->philo_n / 2;
	if (diner->philo_n == 1)
		diner->n_meal = 1;
	return (1);
}

int	parse_argv(int argn, char **argv)
{
	int		*argv_int;
	int		i;
	int		error;

	if (argn < 4 || argn > 5)
		return (parse_error(ERROR_ARGN));
	i = 0;
	error = -1;
	argv_int = (int *)ft_calloc(6, sizeof(int));
	while (argv && argv[i])
	{
		if (!ft_isnumber(*argv))
		{
			error = ERROR_ARGV;
			break ;
		}
		argv_int[i] = ft_atoi(argv[i]);
		i++;
	}
	if (error == ERROR_ARGN || error == ERROR_ARGV)
		error = parse_error(error);
	else
		error = set_options(argv_int, argn);
	free(argv_int);
	return (error);
}
