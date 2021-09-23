/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:54:15 by jisokang          #+#    #+#             */
/*   Updated: 2021/09/23 15:37:25 by jisokang         ###   ########.fr       */
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

typedef struct s_philo
{
	int	num;
	int	stat;
}		t_philo;

typedef struct s_state
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_phi_eat;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	fork_mutex;
	t_philo			*philo;
}					t_state;

#endif
