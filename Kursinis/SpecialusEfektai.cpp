#include "SpecialusEfektai.h"

CSpecialusEfektai::CSpecialusEfektai(string msc)
{
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
	music=Mix_LoadMUS(msc.c_str());
	if (music==NULL) cout<<Mix_GetError();
}
CSpecialusEfektai::CSpecialusEfektai(SDL_Renderer *prenderer)
{
	renderer=prenderer;
    message1=NULL;
	times=TTF_OpenFont("Times_4.ttf",30);
    textColor.r=255; textColor.a=255;textColor.b=255;textColor.g=255;
	spalva.a=255 ;spalva.r= 0;spalva.b=0;spalva.g=255 ;
 	text1=NULL; 
	PlayerscoreRect.x=335;PlayerscoreRect.y=10;PlayerscoreRect.w=40;PlayerscoreRect.h=40; //1-335,,2-430
}

CSpecialusEfektai::~CSpecialusEfektai(void)
{
		Mix_CloseAudio();
}
void CSpecialusEfektai::Level(string uz)
{ 
	SDL_Rect uzr;//uzraso matmenys
	uzr.x =0;	uzr.y =0 ;	uzr.w =100 ;	uzr.h =50 ;
	message1=TTF_RenderText_Solid(times,uz.c_str(),spalva);//kad galeciau atspausdinti esama lygi
	text1=SDL_CreateTextureFromSurface(renderer,message1);//paverciu texture tipu, bes RenderCopy su surface "nedraugauja"
	SDL_RenderCopy(renderer,text1,NULL,&uzr);
	valyti();
}

void CSpecialusEfektai::Score(int score, int x) //kur baigesi 2 ten varzovo duomenys
{
	PlayerscoreRect.x=x;
	stringstream sco1;
	sco1<<score;
    message1=TTF_RenderText_Solid(times,sco1.str().c_str(),textColor);//kad galeciau atspausdinti savo rezultata pasiruosimas 
	text1=SDL_CreateTextureFromSurface(renderer,message1);//paverciu texture tipu, nes RenderCopy su surface "nedraugauja"
	SDL_RenderCopy(renderer,text1,NULL,&PlayerscoreRect);//mano rezultato atspausdinimas (jam reikalingas texture tipas )
	valyti();// kad butu saugiai naudojama atmintis

}
void CSpecialusEfektai::valyti(void)
{
	SDL_FreeSurface(message1);
	SDL_DestroyTexture(text1);
	message1=NULL;
	text1=NULL;
}

void CSpecialusEfektai::groti(void)
{
	Mix_PlayMusic(music,-1);
}
void CSpecialusEfektai::trintimuzika(void)
{
	Mix_FreeMusic(music);
}