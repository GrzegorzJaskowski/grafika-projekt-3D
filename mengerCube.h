#ifndef MENGER_CUBE_CLASS_H
#define MENGER_CUBE_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<math.h>
#include<iostream>


class mengerCube
{
public:
	int level;
	int current_level;
	float max_coord;
	GLfloat* vertices;
	GLuint* indices;
	int cube_number;

	mengerCube(int level, float max_coord);
	void calculate_vertices();
	void create_cube(float front_z, float back_z, float right_x, float left_x, float top_y, float bottom_y);
	void divide_cube(float x, float y, float z);
};
#endif