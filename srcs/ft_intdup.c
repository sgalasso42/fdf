/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:49:19 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/12 15:25:26 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		*ft_intdup(t_map *map, int *src)
{
	int		*cpy;
	int		i;

	i = 0;
	if (!(cpy = (int *)malloc(sizeof(int) * (map->nb_x))))
		return (0);
	while (i < map->nb_x)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}
