// Lainey Schrag

#include <iostream>
#include "Chessboard.hpp"
using namespace std; 


int main()
{
    int choice = 0;
    int size = 0;

    cout << endl << "Hello! Let's solve the Eight Queens Problem.";
    cout << endl << "\tEnter 1 to run test on 8x8 board.";
    cout << endl << "\tEnter 2 to solve the problem on a custom sized board.";
    cout << endl << "Choice: ";
    cin >> choice; 
    while (cin.fail() || (choice != 1 && choice != 2))
    {
        cin.ignore();
        cout << endl << "Error. Please enter valid choice.";
        cout << endl << "Choice: ";
        cin >> choice;
    }

    if(choice == 1) //test on 8x8 board
    {
        Chessboard test_chessboard;
        test_chessboard.doEightQueens();
    }

    if(choice == 2) //queens problem on board sized 4-12
    {
        cout << endl << "What size chessboard would you like?";
        cout << endl << "Choose a size between 4 and 12.";
        cout << endl << "Choice: ";
        cin >> size;
        while(cin.fail() || (size < 4 || size > 12))
        {
            cin.ignore();
            cout << endl << "Error. Please enter valid choice.";
            cout << endl << "Choice must be a number between 4 and 12.";
            cout << endl << "Choice: ";
            cin >> size;
        }
        Chessboard custom_chessboard(size);
    }

    return 0;
}