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
				prenumeValid = false;
				break;
			}
		}
	}

	std::string iban = createIban();
	ContBancar* cont = new ContBancar(nume, prenume, iban);
	m_ConturiBancare.push_back(cont);
	system("CLS");
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

void Bank::vizualizareConturi()
{
	system("CLS");
	std::cout << "Numarul de conturi in banca este: " << m_ConturiBancare.size() << "\n";
	for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		std::cout << "Contul " << i + 1 << ": " << m_ConturiBancare[i]->getNume() + " " + m_ConturiBancare[i]->getPrenume() << "\n";
		std::cout << "Contul IBAN aferent este: " << m_ConturiBancare[i]->getIBAN() << "\n";
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
	//intrebati operatorul ce cont doreste sa modifice
	std::cout << "Introduceti numele de familie:\n";
	std::string nume;
	std::cin >> nume;
	std::cout << "Introduceti prenumele:\n";
	std::string prenume;
	std::cin >> prenume;
	ContBancar* temp = nullptr;
	/*int foundIndex = 0;*/
	/*for (int i = 0; i < m_ConturiBancare.size(); i++)
	{
		if (nume == m_ConturiBancare[i]->getNume() && prenume == m_ConturiBancare[i]->getPrenume())
		{
			temp = m_ConturiBancare[i];
			foundIndex = i;
			break;
		}

	}*/
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
		std::cout << "1 - Intoarecere la meniul principla\n";
		std::cout << "2 - Creati un cont nou\n";
		std::cout << "3 - Cautati un alt cont\n";
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
		//tema:
		std::cout << "Ce modificari vreti sa faceti?\n";
		std::cout << "Apasa tasta aferenta optiunii dorite:\n";
		std::cout << "1 - Modificare nume\n";
		std::cout << "2 - Modificare prenume\n";
		std::cout << "3 - Modificare etc.\n";
		std::cout << "6 - Stergeti contul gasit\n";
		char optiune;
		std::cin >> optiune;
		m_ConturiBancare.erase(it);

	}

	//cautati contul
		//daca exista - intrebat ce modificare doreste
		//daca nu exista - anuntam ca nu exista si dam urm optiuni: return to main / creati un cont / cautati alt cont

}
