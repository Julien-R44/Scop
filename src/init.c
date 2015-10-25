/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:13:31 by y0ja              #+#    #+#             */
/*   Updated: 2015/10/25 06:51:37 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanGL.h"

static void		init_opengl(t_all *all)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	all->win = SDL_CreateWindow(TITLE_WIN, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WWIN, HWIN, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!all->win)
		ft_error(all->win);
	all->glContext = SDL_GL_CreateContext(all->win);
	if (all->glContext == 0)
		ft_error(all->win);

	// TO MOVE BRUH
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
}

static char		*load_file(char *filename)
{
	int		fd;
	int		len;
	char	*data;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	len = lseek(fd, 0, SEEK_END);
	data = (char *)mmap(0, len, PROT_READ, MAP_PRIVATE, fd, 0);
	return (data);
}

static GLuint	init_shaders(char *f_vertex, char *f_fragment)
{
	// Create shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read Vertex Shader
	char *VertexShaderCode;
	VertexShaderCode = load_file(f_vertex);

	// Read Fragment Shader
	char *FragmentShaderCode;
	FragmentShaderCode = load_file(f_fragment);
	printf("segment shader: ------------\n%s\n------------------------\n", FragmentShaderCode);

	GLint Result = GL_FALSE;
	int InfoLogLength = 0;

	// Compile Vertex Shader
	printf("Compiling shader : %s", f_vertex);
	glShaderSource(VertexShaderID, 1, (const char* const*)&VertexShaderCode , NULL);
	glCompileShader(VertexShaderID);
	// free(VertexShaderCode);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		char VertexShaderErrorMessage[InfoLogLength];
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, VertexShaderErrorMessage);
		printf("\n%s\n", VertexShaderErrorMessage);
	}
	else
		printf(" | OK\n");

	// Compile Fragment Shader
	printf("Compiling shader : %s", f_fragment);
	glShaderSource(FragmentShaderID, 1, (const char* const*)&FragmentShaderCode , NULL);
	glCompileShader(FragmentShaderID);
	// free(FragmentShaderCode);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		char FragmentShaderErrorMessage[InfoLogLength];
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, FragmentShaderErrorMessage);
		printf("\n%s\n", FragmentShaderErrorMessage);
	}
	else
		printf(" | OK\n");

	// Link the program
	printf("Linking program...");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
		char ProgramErrorMessage[InfoLogLength];
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, ProgramErrorMessage);
		fprintf(stdout, "%s\n", ProgramErrorMessage);
	}
	else
		printf(" | OK\n");

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
	return (ProgramID);
}

void	init_all(t_all *all)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error(all->win);
	init_opengl(all);
	all->shader = init_shaders("res/shader/VertexShader.vs", "res/shader/FragmentShader.fs");
	glClearColor(0.0, 0.5, 1.0, 1.0);
}
