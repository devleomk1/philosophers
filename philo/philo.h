/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:54:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/19 13:04:40 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include "color.h"

# define ERROR	1
# define TRUE	1
# define FALSE	0

typedef struct s_philo
{
	int	num;
	int	stat;
}		t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_phi_eat;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	_mutex;
	t_philo			*philo;
}					t_info;

#endif
