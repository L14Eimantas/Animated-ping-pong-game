#pragma once
#include"biblioteka.h"
#include"SDL_Instaliacija.h"
#include"Vaizdai.h"
#include"Judesiai.h"
#include "SpecialusEfektai.h"
#include "Meniu.h"

class CPagrindine: public CSDL_Instaliacija
{
public:
	CPagrindine(int ilgis, int plotis);
	~CPagrindine(void);
	void ciklas(void);
private:
	void Pradzia(void);
	void kartojimo_atsikratimas(bool atejusi,CVaizdai *piesti);
	void keitimas(void);
	void Pic_keitimas(void);
	void naikinti(void);
	void grazinimas(void);
	void pagalba_iterpimui(void);
	CVaizdai *fonas;
	CVaizdai *gameover;
	CVaizdai *youwin;
	CJudesiai *Judesiai;
	CMeniu *meniu;
	CSpecialusEfektai *rezultatas;
	CSpecialusEfektai *muzika;
	int sco1,sco2,matmuo;
	int a,b;
	string level;
	int lygis;
	bool testi;
	bool meniupra;//pradziai paleisti meniu
	bool pab;//zaidimo pabaiga
	bool win;//laimejom zaidima
	bool iterbuse;//iterpimui pereitu lygiu
};

