/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 05:43:58 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 06:11:18 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

float		ft_sqrtf(float nb)
{
	float root = 0.f;
	float low, high;
	float tmp = -1;

	while ((root * root) < nb) {
		++root;
	}
	if ((root * root) == nb)
		return (root);
	high = root;
	low = --root;
	while (tmp != root) {
		tmp = root;
		if ((root * root) < nb) {
			low = root;
			root += (high - low) / 2;
		}
		else {
			high = root;
			root -= (high - low) / 2;
		}
	}
	return (root);
}
