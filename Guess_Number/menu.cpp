#include <iostream>
#include <windows.h>

using namespace std;

void menu()
{
    int options;

    cout << "\n\tWELLCOME TO MY GAME\n";
    cout << "\t-------------------\n";
    cout << "\tTHIS IS GUESS THE PASSCODE\n\n";

    do
    {
        cout << "\t|=========================|\n";
        cout << "\t|[1]: START NEW GAME      |\n";
        cout << "\t|[2]: EXIT                |\n";
        cout << "\t|=========================|\n";

        cout << "\t=> YOUR OPTIONS IS: "; cin >> options;

        if(options == 1)
        {
            system("cd D:\\Project\\Mini_Games");
            system("Guess_Number.exe");
        }
        else
            if(options == 2)
                break;
    }
    while(true);
}

int main()
{
    menu();

    return 0;
}