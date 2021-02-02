#include "Nivel.h"

void Nivel::afiseaza_scena()
{
	for (int i = 0; i < DIM_X; i++)
	{
		for (int j = 0; j < DIM_Y; j++)
			cout << scena[i][j];
		cout << endl;
	}
}

void Nivel::initializeaza_element_aparitie_sun()
{
	sun[0] = '(';
	sun[1] = ' ';
	sun[2] = ' ';
	sun[3] = ')';
}

void Nivel::initializeaza_element_resursa_planta()
{
	resursa_planta[0][0] = '/';
	resursa_planta[0][1] = ' ';
	resursa_planta[0][2] = '\\';

	resursa_planta[1][0] = '\\';
	resursa_planta[1][1] = ' ';
	resursa_planta[1][2] = '/';
}

void Nivel::initializeaza_camp_batalie()
{
	for (int i = 1; i < DIM_CAMP_X - 1; i++)
		for (int j = 1; j < DIM_CAMP_Y - 1; j++)
			zona_camp[i][j] = ' ';

	for (int i = 0; i < DIM_CAMP_Y; i++)
		zona_camp[0][i] = zona_camp[DIM_CAMP_X - 1][i] = CHR_LINIE_ORIZONTALA;


	for (int i = 0; i < DIM_CAMP_X; i++)
		zona_camp[i][0] = zona_camp[i][DIM_CAMP_Y - 1] = CHR_LINIE_VERTICALA;


	zona_camp[0][0] = CHR_COLT_STANGA_SUS;
	zona_camp[0][DIM_CAMP_Y - 1] = CHR_COLT_DREAPTA_SUS;
	zona_camp[DIM_CAMP_X - 1][0] = CHR_COLT_STANGA_JOS;
	zona_camp[DIM_CAMP_X - 1][DIM_CAMP_Y - 1] = CHR_COLT_DREAPTA_JOS;
}

void Nivel::initializeaza_zona_plante()
{
	for (int i = 1; i < DIM_ZONA_PLANTA_X - 1; i++)
		for (int j = 1; j < DIM_ZONA_PLANTA_Y - 1; j++)
			zona_plante[i][j] = ' ';

	for (int i = 0; i < DIM_ZONA_PLANTA_Y; i++)
		zona_plante[0][i] = zona_plante[DIM_ZONA_PLANTA_X - 1][i] = CHR_LINIE_ORIZONTALA;


	for (int i = 0; i < DIM_ZONA_PLANTA_X; i++)
		zona_plante[i][0] = zona_plante[i][DIM_ZONA_PLANTA_Y - 1] = CHR_LINIE_VERTICALA;


	zona_plante[0][0] = CHR_COLT_STANGA_SUS;
	zona_plante[0][DIM_ZONA_PLANTA_Y - 1] = CHR_COLT_DREAPTA_SUS;
	zona_plante[DIM_ZONA_PLANTA_X - 1][0] = CHR_COLT_STANGA_JOS;
	zona_plante[DIM_ZONA_PLANTA_X - 1][DIM_ZONA_PLANTA_Y - 1] = CHR_COLT_DREAPTA_JOS;
}

void Nivel::initializeaza_zona_sun()
{

	for (int i = 1; i < DIM_ZONA_SUN_X - 1; i++)
		for (int j = 1; j < DIM_ZONA_SUN_Y - 1; j++)
			zona_sun[i][j] = ' ';

	for (int i = 0; i < DIM_ZONA_SUN_Y; i++)
		zona_sun[0][i] = zona_sun[DIM_ZONA_SUN_X - 1][i] = CHR_LINIE_ORIZONTALA;


	for (int i = 0; i < DIM_ZONA_SUN_X; i++)
		zona_sun[i][0] = zona_sun[i][DIM_ZONA_SUN_Y - 1] = CHR_LINIE_VERTICALA;

	
	zona_sun[0][0] = CHR_COLT_STANGA_SUS;
	zona_sun[0][DIM_ZONA_SUN_Y - 1] = CHR_COLT_DREAPTA_SUS;
	zona_sun[DIM_ZONA_SUN_X - 1][0] = CHR_COLT_STANGA_JOS;
	zona_sun[DIM_ZONA_SUN_X - 1][DIM_ZONA_SUN_Y - 1] = CHR_COLT_DREAPTA_JOS;
}

void Nivel::initializeaza_patrat()
{
	for (int i = 1; i < DIM_PATRAT_X - 1; i++)
		for (int j = 1; j < DIM_PATRAT_Y - 1; j++)
			patrat[i][j] = ' ';


	for (int i = 0; i < DIM_PATRAT_Y; i++)
		patrat[0][i] = patrat[DIM_PATRAT_X - 1][i] = CHR_LINIE_ORIZONTALA;


	for (int i = 0; i < DIM_PATRAT_X; i++)
		patrat[i][0] = patrat[i][DIM_PATRAT_Y - 1] = CHR_LINIE_VERTICALA;


	patrat[0][0] = CHR_COLT_STANGA_SUS;
	patrat[0][DIM_PATRAT_Y - 1] = CHR_COLT_DREAPTA_SUS;
	patrat[DIM_PATRAT_X - 1][0] = CHR_COLT_STANGA_JOS;
	patrat[DIM_PATRAT_X - 1][DIM_PATRAT_Y - 1] = CHR_COLT_DREAPTA_JOS;
}
