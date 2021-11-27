/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:01:05 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/26 23:53:16 by anolivei         ###   ########.fr       */
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
	i = 0;
	j = 1;
	while (j < main->input.num_philo)
	{
		fill_philo_struct(main, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo_struct(main, i, j);
	return (TRUE);
}

void	fill_philo_struct(t_main *main, int i, int j)
{
	main->philo[i].id = i + 1;
	main->philo[i].num_of_times_ate = 0;
	main->philo[i].time_to_die = get_time();
	main->philo[i].time_to_eat = get_time();
	main->philo[i].time_to_sleep = get_time();
	main->philo[i].fork.left = i;
	main->philo[i].fork.right = j;
	printf("id %d left %d right %d\n", main->philo[i].id, main->philo[i].fork.left, main->philo[i].fork.right);
}
