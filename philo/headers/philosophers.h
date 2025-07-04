/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:02:49 by ethebaul          #+#    #+#             */
/*   Updated: 2025/07/04 09:48:22 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stddef.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval	t_time;

typedef struct s_args
{
	int	philo;
	int	die;
	int	eat;
	int	sleep;
	int	limit;
}	t_args;

typedef struct s_settings
{
	int	die;
	int	eat;
	int	sleep;
	int	limit;
}	t_settings;

typedef struct s_thread_data
{
	pthread_mutex_t	*left_mutex;
	int				*left_fork;
	pthread_mutex_t	*right_mutex;
	int				*right_fork;
	pthread_mutex_t	*print;
	pthread_mutex_t	*sig_mutex;
	int				*sig;
	pthread_mutex_t	*ctl_mutex;
	int				*ctl;
	t_settings		*settings;
	t_time			*start;
	int				id;
	int				philo;
}	t_thread_data;

typedef struct s_env
{
	pthread_t		*th;
	pthread_mutex_t	*mut;
	pthread_mutex_t	*sig_mutex;
	int				*sig;
	t_thread_data	*data;
	int				*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*ctl_mutex;
	int				*ctl;
	t_time			*start;
}	t_env;

int		only_digit(char *str);
int		ft_atoi(char *str, int *ret);
int		check_args(int argc, char **argv);
int		parse_args(int argc, char **argv, t_settings *set, int *philo);

int		mutex_init(t_env *env, int philo);
int		mutex_init_special(t_env *env, int philo);
int		populate(t_env *env, int philo, int *created);
int		thread_join(t_env *env, int created);
int		data_init(t_env *env, t_settings *set, int philo);

int		setup(t_env *env, t_settings *set, int philo);
int		sim_start(t_settings *set, int philo);

void	print_nbr(long nbr);
int		salloc(void **ptr, size_t size);
void	free_mutex(t_env *env, int philo);
void	free_env(t_env *env);
ulong	delta_utime(t_time *a, t_time *b);
void	plog(t_thread_data *arg, char *msg);
int		dsleep(ulong usecond, t_thread_data *arg, t_time *last);
int		check_death(t_thread_data *arg, t_time *last);
void	philo_stop(t_thread_data *arg);

void	*thread_routine(t_thread_data *arg);
int		try_live(t_thread_data *arg, t_time *last, int *limit);
int		fleft(t_thread_data *arg, t_time *last);
int		fright(t_thread_data *arg, t_time *last);
int		eat(t_thread_data *arg, t_time *last, int *limit);

#endif