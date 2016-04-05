#include "SDL_Instaliacija.h"

CSDL_Instaliacija::CSDL_Instaliacija(int w, int h)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	langas=NULL;
	TTF_Init();
	langas=SDL_CreateWindow("PING PONG",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,SDL_WINDOW_SHOWN);
	if (langas==NULL) cout<<"BLOGAI SUSIKURE LANGAS \n", exit(0);
	renderer=NULL;
	renderer=SDL_CreateRenderer(langas,-1,SDL_RENDERER_ACCELERATED);
	mainEvent= new SDL_Event;
}
CSDL_Instaliacija::~CSDL_Instaliacija(void)
{
	SDL_DestroyWindow(langas);
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
	SDL_Quit();
}

void CSDL_Instaliacija::begin(void)
{
	SDL_PollEvent(mainEvent);//ekrono pasikrovimui
    SDL_RenderClear(renderer);
}
void CSDL_Instaliacija::end(void)
{
	SDL_RenderPresent(renderer);
}
