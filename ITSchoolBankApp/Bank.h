#pragma once
#include"ContBancar.h"
#include <iostream>
#include <vector>

class Bank
{
	std::vector <ContBancar*> m_ConturiBancare;
	std::string createIban();
public:
	Bank();
	~Bank();
	void adaugareCont();
	void vizualizareConturi();
	void modificareCont();
	TIP_CONT alegeMoneda();
	//sa facem o clasa FileManager cu 2 metode care sa putem citi si sa scriem in CSV
};

