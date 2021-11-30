/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:26:55 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/30 00:14:58 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = main->n_thread;
	if (main->input.num_of_times_eat > 0)
	{
		while (main->input.num_of_times_eat > main->philo[i].num_of_times_ate
			&& main->philo_dead == FALSE)
			routine_execute(main, i);
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (routine_execute(main, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

static int	checker_aux(t_main *main, int *i)
{
	int	time;

	if (*i == main->input.num_philo)
		*i = 0;
	time = delta_time(main->philo[*i].time_to_die);
	if (time > main->input.time_to_die)
	{
		routine_print(main, main->philo[*i].id, PINK, DIED);
		main->philo_dead = TRUE;
		return (TRUE);
	}
	i++;
	return (FALSE);
}

void	*checker(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = 0;
	if (main->input.num_of_times_eat > 0)
	{
		while (main->input.num_of_times_eat > main->philo[i].num_of_times_ate
			&& main->philo_dead == FALSE)
		{
			if (checker_aux(main, &i) == TRUE)
				return (NULL);
		}
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (checker_aux(main, &i) == TRUE)
				return (NULL);
		}
	}
	return (NULL);
}

int	routine_execute(t_main *main, int i)
{
	if (philo_eat(main, i) == FALSE)
		return (FALSE);
	if (philo_sleep(main, i) == FALSE)
		return (FALSE);
	if (philo_think(main, i) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	routine_print(t_main *main, int id, char *color, char *status)
{
	long long	now;

	now = delta_time(main->t0);
	if (main->philo_dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&main->write);
		return (FALSE);
	}
	else
		printf("%s%-10lld %-3d %-30s%s\n", color, now, id, status, RESET);
	pthread_mutex_unlock(&main->write);
	return (TRUE);
}
