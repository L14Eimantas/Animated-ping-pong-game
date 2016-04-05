#pragma once
#include"biblioteka.h"
class CDuomenysSta
{
public:
	CDuomenysSta(void);
	virtual~CDuomenysSta(void){};
	void skaitymas_is_f(void);
	void rasymas_i_f(void);
	void iterpimas_i_reiksmes(long long skai, string zodis);
private:
   void idejimas_i_vector(void);
   void surusiuotireiksmes(void);
   int kiekduom;
protected:
	vector<string> eile;//spausdinimo reiksmiu saugykla
	struct duomenys{ //nauja struktuta vardui ir lygiu skaiciui
		long long sk; //long long nes tik jam tinka metodas to_string
		string vd;
	}reiksmes[25];
	TTF_Font *sifras;
	SDL_Color spalva;
	string vardas;
};

