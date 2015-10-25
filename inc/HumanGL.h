/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanGL.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 01:46:52 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 06:16:11 by y0ja             ###   ########.fr       */
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
# include "libmath.h"

# define TITLE_WIN	"HumanGL"
# define WWIN		600
# define HWIN		400
# define FOV		70.0
# define RATIO		(WWIN / HWIN)
# define NEAR		1.0
# define FAR		100.0
# define TRUE		1
# define FALSE		0

typedef struct		s_all
{
	SDL_Window		*win;
	SDL_GLContext	glContext;
	GLuint 			shader;
	t_mat4			projection;
	t_mat4			modelview;
}					t_all;

#endif
