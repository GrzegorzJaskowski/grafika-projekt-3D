#include "mengerCube.h"

GLfloat* mengerCube::create_cube(float front_z, float back_z, float right_x, float left_x, float top_y, float bottom_y)
{
	GLfloat vertices[] = 
	{
		//back
		left_x, bottom_y, back_z,
		right_x, bottom_y, back_z,
		right_x, top_y, back_z,
		right_x, top_y, back_z,
		left_x, top_y, back_z,
		left_x, bottom_y, back_z,
		//front
		left_x, bottom_y, front_z,
		right_x, bottom_y, front_z,
		right_x, top_y, front_z,
		right_x, top_y, front_z,
		left_x, top_y, front_z,
		left_x, bottom_y, front_z,
		//left
		left_x, top_y, front_z,
		left_x, top_y, back_z,
		left_x, bottom_y, back_z,
		left_x, bottom_y, back_z,
		left_x, bottom_y, front_z,
		left_x, top_y, front_z,
		//right
		right_x, top_y, front_z,
		right_x, top_y, back_z,
		right_x, bottom_y, back_z,
		right_x, bottom_y, back_z,
		right_x, bottom_y, front_z,
		right_x, top_y, front_z,
		//bottom
		left_x, bottom_y, back_z,
		right_x, bottom_y, back_z,
		right_x, bottom_y, front_z,
		right_x, bottom_y, front_z,
		left_x, bottom_y, front_z,
		left_x, bottom_y, back_z,
		//top
		left_x, top_y, back_z,
		right_x, top_y, back_z,
		right_x, top_y, front_z,
		right_x, top_y, front_z,
		left_x, top_y, front_z,
		left_x, top_y, back_z
	};
	for (int i = 0; i < 36; i++)
		std::cout << vertices[0 + 3 * i] << ",   " << vertices[1 + 3 * i] << ",   " << vertices[2 + 3 * i] << std::endl;
	return vertices;
}


void mengerCube::copy_cube(int cube_numer, float* vert)
{
	for (int i = 0; i < 36; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			vertices[i * 11 + k + cube_numer * 396] = vert[i * 3 + k];
		}
	}
	
}


mengerCube::mengerCube(int stage, float maxx, float maxy, float maxz)
{
	this->stage = stage;
	this->maxx = maxx;
	this->maxy = maxy;
	this->maxz = maxz;
	vertices = new GLfloat[pow(20, stage) * 396];
	indices = new GLint[pow(20, stage) * 36];
	for (int i = 0; i < pow(20, stage); i++)
		for(int j = 0; j < 36; j++)
			indices[36*i + j] = j;
}


void mengerCube::calculate_vertices()
{
	
	for (int i = 0; i < pow(20, stage) * 396; i++)
		vertices[i] = 0.0f;

	for (int i = 0; i < pow(20, stage) *36; i++)
	{
		vertices[3 + 11 * i] = 1.0f;
		vertices[4 + 11 * i] = 1.0f;
		vertices[5 + 11 * i] = 1.0f;
	}

	for (int i = 0; i < pow(20, stage); i++)
	{
		for (int j = 0; j < 6; j++)
		{
			vertices[6 + 66 * j + 396 * i] = 0.0f;
			vertices[7 + 66 * j + 396 * i] = 0.0f;

			vertices[17 + 66 * j + 396 * i] = 1.0f;
			vertices[18 + 66 * j + 396 * i] = 0.0f;

			vertices[28 + 66 * j + 396 * i] = 1.0f;
			vertices[29 + 66 * j + 396 * i] = 1.0f;

			vertices[39 + 66 * j + 396 * i] = 1.0f;
			vertices[40 + 66 * j + 396 * i] = 1.0f;

			vertices[50 + 66 * j + 396 * i] = 0.0f;
			vertices[51 + 66 * j + 396 * i] = 1.0f;

			vertices[61 + 66 * j + 396 * i] = 0.0f;
			vertices[62 + 66 * j + 396 * i] = 0.0f;
		}
	}

	for (int i = 0; i < pow(20, stage); i++)
	{
		for (int j = 0; j < 6; j++)
		{
			vertices[10 + j * 11 + 396 * i] = -1.0f;
			vertices[76 + j * 11 + 396 * i] = 1.0f;
			vertices[140 + j * 11 + 396 * i] = -1.0f;
			vertices[206 + j * 11 + 396 * i] = 1.0f;
			vertices[273 + j * 11 + 396 * i] = -1.0f;
			vertices[339 + j * 11 + 396 * i] = 1.0f;
		}
	}

	GLfloat* vert = create_cube(0.6f, 0.2f, 0.6f, 0.2f, 0.6f, 0.2f);
	for (int i = 0; i < 36; i++)
		std::cout << vert[0 + 3 * i] << ",   " << vert[1 + 3 * i] << ",   " << vert[2 + 3 * i] << std::endl;
	copy_cube(0, vert);
}


void mengerCube::display_vertices()
{
	//for (int i = 0; i < 36 * pow(20, stage); i++)
	for (int i = 0; i < 36; i++)
	{
		std::cout << vertices[0 + 11 * i] << ",   " << vertices[1 + 11 * i] << ",   " << vertices[2 + 11 * i] << "\t"
			<< vertices[3 + 11 * i] << ",   " << vertices[4 + 11 * i] << ",   " << vertices[5 + 11 * i] << "\t"
			<< vertices[6 + 11 * i] << ",   " << vertices[7 + 11 * i] << "\t\t"
			<< vertices[8 + 11 * i] << ",   " << vertices[9 + 11 * i] << ",   " << vertices[10 + 11 * i] << std::endl;
	}
}