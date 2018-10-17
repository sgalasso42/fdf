/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:28:27 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:10:03 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_nbrdig(intmax_t n, int base)
{
	int i;

	i = 1;
	while ((ft_pow(base, i) - 1) < n)
		i++;
	return (i);
}

char	*ft_itoa_base(intmax_t nbr, int base)
{
	char	*str;
	int		neg;
	int		i;

	if (base == 10)
		return (ft_itoa(nbr));
	neg = (nbr < 0 ? 1 : 0);
	nbr = (nbr < 0 ? -nbr : nbr);
	i = ft_nbrdig(nbr, base);
	if (!(str = ft_strnew(i)))
		return (0);
	while (i-- > 0)
	{
		str[i] = (nbr % base) + (nbr % base > 9 ? 'A' - 10 : '0');
		nbr /= base;
	}
	return (neg ? ft_strjoin("-", str) : str);
}
