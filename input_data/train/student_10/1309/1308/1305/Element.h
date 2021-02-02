#pragma once
#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Exceptie.h"
#include "Jucator.h"
#include <chrono>
#include <vector>

using namespace UserInterface;
using namespace std::chrono;

class Element;

struct ElementeJoc
{
	vector <Element*> plante;
	vector <Element*> zombii;
	vector <Element*> proiectile;
	Jucator jucator;
	ElementeJoc() :jucator(Jucator::get_instance()) {};

};


class Element
{
protected:
	char afisaj;
	coords locatie;
	int viata;
	bool verifica_moarte(vector<Element*> &lista);
public:
	virtual void refresh(ElementeJoc& elemente)=0;
	Element();
	Element(coords loc,char ch,int viata) :locatie(loc),afisaj(ch),viata(viata) {};
	coords get_locatie() { return locatie; };
	void scade_viata(int damage) { viata -= damage; };
	char get_afisas() { return afisaj; };
	
	virtual ~Element();
};

class ElementMiscator :public Element
{
protected:
	int rata_miscare;
	steady_clock::time_point ultima_miscare;
	int damage;
public:
	ElementMiscator() {};
	ElementMiscator(coords loc, char ch, int viata, int rata_miscare) :Element(loc, ch, viata),rata_miscare(rata_miscare),ultima_miscare(steady_clock::now()),damage(34) {};
};

class Planta : public Element
{
protected:
	int cost;
public:
	Planta() {};
	Planta(coords loc,char ch,int viata) :Element(loc,ch,viata) {};
};

class Zombi : public ElementMiscator
{
protected:
	void incearca_miscare(ElementeJoc& toate);
	void incearca_atac(Element* saracul);
public:
	Zombi() {};
	void refresh(ElementeJoc& elemente) ;
	Zombi(coords loc,char ch,int viata,int rata) :ElementMiscator(loc,ch,viata,rata) {};
};

class Proiectil : public ElementMiscator
{
	void incearca_miscare(ElementeJoc& toate);
	void incearca_atac(Element* saracul);
public:
	Proiectil() {};
	void refresh(ElementeJoc& elemente) ;
	Proiectil(coords loc) :ElementMiscator(loc,'o',1,1000) {};
};

class FloareaSoarelui :public Planta
{
public:
	void refresh(ElementeJoc& elemente) ;
	FloareaSoarelui() {  };
	FloareaSoarelui(coords loc) :Planta(loc,'F',100){};
};

class Pastaie :public Planta
{
	steady_clock::time_point proiectil;
	void trage(ElementeJoc& elemente);
public:
	void refresh(ElementeJoc& elemente) ;
	Pastaie() {  };
	Pastaie(coords loc) :Planta(loc,'P',100), proiectil(steady_clock::now()) {};
};


class PastaieInghetata :public Planta
{
	steady_clock::time_point proiectil;
public:
	void refresh(ElementeJoc& elemente) {};
	PastaieInghetata() {  };
	PastaieInghetata(coords loc) :Planta(loc,'I',100),proiectil(steady_clock::now()) {};
};

class Nuca :public Planta
{
public:
	void refresh(ElementeJoc& elemente) {};
	Nuca() {  };
	Nuca(coords loc) :Planta(loc,'N',100) {};
};

class Cireasa :public Planta
{
public:
	void refresh(ElementeJoc& elemente) {};
	Cireasa() {  };
	Cireasa(coords loc) :Planta(loc,'C',100) {};
};


class ZombiNormal :public Zombi
{
public:
	ZombiNormal() {};
	ZombiNormal(coords locatie) :Zombi(locatie, 'Z', 100, 2000) {};
};

class ZombiGaleata :public Zombi
{
public:

	ZombiGaleata() {};
	ZombiGaleata(coords locatie) :Zombi(locatie, 'G', 400, 2000) {};
};