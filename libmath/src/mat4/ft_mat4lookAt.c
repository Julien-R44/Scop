/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4lookAt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 05:50:42 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/26 02:09:02 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float	ft_vec3dot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * a.z));
}

t_mat4			ft_mat4lookAt(t_vec3 pos, t_vec3 target, t_vec3 up)
{
	t_vec3	f = ft_vec3normalize(ft_vec3sub(target, pos));
	t_vec3	s = ft_vec3normalize(ft_vec3cross(up, f));
	t_vec3	u = ft_vec3cross(f, s);

	t_mat4	ret = {
		{s.x, s.y, s.z, -ft_vec3dot(s, pos)},
		{s.y, u.y, u.z, -ft_vec3dot(u, pos)},
		{s.z, f.y, f.z, -ft_vec3dot(f, pos)},
		{0.f, 0.f, 0.f, 1.f}
	};

	return (ret);
}
