#include "mengerCube.h"

//dzielenie szescianu na mniejsze szesciany
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

	//warunek ilosci iteracji algorytmu w zaleznosci od obecnej i domyslnej liczby iteracji
	if(current_level < level)
	{
		if (pow(20, current_level) == cube_number)
		{
			current_level++;
			cube_number = 0;
		}

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
//funkcja wyznaczajaca wspolrzedne trojkatow, z ktorych sklada sie szescian
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
	//przepisywanie wspolrzednych do wlasciwej tablicy vertices
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
	//level, czyli ilosc iteracji oraz, przy zalozeniu symetrycznosci wzgledem srodka ukladu, najwieksza
	//bezwzgledna odleglosc srodka ukladu na danej osi sa podawane przez uzytkownika
	//kostka zaczyna od pierwszej iteracji usuwania srodka szescianu
	//cube_number to pomocnicza zmienna do uzupelniania tablicy vertices
	this->level = level;
	this->current_level = 1;
	this->max_coord = max_coord;
	this->cube_number = 0;
	vertices = new GLfloat[(size_t)(pow(20, level) * 396)];
	indices = new GLuint[(size_t)(pow(20, level) * 36)];
	for (int i = 0; i < pow(20, level) * 36; i++)
		indices[i] = i;
}

//funkcja opowiadajaca za uzupelnienie tablicy vertices
void mengerCube::calculate_vertices()
{
	//domyslne ustawienie wszystkich elementow tablicy vertices na 0.0f
	for (int i = 0; i < pow(20, level) * 396; i++)
		vertices[i] = 0.0f;
	//uzupelnienie atrybutu kolorow
	for (int i = 0; i < pow(20, level) *36; i++)
	{
		vertices[3 + 11 * i] = 1.0f;
		vertices[4 + 11 * i] = 1.0f;
		vertices[5 + 11 * i] = 1.0f;
	}
	//uzupelnienie atrybutu tekstur
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
	//uzupelnienie atrybutu normalnych
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