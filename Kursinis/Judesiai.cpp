#include "Judesiai.h"

CJudesiai::CJudesiai(SDL_Renderer *p_renderer, SDL_Event *pmainEvent)
{
	renderer=p_renderer;
	mainEvent=pmainEvent;
	Player1=new CVaizdai(renderer,0,250,40,120,"pic/bird.png");
    Player2=new CVaizdai(renderer,700,250,100,180,"pic/dragon.png");
	Ball=new CVaizdai(renderer,390,300,20,20,"pic/BALL.png");
	srand(time(NULL));
	btime=0; //visi time skirti kamuolio koordinacio atjaujinimo spartai
	timeCheck=0;
	dtime=0;
	deltime=0;
	score1=0; 
	score2=-1;// resetball reikia taip padaryti 
	t=1;
}

CJudesiai::~CJudesiai(void)
{
	
	delete Player1;
	delete Player2;
	delete Ball;
}
void CJudesiai::idetiscore(int a, int b, int matmuo) //netik atstato rezultato bet ir keicia Player2 matmenys
{
	score1=a;
	score2=b;
	delete Player2;
	Player2=new CVaizdai(renderer,700-matmuo,250,100+matmuo,180,"pic/dragon.png");
}
void CJudesiai::bendrasjudejimas() //visu zemiau aprasyti judejimai kartu
{
	Player1->Draw(); //atvaizduojam veikejus
	Player2->Draw();
	Ball->Draw();
	Player1->PlayAnimation(0,3,2,200);//200 greitis
	Player2->PlayAnimation(0,3,1,200);
	kamuoliojudejimas();
	pagrindiniovjudejimas();
	salutiniopjudejimas();
}
void CJudesiai::pagrindiniovjudejimas(void) //paukscio dudejimas
{
	switch(mainEvent->type)
		{
		case SDL_KEYDOWN: 
			switch(mainEvent->key.keysym.sym)
			{
			case	SDLK_DOWN:
				Player1->SetY(Player1->GetY() +2); //nustatom naujas koordinates naudodimasi senesnemis
				t=1;
				break;
			case	SDLK_UP:
				Player1->SetY(Player1->GetY() -2);
				t=1;
				 break;
			case SDLK_LEFT:
				Player1->SetX(Player1->GetX()-1);
				t=1;
				break;
			case SDLK_RIGHT:
				Player1->SetX(Player1->GetX()+1);
				t=1;
				break;
			case SDLK_SPACE: //jei spauciam tarpa kamuoliuko greidis dideja 2x, jei paspauciam valdymo klavisa greitis stabilizuojasi
				t=2;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
}

void CJudesiai::kamuolioatsimusimai(void) 
{
	Ball->SetBallXY(xvel,yvel,t);//nurodom naujas kamuolio koordinates
	if(Ball->GetRect().y < 0) yvel=-yvel; //neleidzia komuoliukui iseiti is virsaus
	if(Ball->GetRect().y+Ball->GetRect().h >600) yvel=-yvel;//is apacios
	if (Ball->GetRect().x <0)
	{
		score2+=1; //skaiciuoja priesininko rezultata
		t=1;
		ResetBall(-2);//i kuria puse paleisti kamuolie -2  ar 2 nusako kaire ir desine

	}
	if (Ball->GetRect().x+Ball->GetRect().w >800)
	{
		score1+=1;// skaiciuoja mano rezultata
		t=1;//atstato pradini greiti
		ResetBall(2);
	}
}
void CJudesiai::kamuoliojudejimas(void)
{
	btime=dtime;//visa tai reikalinga kad kamuolys judetu nei per greit nei per letai
	dtime=SDL_GetTicks(); 
	deltime=(dtime-btime)/100.0f;
	timeCheck+=deltime;
	if ((timeCheck)>=0.045f) //per kiek milisekunciu atnaujinti vaizda
	{
	kamuolioatsimusimai();
	if(CheckSusilietimas(Ball->GetRect(),Player1->GetRect())==true) xvel*=-1;
	if(CheckSusilietimas(Ball->GetRect(),Player2->GetRect())==true) xvel*=-1;
	timeCheck=0;
	}
}
void CJudesiai::salutiniopjudejimas(void)//player2 judejimas pagal kamuolio judejima
{
	if(Player2->GetRect().y+0.5*Player2->GetRect().h> Ball->GetRect().y+0.5*Ball->GetRect().h) Player2->SetY(Player2->GetY()-1) ;
	if(Player2->GetRect().y+0.5*Player2->GetRect().h< Ball->GetRect().y+0.5*Ball->GetRect().h) Player2->SetY(Player2->GetY()+1) ;
}
int CJudesiai:: Getramdomnumber(int high, int low)
{
	return rand() %high +low;//sugeneruoja krypti xy[-2,2]
}
void CJudesiai:: ResetBall(int sk) //kamuolio atstatymas i centra sk ar i kaire ar i desine eis kamuolys
{    
	    SDL_Delay(500);
	    Ball->ResetBallXY(390,280);
	 	xvel=Getramdomnumber(2,sk);//kaip kamuoli paleisti trajektorija
	    yvel=Getramdomnumber(2,sk);
}
bool CJudesiai::PointCheck(int x, int y, SDL_Rect rect) //atmusimu tikrinimas
{
	if(x>rect.x && y>rect.y && x<rect.x+rect.w && y<rect.y+rect.h) return true;
	else return false;
}
bool CJudesiai::CheckSusilietimas(SDL_Rect r1, SDL_Rect r2) //atmusimu tikrinimas
{
	if (PointCheck(r1.x,r1.y,r2)==true ||PointCheck(r1.x+r1.w,r1.y,r2)==true ||PointCheck(r1.x,r1.y+r1.h,r2)==true ||
		PointCheck(r1.x+r1.w,r1.y+r1.h,r2)==true)  return true;
	else return false;
}