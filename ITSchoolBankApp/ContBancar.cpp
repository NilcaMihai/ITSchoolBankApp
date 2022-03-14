#include "ContBancar.h"

ContBancar::ContBancar(std::string Nume, std::string Prenume, std::string iban, float Sold)
{
	this->Nume = Nume;
	this->Prenume = Prenume;
	IBAN = iban;
	this->Sold = Sold;
	TIP_CONT Moneda = TIP_CONT::CONT_RON;
}
