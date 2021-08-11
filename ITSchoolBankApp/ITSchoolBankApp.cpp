#include <iostream>
#include "Bank.h"
#include <windows.h>

int main()
{
    // tema introducem parola si user pt utilzator
    //instantam o banca
    Bank* itSchoolBank = new Bank();
    bool isRunning = true;

    std::string userOK = "Administrator";
    std::string parolaOK = "Banca";
    for (int i = 2; i >= 0; --i)
    {
        std::cout << "Introdu userul:\n";
        std::string user;
        std::cin >> user;
        std::cout << "Introdu parola:\n";
        std::string parola;
        std::cin >> parola;
        if (user == userOK && parola == parolaOK)
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
                    std::cout << "Thank you!";
                    isRunning = false;
                    break;

                default:
                    system("CLS");
                    std::cout << "Optiunea nu este valida!\n";
                }
            } while (isRunning);
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
   


    //chemam pentru testare functia de adaugare cont
   /* itSchoolBank->adaugareCont();
    itSchoolBank->vizualizareConturi();*/

    delete itSchoolBank;
}
//extindeti vizualizare cont similar cu metoda adaugare cont
