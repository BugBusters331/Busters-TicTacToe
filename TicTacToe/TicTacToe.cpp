#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class gameboard
{
public:
    string cells[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
    void display()
    {
        cout << " " << cells[0] << " | " << cells[1] << " | " << cells[2] << "\n-----------\n " << cells[3] << " | " << cells[4] << " | " << cells[5] << "\n-----------\n " << cells[6] << " | " << cells[7] << " | " << cells[8] << "\n";
    }
    void playerturn()
    {
        int playerchoice;
        cout << "choose a cell (1-9): ";
        cin >> playerchoice;
        playerchoice--;
        if (cells[playerchoice] != " ")
        {
            cout << "cell is already taken, try again.\n";
            playerturn();
        }
        else
        {
            cells[playerchoice] = "x";
        }
    }
    void cputurn()
    {
        int cpuchoice = rand() % 9;
        if (cells[cpuchoice] != " ")
        {
            cputurn();
        }
        else
        {
            cout << "CPU choice: " << (cpuchoice + 1) << "\n";
            cells[cpuchoice] = "o";
        }
    }
    bool wincheck()
    {
        if (cells[0] == "x" && cells[1] == "x" && cells[2] == "x") { return true; }
        else if (cells[3] == "x" && cells[4] == "x" && cells[5] == "x") { return true; }
        else if (cells[6] == "x" && cells[7] == "x" && cells[8] == "x") { return true; }
        else if (cells[0] == "x" && cells[3] == "x" && cells[6] == "x") { return true; }
        else if (cells[1] == "x" && cells[4] == "x" && cells[7] == "x") { return true; }
        else if (cells[2] == "x" && cells[5] == "x" && cells[8] == "x") { return true; }
        else if (cells[0] == "x" && cells[4] == "x" && cells[8] == "x") { return true; }
        else if (cells[2] == "x" && cells[4] == "x" && cells[6] == "x") { return true; }
        else { return false; }
    }
    bool losecheck()
    {
        if (cells[0] == "o" && cells[1] == "o" && cells[2] == "o") { return true; }
        else if (cells[3] == "o" && cells[4] == "o" && cells[5] == "o") { return true; }
        else if (cells[6] == "o" && cells[7] == "o" && cells[8] == "o") { return true; }
        else if (cells[0] == "o" && cells[3] == "o" && cells[6] == "o") { return true; }
        else if (cells[1] == "o" && cells[4] == "o" && cells[7] == "o") { return true; }
        else if (cells[2] == "o" && cells[5] == "o" && cells[8] == "o") { return true; }
        else if (cells[0] == "o" && cells[4] == "o" && cells[8] == "o") { return true; }
        else if (cells[2] == "o" && cells[4] == "o" && cells[6] == "o") { return true; }
        else { return false; }
    }
};

void playGame()
{
    srand(time(0));
    gameboard game;
    game.display();
    int turns = 0;
    bool gameover = false;
    while (gameover == false)
    {
        game.playerturn();
        turns++;
        game.display();
        if (game.wincheck() == true)
        {
            gameover = true;
            cout << "\nGame Over, Player Wins!";
            break;
        }
        if (turns >= 9)
        {
            gameover = true;
            cout << "\nGame Over, It's a Tie!";
            break;
        }
        game.cputurn();
        turns++;
        game.display();
        if (game.losecheck() == true)
        {
            gameover = true;
            cout << "\nGame Over, CPU Wins!";
            break;
        }

    }
}

void MainMenu() {

    int choice;

    cout << "---------------------------" << endl;
    cout << "|  Welcome to Tic-Tac-Toe |" << endl;
    cout << "|-------------------------|" << endl;
    cout << "| Please Select 1, 2 or 3 |" << endl;
    cout << "|-------------------------|" << endl;
    cout << "|         1. Play         |" << endl;
    cout << "|      2. User Manual     |" << endl;
    cout << "|         3. Exit         |" << endl;
    cout << "---------------------------" << endl;

    cin >> choice;
    if (choice == 1)
    {
        playGame();
    }

}

void UserManual()
{
cout << "-----------------------------------" << endl;
cout << "| 1: The game is played on a      |" << endl;
cout << "|    3x3 grid.                    |" << endl;
cout << "|---------------------------------|" << endl; 
cout << "| 2: Players take turns placing   |" << endl;
cout << "| their mark (X or O) in an       |" << endl;
cout << "| empty space.                    |" << endl;
cout << "|---------------------------------|" << endl; 
cout << "| 3: The first player to get 3    |" << endl;
cout << "| of their marks in a row,        |" << endl;
cout << "| either horizontally, vertically |" << endl;
cout << "| or diagonally, wins the game.   |" << endl;
cout << "|---------------------------------|" << endl;
cout << "| if all the spaces are filled,   |" << endl;
cout << "| and neither player filled three |" << endl;
cout << "| spaces in a row, then the game  |" << endl;
cout << "| is a draw.                      |" << endl;
cout << "-----------------------------------" << endl; 
}


int main()
{
    MainMenu();
}