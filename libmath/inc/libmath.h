#ifndef LIBMATH_H
# define LIBMATH_H

# include <math.h>

# define VEC3(x, y, z) ((t_vec3) {(x), (y), (z)})

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

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

/*
** Maths
*/
double				ft_pow(double x, int pow);
float				ft_sqrtf(float nb);

/*
** Matrix functions
*/
t_mat4				ft_mat4identity(double value);
t_mat4				ft_mat4lookAt(t_vec3 pos, t_vec3 dir, t_vec3 up);
t_mat4				ft_mat4perspective(float fov, float ratio, float near, float far);

/*
** Vector 3D functions
*/
float				ft_vec3length(t_vec3 v);
t_vec3				ft_vec3cross(t_vec3 a, t_vec3 b);
t_vec3				ft_vec3normalize(t_vec3 vec);
t_vec3				ft_vec3sub(t_vec3 v1, t_vec3 v2);

#endif
