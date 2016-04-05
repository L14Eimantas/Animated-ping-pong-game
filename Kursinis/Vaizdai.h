#pragma once
#include"biblioteka.h"
class CVaizdai
{
public:
	CVaizdai(SDL_Renderer *prenderer,int x,int y,int w,int h,string pic);
	~CVaizdai(void);
	void Draw(void);
	int GetY(void);
	int GetX(void);
	void SetY(int p_y);
	void SetX(int p_x);
	SDL_Rect GetRect();
	void SetBallXY(int px, int py,int t);
	void ResetBallXY(int px,int py);
	void PlayAnimation(int BeginFrame, int EndFrame, int Row, int Speed);
private:
	SDL_Renderer *renderer;
	SDL_Rect rect;
	SDL_Texture *image;
	SDL_Rect iskirpimas;
	int img_w;
	int img_h;
	int CurrentFrame;//eilutes elementui rodyti
	int laikas;
};

