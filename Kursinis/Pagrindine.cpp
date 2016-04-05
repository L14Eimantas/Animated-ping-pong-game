#include "Pagrindine.h"
CPagrindine::CPagrindine(int ilgis, int plotis):CSDL_Instaliacija(ilgis, plotis)
{
	testi=true;win=false;pab=false;meniupra=true;//kad pirma paleisti meniu
	iterbuse=false;
	a=ilgis; b=plotis;matmuo=50;lygis=1;
	fonas=new CVaizdai(renderer,0,0,ilgis,plotis,"pic/sky.bmp"); 
	gameover=new CVaizdai(renderer,0,0,ilgis,plotis,"pic/over.png");  
	youwin=new CVaizdai(renderer,0,0,ilgis,plotis,"pic/win.png"); 
	rezultatas=new CSpecialusEfektai(renderer);
	Judesiai=new CJudesiai(renderer,mainEvent);
	muzika=new CSpecialusEfektai("Sony.mp3");
	meniu=new CMeniu(mainEvent,renderer,a,b);
	level="LEVEL 1"; 
}
void CPagrindine::naikinti(void)
{
	fonas->~CVaizdai();
}
CPagrindine::~CPagrindine(void)
{
	delete Judesiai;
	delete muzika;
	delete meniu;
	delete rezultatas;
	delete gameover;
	delete youwin;
}
void CPagrindine::Pic_keitimas(void) //pakeiciam zaidimo laiko atitinkamai pagal lygi
{	naikinti();
	switch(lygis)
	{case 2:
		fonas=new CVaizdai(renderer,0,0,a,b,"pic/sky2.bmp"); break;
	case 3:
		fonas=new CVaizdai(renderer,0,0,a,b,"pic/rain.bmp");  break;
	case 4:
		fonas=new CVaizdai(renderer,0,0,a,b,"pic/sun.bmp"); break;
	case 5:
		fonas=new CVaizdai(renderer,0,0,a,b,"pic/hell.bmp"); break;
	case 6:
		fonas=new CVaizdai(renderer,0,0,a,b,"pic/hell2.bmp"); 	break;
	default :
		break;}		
}

void CPagrindine::keitimas(void) //reultatu
{    
	if (Judesiai->SCORE1()==11) 
	{   matmuo=lygis*50;//kad sudetingeti zaidimas
		Judesiai->idetiscore(0,0,matmuo);//kai lygis pasikeicia atstatom rezultata i 0
		lygis++;
		stringstream ly;//lygis
	    Pic_keitimas();
		ly<<lygis;
		level.erase(level.size()-1,1);
		level+=ly.str(); }
	rezultatas->Level(level); //esamo lygio atvaizdavimas
	rezultatas->Score(Judesiai->SCORE1(),335); //rez atvaizdavimas
	rezultatas->Score(Judesiai->SCORE2(),430);
	if (Judesiai->SCORE2()==11) 
	{pab=true; naikinti();}
	if (lygis==7)
	{win=true; naikinti();  } 
}

void CPagrindine::ciklas(void) //zis ciklas ir suka visa zaidima
{
	muzika->groti();
	while(testi==true)
	{
       begin();
	   if (meniupra==true && pab==false && win==false)
	    {meniupra=meniu->paspaudimas();
	     testi=meniu->isejimas();
	    }
	   if (meniupra==false && pab==false && win==false) {
	   fonas->Draw();
	   Judesiai->bendrasjudejimas();
	   keitimas();
	   }
	   if (SDL_QUIT==mainEvent->type) testi=false;
	   if (win==true && meniupra==false ) kartojimo_atsikratimas(win,youwin);
	   if (pab==true && meniupra==false ) kartojimo_atsikratimas(pab,gameover);
	   end();
	}
	muzika->trintimuzika();
}
void CPagrindine:: kartojimo_atsikratimas(bool atejusi,CVaizdai *piesti) //nes win ir pab sutrumpetu ir laukiam kada 
{                                                                     //bus paspaustas esc
  atejusi=meniu->atstatymas(piesti); //ar grizti i meniu kai nuspausta esc, kai paspaudziam tada false
  meniupra=!atejusi;
  if (iterbuse==false) pagalba_iterpimui(); //kad zinotume kada iterpti rezultata 1 karta, kad nesidubliuotu
  if (atejusi==false) grazinimas();
}
void CPagrindine::pagalba_iterpimui(void) //pasako kad padar reikia rasyti i struktura
{
   meniu->iterpti(lygis-1);//perguota pereitu lygiu skaiciu, kuris keliaus i statistika
   iterbuse=true;//
}
void CPagrindine::grazinimas(void) //viskas atsktatoma i pradines zaidimo reiksmes
{
  Judesiai->idetiscore(0,0,0);
  lygis=1;
  iterbuse=false;
  pab=false;
  win=false;
  meniupra=true;
  fonas=new CVaizdai(renderer,0,0,a,b,"pic/sky.bmp"); 
  level="LEVEL 1";
}