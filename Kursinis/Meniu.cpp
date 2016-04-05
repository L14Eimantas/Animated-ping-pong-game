#include "Meniu.h"

CMeniu::CMeniu(SDL_Event *pmainEvent,SDL_Renderer *p_renderer,int pa,int pb)
{
	a=pa; b=pb;//dydziai ekrano
	mainEvent=pmainEvent;
	renderer=p_renderer;
	menu=true; score=false; testi=true; htp=false; vardoi=false;//vardo ivedimas
	uzrasaiekrane=new CStaValdymas();
	meniufonas=new CVaizdai(renderer,0,0,a,b,"picmeniu/menu.bmp");
	scorefonas=new CVaizdai(renderer,0,0,a,b,"picmeniu/sroce.bmp");
	htpfonas=new CVaizdai(renderer,0,0,a,b,"picmeniu/htp.bmp");
	name=new CVaizdai(renderer,0,0,a,b,"picmeniu/name.bmp");

}
void CMeniu::mygtukas(void) //meniu pasirinkimas bool keitimas ir nustatymas 
{   meniufonas->Draw();    //reikalinga kad atvaizduotu vartotojio pasirinkima
	switch(mainEvent->type)
		{//cia menu tik true ir jam taip priskirima
		case SDL_KEYDOWN: 
			switch(mainEvent->key.keysym.sym)
			{
			case SDLK_KP_1:
			    { menu=true; htp=false; score=false; vardoi=true; //nurodam kad ivedinesim varda
				meniufonas->~CVaizdai();
				meniufonas=NULL;}
				break;
			case SDLK_KP_2:
				{  meniufonas->~CVaizdai(); 
				   meniufonas=NULL;
				   score=true;  menu=true; htp=false; vardoi=false;} //nurodom kad ziuresim rezultatus
				break;
			case SDLK_KP_3:
				{  meniufonas->~CVaizdai();
				   meniufonas=NULL;
				   score=false;  menu=true; htp=true; vardoi=false;}//ziuresim kaip zaisti
				break;
			case SDLK_KP_4:
				testi=false,uzrasaiekrane->rasymas_i_f(); //cia reikes yrasyti duomenis i faila
				break;                                   //ir kartu uzdaryti programa
			default:
				break;
			}
	   }
}
bool CMeniu::atstatymas(CVaizdai *piesimas) //sugriztame i meniu is 2 arba 3 parinkties kai nuspaudziame esc
{                                            //ivedimo atveji jis atlieka space funkcija t.y pradeta zaidima
	piesimas->Draw(); //piesiam reikalinga fona
	switch(mainEvent->type)
		{
		case SDL_KEYDOWN: 
			switch(mainEvent->key.keysym.sym)
			{
			case SDLK_ESCAPE://darniausiai gryztam i menu
				  {
					  menu=true; htp=false; score=false; vardoi=false;
					  return false;
				  }
				break;
			}
	} return true; //visada grasina true iskirys kada paspausta esc
}

void CMeniu:: arbuvopic() //atstotom meniu vaizda
{
	if (htp==false && score==false && vardoi==false && meniufonas==NULL)
    meniufonas=new CVaizdai(renderer,0,0,a,b,"picmeniu/menu.bmp");
}

bool CMeniu::paspaudimas() //ziurin kuris buvo paspaustas ir atitinkamai atliekame veiksmas
{                          // ateina is Pagrindines klases ciklo
	arbuvopic();
	if (htp==false && score ==false && vardoi==false) mygtukas();
	if (htp==true && score==false && vardoi==false) atstatymas(htpfonas);
	if (htp==false && score==true && vardoi==false) 
	{
		atstatymas(scorefonas);
		uzrasaiekrane->uzrasyti(renderer);
	}
	if (htp==false && score ==false && vardoi==true)
	{
	     atstatymas(name);
		 if ((vardoi==uzrasaiekrane->entername(renderer,mainEvent))==false) //entername grasina tik true o false kada baigia
	   {    menu=false; //cia pasakome kad reikia paleisti pati zaidima
		    vardas=uzrasaiekrane->getmane();
			uzrasaiekrane->desvardas(); }//kad nebutu jau to vardo kai kita ivedinesim
	}
	return menu;
}
CMeniu::~CMeniu(void)
{
	delete meniufonas;
	delete htpfonas;
	delete scorefonas;
	delete name;
	delete uzrasaiekrane;
}
