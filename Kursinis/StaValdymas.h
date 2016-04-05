#pragma once
#include"DuomenysSta.h"
class CStaValdymas: public CDuomenysSta
{
public:
	CStaValdymas(void);
	void uzrasyti(SDL_Renderer *renderer);
	~CStaValdymas(void){};
	bool entername(SDL_Renderer *renderer, SDL_Event *mainEvent);
	string getmane(void) {return vardas;} //perduodam varda
	void desvardas(void) {vardas.clear();} //sukaikinan vardas
private:
	void sunaikinti(void);
	void korekcija(void);
	SDL_Surface *uz_surface;//spausdinimui reikalingi duomenys
	SDL_Texture *uz_textute;
	SDL_Rect rect;
	bool ivedimasbaigtas;//kada baigiam ivesti varda, false baigia, dalyvauja meniu klaseje
};

