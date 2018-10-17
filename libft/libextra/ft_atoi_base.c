/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:29:07 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/13 19:10:09 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		convert(char c, int base)
{
	int ret;

	if (c >= '0' && c <= '9')
		ret = c - 48;
	else if (c >= 'a' && c <= 'z')
		ret = c - 97 + 10;
	else if (c >= 'A' && c <= 'Z')
		ret = c - 65 + 10;
	else
		ret = -1;
	if (ret < base && ret != -1)
		return (ret);
	else
		return (-1);
}

int		nbr_digits(const char *str, int base)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (convert(str[i], base) < 0)
			break ;
	}
	return (i);
}

int		ft_atoi_base(const char *str, int base)
{
	int	ret;
	int	length;
	int	i;

	if (base == 10)
		return (ft_atoi(str));
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == ' ')
		str++;
	ret = 0;
	length = nbr_digits(str, base) - 1;
	i = -1;
	while (str[++i] && length >= 0 && convert(str[i], base) >= 0)
	{
		ret += convert(str[i], base) * ft_pow(base, length);
		length--;
	}
	return (ret);
}
