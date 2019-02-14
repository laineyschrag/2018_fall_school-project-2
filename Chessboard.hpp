// Lainey Schrag

#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>

using namespace std;

class Chessboard
{
    public:
    Chessboard(); //Constructor for 8x8 board
    Chessboard(int n); //Constructor for custom sized board
    ~Chessboard(); //deletes array

    void setPosition(int row, int column, char x); 
    void displayBoard();
    void doEightQueens();

    private:
    char getAtPosition(int row, int column);
    int getBoardSize();
    bool placeQueens(int n); //recursive function to solve problem
    bool canMove(int row, int column); //checks if a move is valid

    char** arr; //array
    int boardSize;
    int queenCount; //number of queens currently on board

};

Chessboard::Chessboard()
{
    boardSize = 8;
    queenCount = 0;

    arr = new char*[8];
    for(int i = 0; i < 8; i++) //every element in array set to blank space
    {
        arr[i] = new char[8];
        for(int j = 0; j < 8; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

Chessboard::Chessboard(int n)
{
    boardSize = n;
    queenCount = 0;

    arr = new char*[n];
    for(int i = 0; i < n; i++) //every element in array set to blank space
    {
        arr[i] = new char[n];
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = ' ';
        }
    }

   if (placeQueens(0)) //calls function that is responsible for finding solution
   {
       displayBoard(); //board is only displayed if a solution exists
   }
   else
   {
       cout << endl << "No solution found.";
   }
}

Chessboard::~Chessboard()
{
    for(int i = 0; i < getBoardSize(); i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void Chessboard::setPosition(int row, int column, char x)
{
    arr[row][column] = x;
    if (x == 'Q')
    {
        queenCount++;
    }
    if(x == ' ')
    {
        queenCount--;
    }
}

void Chessboard::displayBoard()
{
    cout << endl << "Here is a solution I found for placement of queens on a " << boardSize << "x" << boardSize << " board:" << endl;
    for(int i = 0; i < getBoardSize(); i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            cout << getAtPosition(i,j) << " ";
        }
        cout << endl; 
    }
    cout << endl;
}

void Chessboard::doEightQueens()
{
    placeQueens(0);
    displayBoard();
}

char Chessboard::getAtPosition(int row, int column)
{
    if (arr[row][column] == ' ')
    {
        return 'X';
    }
    else
    {
        return 'Q';
    }
}

int Chessboard::getBoardSize()
{
    return boardSize;
}

bool Chessboard::canMove(int row, int column)
{
    for(int i = 0; i < getBoardSize(); i++) // checks for queens in the same row
    {
        if(arr[row][i] == 'Q')
        {
            return false;
        }
    }
    for(int i = 0; i < getBoardSize(); i++) // checks for queens in same column
    {
        if(arr[i][column] == 'Q')
        {
            return false;
        }
    }

    int x = row;
    int y = column;

    while(x > 0 && y > 0) // move x/y to highest diagonal position moving toward upper left of board
    {
        x--;
        y--;
    }
 
    while(x < getBoardSize() && y < getBoardSize()) //checks diaganol from upper left -> bottom right
    {
        if(arr[x][y] == 'Q')
        {
            return false;
        }
        x++;
        y++;
    }

    x = row;
    y = column;

    while(x > 0 && y < getBoardSize()) // move x/y to highest diagonal position moving toward upper right of board
    {
        x--;
        y++;
    }

    while(x < getBoardSize() && y > 0) //checks diagonal from upper right -> bottom left
    {
        if(arr[x][y] == 'Q')
        {
            return false;
        }
        x++;
        y--;
    }

    return true;  //only returns true if no queens are found in path
}

bool Chessboard::placeQueens(int n)
{
    if(queenCount == getBoardSize()) //problem is solved if all queens are on board
    {
        return true;
    }
    else
    {
        for(int  i = 0; i < getBoardSize(); i++) //checks row by row
        {
            if(canMove(i,n) == true)
            {
               setPosition(i,n,'Q');
               if(placeQueens(n + 1) == true) //recursive call to check the next column
               {
                   return true;
               }
               setPosition(i,n,' '); //backtrack if position is invalid
            }
        }
        return false;
    } 
}

#endif

