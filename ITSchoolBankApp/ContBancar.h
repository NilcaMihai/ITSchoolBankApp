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
	inline std::string getNume(){ return Nume; }
	inline std::string getPrenume() { return Prenume; }
	inline int getSold() { return sold; }
	inline std::string getIBAN() { return IBAN; }
	inline void setSoldValue(int value) { sold = value; }


	~ContBancar();

};