/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 22:59:22 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 02:10:38 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanGL.h"

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

void	draw(GLfloat g_vertex_buffer_data[], GLuint vertexbuffer)
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
	   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	   3,                  // size
	   GL_FLOAT,           // type
	   GL_FALSE,           // normalized?
	   0,                  // stride
	   (void*)0            // array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
}

void	hook(t_all *all)
{
	int			skip;
	SDL_Event	event;

	skip = FALSE;

    printf("Version: %s\n", (const char *)glGetString(GL_VERSION));
    printf("Vendor: %s\n", (const char *)glGetString(GL_VENDOR));
    printf("Renderer: %s\n", (const char *)glGetString(GL_RENDERER));
    printf("GLSL Version: %s\n", (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION));

	// An array of 3 vectors which represents 3 vertices
	static GLfloat g_vertex_buffer_data[] = {
	   -0.5f, -0.5f, 0.0f,
	   0.5f, -0.5f, 0.0f,
	   0.0f,  0.5f, 0.0f,
	};

	// This will identify our vertex buffer
	GLuint vertexbuffer;

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glUseProgram(all->shader);

	while (skip == FALSE)
	{
		SDL_WaitEvent(&event);
		skip = exit_hook(event);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw(g_vertex_buffer_data, vertexbuffer);

		SDL_GL_SwapWindow(all->win);
	}
}

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

t_mat4		ft_mat4identity(double value)
{
	return ((t_mat4) {
		{value, 0.f, 0.f, 0.f},
		{0.f, value, 0.f, 0.f},
		{0.f, 0.f, value, 0.f},
		{0.f, 0.f, 0.f, value}
	});
}

void		ft_mat4print(t_mat4 mat)
{
	printf("%f, %f, %f, %f\n", mat.x.x, mat.x.y, mat.x.z, mat.x.w);
	printf("%f, %f, %f, %f\n", mat.y.x, mat.y.y, mat.y.z, mat.y.w);
	printf("%f, %f, %f, %f\n", mat.z.x, mat.z.y, mat.z.z, mat.z.w);
	printf("%f, %f, %f, %f\n\n", mat.w.x, mat.w.y, mat.w.z, mat.w.w);
}

int		main(int ac, char **av)
{
	t_all all;
	t_mat4 projection;
	t_mat4 modelview;

	projection = ft_mat4perspective(70, (double) WWIN / HWIN, 1.0, 100.0);
	modelview = ft_mat4identity(1.0);
	// ft_mat4print(projection);
	// ft_mat4print(modelview);

	init_all(&all);
	hook(&all);
    SDL_GL_DeleteContext(all.glContext);
	SDL_DestroyWindow(all.win);
    SDL_Quit();
	return (1);
}
