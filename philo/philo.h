/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:54:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/27 01:18:11 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "color.h"

# define ERROR	1
# define TRUE	1
# define FALSE	0

# define NUM_PHIL	1
# define TIME_DIE	2
# define TIME_EAT	3
# define TIME_SLP	4
# define NUM_PEAT	5

typedef struct s_philo
{
	int		num;
	int		stat;
	int		eat_cnt;
}			t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_phi_eat;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	*forks_mutex; //포크는 여러개니까아
	t_philo			*philo;
}					t_info;

int		ft_atoi_philo(const char *str);

#endif
