#include "Nivel1.h"



Nivel1::Nivel1()
{
	level = LEVEL1;
	nrZombie = 3;
	RataResource = 5;
	RataZombie= 15;
}

void Nivel1::initializeaza_scena()
{
	initializeaza_element_resursa_planta();
	initializeaza_element_aparitie_sun();
	initializeaza_zona_sun();
	initializeaza_zona_plante();
	initializeaza_patrat();
	initializeaza_camp_batalie();


	for (int i = 0; i < DIM_PATRAT_X; i++)
	{
		for (int j = 0, l = 0; j < DIM_PATRAT_Y; j++)
		{
			zona_scor[i][j] = patrat[i][j];
		}
	}

	for (int i = 1; i < DIM_X - 1; i++)
		for (int j = 1; j < DIM_Y - 1; j++)
			scena[i][j] = ' ';

	//plasare zona_scor
	for (int i = 1, k = 0; i < DIM_PATRAT_X + 1; i++, k++)
		for (int j = 2, l = 0; j < DIM_PATRAT_Y + 2; j++, l++)
			scena[i][j] = zona_scor[k][l];

	//plasare zona_sun
	for (int i = 1, k = 0; i < DIM_ZONA_SUN_X + 1; i++, k++)
		for (int j = 12, l = 0; j < DIM_ZONA_SUN_Y + 12; j++, l++)
			scena[i][j] = zona_sun[k][l];

	//plasare zona plante
	for (int i = 4, k = 0; i < DIM_ZONA_PLANTA_X + 4; i++, k++)
		for (int j = 1, l = 0; j < DIM_ZONA_PLANTA_Y + 1; j++, l++)
			scena[i][j] = zona_plante[k][l];

	//plasare zona camp batalie
	for (int i = 4, k = 0; i < DIM_CAMP_X + 4; i++, k++)
		for (int j = 12, l = 0; j < DIM_CAMP_Y + 12; j++, l++)
			scena[i][j] = zona_camp[k][l];

	//plaseaza zonele in care pot aparea sorii
	for (int i = 0; i < 55; i += 5)
		for (int j = 13, k = 0; j < 4 + 13; j++, k++)
			scena[2][j + i] = sun[k];

	//plaseaza zonele in care pot aparea plantele
	for (int p = 0; p < 25; p += 5)
		for (int i = 5, k = 0; i < 3 + 5; i++, k++)
			for (int j = 3, l = 0; j < 3 + 3; j++, l++)
			{
				/*if (p == 0)
					resursa_planta[1][1] = 'P';
				else if (p == 1)
					resursa_planta[1][1] = 'f';
				else
					resursa_planta[1][1] = ' ';*/
				scena[i + p][j] = resursa_planta[k][l];
			}

	scena[6][4] = 'P';
	scena[11][4] = 'f';

	//plaseaza terenul
		for (int p = 0; p < 54; p += DIM_PATRAT_Y)
			for (int i = 5, k = 0; i < DIM_PATRAT_X + 5; i++, k++)
				for (int j = 13, l = 0; j < DIM_PATRAT_Y + 13; j++, l++)
					scena[i][j + p] = zona_scor[k][l];

	for (int j = 0; j < DIM_Y; j++)
		scena[0][j] = scena[DIM_X - 1][j] = CHR_BARA_ORIZONTALA;

	for (int i = 0; i < DIM_X; i++)
		scena[i][0] = scena[i][DIM_Y - 1] = CHR_BARA_VERTICALA;

	scena[0][0] = CHR_STANGA_SUS;
	scena[0][DIM_Y - 1] = CHR_DREAPTA_SUS;
	scena[DIM_X - 1][0] = CHR_STANGA_JOS;
	scena[DIM_X - 1][DIM_Y - 1] = CHR_DREAPTA_JOS;
}


Nivel1::~Nivel1()
{
}
