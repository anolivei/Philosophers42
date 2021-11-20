/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:26:55 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/20 18:26:18 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_main	*main;

	main = (t_main *)args;
	routine_print(main, BLUE, SLEEP);
	routine_print(main, G_BLUE, THINK);
	routine_print(main, G_CYAN, EAT);
	routine_print(main, B_BLUE, L_FORK);
	routine_print(main, B_BLUE, R_FORK);
	routine_print(main, GREEN, FULL);
	routine_print(main, PINK, DIED);
	return (0);
}

void	routine_print(t_main *main, char *color, char *status)
{
	long long	now;

	now = main->philo[main->i_philo].time_to_die;
	printf("%s%-10lld ", color, now);
	printf("%-3d %-30s%s\n", main->philo[main->i_philo].id, status, RESET);
}
