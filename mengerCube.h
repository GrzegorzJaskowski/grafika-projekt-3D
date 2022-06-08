#ifndef MENGER_CUBE_CLASS_H
#define MENGER_CUBE_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<math.h>
#include<iostream>


class mengerCube
{
public:
	int stage;
	float maxx;
	float maxy;
	float maxz;
	GLfloat* vertices;
	GLint* indices;

	mengerCube(int stage, float maxx, float maxy, float maxz);
	void calculate_vertices();
	void display_vertices();
	float* create_cube(float front_z, float back_z, float right_x, float left_x, float top_y, float bottom_y);
	void copy_cube(int cube_numer, float* vert);
};

#endif

