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

};

