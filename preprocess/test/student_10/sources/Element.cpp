#include "Element.h"



Element::Element()
{
}

bool Element::verifica_moarte(vector<Element*>&lista)
{
	if (viata <= 0)
	{
		for (auto i = lista.begin(); i < lista.end(); i++)
		{
			if (*i == this)
			{
				lista.erase(i);
				return true;
			}
		}
	}
	return false;
}

void FloareaSoarelui::refresh(ElementeJoc& elemente)
{
	verifica_moarte(elemente.plante);
}

void Pastaie::trage(ElementeJoc& elemente)
{
	auto acum = steady_clock::now();
	if (duration_cast<milliseconds>(acum - proiectil).count() > 3000)
	{
		proiectil = acum;
		elemente.proiectile.push_back(new Proiectil(coords(locatie.x+1, locatie.y)));
	}
}

void Zombi::incearca_atac(Element* saracul)
{
	saracul->scade_viata(damage);
}

void Zombi::incearca_miscare(ElementeJoc& elemente)
{
	auto acum = steady_clock::now();
	if (duration_cast<milliseconds>(acum - ultima_miscare).count() > rata_miscare)
	{
		ultima_miscare = acum;
		for (auto i : elemente.plante)
		{
			if (i->get_locatie().y == locatie.y&&i->get_locatie().x == locatie.x - 1)
			{
				incearca_atac(i);
				return;
			}
		}
		locatie.x -= 1;
	}
}

void Proiectil::incearca_atac(Element* saracul)
{
	saracul->scade_viata(damage);
}

void Proiectil::incearca_miscare(ElementeJoc& elemente)
{
	auto acum = steady_clock::now();
	if (duration_cast<milliseconds>(acum - ultima_miscare).count() > rata_miscare)
	{
		ultima_miscare = acum;
		for (auto i : elemente.zombii)
		{
			if (i->get_locatie().y == locatie.y&&i->get_locatie().x == locatie.x)
			{
				incearca_atac(i);
				viata--;
				return;
			}
		}
		locatie.x += 1;
		{
			if (locatie.x >= 11)
				viata--;
		}
		verifica_moarte(elemente.proiectile);
	}
}

void Proiectil::refresh(ElementeJoc& elemente)
{
	
	incearca_miscare(elemente);
}

void Zombi::refresh(ElementeJoc& elemente)
{
	if (verifica_moarte(elemente.zombii))
	{
		elemente.jucator.adauga_scor();
	}

	incearca_miscare(elemente);
}

void Pastaie::refresh(ElementeJoc& elemente)
{
	verifica_moarte(elemente.zombii);
	trage(elemente);
}

Element::~Element()
{
}
