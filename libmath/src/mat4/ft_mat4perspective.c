/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4perspective.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 05:49:02 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 06:09:59 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_mat4		ft_mat4perspective(float fov, float ratio, float near, float far)
{
	t_mat4	ret;
	float	tanHalfFovy;

	tanHalfFovy = tan(fov / 2);
	ret.x = (t_vec4) {1.f / (ratio * tanHalfFovy), 0.f, 0.f, 0.f};
	ret.y = (t_vec4) {0.f, 1.f / (tanHalfFovy), 0.f, 0.f};
	ret.z = (t_vec4) {0.f, 0.f, -(far + near) / (far - near), 1.f};
	ret.w = (t_vec4) {0.f, 0.f, -(2.f * far * near) / (far - near), 0.f};
	return (ret);
}
