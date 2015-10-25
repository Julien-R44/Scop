/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 03:25:18 by jripoute          #+#    #+#             */
/*   Updated: 2015/09/30 03:30:10 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*yolo;
	int		i;

	i = 0;
	if (s != 0 && (*f) != 0)
	{
		yolo = (char*)ft_memalloc(ft_strlen(s) + 1);
		if (!yolo)
			return (NULL);
		while (s[i] != '\0')
		{
			yolo[i] = (*f)(i, s[i]);
			i++;
		}
		return (yolo);
	}
	return (0);
}
