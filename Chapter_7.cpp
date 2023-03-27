//Chapter 7 code

//								Pointing program

/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int* pAPointer;			//declare a pointer
	
	int* pScore = 0;		//declare and initialize a pointer
	
	int score = 1000;
	pScore = &score;		//assign pointer pScore to the address of variable score
	
	cout<<"Assigning &score to pScore\n";
	cout<<"&score is: "<<&score<<"\n";		//address of score variable
	cout<<"pScore is: "<<pScore<<"\n";		//address stored in pointer
	cout<<"score is: "<<score<<"\n";
	cout<<"*pScore is:"<<*pScore<<"\n\n";	//value pointed to by pointer
	
	cout<<"Adding 500 to score\n";
	score += 500;
	cout<<"&score is: "<<&score<<"\n";		//address of score variable
	cout<<"pScore is: "<<pScore<<"\n";		//address stored in pointer
	cout<<"score is: "<<score<<"\n";
	cout<<"*pScore is:"<<*pScore<<"\n\n";	//value pointed to by pointer
	
	cout<<"Adding 500 to *pScore\n";
	*pScore += 500;
	cout<<"&score is: "<<&score<<"\n";		//address of score variable
	cout<<"pScore is: "<<pScore<<"\n";		//address stored in pointer
	cout<<"score is: "<<score<<"\n";
	cout<<"*pScore is:"<<*pScore<<"\n\n";	//value pointed to by pointer
	
	cout<<"Assigning &newScore to pScore\n";
	int newScore = 5000;
	pScore = &newScore;
	cout<<"&score is: "<<&score<<"\n";
	cout<<"&newScore is: "<<&newScore<<"\n";		//address of newScore variable
	cout<<"pScore is: "<<pScore<<"\n";				//address stored in pointer
	cout<<"newScore is: "<<newScore<<"\n";
	cout<<"*pScore is:"<<*pScore<<"\n\n";			//value pointed to by pointer
	
	cout<<"Assigning &str to pStr\n";
	string str = "score";
	string* pStr = &str;				//pointer to string object
	cout<<"str is: "<<str<<"\n";
	cout<<"*pStr is: "<<*pStr<<"\n";
	cout<<"(*pStr).size() is: "<<(*pStr).size()<<"\n";
	cout<<"pStr->size() is: "<<pStr->size()<<"\n";
	
	return 0;
}
*/

//								Swap Pointer Version program

/*
#include <iostream>
using namespace std;

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

int main()
{
	int myScore = 150;
	int yourScore = 1000;
	cout<<"Original Values\n";
	cout<<"myScore: "<<myScore<<"\n";
	cout<<"yourScore: "<<yourScore<<"\n\n";
	
	cout<<"Calling badSwap()\n";
	badSwap(myScore, yourScore);
	cout<<"myScore: "<<myScore<<"\n";
	cout<<"yourScore: "<<yourScore<<"\n\n";
	
	cout<<"Calling goodSwap()\n";
	goodSwap(&myScore, &yourScore);
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

void goodSwap(int* const pX, int* const pY)
{
	//store value pointed to by pX in temp
	int temp = *pX;
	//store value pointed to by pY in address pointed to by pX
	*pX = *pY;
	//store value originally pointed to by pX in address pointed to by pY
	*pY = temp;
}
*/

//								Inventory Pointer program

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//returns a pointer to a string element
string* ptrToElement(vector<string>* const pVec, int i);

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	
	//displays string object that the returned pointer points to
	cout<<"Sending the object pointed to by returned pointer to cout:\n";
	cout<<*(ptrToElement(&inventory, 0))<<"\n\n";
	//assigns one pointer to another -- inexpensive assignment
	cout<<"Assigning the returned pointer to another pointer.\n";
	string* pStr = ptrToElement(&inventory, 1);
	cout<<"Sending the object pointed to by new pointer to cout:\n";
	cout<<*pStr<<"\n\n";
	
	//copies a string object -- expensive assignment
	cout<<"Assigning object pointed to by pointer to a string object.\n";
	string str = *(ptrToElement(&inventory, 2));
	cout<<"Sending the new string object to cout:\n";
	cout<<str<<"\n\n";
	
	//altering the string object through a returned pointer
	cout<<"Altering an object through a returned pointer.\n";
	*pStr = "Healing Potion";
	cout<<"Sending the altered object to cout:\n";
	cout<<inventory[1]<<endl;
	
	return 0;
}

string* ptrToElement(vector<string>* const pVec, int i)
{
	//returns address of the string in position i of vector that pVec points to
	return &((*pVec)[i]);
}
*/

//								Array Passer program

/*
#include <iostream>
using namespace std;

void increase(int* const array, const int NUM_ELEMENTS);
void display(const int* const array, const int NUM_ELEMENTS);

int main()
{
	cout<<"Creating an array of high scores.\n\n";
	const int NUM_SCORES = 3;
	int highScores[NUM_SCORES] = {5000,3500,2700};
	
	cout<<"Displaying scores using array name as a constant pointer.\n";
	cout<<*highScores<<endl;
	cout<<*(highScores + 1)<<endl;
	cout<<*(highScores + 2)<<"\n\n";
	
	cout<<"Increasing scores by passing array as a constant pointer.\n\n";
	increase(highScores, NUM_SCORES);
	cout<<"Displaying scores by passing array as a constant pointer to a constant.\n";
	display(highScores, NUM_SCORES);
	
	return 0;
}

void increase(int* const array, const int NUM_ELEMENTS)
{
	for(int i=0;i<NUM_ELEMENTS;++i)
	{
		array[i] += 500;
	}
}

void display(const int* const array, const int NUM_ELEMENTS)
{
	for(int i=0;i<NUM_ELEMENTS;++i)
	{
		cout<<array[i]<<endl;
	}
}
*/

//								Tic-Tac-Toe 2.0 program


//cannot be located
