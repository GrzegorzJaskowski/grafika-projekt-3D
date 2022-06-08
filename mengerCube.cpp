#include "mengerCube.h"

void mengerCube::create_cube(float right_x, float left_x, float top_y, float bottom_y, float front_z, float back_z, int cube_number)
{
	GLfloat vert[] =
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
	{
		for (int k = 0; k < 3; k++)
		{
			vertices[i * 11 + k + cube_number * 396] = vert[i * 3 + k];
		}
	}
}

mengerCube::mengerCube(int stage, float maxx, float maxy, float maxz)
{
	this->stage = stage;
	this->maxx = maxx;
	this->maxy = maxy;
	this->maxz = maxz;
	vertices = new GLfloat[(size_t)(pow(20, stage) * 396)];
	indices = new GLuint[(size_t)(pow(20, stage) * 36)];
	for (int i = 0; i < pow(20, stage) * 36; i++)
		indices[i] = i;
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

	create_cube(0.6f, 0.2f, 0.6f, 0.2f, 0.6f, 0.2f, 0); //right top front
	create_cube(0.2f, -0.2f, 0.6f, 0.2f, 0.6f, 0.2f, 1); //middle top front
	create_cube(-0.2f, -0.6f, 0.6f, 0.2f, 0.6f, 0.2f, 2); // left top front

	create_cube(0.6f, 0.2f, 0.2f, -0.2f, 0.6f, 0.2f, 3); //right middle front
	create_cube(0.6f, 0.2f, -0.2f, -0.6f, 0.6f, 0.2f, 4); //right bottom front

	create_cube(-0.2f, -0.6f, 0.2f, -0.2f, 0.6f, 0.2f, 5); // left middle front
	create_cube(-0.2f, -0.6f, -0.2f, -0.6f, 0.6f, 0.2f, 6); // left bottom front

	create_cube(0.2f, -0.2f, -0.2f, -0.6f, 0.6f, 0.2f, 7); //middle bottom front


	create_cube(-0.2f, -0.6f, -0.2f, -0.6f, -0.2f, -0.6f, 8); //left bottom back
	create_cube(0.2f, -0.2f, -0.2f, -0.6f, -0.2f, -0.6f, 9); //middle bottom back
	create_cube(0.6f, 0.2f, -0.2f, -0.6f, -0.2f, -0.6f, 10); //right bottom back

	create_cube(-0.2f, -0.6f, 0.2f, -0.2f, -0.2f, -0.6f, 11); //left middle back
	create_cube(-0.2f, -0.6f, 0.6f, 0.2f, -0.2f, -0.6f, 12); //left top back

	create_cube(0.6f, 0.2f, 0.2f, -0.2f, -0.2f, -0.6f, 13); //right middle back
	create_cube(0.6f, 0.2f, 0.6f, 0.2f, -0.2f, -0.6f, 14); //right top back

	create_cube(0.2f, -0.2f, 0.6f, 0.2f, -0.2f, -0.6f, 15); //middle bottom back


	create_cube(0.6f, 0.2f, -0.2f, -0.6f, 0.2f, -0.2f, 16); //right bottom middle
	create_cube(0.6f, 0.2f, 0.6f, 0.2f, 0.2f, -0.2f, 17); //right top middle

	create_cube(-0.2f, -0.6f, -0.2f, -0.6f, 0.2f, -0.2f, 18); //left bottom middle
	create_cube(-0.2f, -0.6f, 0.6f, 0.2f, 0.2f, -0.2f, 19); //left top middle
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