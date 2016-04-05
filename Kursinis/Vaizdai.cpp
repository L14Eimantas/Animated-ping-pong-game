#include "Vaizdai.h"

CVaizdai::CVaizdai(SDL_Renderer *prenderer,int x,int y,int w,int h,string pic)
{
	renderer=prenderer;
	image=NULL;
	image=IMG_LoadTexture(renderer,pic.c_str());
	if(image==NULL) cout<<"Neatsidaro pic \n";
	rect.x=x;rect.y=y;rect.w=w;rect.h=h;
	SDL_QueryTexture(image,NULL,NULL,&img_w,&img_h);//kad zinotume ir nustatytume tikra paveiksleliu dydi
	iskirpimas.x=0;
	iskirpimas.y=0;
	iskirpimas.w=img_w;
	iskirpimas.h=img_h;
	CurrentFrame=0;
	laikas=SDL_GetTicks();
}

CVaizdai::~CVaizdai(void)
{
	SDL_DestroyTexture(this->image);
}

void CVaizdai::PlayAnimation(int BeginFrame, int EndFrame, int Row, int Speed) 
{

	if ((laikas+Speed)<SDL_GetTicks()) //dalynam is 4 nes paveislelis 4X4, kiatip sakant paveikslyli sydaro 16 gabaleliu
	{
	if (CurrentFrame >= EndFrame)  CurrentFrame=BeginFrame; //0 iki 3
     else CurrentFrame++;
	iskirpimas.x=(img_w/4)* CurrentFrame; //paveikslelis kuris man reikalingas
	iskirpimas.y=Row* (img_h/4);
	iskirpimas.w=img_w/4;//nes paveiksleiai 4x4
	iskirpimas.h=img_h/4;
	laikas=SDL_GetTicks();
	}
}
void CVaizdai::Draw(void) //visu vaizdu atvaizdavimas
{
	SDL_RenderCopy(renderer,this->image,&iskirpimas,&rect);
}
void CVaizdai::SetY(int p_y) //priskiriam nauja y koordinate Reikalinga Player1 ir Player2 judejimui
{
	if(rect.y<0) rect.y=0; //neleidziam iseiti is ribu
	else if(rect.y+rect.h>600) rect.y=600-rect.h;
	     else rect.y=p_y;
}
int CVaizdai:: GetY(void)
{
	return rect.y; //grazina y koordinate
}

void CVaizdai::SetX(int p_x) //priskiriam nauja x koordinate Reikalinga Player1 kairen desinem judejimui
{
	if(rect.x<0) rect.x=0; //neleidziam iseiti is ribu
	else if(rect.x+rect.w>250) rect.x=250-rect.w;
	     else rect.x=p_x;
}
int CVaizdai::GetX(void)
{
	return rect.x; //grazina x koordinate kad Player1 vaiksciuotu kairen desinen
}

SDL_Rect CVaizdai ::GetRect()//grazinam ju koordinates
{
	return rect;
}

void CVaizdai::SetBallXY(int px,int py,int t)// Kad keistusi kamuolio kriptis
{
	rect.x+=(px*t);//t greitis 2x arba 1x
	rect.y+=(py*t);
}
void CVaizdai::ResetBallXY(int px,int py)//ATSTATOM kamuolio pradines koardinates ateina is Judesiu klases
{
	rect.x=px;
	rect.y=py;
}
