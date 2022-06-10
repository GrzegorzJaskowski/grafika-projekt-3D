#include "mengerCube.h"

//dzielenie sze�cianu na mniejsze sze�ciany
void mengerCube::divide_cube(float x, float y, float z)
{
	float diff = abs(2 * max_coord) / pow(3,current_level);
	create_cube(x, x - diff, y, y - diff, z, z - diff);
	create_cube(x - diff, x - 2 * diff, y, y - diff, z, z - diff);
	create_cube(x - 2 * diff, x-3*diff, y, y - diff, z, z - diff);

	create_cube(x, x - diff, y - diff, y - 2 * diff, z, z - diff);
	create_cube(x, x - diff, y - 2 * diff, y-3*diff, z, z - diff);

	create_cube(x - 2 * diff, x-3*diff, y - diff, y - 2 * diff, z, z - diff);
	create_cube(x - 2 * diff, x - 3 * diff, y - 2 * diff, y - 3 * diff, z, z - diff);

	create_cube(x - diff, x - 2 * diff, y - 2 * diff, y - 3 * diff, z, z - diff);


	create_cube(x - 2 * diff, x - 3 * diff, y - 2 * diff, y - 3 * diff, z - 2 * diff, z - 3 * diff);
	create_cube(x - diff, x - 2 * diff, y - 2 * diff, y - 3 * diff, z - 2 * diff, z - 3 * diff);
	create_cube(x, x - diff, y - 2 * diff, y - 3 * diff, z - 2 * diff, z - 3 * diff);

	create_cube(x - 2 * diff, x - 3 * diff, y - diff, y - 2 * diff, z - 2 * diff, z - 3 * diff);
	create_cube(x - 2 * diff, x - 3 * diff, y, y - diff, z - 2 * diff, z - 3 * diff);

	create_cube(x, x - diff, y - diff, y - 2 * diff, z - 2 * diff, z - 3 * diff);
	create_cube(x, x - diff, y, y - diff, z - 2 * diff, z - 3 * diff);

	create_cube(x - diff, x - 2 * diff, y, y - diff, z - 2 * diff, z - 3 * diff);


	create_cube(x, x - diff, y - 2 * diff, y - 3 * diff, z - diff, z - 2 * diff);
	create_cube(x, x - diff, y, y - diff, z - diff, z - 2 * diff);

	create_cube(x - 2 * diff, x - 3 * diff, y - 2 * diff, y - 3 * diff, z - diff, z - 2 * diff);
	create_cube(x - 2 * diff, x - 3 * diff, y, y - diff, z - diff, z - 2 * diff);

	//warunek ilo�ci iteracji algorytmu w zale�no�ci od obecnej i domy�lnej liczby iteracji
	if(current_level < level)
	{
		if (pow(20, current_level) == cube_number)
		{
			current_level++;
			cube_number = 0;
		}
		std::cout << "cur level = " << current_level << std::endl;

		divide_cube(x, y, z);
		divide_cube(x - diff, y, z);
		divide_cube(x - 2 * diff, y, z);

		divide_cube(x, y - diff, z);
		divide_cube(x, y - 2 * diff, z);

		divide_cube(x - 2 * diff, y - diff, z);
		divide_cube(x - 2 * diff, y - 2 * diff, z);

		divide_cube(x - diff, y - 2 * diff, z);


		divide_cube(x - 2 * diff, y - 2 * diff, z - 2 * diff);
		divide_cube(x - diff, y - 2 * diff, z - 2 * diff);
		divide_cube(x, y - 2 * diff, z - 2 * diff);

		divide_cube(x - 2 * diff, y - diff, z - 2 * diff);
		divide_cube(x - 2 * diff, y, z - 2 * diff);

		divide_cube(x, y - diff, z - 2 * diff);
		divide_cube(x, y, z - 2 * diff);

		divide_cube(x - diff, y, z - 2 * diff);


		divide_cube(x, y - 2 * diff, z - diff);
		divide_cube(x, y, z - diff);

		divide_cube(x - 2 * diff, y - 2 * diff, z - diff);
		divide_cube(x - 2 * diff, y, z - diff);
	}
}
//funkcja wyznaczaj�ca wsp�rz�dne tr�jk�t�w, z kt�rych sk�ada si� sze�cian
void mengerCube::create_cube(float right_x, float left_x, float top_y, float bottom_y, float front_z, float back_z)
{
	//tworzenie lokalnej tablicy
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
	//przepisywanie wsp�rz�dnich do w�a�ciwej tablicy vertices
	for (int i = 0; i < 36; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			vertices[i * 11 + k + cube_number * 396] = vert[i * 3 + k];
		}
	}
	cube_number++;
}

//konstruktor klasy mengerCube
mengerCube::mengerCube(int level, float max_coord)
{
	//level, czyli ilo�� iteracji oraz, przy za�o�eniu symetryczno�ci wzgl�dem �rodka uk�adu, najwi�ksza
	//bezwzgl�dna odleg�o�� �rodka uk�adu na danej osi s� podawane przez u�ytkownika
	//kostka zaczyna od pierwszej iteracji usuwania �rodka sze�cianu
	//cube_number to pomocnicza zmienna do uzupe�niania tablicy vertices
	this->level = level;
	this->current_level = 1;
	this->max_coord = max_coord;
	this->cube_number = 0;
	vertices = new GLfloat[(size_t)(pow(20, level) * 396)];
	indices = new GLuint[(size_t)(pow(20, level) * 36)];
	for (int i = 0; i < pow(20, level) * 36; i++)
		indices[i] = i;
	std::cout << pow(20, level) * 396 / sizeof(float) << std::endl;
	std::cout << pow(20, level) * 36 / sizeof(int);
}

//funkcja opowiadaj�ca za uzupe�nienie tablicy vertices
void mengerCube::calculate_vertices()
{
	//domy�lne ustawienie wszystkich element�w tablicy vertices na 0.0f
	for (int i = 0; i < pow(20, level) * 396; i++)
		vertices[i] = 0.0f;
	//uzupe�nienie atrybutu kolor�w
	for (int i = 0; i < pow(20, level) *36; i++)
	{
		vertices[3 + 11 * i] = 1.0f;
		vertices[4 + 11 * i] = 1.0f;
		vertices[5 + 11 * i] = 1.0f;
	}
	//uzupe�nienie atrybutu tekstur
	for (int i = 0; i < pow(20, level); i++)
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
	//uzupe�nienie atrybutu normalnych
	for (int i = 0; i < pow(20, level); i++)
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

	divide_cube(max_coord, max_coord, max_coord);
}