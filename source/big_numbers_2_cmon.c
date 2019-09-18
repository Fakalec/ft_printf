/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers_2_cmon.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:31:33 by dstracke          #+#    #+#             */
/*   Updated: 2019/01/23 17:17:03 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				init_long(t_long *a, int nbr)
{
	if (!((*a).nbr = (long long *)malloc(sizeof(long long))))
		exit(1);
	(*a).len = 1;
	(*a).nbr[0] = nbr;
	(*a).power = 0;
}

void				zero_passer(t_long *a)
{
	int				i;

	i = (*a).len - 1;
	while (i >= 0 && (*a).nbr[i--] == 0)
		(*a).len--;
}

void				tidy_up(t_karatsuba_var *var)
{
	free((*var).res1.nbr);
	free((*var).res2.nbr);
	free((*var).res3.nbr);
	free((*var).sum1.nbr);
	free((*var).sum2.nbr);
}

t_long				*sub(t_long *a, t_long b)
{
	int				i;

	i = -1;
	while (++i < b.len)
		(*a).nbr[i] -= b.nbr[i];
	normalize(a);
	return (a);
}

void				init_var(t_long *a, t_karatsuba_var *var, int flag)
{
	if (flag)
	{
		(*var).a_l.nbr = (*a).nbr;
		(*var).a_l.len = ((*a).len + 1) / 2;
		(*var).a_r.nbr = (*a).nbr + (*var).a_l.len;
		(*var).a_r.len = (*a).len / 2;
	}
	else
	{
		(*var).b_l.nbr = (*a).nbr;
		(*var).b_l.len = ((*a).len + 1) / 2;
		(*var).b_r.nbr = (*a).nbr + (*var).a_l.len;
		(*var).b_r.len = (*a).len / 2;
	}
}
