/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:53:14 by eberkowi          #+#    #+#             */
/*   Updated: 2025/02/13 09:32:05 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_abs_double(double n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}
