/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:30:47 by amoodley          #+#    #+#             */
/*   Updated: 2017/09/07 15:33:51 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = -1;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (little[j] && k < len)
			{
				if (little[j] != big[k])
					break ;
				j++;
				k++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
	}
	return (NULL);
}
