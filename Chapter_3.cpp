//								Counter code

/*
#include <iostream>
using namespace std;

int main(){
	
	cout<<"Counting forward:\n";
	for (int i=0; i<10; ++i){
		cout<<i<<" ";
	}
	
	cout<<"\n\nCounting backward:\n";
	for (int i=9;i>=0;--i){
		cout<<i<<" ";
	}
	
	cout<<"\n\nCounting by fives:\n";
	for (int i=0; i<=50; i+=5){
		cout<<i<<" ";
	}
	
	cout<<"\n\nCounting with null statements:\n";
	int count=0;
	for(;count<10;){
		cout<<count<<" ";
		++count;
	}
	
	cout<<"\n\nCounting with nested \'for\' loops:\n";
	const int ROWS=5;
	const int COLUMNS=3;
	for (int i=0; i<ROWS;++i){
		for (int j=0; j<COLUMNS;++j){
			cout<<i<<","<<j<<" ";
		}
		
		cout<<endl;
	}
	
	return 0;
}
*/

//								String Tester code

/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string word1 = "Game";
	string word2("Over");
	string word3(3, '!');
	
	string phrase = word1+" "+word2+word3;
	cout<<"The phrase is: "<<phrase<<"\n\n";
	
	cout<<"The phrase has "<<phrase.size()<<" characters in it.\n\n";
	
	cout<<"The character at position 0 is:"<<phrase[0]<<"\n\n";
	
	cout<<"Changing the character at position 0.\n";
	phrase[0]='L';
	cout<<"The phrase is now: "<<phrase<<"\n\n";
	
	for (unsigned int i=0; i<phrase.size(); ++i){
		
		cout<<"Character at position "<<i<<" is: "<<phrase[i]<<endl;
	}
	
	cout<<"\nThe sequence 'Over' begins at location ";
	cout<<phrase.find("Over")<<endl;
	
	if (phrase.find("eggplant") == string::npos){
		
		cout<<"'eggplant' is not in the phrase.\n\n";
	}
	
	phrase.erase(4,5);
	cout<<"The phrase is now: "<<phrase<<endl;
	
	phrase.erase(4);
	cout<<"The phrase is now: "<<phrase<<endl;
	
	phrase.erase();
	cout<<"The phrase is now: "<<phrase<<endl;
	
	if (phrase.empty()){
		
		cout<<"\nThe phrase is no more.\n";
	}
	
	return 0;
}
*/

//								Hero's Inventory code

/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	
	const int MAX_ITEMS = 10;
	string inventory[MAX_ITEMS];
	
	int numItems = 0;
	inventory[numItems++] = "sword";
	inventory[numItems++] = "armor";
	inventory[numItems++] = "shield";
	
	cout<<"Your items:\n";
	for (int i=0;i<numItems;++i){
		
		cout<<inventory[i]<<endl;
	}
	
	cout<<"\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";
	cout<<"\n\nYour items:\n";
	for (int i=0;i<numItems;++i){
		
		cout<<inventory[i]<<endl;
	}
	
	cout<<"\nThe item name '"<<inventory[0]<<"' has ";
	cout<<inventory[0].size()<<" letters in it.\n";
	
	cout<<"\nYou find a healing potion.\n";
	if(numItems<MAX_ITEMS){
		
		inventory[numItems++] = "healing potion";
	}
		
	else{
			
		cout<<"You have too many items, and cannot carry another.";
	}
		
	cout<<"\nYour items:\n";
	for(int i=0;i<numItems;++i){
			
		cout<<inventory[i]<<endl;
	}
	
}
*/

//								Tic-Tac-Toe Board code

/*
#include <iostream>
using namespace std;

int main(){
	
	const int ROWS = 3;
	const int COLUMNS = 3;
	char board[ROWS][COLUMNS] = {{'O', 'X', 'O'},
								 {' ', 'X', 'X'},
								 {'X', 'O', 'O'}};
								 
	cout<<"Here's the tic-tac-toe board:\n";
	for(int i=0; i<ROWS; ++i){
		
		for(int j=0; j<COLUMNS; ++j){
			cout<<board[i][j];
		}
		
		cout<<endl;
	}
	
	cout<<"\n'X' moves to the empty location.\n\n";
	board[1][0] = 'X';
	
	cout<<"Here's the updated tic-tac-toe board:\n";
	for(int i=0; i<ROWS; ++i){
		
		for(int j=0; j<COLUMNS; ++j){
			cout<<board[i][j];
		}
		
		cout<<endl;
	}
	
	cout<<"\n 'X' wins!";
	return 0;
}
*/

//								Word Jumble code


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it!"},
		{"jumble", "It's what the game is all about."}
	};
	
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; //word to guess
	string theHint = WORDS[choice][HINT]; //hint for word
	
	string jumble = theWord; //jumbled version of word
	int length = jumble.size();
	for(int i=0; i<length; ++i){
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	
	cout<<"\t\t\tWelcome to Word Jumble!\n\n";
	cout<<"Unscramble the letters to make the word.\n";
	cout<<"Enter 'hint' for a hint.\n";
	cout<<"Enter 'quit' to quit the game.\n\n";
	cout<<"The jumble is: "<<jumble;
	
	string guess;
	cout<<"\n\nYour guess: ";
	cin>>guess;
	int points = theWord.length();
	
	//game loop
	while((guess != theWord)&&(guess != "quit"))
	{
		if(guess == "hint")
		{
			cout<<theHint;
			points /= 2;
			
		}
		else
		{
			cout<<"Sorry,that's not it.";
		}
		
		cout<<"\n\nYour guess: ";
		cin>>guess;
	}
	
	if(guess == theWord)
	{
		cout<<"\nThat's it! You guessed it!\n";
		cout<<"\nYou earned "<<points<<" points!\n";
	}
	
	cout<<"\nThanks for playing.\n";
	return 0;
}
