#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

char control_key;   // will be use to take input from the keyboard
const int rows = 9; // constant number of rows for grid
const int cols = 9; // constant number of columns for grid
string player1;     // players name will be used throughout the game
string player2;

//______________________________Welcome Module______________________________
void LeftPaddingTillCenter(int text_length);
void WelcomeScreen(string text = "                 Welcome to the BattleShip Game    ", int breakage = 70);
//____________________________________Menu Display_______________________________________
void Menu(int &choice);
//____________________________________Instruction_______________________________________
void DisplayInstruction();
//______________________________Game Logic_______________________________________
void StartGame();
void DisplayGrid(char grid[][cols], int &x, int &y, string name);
void DisplayDoubleGrid(char grid1[][cols], int &x1, int &y1, char grid2[][cols], int &x2, int &y2, int &score1, int &score2);
void GridControl(char grid[][cols], int &x, int &y, string name);
void DoubleGridControl(char grid1[][cols], int &x1, int &y1, char grid2[][cols], int &x2, int &y2, int &score1, int &score2, bool ControleMode);
void ShipPlacement(char grid[][cols], string name);
void ShipBombardment(char grid1[][cols], char grid2[][cols], char temp1[][cols], char temp2[][cols]);
void DisplayScoreBoard(int score1, int score2);

//______________________________________ Main(Driver Function for menu) _________________________________________
int main()
{
    system("cls");
    std::system("Color F0");

    WelcomeScreen();

    int choice = 1;
    while (true)
    {
        std::system("cls");
        std::cout << endl
                  << endl
                  << endl
                  << endl
                  << endl
                  << endl
                  << endl
                  << endl
                  << endl;
        Menu(choice);

        control_key = getch();

        if (control_key == 80) // Down Arrow key
            choice++;
        if (control_key == 72) // up key
            choice--;
        if (control_key == 13)
        {
            if (choice == 1)
            {
                std::system("cls");
                std::cout << endl
                          << endl
                          << endl
                          << endl
                          << endl
                          << endl;
                WelcomeScreen("Get Ready Captain !    ");
                StartGame();
            }
            if (choice == 2)
            {
                std::system("cls");
                DisplayInstruction();
            }
            if (choice == 3)
            {
                std::system("cls");
                WelcomeScreen("GoodBye Captain !");
                Sleep(150);
                std::exit(0);
            }
        }
    }
    std::system("pause");
    return 0;
}

//______________________________Welcome Module______________________________
void LeftPaddingTillCenter(int text_length)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    int screenWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;

    // Calculate the left padding to center the text
    int leftPadding = (screenWidth - static_cast<int>(text_length)) / 2;

    // Print the text with the calculated left padding
    std::cout << std::setw(leftPadding);
}

void WelcomeScreen(string text, int breakage)
{
    int l = text.length();
    std::cout << endl
              << endl
              << endl
              << endl
              << endl
              << endl
              << endl
              << endl
              << endl;
    LeftPaddingTillCenter(l);
    for (int i = 0; i < l; i++)
    {
        std::cout << text[i];
        Sleep(breakage);
    }
    std::cout << endl
              << endl
              << endl
              << endl
              << endl
              << endl
              << endl
              << endl
              << endl;
}

//____________________________________Menu Display_______________________________________
void Menu(int &choice)
{
    if (choice > 3)
        choice = 1;
    else if (choice < 1)
        choice = 3;

    if (choice == 1)
    {
        LeftPaddingTillCenter(12);
        std::cout << "--> 1. Start Game" << endl;
        LeftPaddingTillCenter(6);
        std::cout << "2. Instruction  " << endl;
        LeftPaddingTillCenter(19);
        std::cout << "3. Quit  " << endl;
    }
    else if (choice == 2)
    {
        LeftPaddingTillCenter(12);
        std::cout << "1. Start Game" << endl;
        LeftPaddingTillCenter(6);
        std::cout << "--> 2. Instruction  " << endl;
        LeftPaddingTillCenter(19);
        std::cout << "3. Quit  " << endl;
    }
    else if (choice == 3)
    {
        LeftPaddingTillCenter(12);
        std::cout << "1. Start Game" << endl;
        LeftPaddingTillCenter(6);
        std::cout << "2. Instruction  " << endl;
        LeftPaddingTillCenter(19);
        std::cout << "--> 3. Quit  " << endl;
    }
}

//______________________________________ Instruction _________________________________________
void DisplayInstruction()
{
    std::system("Color F0");
    std::cout << endl
              << setw(85) << "Hi there! Thank you for playing Battleship." << endl
              << endl
              << setw(100) << "This is a fun and simple game and you are guaranteed to have a good time." << endl
              << endl
              << setw(118) << "The rules are pretty simple, first, the player 1 will set it's ships on the board and then player2 do the same." << endl
              << endl
              << setw(120) << "  You need to select the coordinates using the arrow keys and enter key to set and attack ships. E.g :- a3, d9, b1, c5 etc." << endl
              << endl
              << setw(100) << "  Both players will be given 3 boats to set on the board.  " << endl
              << endl
              << setw(85) << "   Every ship is represented by 'S'.   " << endl
              << endl
              << setw(87) << " All of these ships are to be set either in a " << endl
              << endl
              << setw(80) << "horizontal or vertical position." << endl
              << endl
              << setw(91) << "Once you are done, it's time for the ultimate show down!!!" << endl
              << endl
              << setw(102) << " Both the players will each take turns and try to sink each other's ships. " << endl
              << endl
              << setw(89) << "        The first one to sink all 3 ships of other player wins!!!" << endl
              << endl
              << setw(30) << "            The symbol ( M ) represents the fact that you attacked a particular position but missed" << endl
              << endl
              << setw(87) << "thus, disabling you to attack the same position." << endl
              << endl
              << setw(31) << "            On the other hand ( H ) represents the fact that you have hit one of the opponent's ships." << endl
              << endl
              << setw(112) << "  Thats all you need to know. So, press the  any button to return to the previous menu and start a game." << endl
              << endl
              << setw(95) << "Bon Voyage Captain, and may the odds be ever in your favor " << (char)1 << endl;

    std::system("pause");
    return;
}

//_____________________________________Game Logic______________________________________
void StartGame()
{
    system("cls");
    player1 = "";
    player2 = "";
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    LeftPaddingTillCenter(15);
    cout << "Enter the name of the first player : ";
    getline(cin, player1);
    LeftPaddingTillCenter(15);
    cout << "Enter the name of the second player : ";
    getline(cin, player2);

    char grid1[rows][cols] = {
        {'a', '1', '2', '3', '4', '5', '6', '7', '8'},
        {'b', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'c', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'d', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'e', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'f', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'g', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'h', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'i', '-', '-', '-', '-', '-', '-', '-', '-'}};
    char grid2[rows][cols] = {
        {'a', '1', '2', '3', '4', '5', '6', '7', '8'},
        {'b', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'c', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'d', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'e', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'f', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'g', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'h', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'i', '-', '-', '-', '-', '-', '-', '-', '-'}};
    char temp1[rows][cols] = {
        {'a', '1', '2', '3', '4', '5', '6', '7', '8'},
        {'b', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'c', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'d', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'e', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'f', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'g', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'h', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'i', '-', '-', '-', '-', '-', '-', '-', '-'}};
    char temp2[rows][cols] = {
        {'a', '1', '2', '3', '4', '5', '6', '7', '8'},
        {'b', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'c', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'d', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'e', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'f', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'g', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'h', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'i', '-', '-', '-', '-', '-', '-', '-', '-'}};

    std::system("cls");
    WelcomeScreen("      get ready " + player1 + " for placing ships at the grid     (DISCLAIMER: Hide your strategy from " + player2 + ")          ", 5);
    WelcomeScreen("      You have to place Patrol boat of size 2, Submarine of size 3, and Helicarrier of size 4 respectively   ", 50);
    WelcomeScreen("      Good Luck !    ", 65);
    ShipPlacement(grid1, player1);

    std::system("cls");
    WelcomeScreen("      get ready " + player2 + " for placing ships at the grid     (DISCLAIMER: Hide your strategy from " + player1 + ")          ", 5);
    WelcomeScreen("      You have to place Patrol boat of size 2, Submarine of size 3, and Helicarrier of size 4 respectively    ", 50);
    WelcomeScreen("      Good Luck !    ", 65);
    ShipPlacement(grid2, player2);

    ShipBombardment(grid1, grid2, temp1, temp2);
}

void ShipPlacement(char grid[][cols], string name)
{
    const int ships[3]{2, 3, 4}; // const int petrol_boat_size = 2, submarine_size = 3, helicarrier_size = 4  respectively;
    int x = 1, y = 1;            // To recieve the control

    bool repeat = false; // later used for validation of the co-ordinates

    for (int i = 0; i < 3; i++)
    {
        GridControl(grid, x, y, name);

        if ((x + 1) <= 8 && grid[x + 1][y] != 'S')
            grid[x + 1][y] = 'v';
        if ((x - 1) >= 1 && grid[x - 1][y] != 'S')
            grid[x - 1][y] = '^';
        if ((y + 1) <= 8 && grid[x][y + 1] != 'S')
            grid[x][y + 1] = '>';
        if ((y - 1) >= 1 && grid[x][y - 1] != 'S')
            grid[x][y - 1] = '<';

        DisplayGrid(grid, x, y, name); // Displaying grid again after adding the characters

        if (ships[i] == 2)
        {
            LeftPaddingTillCenter(5);
            std::cout << "    Place petrol boat of size 2 " << endl;
        }
        else if (ships[i] == 3)
        {
            LeftPaddingTillCenter(5);
            std::cout << "    Place submarine of size 3 " << endl;
        }
        else if (ships[i] == 4)
        {
            LeftPaddingTillCenter(5);
            std::cout << "    Place helicarrier of size 4 " << endl;
        }

        getch(); // now it is being just use for a pause

        // Erasing the unnecessary things which were added just to navigate the constrol key for ship placement
        if (grid[x + 1][y] == 'v')
            grid[x + 1][y] = '-';
        if (grid[x - 1][y] == '^')
            grid[x - 1][y] = '-';
        if (grid[x][y + 1] == '>')
            grid[x][y + 1] = '-';
        if (grid[x][y - 1] == '<')
            grid[x][y - 1] = '-';
        if (grid[x][y] == 'X')
            grid[x][y] = '-';

        // DisplayGrid(grid, x, y);   just for testing
        // std::cout<<"Sleeping for 2s..."<<endl;
        // Sleep(2000);

        repeat = false;
        // Using GetAsyncKeyState() because getch() is now buffered
        if (GetAsyncKeyState(VK_UP) & 0x8000) // up arrow key
        {
            for (int k = 0; k <= ships[i]; k++)
            {
                if (grid[x - k][y] != '-' || grid[x - k][y] == 'S' || grid[x][y] == 'S')
                {
                    repeat = true;
                    i--;
                    std::cout << endl;
                    LeftPaddingTillCenter(12);
                    std::cout << "Your Ship is breaking the boundries or colliding with other ship! " << endl;
                    LeftPaddingTillCenter(12);
                    std::cout << "Please select the co-ordinates again for this ship." << endl;
                    Sleep(1000);
                    break;
                }
            }
            if (repeat == false)
                for (int j = 0; j < ships[i]; j++)
                {
                    grid[x - j][y] = 'S';
                }
        }
        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) // down arrow key
        {
            for (int k = 0; k <= ships[i]; k++)
            {
                if (grid[x + k][y] != '-' || grid[x + k][y] == 'S' || grid[x][y] == 'S')
                {
                    repeat = true;
                    i--;
                    std::cout << endl;
                    LeftPaddingTillCenter(12);
                    std::cout << "Your Ship is breaking the boundries or colliding with other ship! " << endl;
                    LeftPaddingTillCenter(12);
                    std::cout << "Please select the co-ordinates again for this ship." << endl;
                    Sleep(1000);
                    break;
                }
            }
            if (repeat == false)
                for (int j = 0; j < ships[i]; j++)
                {
                    grid[x + j][y] = 'S';
                }
        }
        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // right arrow key
        {
            for (int k = 0; k <= ships[i]; k++)
            {
                if (grid[x][y + k] != '-' || grid[x][y + k] == 'S' || grid[x][y] == 'S')
                {
                    repeat = true;
                    i--;
                    std::cout << endl;
                    LeftPaddingTillCenter(12);
                    std::cout << "Your Ship is breaking the boundries or colliding with other ship! " << endl;
                    LeftPaddingTillCenter(12);
                    std::cout << "Please select the co-ordinates again for this ship." << endl;
                    Sleep(1000);
                    break;
                }
            }
            if (repeat == false)
                for (int j = 0; j < ships[i]; j++)
                {
                    grid[x][y + j] = 'S';
                }
        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) // left arrow key
        {
            for (int k = 0; k <= ships[i]; k++)
            {
                if (grid[x][y - k] != '-' || grid[x][y - k] == 'S' || grid[x][y] == 'S')
                {
                    repeat = true;
                    i--;
                    std::cout << endl;
                    LeftPaddingTillCenter(12);
                    std::cout << "Your Ship is breaking the boundries or colliding with other ship! " << endl;
                    LeftPaddingTillCenter(12);
                    std::cout << "Please select the co-ordinates again for this ship." << endl;
                    Sleep(1000);
                    break;
                }
            }
            if (repeat == false)
                for (int j = 0; j < ships[i]; j++)
                {
                    grid[x][y - j] = 'S';
                }
        }
    }
    DisplayGrid(grid, x, y, name);
    LeftPaddingTillCenter(12);
    std::cout << "You have placed all the ships " << endl;
    LeftPaddingTillCenter(12);
    std::system("pause");
}
void ShipBombardment(char grid1[][cols], char grid2[][cols], char temp1[][cols], char temp2[][cols])
{
    const int bombs = 9;
    bool ControlMode = 0;
    int x1 = 1, y1 = 1, x2 = 1, y2 = 1, score1 = 0, score2 = 0;

    std::system("cls");
    WelcomeScreen("                   Now the battle will begin!   Both players have 9  bombs                ", 40);

    DisplayDoubleGrid(temp1, x1, y1, temp2, x2, y2, score1, score2);
    std::system("pause");

    for (int i = 0; i < bombs; i++)
    {
        cout << endl
             << "                                  " << player2 << "'s turn to hit the bomb.no : " << i + 1 << " on " << player1 << "'s Grid" << endl;
        std::system("pause");
        ControlMode = 0;
        DoubleGridControl(temp1, x1, y1, temp2, x2, y2, score1, score2, ControlMode);
        if (grid1[x1][y1] == 'S')
        {
            cout << "                        It's a Hit on " << player1 << "'s Ship!" << endl;
            temp1[x1][y1] = 'H';
            score1++;
        }
        else
            cout << "                             It's a Miss " << endl;

        //_________________________________________________________________    

        cout << endl
             << "                                  " << player1 << "'s turn to hit the bomb.no : " << i + 1 << " on " << player2 << "'s Grid" << endl;
        std::system("pause");
        ControlMode = 1;
        DoubleGridControl(temp1, x1, y1, temp2, x2, y2, score1, score2, ControlMode);
        if (grid2[x2][y2] == 'S')
        {
            cout << "                        It's a Hit on " << player2 << "'s Ship!" << endl;
            temp2[x2][y2] = 'H';
            score2++;
        }
        else
            cout << "                             It's a Miss " << endl;
    }
    DisplayDoubleGrid(temp1, x1, y1, temp2, x2, y2, score1, score2);
    cout << endl
         << endl
         << endl;
    cout << "                                     Both Players are out of Bombs !" << endl;
    std::system("pause");
    DisplayScoreBoard(score1, score2);
    return;
}

void GridControl(char grid[][cols], int &x, int &y, string name = "") // x & y use to move the control key and to return the control
{                                                                     // ControlMode = 1 and ControlMode = 0
    bool lock = false;                                                // lock the input co-ordinate

    while (true)
    {
        if (x > 8) // TO keep the control key within the grid
            x = 1;
        if (x < 1)
            x = 8;
        if (y > 8)
            y = 1;
        if (y < 1)
            y = 8;

        DisplayGrid(grid, x, y, name); // x and y are used to display the control

        control_key = getch();

        if (control_key == 27) // escape key
            main();
        if (control_key == 72) // up arrow key
            x--;
        if (control_key == 80) // down arrow key
            x++;
        if (control_key == 77) // right arrow key
            y++;
        if (control_key == 75) // left arrow key
            y--;
        if (control_key == 13) // Enter key
            lock = true;

        if (lock == true)
        {
            if (grid[x][y] != 'S')
                grid[x][y] = 'X';
            lock = false;
            return;
        }
    }
}
void DoubleGridControl(char grid1[][cols], int &x1, int &y1, char grid2[][cols], int &x2, int &y2, int &score1, int &score2, bool ControleMode) // x & y use to move the control key and to return the control
{                                                                                                                                               // ControlMode = 0 for Grid1 and ControlMode = 1 for Grid2
    bool lock1 = false;
    bool lock2 = false; // lock the input co-ordinate

    while (true)
    {
        if (x1 > 8) // TO keep the control key within the grid1
            x1 = 1;
        if (x1 < 1)
            x1 = 8;
        if (y1 > 8)
            y1 = 1;
        if (y1 < 1)
            y1 = 8;

        if (x2 > 8) // TO keep the control key within the grid2
            x2 = 1;
        if (x2 < 1)
            x2 = 8;
        if (y2 > 8)
            y2 = 1;
        if (y2 < 1)
            y2 = 8;

        DisplayDoubleGrid(grid1, x1, y1, grid2, x2, y2, score1, score2); // x1, x2 and y1, y2 are used to display the control

        control_key = getch();

        if (ControleMode == 0)
        {
            if (control_key == 27) // escape key
                main();
            if (control_key == 72) // up arrow key
                x1--;
            if (control_key == 80) // down arrow key
                x1++;
            if (control_key == 77) // right arrow key
                y1++;
            if (control_key == 75) // left arrow key
                y1--;
            if (control_key == 13) // Enter key
                lock1 = true;

            if (lock1 == true)
            {
                if (grid1[x1][y1] != 'M' && grid1[x1][y1] != 'H')
                {
                    grid1[x1][y1] = 'M';
                    lock1 = false;
                    return;
                }
                else
                {
                    cout << "                                       This Co-ordinate is already been selected! Select other co-ordinates." << endl;
                    lock1 = false;
                    std::system("pause");
                }
            }
        }
        else if (ControleMode == 1)
        {
            if (control_key == 27) // escape key
                main();
            if (control_key == 72) // up arrow key
                x2--;
            if (control_key == 80) // down arrow key
                x2++;
            if (control_key == 77) // right arrow key
                y2++;
            if (control_key == 75) // left arrow key
                y2--;
            if (control_key == 13) // Enter key
                lock2 = true;

            if (lock2 == true)
            {
                if (grid2[x2][y2] != 'M' && grid2[x2][y2] != 'H')
                {
                    grid2[x2][y2] = 'M';
                    lock2 = false;
                    return;
                }
                else
                {
                    cout << "                                       This Co-ordinate is already been selected! Select other co-ordinates." << endl;
                    lock2 = false;
                    std::system("pause");
                }
            }
        }
    }
}

void DisplayGrid(char grid[][cols], int &x, int &y, string name = "") // x and y are used to display the control
{
    std::system("cls");
    LeftPaddingTillCenter(-20);
    std::cout << " Displaying Grid to place " << name << "'s ships" << endl
              << endl;
    // Display the grid
    for (int i = 0; i < rows; i++)
    {
        LeftPaddingTillCenter(18);
        for (int j = 0; j < cols; j++)
        {
            if ((x != -1 || y != -1) && x == i && y == j)
                std::cout << "o  ";
            else
                std::cout << grid[i][j] << "  ";
        }
        std::cout << endl;
    }
    return;
}
void DisplayDoubleGrid(char grid1[][cols], int &x1, int &y1, char grid2[][cols], int &x2, int &y2, int &score1, int &score2) // x and y are used to display the control
{
    std::system("cls");
    LeftPaddingTillCenter(25);
    std::cout << "Displaying Grid of " << player1 << "           Displating Grid of " << player2 << endl
              << endl;
    LeftPaddingTillCenter(45);
    std::cout << "Score of " << player1 << " : " << score1 << "                 Score of " << player2 << " : " << score2 << endl
              << endl;
    // Display the grid
    for (int i = 0; i < rows; i++)
    {
        LeftPaddingTillCenter(70);
        for (int j = 0; j < cols; j++)
        {
            if ((x1 != -1 || y1 != -1) && x1 == i && y1 == j)
                std::cout << "o  ";
            else
                std::cout << grid1[i][j] << "  ";
        }
        std::cout << "         ";
        for (int j = 0; j < cols; j++)
        {
            if ((x2 != -1 || y2 != -1) && x2 == i && y2 == j)
                std::cout << "o  ";
            else
                std::cout << grid2[i][j] << "  ";
        }
        std::cout << endl;
    }
    return;
}

void DisplayScoreBoard(int score1, int score2)
{
    system("cls");
    std::cout << std::endl
              << std::endl;
    LeftPaddingTillCenter(45);
    std::cout << "" << player1 << " Scored : " << score1 << "                  " << player2 << " Scored : " << score2 << std::endl;
    if (score1 == score2)
    {
        std::cout << std::endl
                  << std::endl;
        LeftPaddingTillCenter(8);
        std::cout << "The game is a tie! " << std::endl;
    }
    else if (score1 > score2)
    {
        std::cout << std::endl;
        LeftPaddingTillCenter(8);
        std::cout << "Congratulation " << player1 << "! You Won the game! " << std::endl;
    }
    else if (score1 < score2)
    {
        std::cout << std::endl;
        LeftPaddingTillCenter(8);
        std::cout << "Congratulation " << player2 << "! You Won the game! " << std::endl;
    }
    Sleep(3000);
    std::system("pause");
}
