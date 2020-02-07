//---------------------------------------------------------------------
// Name: Dalina tu
// Email: dtt5131@psu.edu
// Class: CMPSC 122
// Program 1.1
// Due Date: February 04, 2020
//
// Description: This program calculates the results of an Omok game, a 2-player strategy board game where players 
// alternate turns and place a stone of their color hoping to form an unbroken link of N stones.
// It reads, as a command line argument, an input file name that contains the size of the board N, a list of stone locations,
// and corresponding colors. It will write the board with the provided data, determine if the white
// or black player can win in the game with such provided data, and write a list of winning conditions of white and black players.
//
// Acknowledgement:
// 1. I went to the UNIX xeminar and got help from friends about Unix, directories, file copying, and submitting.
// 2. I read ahead in the class textbook. 
//---------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

char** ReadBoard(char* filepath, int& num_rows, int& num_cols, int& N) // pass by pointer and reference parameters
{ // reads size of board, N, and stone locations/colors, and returns the board as a dynamically allocated 2D array with elements of type char.

	// accepts an input file 'filepath'
	fstream infile;
	infile.open(filepath);

	// the given file will initialize num_rows and num_cols and N
	infile >> num_rows; // rows of the board
	infile >> num_cols; // columns of the board
	infile >> N; // N is number of stones that must be linked to win

 // returned number of rows and cols by references and N by reference.
	////////////////////////////////////////////////////////////////

	// Create board with adding stones into the board
	// dynamic 2D array
	char** board = new char* [num_rows];
	for (int i = 0; i < num_rows; ++i)
	{
		board[i] = new char[num_cols];
	}
	/*for (int i = 0; i < num_rows; i++)
	{
		for (int x = 0; x < num_cols; x++)
		{
			board[i][x] = " .";
		}
	}
	for (int i = 0; i < num_rows; i++)
	{
		for (int x = 0)
		{
			board[i][x] = i;
			x++;
		}
	}
	*/
	char** board = NULL;
	//function returns board, type char**
	return board;
	/////////////////////////////////////////////////////////////////
}

void PrintBoard(char** board, int num_rows, int num_cols) // rows and cols parameters here are pass by value
{ // Writes the ReadBoard on the console

	cout << "Print board:" << endl << endl;
	// Print board with stones.
	// AKA Prints 2D Array element by element. Array is called board.
	for (int i = 0; i < num_rows; i++)
	{
		for (int x = 0; x < num_cols; x++)
		{
			cout << board[i][x];
		}
	}
	/* for (int i = 0; i < num_rows; i++)
	{
		for (int x = 0; x < num_cols; x++)
		{
			if(**board == 'W' )
			{
				cout << " W";
			}
			else if (**board == 'B')
			{
				cout << " B";
			}
			else
			{
				cout << " .";
			}
		}

		cout << endl;
	}
	*/
	//   * " W" to print a white stone, and
	//   * " B" to print a black stone, and
	//   * " ." to print an empty cell.

	/////////////////////////////////////////////////////////////////
}

bool CheckWhitePlayerWin(int num_rows, int num_cols, char** board, int N)
{
	return true;
}
bool CheckBlackPlayerWin(int num_rows, int num_cols, char** board, int N)
{
	return true;
}
void PrintPlayerWinCondition(int num_rows, int num_cols, char** board, int N)
{
	// Finally, print the list of winning conditions sorted by the index of the top left stone location
	// Sort through the array
	//
	cout << "Here we are in listing stuff";
	/* if ()
	{
		cout << "W: ";
	}
	if ()
	{
		<< "(" << "," << "" << "," << "" << ",";
	}
	if ()
	{
		cout << "B: ";
	}
	*/
}

/////////////////////////////////////////////////////////////////////

//********** Program starts here at int main
int main(int argc, char* argv[]) // int main has 2 arguments, a int variable and a char* array (array of pointers to characters)
{
	if (argc <= 1)
	{
		cout << "Need the input file containing board size, N, and stones." << endl;
		return 0;
	}
	
	// create variables num of rows, num of cols, and N size of board
	// all of these are uninitialized
	int num_rows;
	int num_cols;
	int N;

	// call the ReadBoard function, passing these arguments, and then assign return value to char** board, a character double pointer.
	// ReadBoard will involve accepting an input file, which initializes some of our variables
	char** board = ReadBoard(argv[1], num_rows, num_cols, N);

	// Use num of rows and num cols and board to print the board for user to see
	PrintBoard(board, num_rows, num_cols);

	// If/else statements with conditions which call bool functions CheckWhitePlayerWin and CheckBlackPlayerwin
	if (CheckWhitePlayerWin(num_rows, num_cols, board, N))
		cout << "Can white player win? Yes" << endl;
	else
		cout << "Can white player win? No" << endl;

	if (CheckBlackPlayerWin(num_rows, num_cols, board, N))
		cout << "Can black player win? Yes" << endl;
	else
		cout << "Can black player win? No" << endl;

	// Finally, print the list of winning conditions sorted by the index of the top left stone location
	cout << endl;
	cout << "List of winning conditions sorted by the index of top-left stone location:" << endl;

	// Call the PrintPlayerWinCondition Function with given arguments
	PrintPlayerWinCondition(num_rows, num_cols, board, N);

	// My code to delete my dynamically allocated memories

	delete[]argv;
	argv = nullptr;


}
