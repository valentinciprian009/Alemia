#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#pragma region definitii
#define DIM_X 30
#define DIM_Y 80

#define DIM_PATRAT_X 3
#define DIM_PATRAT_Y 5

#define DIM_ZONA_SUN_X 3
#define DIM_ZONA_SUN_Y 60

#define DIM_ZONA_PLANTA_X 25
#define DIM_ZONA_PLANTA_Y 7

#define DIM_CAMP_X 25
#define DIM_CAMP_Y 60

#define CHR_STANGA_SUS 201
#define CHR_STANGA_JOS 200
#define CHR_DREAPTA_SUS 187
#define CHR_DREAPTA_JOS 188
#define CHR_BARA_VERTICALA 186
#define CHR_BARA_ORIZONTALA 205


#define CHR_LINIE_ORIZONTALA 196
#define CHR_LINIE_VERTICALA 179
#define CHR_COLT_DREAPTA_SUS 191
#define CHR_COLT_DREAPTA_JOS 217
#define CHR_COLT_STANGA_SUS 218
#define CHR_COLT_STANGA_JOS 192

#define CHR_ZOMBIE 35
#define CHR_PLANT 156
#define CHR_BULLET 248
#define CHR_BUCKETHEAD 36
#pragma endregion

typedef enum Level
{
	LEVEL1,LEVEL2,LEVEL3
};
class Nivel
{
protected:

#pragma region variabile
	unsigned char patrat[DIM_PATRAT_X][DIM_PATRAT_Y];
	unsigned char zona_sun[DIM_ZONA_SUN_X][DIM_ZONA_SUN_Y];
	unsigned char zona_plante[DIM_ZONA_PLANTA_X][DIM_ZONA_PLANTA_Y];
	unsigned char zona_scor[DIM_PATRAT_X][DIM_PATRAT_Y];
	unsigned char zona_camp[DIM_CAMP_X][DIM_CAMP_Y];
	unsigned char sun[5], resursa_planta[3][3];
#pragma endregion

#pragma region initializari_zone
	void initializeaza_element_aparitie_sun();
	void initializeaza_element_resursa_planta();
	void initializeaza_camp_batalie();
	void initializeaza_zona_plante();
	void initializeaza_zona_sun();
	void initializeaza_patrat();

#pragma endregion

	Level level;
	int nrZombie;

	
public:
	char scena[DIM_X][DIM_Y];
	int RataResource;
	int RataZombie;

	virtual void initializeaza_scena() = 0;
	virtual void afiseaza_scena();

	Level getLevel() { return level; }
	int getNrZombie() { return nrZombie; }
};

