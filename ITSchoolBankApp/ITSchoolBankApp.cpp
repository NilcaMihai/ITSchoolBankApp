#include <iostream>
#include "Bank.h"

int main()
{
    //instantam o banca
    Bank* itSchoolBank = new Bank();
    bool isRunning = true;
    
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


    //chemam pentru testare functia de adaugare cont
   /* itSchoolBank->adaugareCont();
    itSchoolBank->vizualizareConturi();*/

    delete itSchoolBank;
}
//extindeti vizualizare cont similar cu metoda adaugare cont
