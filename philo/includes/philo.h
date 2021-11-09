/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:29:31 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/08 22:54:22 by anolivei         ###   ########.fr       */
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
** Structures
*/

typedef struct s_philo
{
	unsigned int	num_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	num_of_times_each_philo_must_eat;
}					t_philo;

/*
** Functions
*/
void	error_handling(int argc, char **argv, t_philo *philo);
int		init_philo_struct(int argc, char **argv, t_philo *philo);
int		philo_atoi(char *str);

#endif