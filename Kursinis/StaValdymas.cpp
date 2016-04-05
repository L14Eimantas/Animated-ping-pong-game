#include "StaValdymas.h"

CStaValdymas::CStaValdymas(void):CDuomenysSta()
{
	uz_surface=NULL;
	uz_textute=NULL;
	rect.x=200; rect.y=150; rect.w=250; rect.h=30;
	skaitymas_is_f();
	ivedimasbaigtas=true; //reikalingas kad zinotu kada baigesi ivedimas
}
void CStaValdymas::uzrasyti(SDL_Renderer *renderer)//uzrasyti hight scorus
{
	rect.y=100;
	{
		for(int i=0; i<eile.size(); i++)
		{
			rect.y+=20;
			uz_surface=TTF_RenderText_Solid(sifras,eile.at(i).c_str(),spalva);
			uz_textute=SDL_CreateTextureFromSurface(renderer,uz_surface);
			SDL_RenderCopy(renderer,uz_textute,NULL,&rect);
			sunaikinti();
		}
	}
}

void CStaValdymas::sunaikinti(void)
{
	SDL_DestroyTexture(uz_textute);
	SDL_FreeSurface(uz_surface);
}
void CStaValdymas::korekcija(void)//kad neivestu nepageidaujamu zeklu
{
	int a;
	a=vardas.find("Return");
	if (a!=string::npos) vardas.erase(a,vardas.size());
	a=vardas.find("Backspace");
	if (a!=string::npos) vardas.erase(a,vardas.size());
	a=vardas.find("Right");
	if (a!=string::npos) vardas.erase(a,vardas.size());
	a=vardas.find("Left");
	if (a!=string::npos) vardas.erase(a,vardas.size());
	a=vardas.find("CapsLock");
	if (a!=string::npos) vardas.erase(a,vardas.size());
	a=vardas.find("Keypad");
	if (a!=string::npos) vardas.erase(a,vardas.size());
	a=vardas.find("Escape");
	if (a!=string::npos) vardas.erase(a,vardas.size());
}
bool CStaValdymas::entername(SDL_Renderer *renderer,SDL_Event *mainEvent)//vardo ivedimas
{
	int a; rect.y=150;
	if(mainEvent->type==SDL_KEYDOWN)  vardas+=SDL_GetScancodeName(mainEvent->key.keysym.scancode);
	korekcija();
	a=vardas.find("Space"); //kai ivedamas space ivedimas baigtas
	if(a==string::npos)
	{   uz_surface=TTF_RenderText_Solid(sifras,vardas.c_str(),spalva);
		uz_textute=SDL_CreateTextureFromSurface(renderer,uz_surface);
		SDL_RenderCopy(renderer,uz_textute,NULL,&rect);
	    sunaikinti();
	    return true;
	}
	else {vardas.erase(a,vardas.size()); //kad nebutu space
		SDL_Delay(3000);
		return false;
	};
	return true;
}