/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:40:17 by amoodley          #+#    #+#             */
/*   Updated: 2017/09/07 15:33:49 by amoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		k;

	if (ft_strlen(little) == '\0')
		return ((char *)big);
	i = -1;
	while (big[++i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (little[j])
			{
				if (little[j] != big[k])
					break ;
				j++;
				k++;
			}
			if (j == (int)ft_strlen(little))
				return ((char *)&big[i]);
		}
	}
	return (NULL);
}
