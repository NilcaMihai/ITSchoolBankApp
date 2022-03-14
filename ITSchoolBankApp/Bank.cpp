#include "Bank.h"
#include <Windows.h>
#include <vector>
#include <time.h>

TIP_CONT Bank::alegeMoneda()
{
	system("CLS");
	std::cout << "Alegeti tipul contului pe care il doriti, apasand tasta aferenta:\n";
	std::cout << "1 - RON\n";
	std::cout << "2 - EURO\n";
	std::cout << "3 - DOLAR\n";
	int optiune;
	std::cin >> optiune;
	switch (optiune)
	{
	case 1:
		return TIP_CONT::CONT_RON;
		break;
	case 2:
		return TIP_CONT::CONT_EURO;
		break;
	case 3:
		return TIP_CONT::CONT_DOLAR;
		break;
	default:
		std::cout << "Optiune invalida!\n";
		Sleep(1500);
		alegeMoneda();
	}
}

std::string Bank::createIban()
{
	std::vector <std::string> conturiIBAN;
	std::string IBAN[6] = {  };

	TIP_CONT Moneda(alegeMoneda());
	switch (Moneda)
	{
	case TIP_CONT::CONT_RON:
		IBAN[0] = "RO";
		break;
	case TIP_CONT::CONT_EURO:
		IBAN[0] = "EURO";
		break;
	case TIP_CONT::CONT_DOLAR:
		IBAN[0] = "USD";
		break;
	}

	IBAN[1] = std::to_string(rand() % 89 + 10);
	IBAN[2] = "ITBK";
	for (int i = 3; i < 6; ++i)
	{
		IBAN[i] = std::to_string(rand() % 8999 + 1000);
	}

	std::string IBANvalid;
	for (int i = 0; i < 6; ++i)
	{
		 IBANvalid += IBAN[i];
	}

	return IBANvalid;
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
	std::cin.ignore();
	system("CLS");

	bool numeValid = false;
	bool prenumeValid = false;
	std::string nume;
	std::string prenume;

	while (numeValid == false)
	{
		std::cout << "Introduceti numele utilizatorului (folositi doar litere din alfabetul latin):\n";
		std::getline(std::cin, nume);
		for (int j = 0; j < nume.length(); ++j)
		{
			if ((nume[j] >= 'A' && nume[j] <= 'Z') || (nume[j] >= 'a' && nume[j] <= 'z') || (nume[j] == ' ' || nume[j] == '-'))
				numeValid = true;
			else
			{
				std::cout << "Numele nu este valid!\n";
				numeValid = false;
				break;
			}
		}
	}

	while (prenumeValid == false)
	{
		std::cout << "Introduceti prenumele utilizatorului (folositi doar litere din alfabetul latin):\n";
		std::getline(std::cin, prenume);
		for (int j = 0; j < prenume.length(); ++j)
		{
			if ((prenume[j] >= 'A' && prenume[j] <= 'Z') || (prenume[j] >= 'a' && prenume[j] <= 'z') || (prenume[j] == ' ' || prenume[j] == '-'))
				prenumeValid = true;
			else
			{
				std::cout << "Prenumele nu este valid!\n";
				prenumeValid = false;
				break;
			}
		}
	}

	std::string iban = createIban();
	float Sold = 0;
	ContBancar* cont = new ContBancar(nume, prenume, iban, Sold);
	m_ConturiBancare.push_back(cont);

	system("CLS");
	std::cout << "Finalizare operatiune! Apasa tasta aferenta optiunii dorite:\n";
	std::cout << "1 -> pentru creearea unui alt cont.\n";
	std::cout << "2 -> pentru meniul principal.\n";

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
	system("CLS");
	std::cout << "Numarul de conturi in banca este: " << m_ConturiBancare.size() << "\n\n";
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << ": " << m_ConturiBancare[i]->getNume() + " " + m_ConturiBancare[i]->getPrenume() << "\n";
		std::cout << "Contul IBAN aferent este: " << m_ConturiBancare[i]->getIBAN() << "\n";
		std::cout << "Soldul disponibil este: " << m_ConturiBancare[i]->getSold() << "\n\n";
	}
	std::cout << "Finalizare operatiune! Apasa tasta aferenta optiunii dorite:\n";
	std::cout << "1 -> pentru creearea unui cont.\n";
	std::cout << "2 -> pentru meniul principal.\n";

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

void Bank::modificareCont()
{
	system("CLS");
	std::cin.ignore();

	//intrebam operatorul ce cont doreste sa modifice
	std::cout << "Introduceti numele de familie:\n";
	std::string nume;
	std::getline(std::cin, nume);
	std::cout << "Introduceti prenumele:\n";
	std::string prenume;
	std::getline(std::cin, prenume);

	ContBancar* temp = nullptr;
	std::vector<ContBancar*>::iterator it;
	for (it = m_ConturiBancare.begin(); it != m_ConturiBancare.end(); it++)
	{
		if (nume == (*it)->getNume() && prenume == (*it)->getPrenume())
		{
			temp = *it;
			break;
		}
	}

	if (temp == nullptr)
	{
		std::cout << "Contul nu a fost gasit!\n";
		std::cout << "Apasa tasta aferenta optiunii dorite:\n";
		std::cout << "1 - Intoarecere la meniul principal.\n";
		std::cout << "2 - Creati un cont nou.\n";
		std::cout << "3 - Cautati un alt cont.\n";
		char optiune;
		std::cin >> optiune;
		switch (optiune)
		{
		case '1':
			std::cout << "Going back";
			break;
		case '2':
			adaugareCont();
			break;
		case '3':
			modificareCont();
			break;
		default:
			break;
		}
	}
	else
	{
		system("CLS");
		std::cout << "Ce modificare doriti sa faceti?\n";
		std::cout << "Apasa tasta aferenta optiunii dorite:\n";
		std::cout << "1 - Modificare nume\n";
		std::cout << "2 - Modificare prenume\n";
		std::cout << "3 - Adaugare numerar\n";
		std::cout << "4 - Retragere numerar\n";
		std::cout << "5 - Stergeti contul indicat.\n";
		std::cout << "6 - Intoarcere la meniul principal.\n";
		char optiune;
		std::cin >> optiune;
		std::string modificare;
		bool modificareValida = false;
		float contCurent = temp->getSold();
		switch (optiune)
		{
		case'1':
			system("CLS");
			std::cin.ignore();
			while (modificareValida == false)
			{
				std::cout << "Introduceti modificarea dorita (folositi doar litere din alfabetul latin):\n";
				std::getline(std::cin, modificare);
				for (int i = 0; i < modificare.length(); ++i)
				{
					if ((modificare[i] >= 'A' && modificare[i] <= 'Z') || (modificare[i] >= 'a' && modificare[i] <= 'z') || (modificare[i] == ' ' || modificare[i] == '-'))
						modificareValida = true;
					else
					{
						std::cout << "Numele nu este valid!\n";
						modificareValida = false;
						break;
					}
				}
			}
			temp->setNume(modificare);
			std::cout << "Operatiune finalizata cu succes!\n";
			Sleep(1500);
			break;
		case'2':
			system("CLS");
			std::cin.ignore();
			while (modificareValida == false)
			{
				std::cout << "Introduceti modificarea dorita (folositi doar litere din alfabetul latin):\n";
				std::getline(std::cin, modificare);
				for (int i = 0; i < modificare.length(); ++i)
				{
					if ((modificare[i] >= 'A' && modificare[i] <= 'Z') || (modificare[i] >= 'a' && modificare[i] <= 'z') || (modificare[i] == ' ' || modificare[i] == '-'))
						modificareValida = true;
					else
					{
						std::cout << "Prenumele nu este valid!\n";
						modificareValida = false;
						break;
					}
				}
			}
			temp->setPrenume(modificare);
			std::cout << "Operatiune finalizata cu succes!\n";
			Sleep(1500);
			break;
		case'3':
			system("CLS");
			float depunere;
			std::cout << "Introduceti suma pe care doriti sa o depuneti in cont:\n";
			std::cin >> depunere;
			temp->setSoldValue(contCurent + depunere);
			std::cout << "Operatiune finalizata cu succes!\n";
			Sleep(1500);
			break;
		case'4':
			system("CLS");
			float retragere;
			std::cout << "Introduceti suma pe care doriti sa o retrageti din cont:\n";
			std::cin >> retragere;
			if (retragere > contCurent)
			{
				std::cout << "Fonduri insuficiente!\n";
				Sleep(1500);
				break;
			}
			else
			{
				temp->setSoldValue(contCurent - retragere);
				std::cout << "Operatiune finalizata cu succes!\n";
				Sleep(1500);
				break;
			}
		case'5':
			system("CLS");
			m_ConturiBancare.erase(it);
			std::cout << "Operatiune finalizata cu succes!\n";
			Sleep(1500);
			break;
		default:
			break;
		}
	}
}