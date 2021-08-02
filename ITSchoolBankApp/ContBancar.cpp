#include "ContBancar.h"

ContBancar::ContBancar(std::string Nume, std::string Prenume, std::string iban)
{
	this->Nume = Nume;
	this->Prenume = Prenume;
	IBAN = iban;
	sold = 0;
	eTipCont = TIP_CONT::CONT_RON;
}
