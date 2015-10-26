/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 22:59:22 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/26 02:59:49 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanGL.h"

static const GLfloat vertex[] = {
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

static const GLfloat g_color_buffer_data[] = {
    0.0255f,  0.12555f,  0.014f,
    0.0255f,  0.12555f,  0.436f,
    0.0255f,  0.12555f,  0.844f,
    0.0255f,  0.12555f,  0.201f,
    0.0255f,  0.12555f,  0.223f,
    0.0255f,  0.12555f,  0.185f,
    0.0255f,  0.12555f,  0.761f,
    0.0255f,  0.12555f,  0.730f,
    0.0255f,  0.4555f,  0.152f,
    0.0255f,  0.4555f,  0.789f,
    0.0255f,  0.4555f,  0.639f,
    0.0255f,  0.4555f,  0.859f,
    0.0255f,  0.4555f,  0.576f,
    0.0255f,  0.4555f,  0.970f,
    0.0255f,  0.4555f,  0.116f,
    0.0255f,  0.4555f,  0.133f,
    0.0255f,  0.12555f,  0.833f,
    0.0255f,  0.12555f,  0.489f,
    0.0255f,  0.12555f,  0.064f,
    0.0255f,  0.12555f,  0.592f,
    0.0255f,  0.12555f,  0.978f,
    0.0255f,  0.12555f,  0.505f,
    0.0255f,  0.12555f,  0.077f,
    0.0255f,  0.12555f,  0.137f,
    0.0255f,  0.12555f,  0.042f,
    0.0255f,  0.12555f,  0.345f,
    0.0255f,  0.12555f,  0.734f,
    0.0255f,  0.12555f,  0.174f,
    0.0255f,  0.19555f,  0.848f,
    0.0255f,  0.19555f,  0.040f,
    0.0255f,  0.19555f,  0.338f,
    0.0255f,  0.19555f,  0.120f,
    0.0255f,  0.12555f,  0.362f,
    0.0255f,  0.12555f,  0.457f,
    0.0255f,  0.12555f,  0.371f,
    0.0255f,  0.19555f,  0.879f
};

void	ft_error(SDL_Window *win)
{
	printf("Erreur : %s.\n", SDL_GetError());
	SDL_Quit();
	SDL_DestroyWindow(win);
	exit(-1);
}

int		exit_hook(SDL_Event event)
{
	if (event.window.event == SDL_WINDOWEVENT_CLOSE ||
		(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			return (1);
	return (0);
}

void		ft_mat4print(t_mat4 *mat)
{
	printf("%f, %f, %f, %f\n", mat->x.x, mat->x.y, mat->x.z, mat->x.w);
	printf("%f, %f, %f, %f\n", mat->y.x, mat->y.y, mat->y.z, mat->y.w);
	printf("%f, %f, %f, %f\n", mat->z.x, mat->z.y, mat->z.z, mat->z.w);
	printf("%f, %f, %f, %f\n\n", mat->w.x, mat->w.y, mat->w.z, mat->w.w);
}

t_mat4		ft_mat4multiply(t_mat4 a, t_mat4 b)
{
	t_mat4 ret;

	ret.x.x = (b.x.x * a.x.x) + (b.x.y * a.y.x) + (b.x.z * a.z.x) + (b.x.w * a.w.x);
	ret.x.y = (b.x.x * a.x.y) + (b.x.y * a.y.y) + (b.x.z * a.z.y) + (b.x.w * a.w.y);
	ret.x.z = (b.x.x * a.x.z) + (b.x.y * a.y.z) + (b.x.z * a.z.z) + (b.x.w * a.w.z);
	ret.x.w = (b.x.x * a.x.w) + (b.x.y * a.y.w) + (b.x.z * a.z.w) + (b.x.w * a.w.w);
	ret.y.x = (b.y.x * a.x.x) + (b.y.y * a.y.x) + (b.y.z * a.z.x) + (b.y.w * a.w.x);
	ret.y.y = (b.y.x * a.x.y) + (b.y.y * a.y.y) + (b.y.z * a.z.y) + (b.y.w * a.w.y);
	ret.y.z = (b.y.x * a.x.z) + (b.y.y * a.y.z) + (b.y.z * a.z.z) + (b.y.w * a.w.z);
	ret.y.w = (b.y.x * a.x.w) + (b.y.y * a.y.w) + (b.y.z * a.z.w) + (b.y.w * a.w.w);
	ret.z.x = (b.z.x * a.x.x) + (b.z.y * a.y.x) + (b.z.z * a.z.x) + (b.z.w * a.w.x);
	ret.z.y = (b.z.x * a.x.y) + (b.z.y * a.y.y) + (b.z.z * a.z.y) + (b.z.w * a.w.y);
	ret.z.z = (b.z.x * a.x.z) + (b.z.y * a.y.z) + (b.z.z * a.z.z) + (b.z.w * a.w.z);
	ret.z.w = (b.z.x * a.x.w) + (b.z.y * a.y.w) + (b.z.z * a.z.w) + (b.z.w * a.w.w);
	ret.w.x = (b.w.x * a.x.x) + (b.w.y * a.y.x) + (b.w.z * a.z.x) + (b.w.w * a.w.x);
	ret.w.y = (b.w.x * a.x.y) + (b.w.y * a.y.y) + (b.w.z * a.z.y) + (b.w.w * a.w.y);
	ret.w.z = (b.w.x * a.x.z) + (b.w.y * a.y.z) + (b.w.z * a.z.z) + (b.w.w * a.w.z);
	ret.w.w = (b.w.x * a.x.w) + (b.w.y * a.y.w) + (b.w.z * a.z.w) + (b.w.w * a.w.w);
	return (ret);
}

t_mat4			ft_mat4lookAt2(t_vec3 pos, t_vec3 target, t_vec3 up)
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

void	hook(t_all *all)
{
	int			skip = FALSE;
	SDL_Event	event;

	t_mat4 projection;
	t_mat4 model;
	// t_mat4 view;
	t_mat4 MVP;

		GLenum err = GL_NO_ERROR;

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	all->shader = init_shaders("res/shader/VertexShader.vs", "res/shader/FragmentShader.fs");

	GLuint MatrixID = glGetUniformLocation(all->shader, "MVP");

	projection = ft_mat4perspective(45.0f, 4.0f / 3.0f , 0.1f, 100.0f);
	printf("Perspective:\n"); ft_mat4print(&projection);

	t_mat4 view = {
		{ 0.600000, -0.411597,  0.685994,  0.000000},
    	{ 0.000000,  0.857493,  0.514496,  0.000000},
    	{-0.800000, -0.308697,  0.514496,  0.000000},
    	{-0.000000, -0.000000, -5.830953,  1.000000}
	};

	// view = ft_mat4lookAt2(VEC3(4, 3, 3), VEC3(0, 0, 0), VEC3(0, 1, 0));
	printf("View\n"); ft_mat4print(&view);


	model = ft_mat4identity(1.0);
	printf("Model\n"); ft_mat4print(&model);

	MVP = ft_mat4multiply(ft_mat4multiply(projection, view), model);
	printf("MVP\n"); ft_mat4print(&MVP);

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);


	while (skip == FALSE)
	{
		SDL_WaitEvent(&event);
		skip = exit_hook(event);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(all->shader);
			glUniformMatrix4fv(MatrixID, 1, GL_FALSE, (float *)&MVP);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,NULL);

			glEnableVertexAttribArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
			glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, 0,NULL);

			glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
			glDisableVertexAttribArray(0);
		glUseProgram(0);

		SDL_GL_SwapWindow(all->win);

		while((err = glGetError()) != GL_NO_ERROR) { printf("ERROR %d\n", err); }
	}
}

int		main(int ac, char **av)
{
	t_all	all;
	// t_mat4 a = {
	// 	{1, 3, 2, 6},
	// 	{2, 1, 2, 0},
	// 	{5, 0, 1, 3},
	// 	{1, 2, 3, 2}
	// };

	// t_mat4 b = {
	// 	{2, 3, 2, 0},
	// 	{4, 1, 2, 3},
	// 	{3, 0, 1, 3},
	// 	{1, 3, 0, 2},
	// };

	// t_mat4 tmp = ft_mat4multiply(a, b);
	// ft_mat4print(&tmp);


	init_all(&all);
	hook(&all);

	// Exit
    SDL_GL_DeleteContext(all.glContext);
	SDL_DestroyWindow(all.win);
    SDL_Quit();
	return (1);
}
