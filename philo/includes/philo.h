/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:29:31 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/18 20:47:24 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

/*
** limits
*/
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*
** bool
*/
# define TRUE 1
# define FALSE 0

/*
** Colors
*/
# define RED "\e[0;31m"
# define RESET "\e[0m"

/*
** Error messages
*/
# define NUM_ARGS "ERROR: The number of argments must be 4 or 5"
# define ARG1 "ERROR: There is a mistake in number of philosophers"
# define ARG2 "ERROR: There is a mistake in time to die"
# define ARG3 "ERROR: There is a mistake in time to eat"
# define ARG4 "ERROR: There is a mistake in time to sleep"
# define ARG5 "ERROR: There is a mistake in number of times each \
philosopher must eat"

/*
** Structures
*/
typedef struct s_input
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philo_must_eat;
}					t_input;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				status;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	t_fork			fork;
	pthread_t		thread;
}					t_philo;

typedef struct s_main
{
	t_input			input;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_main;

/*
** error_handling.c
*/
int			error_handling(int argc, char **argv, t_main *main);
int			init_input_struct(int argc, char **argv, t_main *main);

/*
** philo_utils.c
*/
int			philo_atoi(char *str);
void		philo_free(t_main *main);

/*
** create_philos.c
*/
int			create_philos(t_main *main);
void		fill_philo_struct(t_main *main, int i, int j);

/*
** create_forks.c
*/
int			create_forks(t_main *main);

/*
** time_handling.c
*/
long long	get_time(void);

/*
** create_threads.c
*/
int			create_threads(t_main *main);

/*
** routine.c
*/
void		*routine(void);

#endif