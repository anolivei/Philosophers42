/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:10:58 by anolivei          #+#    #+#             */
/*   Updated: 2021/11/21 16:17:15 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handling(int argc, char **argv, t_main *main)
{
	if (argc == 2 && !philo_strncmp(argv[1], "help", 4)
		&& philo_strlen(argv[1]) == 4)
	{
		printf("%s%s%s\n", GREEN, HELP, RESET);
		return (FALSE);
	}
	else if (init_input_struct(argc, argv, main) == FALSE)
	{
		printf("%s%s%s\n", PINK, NUM_ARGS, RESET);
		return (FALSE);
	}
	else
	{
		print_args_errors(main, argc);
		if (!main->input.num_philo || !main->input.time_to_die
			|| !main->input.time_to_eat || !main->input.time_to_sleep
			|| (argc == 6 && !main->input.num_of_times_eat))
			return (FALSE);
	}
	return (TRUE);
}

int	init_input_struct(int argc, char **argv, t_main *main)
{
	if (argc == 5 || argc == 6)
	{
		main->input.num_philo = philo_atoi(argv[1]);
		main->input.time_to_die = philo_atoi(argv[2]);
		main->input.time_to_eat = philo_atoi(argv[3]);
		main->input.time_to_sleep = philo_atoi(argv[4]);
		if (argc == 6)
			main->input.num_of_times_eat = philo_atoi(argv[5]);
		else
			main->input.num_of_times_eat = -1;
		return (TRUE);
	}
	return (FALSE);
}

void	print_args_errors(t_main *main, int argc)
{
	if (!main->input.num_philo)
		printf("%s%s%s\n", PINK, ARG1, RESET);
	if (!main->input.time_to_die)
		printf("%s%s%s\n", PINK, ARG2, RESET);
	if (!main->input.time_to_eat)
		printf("%s%s%s\n", PINK, ARG3, RESET);
	if (!main->input.time_to_sleep)
		printf("%s%s%s\n", PINK, ARG4, RESET);
	if (argc == 6 && !main->input.num_of_times_eat)
		printf("%s%s%s\n", PINK, ARG5, RESET);
}
