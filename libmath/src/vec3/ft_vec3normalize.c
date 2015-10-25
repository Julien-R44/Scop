/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 05:52:03 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 06:11:31 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3		ft_vec3normalize(t_vec3 vec)
{
	float	length = ft_vec3length(vec);

	return (VEC3(
		vec.x / length,
		vec.y / length,
		vec.z / length
	));
}
