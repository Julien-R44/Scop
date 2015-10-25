/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanGL.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 01:46:52 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 02:11:28 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANGL_H
# define HUMANGL_H

# include <SDL2/SDL.h>
# include <GL/glut.h>
# include <GL/gl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <math.h>

# include "libft.h"

# define WWIN 600
# define HWIN 400
# define TRUE 1
# define FALSE 0

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

typedef struct	s_mat4
{
	t_vec4		x;
	t_vec4		y;
	t_vec4		z;
	t_vec4		w;
}				t_mat4;

typedef struct		s_all
{
	SDL_Window		*win;
	SDL_GLContext	glContext;
	GLuint 			shader;
	t_mat4			projection;
	t_mat4			modelview;
}					t_all;

#endif
