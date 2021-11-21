/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:29:31 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/21 16:22:52 by anolivei         ###   ########.fr       */
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
# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"

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
** Help message
*/
# define HELP "The number of argments must be 4 or 5:\n\
- arg1 number of philosophers\n\
- arg2 time to die\n\
- arg3 time to eat\n\
- arg4 time to sleep\n\
- arg5 number of times each philosopher must eat (optional)"

/*
** Routines messages
*/
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define L_FORK "has taken the left fork"
# define R_FORK "has taken the right fork"
# define DIED "died ☠️"
# define FULL "is full"

/*
** Structures
*/
typedef struct s_input
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
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
	int				n_thread;
	int				num_of_times_ate;
	int				philo_dead;
	t_input			input;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_main;

/*
** handling_errors.c
*/
int			error_handling(int argc, char **argv, t_main *main);
int			init_input_struct(int argc, char **argv, t_main *main);
void		print_args_errors(t_main *main, int argc);

/*
** handling_forks.c
*/
int			create_forks(t_main *main);
void		unlock_forks(t_main *main);

/*
** handling_philos.c
*/
int			create_philos(t_main *main);
void		fill_philo_struct(t_main *main, int i, int j);

/*
** handling_threads.c
*/
int			create_threads(t_main *main);
int			destroy_threads(t_main *main);

/*
** handling_time.c
*/
long long	get_time(void);
long long	delta_time(long long time2);

/*
** philo_utils.c
*/
int			philo_atoi(char *str);
int			philo_strncmp(const char *s1, const char *s2, size_t n);
int			philo_strlen(const char *str);
void		philo_free(t_main *main);

/*
** routine.c
*/
void		*routine(void *args);
int			routine_execute(t_main *main);
void		routine_print(t_main *main, int id, char *color, char *status);

#endif