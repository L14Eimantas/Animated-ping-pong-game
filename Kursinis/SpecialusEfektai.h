#pragma once
#include "biblioteka.h"
class CSpecialusEfektai
{
public:
	CSpecialusEfektai(string msc);
	CSpecialusEfektai(SDL_Renderer *prenderer);
	~CSpecialusEfektai(void);
	void groti(void);
	void Score(int score,int x);
	void Level(string uz);
	void trintimuzika(void);
private:
	void valyti(void);
	Mix_Music *music;
	SDL_Renderer *renderer;
	TTF_Font *times;
	SDL_Rect PlayerscoreRect;
	SDL_Color textColor;
	SDL_Color spalva;//lygiu uzrasui
	SDL_Surface *message1;
	SDL_Texture *text1;
};

