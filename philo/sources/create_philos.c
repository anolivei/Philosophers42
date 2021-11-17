/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:01:05 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/16 22:24:50 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(t_main *main)
{
	int	i;
	int	j;

	main->philo = malloc(sizeof(t_philo) * (main->input.num_philo + 1));
	if (main->philo == NULL)
		return (FALSE);
	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.num_philo + 1);
	if (main->forks == NULL)
		return (FALSE);
	i = 0;
	j = 1;
	while (i < main->input.num_philo - 1)
	{
		fill_philo_struct(main, i, j);
		j++;
		i++;
	}
	j = 0;
	fill_philo_struct(main, i, j);
	return (TRUE);
}

void	fill_philo_struct(t_main *main, int i, int j)
{
	main->philo[i].id = i + 1;
	main->philo[i].time_to_die = get_time();
	main->philo[i].time_to_eat = get_time();
	main->philo[i].time_to_sleep = get_time();
	main->philo[i].fork.left = i;
	main->philo[i].fork.right = j;
}
