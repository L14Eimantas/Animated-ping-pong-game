#pragma once
#include"biblioteka.h"
#include"Vaizdai.h"
class CJudesiai
{
public:
	CJudesiai(SDL_Renderer *p_renderer,SDL_Event *pmainEvent);
	~CJudesiai(void);
	int SCORE1() {return score1;} 
	int SCORE2() {return score2;}
	void idetiscore(int a, int b, int matmuo);
	void bendrasjudejimas(void);
private:
	void kamuoliojudejimas(void);
	void pagrindiniovjudejimas(void);
	void salutiniopjudejimas(void);
	int Getramdomnumber(int high, int low);//kamuolio trajektorija
	void ResetBall(int sk);
	void kamuolioatsimusimai(void);
	bool PointCheck(int x, int y, SDL_Rect rect);
	bool CheckSusilietimas(SDL_Rect r1, SDL_Rect r2);
	SDL_Renderer *renderer;
	SDL_Event *mainEvent;
	CVaizdai *Player1;
	CVaizdai *Player2;
	CVaizdai *Ball;
	float timeCheck;
	int btime; //buves laikas
	int dtime;//dabartinis laikas
	float deltime; //skirtumas laiko;
	int xvel;
	int yvel;
	int score1;
	int score2;
	int t;//pagritinimas
};

