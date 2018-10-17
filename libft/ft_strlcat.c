/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:29:06 by amoodley          #+#    #+#             */
/*   Updated: 2017/09/07 15:33:49 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	res;

	i = 0;
	j = ft_strlen(dst);
	res = ft_strlen(src) + j;
	if (size <= (size_t)j)
		return (ft_strlen(src) + size);
	while (src[i] && (size > (size_t)j + 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (res);
}
