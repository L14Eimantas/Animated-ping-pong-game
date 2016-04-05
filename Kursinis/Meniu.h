#pragma once
#include "Vaizdai.h"
#include "biblioteka.h"
#include "StaValdymas.h"
class CMeniu
{
public:
	CMeniu(SDL_Event *pmainEvent,SDL_Renderer *p_renderer,int pa,int pb);
	bool paspaudimas(void);
	void mygtukas(void);
	bool isejimas(void){return testi;}; //jei paspaudzia 4 kad iseitu is programos
	~CMeniu(void);
	bool atstatymas(CVaizdai *piesimas);
	void iterpti(int sk){uzrasaiekrane->iterpimas_i_reiksmes(sk,vardas);}
private:
	void arbuvopic(void);
	SDL_Event *mainEvent;
	SDL_Renderer *renderer;
	CVaizdai *meniufonas;
	CVaizdai *htpfonas;
	CVaizdai *scorefonas;
	CVaizdai *name;
	CStaValdymas *uzrasaiekrane;
	bool htp;//kaip zaisti zaidima
	bool menu;//jis paroda kada iseiti is menu klases
	bool score;//rodymui rezultato
	bool testi; //ar neuzdaryras zaidimas
	int a;
	int b;
	string vardas;
	bool vardoi;//kada ideti istatistikos klase varda ir lygiu skaiciu
};

