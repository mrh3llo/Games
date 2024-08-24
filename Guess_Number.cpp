#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

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

void guess_number_v2()
{
    int key[4];
    int num[4];
    int pos_wrong[4];
    int count_wrong = 0;

    //random key
    srand(time(NULL));
    for(int i = 0; i < 4; i++)
        key[i] = rand() % 10;   

    //guess the number
    for(int num_loop = 0; num_loop < 4; num_loop++)
    {
        //Show what key player guess
        if(num_loop == 0)
            cout << "\n---The First number---\n";
        else
            if(num_loop == 1)
                cout << "\n---The Second number---\n";
        else
            if(num_loop == 2)
                cout << "\n---The Third number---\n";
        else
            if(num_loop == 3)
                cout << "\n---The Fourth number---\n";

        //Type guess number loop
        for(int time = 0; time < 2; time++)
        {
            cout << "Your answer is: "; cin >> num[num_loop];

            if(key[num_loop] == num[num_loop])
            {
                cout << "Correct!\n";
                break;
            }
            else
            {
                if(key[num_loop] < num[num_loop])
                {
                    cout << "The key is lower!\n";
                    pos_wrong[count_wrong] = num_loop;
                }
                else
                {
                    cout << "The key is greater!\n";
                    pos_wrong[count_wrong] = num_loop;
                }
            }
        }

        count_wrong++;
    }

    if(count_wrong != 0)
    {
        cout << "You have once more chance!!!\n";

        for(int i = 0; i < count_wrong; i++)
        {
            if(pos_wrong[i] == 0)
                cout << "\n---The First number---\n";
            else
                if(pos_wrong[i] == 1)
                    cout << "\n---The Second number---\n";
            else
                if(pos_wrong[i] == 2)
                    cout << "\n---The Third number---\n";
            else
                if(pos_wrong[i] == 3)
                    cout << "\n---The Fourth number---\n";

            cout << "Your answer is: "; cin >> num[pos_wrong[i]];
        }
    }
    else
    {
        cout << "\n---GAME OVER---\n";

        cout << "\nThe key is: "; key_show(key);
        cout << "\nYour key is: "; key_show(num);

        cout << "\n\n---Congratulations! You've won the game!---\n";

        return;
    }

    cout << "\n---GAME OVER---\n";

    cout << "\nThe key is: "; key_show(key);
    cout << "\nYour key is: "; key_show(num);

    cout << "\n\n---You loseee!!!---\n";

    return;
}

int main()
{
    guess_number_v2();

    return 0;
}
