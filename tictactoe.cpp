#include <iostream>
#include <iterator>
#include <string>

char boardState[3][3] = {{'0', '0', '0'}, {'0', '0', '0'}, {'0', '0', '0'}};

void printBoard()
{
    std::cout << "=======================\n\n";
    std::cout << "       1   2   3       \n";
    for (int row = 0; row != 3; row++)
    {
        if (row == 0)
        {
            std::cout << "    a ";
        }
        else if (row == 1)
        {
            std::cout << "    b ";
        }
        else if (row == 2)
        {
            std::cout << "    c ";
        }

        for (int col = 0; col != 3; col++)
        {
            if (boardState[row][col] != '0')
                std::cout << " " << boardState[row][col] << " ";
            else
                std::cout << "   ";
            if (col != 2)
                std::cout << "|";
        }
        if (row != 2)
            std::cout << "\n      --- --- ---\n";
    }
    std::cout << "\n\n=======================\n";
}

bool checkWin()
{
    if (boardState[0][0] != '0' && boardState[0][0] == boardState[1][1] && boardState[0][0] == boardState[2][2])
        return true;
    if (boardState[0][2] != '0' && boardState[0][2] == boardState[1][1] && boardState[0][2] == boardState[2][0])
        return true;
    for (int i = 0; i != 3; i++)
    {
        if (boardState[i][0] != '0' && boardState[i][0] == boardState[i][1] && boardState[i][0] == boardState[i][2])
            return true;
        if (boardState[0][i] != '0' && boardState[0][i] == boardState[1][i] && boardState[0][i] == boardState[2][i])
            return true;
    }
    return false;
}

bool fill(const int whoseTurn, const int row, const int column)
{
    if (boardState[row][column] == '0')
    {
        boardState[row][column] = whoseTurn;
        return true;
    }
    else
    {
        std::cout << "Spot has already been taken!\n";
        return false;
    }
}

int getRowColumn(const std::string &input, const int rowOrColumn)
{
    int i;
    switch(tolower(input[rowOrColumn]))
    {
        case 'a':
            i = 0;
            break;
        case 'b':
            i = 1;
            break;
        case 'c':
            i = 2;
            break;
        case '1':
            i = 0;
            break;
        case '2':
            i = 1;
            break;
        case '3':
            i = 2;
            break;
    }
    return i;
}

std::string getInput()
{
    std::string input;
    bool validInput = 0;
    std::cout << "Enter notation: ";
    std::cin >> input;
    std::cin.ignore(1000, '\n');
    while (!validInput)
    {
        input[0] = tolower(input[0]);
        if ((input[0] == 'a' || input[0] == 'b' || input[0] == 'c'))
        {
            if ((input[1] == '1' || input[1] == '2' || input[1] == '3'))
            {
                validInput = 1;
                break;
            }
        }
        std::cout << "Invalid input, try again: ";
        std::cin >> input;
        std::cin.ignore(1000, '\n');
        auto it = input.begin();
    }
    return input;
}

int main()
{
    int whoseTurn = 'X'; // Turn 1 = X, Turn 2 = O
    bool gameOver = false;
    int turnNumb = 1;
    std::cout << "      Tic Tac Toe      \n";
    printBoard();
    while (!gameOver)
    {
        if (whoseTurn == 'X')
            std::cout << "It is player 1's turn!\n";
        else
            std::cout << "It is player 2's turn!\n";
        bool validSpotCheck = true;
        do
        {
            std::string currInput = getInput();
            validSpotCheck = fill(whoseTurn, getRowColumn(currInput, 0), getRowColumn(currInput, 1));
        }
        while (!validSpotCheck);
        std::cout << '\n';
        printBoard();
        gameOver = checkWin();
        if(gameOver || turnNumb == 9)
        {
            break;
        }
        turnNumb++;
        if (whoseTurn == 'X') whoseTurn = 'O';
        else whoseTurn = 'X';
    }
    if (gameOver == true)
    {
        if (whoseTurn == 'X')
            std::cout << "Player 1 has won the game!\n";
        else
            std::cout << "Player 2 has won the game!\n";
    }
    else if (turnNumb == 9)
    {
        std::cout << "The game is a draw!\n";
    }

    return 0;
}