/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 22:59:22 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 06:53:56 by y0ja             ###   ########.fr       */
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

void		ft_mat4print(t_mat4 mat)
{
	printf("%f, %f, %f, %f\n", mat.x.x, mat.x.y, mat.x.z, mat.x.w);
	printf("%f, %f, %f, %f\n", mat.y.x, mat.y.y, mat.y.z, mat.y.w);
	printf("%f, %f, %f, %f\n", mat.z.x, mat.z.y, mat.z.z, mat.z.w);
	printf("%f, %f, %f, %f\n\n", mat.w.x, mat.w.y, mat.w.z, mat.w.w);
}

void	hook(t_all *all)
{
	int			skip;
	SDL_Event	event;

	t_mat4 projection;
	t_mat4 modelview;
	t_mat4 view;
	t_mat4 mvp;

	projection = ft_mat4perspective(FOV, (double) RATIO, NEAR, FAR);
	// view = ft_mat4lookAt(VEC3(4, 3, 3), VEC3(0, 0, 0), VEC3(0, 1, 0));

	modelview = ft_mat4identity(1.0);
	// mvp = projection
	// ft_mat4print(projection);
	// ft_mat4print(modelview);

	skip = FALSE;

    printf("Version: %s\n", (const char *)glGetString(GL_VERSION));
    printf("Vendor: %s\n", (const char *)glGetString(GL_VENDOR));
    printf("Renderer: %s\n", (const char *)glGetString(GL_RENDERER));
    printf("GLSL Version: %s\n", (const char *)glGetString(GL_SHADING_LANGUAGE_VERSION));

	static GLfloat vertices[] = {
	   -0.5f, -0.5f, -1.f,
	   0.5f, -0.5f, -1.f,
	   0.0f,  0.5f, -1.f,
	};
	static GLfloat vertices2[] = {
	   -0.5f, -0.5f, 0.f,
	   0.5f, -0.5f, 0.f,
	   0.0f,  0.5f, 0.f,
	};
	float couleurs[] = {1.0, 0.0, 0.0,  0.0, 1.0, 0.0,  0.0, 0.0, 1.0};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// glUseProgram(all->shader);

		// GLenum err = GL_NO_ERROR;
	while (skip == FALSE)
	{
		SDL_WaitEvent(&event);
		skip = exit_hook(event);

		glClear(GL_COLOR_BUFFER_BIT);
		modelview = ft_mat4identity(1.0);


		// DRAW
		glUseProgram(all->shader);
		// glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,(void*)0);
			glEnableVertexAttribArray(0);

			// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, couleurs);
	  //       glEnableVertexAttribArray(1);


			// glUniformMatrix4fv(glGetUniformLocation(all->shader, "modelview"), 1, GL_FALSE, (float *)&modelview);
			// glUniformMatrix4fv(glGetUniformLocation(all->shader, "projection"), 1, GL_FALSE, (float *)&projection);


			glDrawArrays(GL_TRIANGLES, 0, 3);
			// glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(0);
		glUseProgram(0);
		// draw(all, vertices, vertexbuffer);


		SDL_GL_SwapWindow(all->win);

		// while((err = glGetError()) != GL_NO_ERROR)
		// {
		// 	printf("ERROR %d\n", err);
		// }
	}
}

int		main(int ac, char **av)
{
	t_all	all;

	init_all(&all);
	hook(&all);

	// Exit
    SDL_GL_DeleteContext(all.glContext);
	SDL_DestroyWindow(all.win);
    SDL_Quit();
	return (1);
}
