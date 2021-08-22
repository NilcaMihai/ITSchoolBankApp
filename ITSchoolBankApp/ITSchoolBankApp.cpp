#include <iostream>
#include "Bank.h"
#include <windows.h>
#include <fstream>

int main()
{
   /* std::ofstream test("BazeDeDate.csv");
    test << "Test\n";
    test << "1\n";
    test << "2\n";
    test.close();

    std::ifstream testCitire("BazeDeDate.csv");
    if (!testCitire.is_open())
    {
        std::cout << "Fisierul nu poate fi deschis!\n";
    }
    if (testCitire.good())
    {
        std::string line;
        while (std::getline(testCitire, line))
        {
            std::cout << line << "\n";
        }
    }
    testCitire.close();*/

    Bank* itSchoolBank = new Bank();

    std::string userOK = "Administrator";
    std::string parolaOK = "Banca";
    
    std::cout << "Buna ziua!\n";
    bool acces = false;
    for (int i = 2; i >= 0; --i)
    {
        std::cout << "Va rugam introduceti userul: \n";
        std::string user;
        std::cin >> user;
        system("CLS");
        std::cout << "Va rugam introduceti parola:\n";
        std::string parola;
        std::cin >> parola;
        system("CLS");
        if (user == userOK && parola == parolaOK)
        {
            acces = true;
            break;
        }
        else
        {
            if (i > 0)
            {
                std::cout << "Ati introdus userul sau parola gresit!\n";
                std::cout << "Mai aveti " << i << " incercari!\n";
                Sleep(2500);
                system("CLS");
            }
            else
            {
                system("CLS");
                std::cout << "Ati introdus userul sau parola gresit!\n";
                std::cout << "Nu mai aveti incercari!\n";
                std::cout << "La revedere!\n";
                break;
            }
        }
    }
   
    bool isRunning = true;
    if (acces)
    {
        do
        {
            system("CLS");
            std::cout << "Meniu principal\n";
            std::cout << "1 -> Adaugare cont\n";
            std::cout << "2 -> Vizualizare conturi\n";
            std::cout << "3 -> Modificare conturi\n";
            std::cout << "9 -> Exit\n";
            std::cout << "Introduceti optiunea: \n";
            char optiune;
            std::cin >> optiune;
            switch (optiune)
            {
            case '1':
                system("CLS");
                itSchoolBank->adaugareCont();
                break;
            case '2':
                system("CLS");
                itSchoolBank->vizualizareConturi();
                break;
            case '3':
                system("CLS");
                itSchoolBank->modificareCont();
                break;
            case '9':
                system("CLS");
                std::cout << "La revedere!\n";
                isRunning = false;
                break;

            default:
                system("CLS");
                std::cout << "Optiunea nu este valida!\n";
            }
        } while (isRunning);
    }

    delete itSchoolBank;
}