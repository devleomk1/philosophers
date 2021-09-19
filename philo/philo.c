/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:35 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/18 18:01:37 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_msg(char *str)
{

}

int	main(int argc, char **argv)
{
	int		i;
	int		argv_num[5];
	t_info	*info;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong argument! Please check usage.\n"\
			YELLOW"Usage: ./philo [num_philos] [time_die] [time_eat]\
			[time_sleep] [num_each_philos_eat(optional)]\n"RESET);
		return (ERROR);
	}
	i = 1;
	while (i < argc)
	{
		//atoi -> ft_atoi for philo -> 음수 처리
		//
		argv_num[i] = atoi(argv[i]);
		printf("argv_num[%d] = %d\n", i, argv_num[i]);
		i++;
	}
	if (argv_num[1] < 2)
	{
		printf("ERROR\n");
		return (ERROR);
	}
	return (0);
}
