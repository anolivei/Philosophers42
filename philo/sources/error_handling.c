/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:10:58 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/15 22:09:17 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_input_struct(int argc, char **argv, t_main *main)
{
	if (argc == 5 || argc == 6)
	{
		main->input.num_philo = philo_atoi(argv[1]);
		main->input.time_to_die = philo_atoi(argv[2]);
		main->input.time_to_eat = philo_atoi(argv[3]);
		main->input.time_to_sleep = philo_atoi(argv[4]);
		if (argc == 6)
			main->input.num_of_times_each_philo_must_eat = philo_atoi(argv[5]);
		return (TRUE);
	}
	return (FALSE);
}

int	error_handling(int argc, char **argv, t_main *main)
{
	if (init_input_struct(argc, argv, main) == FALSE)
	{
		printf("%s%s%s\n", RED, NUM_ARGS, RESET);
		return (FALSE);
	}
	else
	{
		if (!main->input.num_philo)
			printf("%s%s%s\n", RED, ARG1, RESET);
		if (!main->input.time_to_die)
			printf("%s%s%s\n", RED, ARG2, RESET);
		if (!main->input.time_to_eat)
			printf("%s%s%s\n", RED, ARG3, RESET);
		if (!main->input.time_to_sleep)
			printf("%s%s%s\n", RED, ARG4, RESET);
		if (argc == 6 && !main->input.num_of_times_each_philo_must_eat)
			printf("%s%s%s\n", RED, ARG5, RESET);
	}
	return (TRUE);
}
