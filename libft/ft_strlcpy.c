/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:30:52 by mg                #+#    #+#             */
/*   Updated: 2024/08/08 23:17:55 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t d_size)
{
	size_t	i;

	i = 0;
	if (d_size == 0)
	{
		return (ft_strlen(src));
	}
	while (i < d_size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (d_size != 0)
		d_size = '\0';
	return (ft_strlen(src));
}
