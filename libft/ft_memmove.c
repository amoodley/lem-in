/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 10:18:42 by amoodley          #+#    #+#             */
/*   Updated: 2017/09/07 15:33:49 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcc;
	char	*dstc;
	size_t	i;
	size_t	n;

	n = len - 1;
	i = 0;
	srcc = (char *)src;
	dstc = (char *)dst;
	if (srcc < dstc)
		while ((int)n >= 0)
		{
			dstc[n] = srcc[n];
			n--;
		}
	else
		while (i < len)
		{
			dstc[i] = srcc[i];
			i++;
		}
	return (dst);
}
