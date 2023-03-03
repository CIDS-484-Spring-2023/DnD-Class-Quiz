//								Chapter 6 code


//								Referencing code


#include <iostream>
using namespace std;

int main()
{
	int myScore = 1000;
	int& mikesScore = myScore; //create a reference
	
	cout<<"myScore is: "<<myScore<<"\n";
	cout<<"mikesScore is: "<<mikesScore<<"\n\n";
	
	cout<<"Adding 500 to myScore\n";
	myScore += 500;
	cout<<"myScore is: "<<myScore<<"\n";
	cout<<"mikesScore is: "<<mikesScore<<"\n\n";
	
	cout<<"Adding 500 to mikesScore\n";
	mikesScore += 500;
	cout<<"myScore is: "<<myScore<<"\n";
	cout<<"mikesScore is: "<<mikesScore<<"\n\n";
	
	return 0;
}


//								Swap code

/*
#include <iostream>
using namespace std;

void badSwap(int x, int y);
void goodSwap(int& x, int& y);

int main()
{
	int myScore = 150;
	int yourScore = 1000;
	cout<<"Original values\n";
	cout<<"myScore: "<<myScore<<"\n";
	cout<<"yourScore: "<<yourScore<<"\n\n";
	
	cout<<"Calling badSwap()\n";
	badSwap(myScore, yourScore);
	cout<<"myScore: "<<myScore<<"\n";
	cout<<"yourScore: "<<yourScore<<"\n\n";
	
	cout<<"Calling goodSwap()\n";
	goodSwap(myScore, yourScore);
	cout<<"myScore: "<<myScore<<"\n";
	cout<<"yourScore: "<<yourScore<<"\n\n";
	
	return 0;
}

void badSwap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void goodSwap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
*/

//								Inventory Displayer code

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//parameter vec is a constant reference to a vector of strings
void display(const vector<string>& inventory);

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	display(inventory);
	
	return 0;
}

void display(const vector<string>& vec)
{
	cout<<"Your items:\n";
	for(vector<string>::const_iterator iter = vec.begin();
		iter != vec.end(); ++iter)
	{
		cout<<*iter<<endl;	
	}
}
*/

//								Inventory Referencer code

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string& refToElement(vector<string>& inventory, int i);

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	
	cout<<"Sending the returned reference to cout:\n";
	cout<<refToElement(inventory, 0)<<"\n\n";
	
	cout<<"Assigning the returned reference to another reference.\n";
	string& rStr = refToElement(inventory, 1);
	cout<<"Sending the new reference to cout:\n";
	cout<<rStr<<"\n\n";
	
	cout<<"Assigning the returned reference to a string object.\n";
	string str = refToElement(inventory, 2);
	cout<<"Sending the new string object to cout:\n";
	cout<<str<<"\n\n";
	
	cout<<"Altering an object through a returned reference.\n";
	rStr = "Healing Potion";
	cout<<"Sending the altered object to cout:\n";
	cout<<inventory[1]<<endl;
	
	return 0;
}

string& refToElement(vector<string>& vec, int i)
{
	return vec[i];
}
*/

//								Tic Tac Toe code

/*
Create an empty Tic Tac Toe board
Display the game instructions
Determine who goes first
Display the board
While nobody has won and it's not a tie
	If it's the human's turn
		Get the human's move
		Update the board with the human move
	Otherwise
		Calculate the computer's move
		Update the board with the computer's move
	Display the board
	Switch turns
Congratulate the winner or declare a tie
*/

/*

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

//function prototypes
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(const vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	
	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);
	
	while(winner(board) == NO_ONE)
	{
		if(turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	
	announceWinner(winner(board), computer, human);
	
	return 0;
}

void instructions()
{
	cout<<"Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
	cout<<"--where human brain is pit against silicon processor\n\n";
	
	cout<<"Make your move known by entering a number, 0-8. The number\n";
	cout<<"corresponds to the desired board position, as illustrated below:\n\n";
	
	cout<<"0 | 1 | 2\n";
	cout<<"---------\n";
	cout<<"3 | 4 | 5\n";
	cout<<"---------\n";
	cout<<"6 | 7 | 8\n\n";
	
	cout<<"Prepare yourself, human. The battle is about to begin.\n\n";
}

char askYesNo(string question)
{
	char response;
	do
	{
		cout<<question<<" (y/n): ";
		cin>>response;
	} while(response != 'y' && response != 'n');
	
	return response;
}

int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout<<question<<" ("<<low<<"-"<<high<<"): ";
		cin>>number;
	} while(number > high || number < low);
	
	return number;
}

char humanPiece()
{
	char go_first = askYesNo("Do you require the first move?");
	if(go_first == 'y')
	{
		cout<<"\nThen take the first move. You will need it...\n";
		return X;
	}
	else
	{
		cout<<"\nYour bravery will be your undoing, mortal. I will go first...\n";
		return O;
	}
}

char opponent(char piece)
{
	if(piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void displayBoard(const vector<char>& board)
{
	cout<<"\n\t"<<board[0]<<" | "<<board[1]<<" | "<<board[2];
	cout<<"\n\t"<<"---------";
	cout<<"\n\t"<<board[3]<<" | "<<board[4]<<" | "<<board[5];
	cout<<"\n\t"<<"---------";
	cout<<"\n\t"<<board[6]<<" | "<<board[7]<<" | "<<board[8];
	cout<<"\n\n";
}

char winner(const vector<char>& board)
{
	//all possible winning combinations
	const int WINNING_ROWS[8][3] = {{0,1,2},
									{3,4,5},
									{6,7,8},
									{0,3,6},
									{1,4,7},
									{2,5,8},
									{0,4,8},
									{2,4,6}};
									
	const int TOTAL_ROWS = 8;
	//if any winning row has three values that are the same and are NOT empty, then we have a winner
	for(int row = 0; row < TOTAL_ROWS; ++row)
	{
		if( (board[WINNING_ROWS[row][0]] != EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
		{
			return board[WINNING_ROWS[row][0]];
		}
	}
	
	//since nobody has won, check for tie (no empty squares left)
	if(count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
		
	//since nobody has won and it isn't a tie, the game isn't over
	return NO_ONE;
}

inline bool isLegal(int move, const vector<char>& board)
{
	return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("Where will you move?", (board.size() - 1));
	while(!isLegal(move, board))
	{
		cout<<"\nThat square is already occupied, dumbass.\n";
		move = askNumber("Where will you move?", (board.size() - 1));
	}
	cout<<"Took you long enough to decide...\n";
	
	return move;
}

int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;
	
	//if the computer can win, make that move
	while(!found && move < board.size())
	{
		if(isLegal(move, board))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		
		if(!found)
		{
			++move;
		}
	}
	
	//otherwise, if human can win next turn, that's the move to make
	if(!found)
	{
		move = 0;
		char human = opponent(computer);
		
		while(!found && move < board.size())
		{
			if(isLegal(move, board))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			
			if(!found)
			{
				++move;
			}
		}
	}
	
	//otherwise, moving to the best open square is the move to make
	if(!found)
	{
		move = 0;
		unsigned int i = 0;
		
		const int BEST_MOVES[] = {4,0,2,6,8,1,3,5,7};
		//pick best open square
		while(!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if(isLegal(move, board))
			{
				found = true;
			}
			
			++i;
		}
	}
	
	cout<<"I shall take square number "<<move<<endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if(winner == computer)
	{
		cout<<winner<<"'s won!\n";
		cout<<"As I predicted, human, I am triumphant once more --\n";
		cout<<"of course, no other outcome was possible. Begone, Scum!\n";
	}
	
	else if(winner == human)
	{
		cout<<winner<<"'s won!\n";
		cout<<"I guess even a blind squirrel finds a nut or two in\n";
		cout<<"their lifetime. Enjoy the moment while it lasts...\n";
	}
	
	else
	{
		cout<<winner<<"'s won!\n";
		cout<<"This was the best you could do? Why do I even bother\n";
		cout<<"trying to find a challenge with such lowly lifeforms?\n";
	}
}

*/
