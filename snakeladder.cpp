#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

using namespace std;

void DrawLine(int n, char li)
{
    for (int i = 0; i < n; i++)
        cout << li;
}

void Board()
{
    system("cls");
    cout << "\n\n\n";

    DrawLine(70, '-');
    cout << "\n\n\t SNAKES POSITIONS ON THE BOARD\n\n";
    DrawLine(70, '-');

    cout << "\n\tFrom 98 to 28";
    cout << "\n\tFrom 95 to 24";
    cout << "\n\tFrom 92 to 51";
    cout << "\n\tFrom 83 to 19";
    cout << "\n\tFrom 73 to 1";
    cout << "\n\tFrom 69 to 33";
    cout << "\n\tFrom 64 to 36";
    cout << "\n\tFrom 59 to 17";
    cout << "\n\tFrom 55 to 7";
    cout << "\n\tFrom 52 to 11";
    cout << "\n\tFrom 48 to 9";
    cout << "\n\tFrom 46 to 5";
    cout << "\n\tFrom 44 to 22\n";


    DrawLine(70, '-');
    cout << "\n\n\t LADDERS POSITIONS ON THE BOARD\n\n";
    DrawLine(70, '-');

    cout << "\n\tFrom 8 to 26";
    cout << "\n\tFrom 21 to 82";
    cout << "\n\tFrom 43 to 77";
    cout << "\n\tFrom 50 to 91";
    cout << "\n\tFrom 62 to 96";
    cout << "\n\tFrom 66 to 87";
    cout << "\n\tFrom 80 to 100\n";
    DrawLine(70, '-');

    cout << endl;
}

void GameScore(string name1, string name2, int p1, int p2)
{
    cout << "\n\n";
    DrawLine(60, '<>');
    cout << "\n\n\tGAME STATUS\n\n";
    DrawLine(60, '<>');

    cout << "\n\n\t===>" << name1 << " is at position " << p1;
    cout << "\n\t===>" << name2 << " is at position " << p2 << endl;

    DrawLine(60, '_');
    cout << endl;
}

void PlayDice(int &Score)
{
    srand(time(0));
    int Dice;
    Dice = (rand() % 6) + 1;
    cout << "\nYou got " << Dice << " Point !! ";
    Score = Score + Dice;
    cout << "Now you are at position " << Score;
    switch (Score)
    {
    case 98:
        Score = 28;
        break;
    case 95:
        Score = 24;
        break;
    case 92:
        Score = 51;
        break;
    case 83:
        Score = 19;
        break;
    case 73:
        Score = 1;
        break;
    case 69:
        Score = 33;
        break;
    case 64:
        Score = 36;
        break;
    case 59:
        Score = 17;
        break;
    case 55:
        Score = 7;
        break;
    case 52:
        Score = 11;
        break;
    case 48:
        Score = 9;
        break;
    case 46:
        Score = 5;
        break;
    case 44:
        Score = 22;
        break;
    case 8:
        Score = 26;
        break;
    case 21:
        Score = 82;
        break;
    case 43:
        Score = 77;
        break;
    case 50:
        Score = 91;
        break;
    case 54:
        Score = 93;
        break;
    case 62:
        Score = 96;
        break;
    case 66:
        Score = 87;
        break;
    case 80:
        Score = 100;
    }
}

int main()
{
    int Player_1 = 0, Player_2 = 0, LastPosition;

    string Player_1_Name, Player_2_Name;

    system("cls");

    int randomize();

    DrawLine(70, '=');

    cout << "\n\n\n\n\t\tSNAKE LADDER GAME\n\n\n\n";

    DrawLine(70, '=');

    cout << "\n\nEnter The Name of Player 1 :";
    getline(cin, Player_1_Name);

    cout << "\n\nEnter The Name of Player 2 :";
    getline(cin, Player_2_Name);

    while (Player_1 <= 100 && Player_2 <= 100)
    {
        Board();
        GameScore(Player_1_Name, Player_2_Name, Player_1, Player_2);

        cout << "\n\n===>" << Player_1_Name << " Now Your Turn >>> Press Any Key To Play";

        getch();

        LastPosition = Player_1;
        PlayDice(Player_1);

        if (Player_1 < LastPosition)
            cout << "\n\aOops!! Snake found !! You are at Postion " << Player_1 << "\n";

        else if (Player_1 > LastPosition + 6)
            cout << "\nGreat!! you got a ladder !! You are at Position " << Player_1;

        if (Player_1 == 100)
        {
            break;
        }
        cout << "\n\n===>" << Player_2_Name << " Now your Turn >> Press Any Key To Play";
        getch();

        LastPosition = Player_2;
        PlayDice(Player_2);

        if (Player_2 < LastPosition)
            cout << "\n\aOops!! Snake found !! You are at Postion " << Player_2 << "\n";
        else if (Player_2 > LastPosition + 6)
            cout << "\nGreat!! you got a ladder !! You are at Position " << Player_2;
        if (Player_2 == 100)
        {
            break;
        }
    }


    system("cls");
    cout << "\n\n\n\n";
    DrawLine(70, '*');
    cout << "\n\n\t\tRESULT\n\n";
    DrawLine(70, '*');
    cout << endl;

    GameScore(Player_1_Name, Player_2_Name, Player_1, Player_2);
    cout << "\n\n\n\n";

    if (Player_1 >= Player_2)
        cout << Player_1_Name << " !! You are the winner of the game\n\n";
    else
        cout << Player_2_Name << " !! You are the winner of the game\n\n";
    DrawLine(70, '*');
    getch();
    
}
