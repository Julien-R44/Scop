/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4lookAt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 05:50:42 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 06:10:04 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat4		ft_mat4lookAt(t_vec3 pos, t_vec3 dir, t_vec3 up)
{
	t_vec3 f = ft_vec3normalize(ft_vec3sub(dir, pos));
	t_vec3 s = ft_vec3normalize(ft_vec3cross(f, up));
	t_vec3 u = ft_vec3cross(s, f);
}
