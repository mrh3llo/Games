#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include "menu.cpp"

using namespace std;

void SetColor(int textColor)
{
    cout << "\033[" << textColor << "m";
}

// Function to reset the console color
void ResetColor() { cout << "\033[0m"; }

//Show the key function
void key_show(int key[])
{
    for(int i = 0; i < 4; i++)
        cout << "|" << key[i] << "|";
}

//compare the key
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

int compare_func(int num1, int num2)
{
    if(num1 == num2)
        return 0;
    else
        //key is lower
        if(num1 < num2)
            return -1;
    else
        //key is higher
        if(num1 > num2)
            return 1;
}

void show_wrong(int compare_val, int num)
{
    if(compare_val == 0)
    {
        SetColor(32);
        cout << "|" << num << "|";
        ResetColor();
    }
    else
        if(compare_val == -1)
        {
            SetColor(31);
            cout << "|" << num << "v|";
            ResetColor();
        }
    else
        if(compare_val == 1)
        {
            SetColor(31);
            cout << "|" << num << "^|";
            ResetColor();
        }
}

void location_num(int num)
{
    if(num == 0)
        cout << "\n---The First number---\n";
    else
        if(num == 1)
            cout << "\n---The Second number---\n";
    else
        if(num == 2)
            cout << "\n---The Third number---\n";
    else
        if(num== 3)
            cout << "\n---The Fourth number---\n";
}

void guess_number_v2()
{
    int key[4];
    int num[4];

    int count_wrong = 0;

    int pos_compare[4];

    //random key
    srand(time(NULL));
    for(int i = 0; i < 4; i++)
        key[i] = rand() % 10;   

    //guess the number
    for(int num_loop = 0; num_loop < 4; num_loop++)
    {
        //Show what key player enter
        location_num(num_loop);

        //Type guess number loop
        for(int time = 0; time < 2; time++)
        {
            cout << "Your answer is: "; cin >> num[num_loop];

            int  compare = compare_func(key[num_loop], num[num_loop]);

            if(compare == 0)
            {
                pos_compare[num_loop] = 0;

                cout << "Correct!!!\n";
                break;
            }
            else
                if(compare == -1)
                {
                    pos_compare[num_loop] = -1;

                    cout << "Key is LOWER!!!\n";
                }
            else
                if(compare == 1)
                {
                    pos_compare[num_loop] = 1;

                    cout << "Key is HIGHER!!!\n";
                }

        }

        count_wrong++;
    }
    //end of type answers input

    //check the answers
    //character 'v' is lower
    //character '^' is greater

    system("cls");
    if(count_wrong != 0)
    {

        cout << "\tYour current key is: ";
        for(int i = 0; i < 4; i++)
            show_wrong(compare_func(key[i], num[i]) , num[i]);

        cout << "\n---You have once more chance!!!---\n";

        for(int i = 0; i < 4; i++)
        {
            //show what key player enter
            location_num(i);

            cout << "Your answer is: "; cin >> num[i];
        }
    }

    system("cls");
    if(check(key, num) == true)
    {
        cout << "\n----GAME OVER ----\n";

        cout << "\nThe key is: "; key_show(key);

        cout << "\nYour key is: ";
        for(int i = 0; i < 4; i++)
        {
            if(compare_func(key[i], num[i]) == 0)
                show_wrong(0, num[i]);
            else
                if(compare_func(key[i], num[i]) == -1)
                    show_wrong(-1, num[i]);
            else
                if(compare_func(key[i], num[i]) == 1)
                    show_wrong(1, num[i]);
        }

        cout << "\n---Congratulations!!! You WON!!!---\n";
    }
    else
    {
        cout << "\n----GAME OVER ----\n";

        cout << "\nThe key is: "; key_show(key);

        cout << "\nYour key is: ";
        for(int i = 0; i < 4; i++)
        {
            if(compare_func(key[i], num[i]) == 0)
                show_wrong(0, num[i]);
            else
                if(compare_func(key[i], num[i]) == -1)
                    show_wrong(-1, num[i]);
            else
                if(compare_func(key[i], num[i]) == 1)
                    show_wrong(1, num[i]);
        }

        cout << "\n---You LOSE!!! NOOOOBBBBBB---\n";
    }
}

int main()
{
    menu();
    guess_number_v2();

    return 0;
}
