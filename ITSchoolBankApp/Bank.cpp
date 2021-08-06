#include "Bank.h"

std::string Bank::createIban()
{
	std::string iban = "123";
	return iban;
}

Bank::Bank()
{

}

Bank::~Bank()
{
	m_ConturiBancare.clear();
}

void Bank::adaugareCont()
{
	system("CLS");
	std::string nume;
	std::cout << "Introduceti numele utilizatorului:\n";
	std::cin >> nume;
	std::string prenume;
	std::cout << "Introduceti prenumele utilizatorului:\n";
	std::cin >> prenume;
	std::string iban = createIban();
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_ConturiBancare.push_back(cont);
	std::cout << "Finalizare operatiune! Apasa tasta aferenta optiunii dorite.\n";
	std::cout << "1 -> pentru creearea unui cont\n";
	std::cout << "2 -> pentru meniul principal\n";
	char optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case'1':
		adaugareCont();
		break;
	default:
		break;
	}
}

void Bank::vizualizareConturi()
{
	std::cout << "Numarul de conturi in banca este: " << m_ConturiBancare.size() << "\n";
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << " " << m_ConturiBancare[i]->getNume() << "\n";
	}
}
