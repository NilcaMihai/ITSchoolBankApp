#pragma once
#include <string>
enum class TIP_CONT
{
	CONT_RON,
	CONT_EURO,
	CONT_DOLAR
};

class ContBancar
{
private:
	std::string Nume;
	std::string Prenume;
	int sold;
	TIP_CONT eTipCont;
	std::string IBAN;
public:
	ContBancar(std::string Nume, std::string Prenume, std::string iban);
	~ContBancar();

};

