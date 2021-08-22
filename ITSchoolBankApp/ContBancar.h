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
	float sold;
	TIP_CONT Moneda;
	std::string IBAN;
public:
	ContBancar(std::string Nume, std::string Prenume, std::string iban);
	inline std::string getNume(){ return Nume; }
	inline std::string getPrenume() { return Prenume; }
	inline float getSold() { return sold; }
	inline std::string getIBAN() { return IBAN; }

	inline void setNume(std::string nume) { Nume = nume; }
	inline void setPrenume(std::string prenume) { Prenume = prenume; }
	inline void setSoldValue(float value) { sold = value; }
	inline void setIBAN(std::string Iban) { IBAN = Iban; }


	~ContBancar();

};