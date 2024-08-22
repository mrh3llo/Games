#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void guess_number()
{
    int key[4];

    //random key
    srand(time(NULL));
    for(int i = 0; i < 4; i++)
        key[i] = rand() % 10;

    //guess the key algorithm
    int num1, num2, num3, num4;

    cout << "---The first---\n";
    for(int i = 0; i < 2; i++)
    {
        cout << "Guess the first number: "; cin >> num1;

        if(key[0] == num1)
        {
            cout << "The first number is correct!\n";
            break;
        }
        else
            if(key[0] < num1)
                cout << "The first number is lower!\n";
        else
            if(key[0] > num1)
                cout << "The first number is greater!\n";
    }

    cout << "---The second---\n";
    for(int i = 0; i < 2; i++)
    {
        cout << "Guess the second number: "; cin >> num2;
        if(key[1] == num2)
        {
            cout << "The second number is correct!\n";
            break;
        }
        else
            if(key[1] < num2)
                cout << "The second number is lower!\n";
        else
            if(key[1] > num2)
                cout << "The second number is greater!\n";
    }

    cout << "---The third---\n";
    for(int i = 0; i < 2; i++)
    {
        cout << "Guess the thirt number: "; cin >> num3;
        if(key[2] == num3)
        {
            cout << "The thirt number is correct!\n";
            break;
        }
        else
            if(key[2] < num3)
                cout << "The thirt number is lower!\n";
        else
            if(key[2] > num3)
                cout << "The thirt number is greater!\n";
    }

    cout << "---The fourth---\n";
    for(int i = 0; i < 2; i++)
    {
        cout << "Guess the fourt number: "; cin >> num4;
        if(key[3] == num4)
        {
            cout << "The fourth number is correct!\n";
            break;
        }
        else
            if(key[3] < num4)
                cout << "The fourth number is lower!\n";
        else
            if(key[3] > num4)
                cout << "The fourth number is greater!\n";
    }

    cout << "--------------------------------";
    cout << "You have the last chance to guess the key!\n";
    cout << "Guess the first number: "; cin >> num1;
    cout << "Guess the second number: "; cin >> num2;
    cout << "Guess the third number: "; cin >> num3;
    cout << "Guess the fourth number: "; cin >> num4;

    key[0] == num1 ? cout << "The first is correct!\n" : cout << "The first is incorrect!\n";
    key[1] == num2 ? cout << "The second is correct!\n" : cout << "The second is incorrect!\n";
    key[2] == num3 ? cout << "The third is correct!\n" : cout << "The third is incorrect!\n";
    key[3] == num4 ? cout << "The fourth is correct!\n" : cout << "The fourth is incorrect!\n";

    cout << "The key is: ";
    for(int i = 0; i < 4; i++)
        cout << key[i] << " ";
}

int main()
{
    guess_number();

    return 0;
}