/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beautiful_way_for_life_cmon.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:31:33 by dstracke          #+#    #+#             */
/*   Updated: 2019/01/23 17:17:03 by dstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		kekes_lales(char **str, int *pre, int end)
{
	int i;
	int kek;
	int lol;

	lol = 0;
	while ((*str)[lol] <= '0' && lol < end)
		lol++;
	if ((*str)[lol] < '1' || (*str)[lol] > '9')
		return (0);
	((*str)[1] = (*str)[lol]);
	*pre > 0 ? ((*str)[2] = '.') : 0;
	i = 3;
	kek = lol + 1;
	while (kek < end)
		(*str)[i++] = (*str)[kek++];
	while (i < end)
		(*str)[i++] = '0';
	lol -= 2;
	(*str)[2] != '.' ? lol += 1 : 0;
	lol *= -1;
	return (lol);
}

int		lales_kekes(char **str, int *pre, int sta, int end)
{
	int kek;
	int lol;

	lol = 0;
	if ((*str)[1] != '0')
	{
		while ((*str)[lol] != '.' && lol < sta)
			lol++;
		kek = lol + 1;
		while (--kek > 2)
			(*str)[kek] = (*str)[kek - 1];
		*pre > 0 || (*str)[2] != '.' ? (*str)[kek] = '.' : 0;
		lol -= 2;
	}
	else
		lol = kekes_lales(str, pre, end);
	return (lol);
}

int		add_expo(char **str, size_t *flags, t_bits *tally, int *pre)
{
	int c;

	c = (*tally).middle + (pre > 0 ? *pre : 0);
	(*str)[c++] = 'e';
	*flags & BIG ? (*str)[c - 1] = 'E' : 0;
	(*str)[c++] = '+';
	(*tally).tmp_ex < 0 ? ((*tally).tmp_ex *= -1) && ((*str)[c - 1] = '-') : 0;
	if ((*tally).tmp_ex >= 10 && (*tally).tmp_ex < 100)
	{
		(*str)[c++] = (*tally).tmp_ex / 10 + '0';
		(*str)[c++] = (*tally).tmp_ex % 10 + '0';
	}
	else if ((*tally).tmp_ex >= 100)
	{
		(*str)[c++] = (*tally).tmp_ex / 100 + '0';
		(*str)[c++] = ((*tally).tmp_ex % 100) / 10 + '0';
		(*str)[c++] = ((*tally).tmp_ex % 100) % 10 + '0';
		(*pre)++;
	}
	else
	{
		(*str)[c++] = '0';
		(*str)[c++] = (*tally).tmp_ex + '0';
	}
	return (1);
}

int		scientific_record(char **str, t_bits *tally, size_t *flags, int *pre)
{
	int count;

	count = (*tally).tmp_ex;
	(*tally).exhibi = lales_kekes(str, pre, (*tally).middle, (*tally).middle
	+ (*tally).size);
	(*tally).middle = 3;
	roundd(str, pre, (*tally).middle - 2, (*tally).middle + (*tally).size +
	((*tally).exhibi > 0 ? (*tally).exhibi : 0));
	if ((*str)[0] > '0')
	{
		(*str)[2] = (*str)[1];
		(*str)[1] = '.';
		(*tally).exhibi++;
		(*tally).middle = 2;
	}
	(*tally).tmp_ex = (*tally).exhibi;
	while ((*tally).exhibi++ < *pre)
		(*str)[count++] = '0';
	*pre <= 0 && !(*flags & HAS) ? (*tally).middle-- : 0;
	add_expo(str, flags, tally, pre);
	return ((*tally).middle + *pre);
}
