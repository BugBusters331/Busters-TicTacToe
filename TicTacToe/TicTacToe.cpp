#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
void playGame();
void MainMenu();
void UserManual();
void PlayerWins();
void CPUWins();
void Tie();
void EndChoice();
// Function Prototypes End

class gameboard
{
public:
    string cells[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
    void display()
    {
		system("cls");
        cout << " " << cells[0] << " | " << cells[1] << " | " << cells[2] << "\n-----------\n " << cells[3] << " | " << cells[4] << " | " << cells[5] << "\n-----------\n " << cells[6] << " | " << cells[7] << " | " << cells[8] << "\n";
    }
    void playerturn()
    {
        int playerchoice = 0;
        cout << "choose a cell (1-9): ";
        cin >> playerchoice;

        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number (1-9).\n";
            playerturn();
        }
        else if (playerchoice < 1 || playerchoice > 9)
        {
            cout << "Number must be between 1 and 9, try again.\n";
            playerturn();
        }
        else if (cells[playerchoice -1] == "x" || cells[playerchoice -1] == "o")
        {
            cout << "cell is already taken, try again.\n";
            playerturn();
        }
        else
        {
            cells[playerchoice -1] = "x";
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
            PlayerWins();
            EndChoice();
            break;
        }
        if (turns >= 9)
        {
            gameover = true;
            Tie();
            EndChoice();
            break;
        }
        game.cputurn();
        turns++;
        game.display();
        if (game.losecheck() == true)
        {
            gameover = true;
            CPUWins();
			EndChoice();
            break;
        }

    }
}

void MainMenu() {


    cout << "---------------------------" << endl;
    cout << "|  Welcome to Tic-Tac-Toe |" << endl;
    cout << "|-------------------------|" << endl;
    cout << "| Please Select 1, 2 or 3 |" << endl;
    cout << "|-------------------------|" << endl;
    cout << "|         1. Play         |" << endl;
    cout << "|      2. User Manual     |" << endl;
    cout << "|         3. Exit         |" << endl;
    cout << "---------------------------" << endl;
    
}

void UserManual() {
cout << "-----------------------------------" << endl;
cout << "| 1: The game is played on a      |" << endl;
cout << "|    3x3 grid.                    |" << endl;
cout << "|---------------------------------|" << endl; 
cout << "| 2: Players take turns placing   |" << endl;
cout << "| their mark (X or O) in an       |" << endl;
cout << "| empty space.                    |" << endl;
cout << "|---------------------------------|" << endl; 
cout << "| 3: To choose a space, select a  |" << endl;
cout << "| number from 1-9, with each      |" << endl;
cout << "| number corresponding to the     |" << endl;
cout << "| spaces as shown below:          |" << endl;
cout << "|            1 | 2 | 3            |" << endl;
cout << "|           -----------           |" << endl;
cout << "|            4 | 5 | 6            |" << endl;
cout << "|           -----------           |" << endl;
cout << "|            7 | 8 | 9            |" << endl;
cout << "|---------------------------------|" << endl;
cout << "| 4: The first player to get 3    |" << endl;
cout << "| of their marks in a row,        |" << endl;
cout << "| either horizontally, vertically |" << endl;
cout << "| or diagonally, wins the game.   |" << endl;
cout << "|---------------------------------|" << endl;
cout << "| 5. If all the spaces are filled,|" << endl;
cout << "| and neither player filled three |" << endl;
cout << "| spaces in a row, then the game  |" << endl;
cout << "| is a draw.                      |" << endl;
cout << "-----------------------------------" << endl; 

}

// temporary place holder for Game Results.
void PlayerWins() {
	cout << "\nPlayer Wins!" << endl;
	cout << "press 1 to return to the main menu..." << endl;
	cout << "press 2 to exit the game..." << endl;
}
void CPUWins() {
	cout << "\nCPU Wins!" << endl;
	cout << "press 1 to return to the main menu..." << endl;
	cout << "press 2 to exit the game..." << endl;
}
void Tie() {
	cout << "\nIt's a Tie!" << endl;
	cout << "press 1 to return to the main menu..." << endl;
	cout << "press 2 to exit the game..." << endl;
}

void EndChoice() {
	int choice;
	while (true) {
		cout << "Enter your choice: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear(); // clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			cout << "Invalid input. Please enter a number (1 or 2)." << endl;
		}
        else if (choice == 1) {
            break;
		}
		else if (choice == 2) {
			cout << "Exiting the game. Goodbye!" << endl;
			exit(0);
		}
		else {
			cout << "Invalid choice. Please select 1 or 2." << endl;
		}
	}
}

int main()
{
    int choice;
    while (true){
		system("cls");
        MainMenu();

		cin >> choice;

		if (cin.fail()) {
			cin.clear(); // clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			cout << "Invalid input. Please enter a number (1, 2, or 3).\nPress Enter to continue..." << endl;
            cin.get();
		}

        if (choice == 1)
        {
            playGame();
        }
        else if (choice == 2)
        {
			system("cls");
            UserManual();
			cout << "Press Enter to return to the main menu..." << endl;
			cin.get();
			cin.ignore();
        }
        else if (choice == 3)
        {
            cout << "Exiting the game. Goodbye!" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }
    }
}