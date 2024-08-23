#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void key_show(int key[])
{
    for(int i = 0; i < 4; i++)
        cout << key[i] << " ";
}

bool check(int key[], int num[])
{
    for(int i = 0; i < 4; i++)
    {
        if(key[i] != num[i])
            return false;
        if(i == 3)
            return true;
    }
}

void guess_number()
{
    int key[4];

    //random key
    srand(time(NULL));
    for(int i = 0; i < 4; i++)
        key[i] = rand() % 10;

    //guess the key algorithm
    int num[4];

    cout << "---The first---\n";
    for(int i = 0; i < 2; i++)
    {
        cout << "Guess the first number: "; cin >> num[0];

        if(key[0] == num[0])
        {
            cout << "The first number is correct!\n";
            break;
        }
        else
            if(key[0] < num[0])
                cout << "The first number is lower!\n";
        else
            if(key[0] > num[0])
                cout << "The first number is greater!\n";
    }

    cout << "---The second---\n";
    for(int i = 0; i < 2; i++)
    {
        cout << "Guess the second number: "; cin >> num[1];
        if(key[1] == num[1])
        {
            cout << "The second number is correct!\n";
            break;
        }
        else
            if(key[1] < num[1])
                cout << "The second number is lower!\n";
        else
            if(key[1] > num[1])
                cout << "The second number is greater!\n";
    }

    cout << "---The third---\n";
    for(int i = 0; i < 2; i++)
    {
        cout << "Guess the thirt number: "; cin >> num[2];
        if(key[2] == num[2])
        {
            cout << "The thirt number is correct!\n";
            break;
        }
        else
            if(key[2] < num[2])
                cout << "The thirt number is lower!\n";
        else
            if(key[2] > num[2])
                cout << "The thirt number is greater!\n";
    }

    cout << "---The fourth---\n";
    for(int i = 0; i < 2; i++)
    {
        cout << "Guess the fourt number: "; cin >> num[3];
        if(key[3] == num[3])
        {
            cout << "The fourth number is correct!\n";
            break;
        }
        else
            if(key[3] < num[3])
                cout << "The fourth number is lower!\n";
        else
            if(key[3] > num[3])
                cout << "The fourth number is greater!\n";
    }

    system("cls");

    cout << "\nYour key is: "; key_show(num);
    if(check(key, num) == 1)
    {
        cout << "\n=> The key is: "; key_show(key);

        cout << "\nYou WIN. Good Job!!!";

        return;
    }

    cout << "\n--------------------------------\n";
    cout << "\nYou have the last chance to guess the key!\n";
    cout << "Guess the first number: "; cin >> num[0];
    cout << "Guess the second number: "; cin >> num[1];
    cout << "Guess the third number: "; cin >> num[2];
    cout << "Guess the fourth number: "; cin >> num[3];

    cout << "Your key is: "; key_show(num);
    if(check(key, num) == 1)
    {
        cout << "\nThe key is: "; key_show(key);

        cout << "\nYou WIN. Good Job!!!";

        return;
    }
    else
    {
        cout << "\nThe key is: "; key_show(key);

        cout << "\nYou Lose!!!";

        return;
    }
}

int main()
{
    guess_number();

    return 0;
}