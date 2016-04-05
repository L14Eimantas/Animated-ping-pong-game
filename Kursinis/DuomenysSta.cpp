#include "DuomenysSta.h"
CDuomenysSta::CDuomenysSta(void)
{
	sifras=TTF_OpenFont("Times_4.ttf",25);
	spalva.a=255 ;spalva.r= 250;spalva.b=0;spalva.g=0 ;
	kiekduom=0;
}

void CDuomenysSta::skaitymas_is_f(void)
{
	ifstream os("statistika.txt");
	if (os==NULL) cout<<"klaida sk", exit(0);
	while (!os.eof())
	{
		os>>reiksmes[kiekduom].sk;
		os>>reiksmes[kiekduom].vd;
		if (!os.eof()) kiekduom++;
	}
	os.close();
	surusiuotireiksmes();
	idejimas_i_vector();
}
void CDuomenysSta::surusiuotireiksmes(void)
{
	for (int i=0; i<kiekduom-1; i++)
	{
		for (int j=i; j<kiekduom; j++)
		{
			int min=i;
			if (reiksmes[i].sk<reiksmes[j].sk)
				min=j;
			duomenys tmp=reiksmes[i];
			reiksmes[i]=reiksmes[min];
			reiksmes[min]=tmp;
		}
	}
}
void CDuomenysSta::idejimas_i_vector(void)
{
	string pagalbinis;
	for(int i=0; i<kiekduom; i++) //reikalingas gal ideti mazejimo tvarka pagal rezultata
	{
		pagalbinis=reiksmes[i].vd;
		pagalbinis+="_";
		pagalbinis+=to_string(reiksmes[i].sk);
		eile.push_back(pagalbinis);  
	}
}
void CDuomenysSta::rasymas_i_f(void)//irasau duomenis i faila kai nuspaudziama 4 is meniu
{
    ofstream os("statistika.txt");
	if (kiekduom>12) kiekduom=12;
	for(int i=0; i<kiekduom; i++)
	{
		os<<reiksmes[i].sk<<" "<<reiksmes[i].vd<<endl;
	}
	os.close();
}
void CDuomenysSta::iterpimas_i_reiksmes(long long skai, string zodis) //iterpiu i struktura
{
	eile.clear();
	reiksmes[kiekduom].sk=skai;
	reiksmes[kiekduom].vd=zodis;
	kiekduom++;
	surusiuotireiksmes();
	idejimas_i_vector();
}