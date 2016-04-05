#pragma once
#include "biblioteka.h"
class CSDL_Instaliacija
{
public:
	CSDL_Instaliacija(int w, int h);
	~CSDL_Instaliacija(void);
	void begin(void); //tarp ju visas atvaisdavimas ir bus
	void end(void);
protected:
	SDL_Window *langas;
	SDL_Renderer *renderer;
	SDL_Event *mainEvent;
};

