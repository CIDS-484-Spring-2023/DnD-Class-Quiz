//			Chapter 4 code

//								Hero's Inventory 2.0 code

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	
	cout<<"You have "<<inventory.size()<<" items.\n";
	
	cout<<"Your items:\n";
	for (int i=0;i<inventory.size();++i){
		
		cout<<inventory[i]<<endl;
	}
	
	cout<<"\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";
	cout<<"\n\nYour items:\n";
	for (int i=0;i<inventory.size();++i){
		
		cout<<inventory[i]<<endl;
	}
	
	cout<<"\nThe item name '"<<inventory[0]<<"' has ";
	cout<<inventory[0].size()<<" letters in it.\n";
	
	cout<<"\nYour shield was destroyed in a fierce battle.";
	inventory.pop_back();
	cout<<"\nYour items: \n";
	for (int i=0;i<inventory.size();++i)
	{
		cout<<inventory[i]<<endl;
	}
	
	cout<<"\nYou were robbed of all your possessions by a thief.";
	inventory.clear();
	
	if(inventory.empty())
	{
		cout<<"\nYou have nothing.\n";
	}
	else
	{
		cout<<"\nYou have at least one item.\n";
	}
	
	return 0;
	
}
*/

//								Hero's Inventory 3.0 code

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	
	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;
	
	cout<<"Your items: \n";
	for(iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	
	cout<<"\nYou trade your sword for a battle axe.";
	myIterator = inventory.begin();
	*myIterator = "battle axe";
	cout<<"\nYour items:\n";
	for(iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	
	cout<<"\nThe item name '"<<*myIterator<<"' has ";
	cout<<(*myIterator).size()<<" letters in it.\n";
	
	cout<<"\nThe item name '"<<*myIterator<<"' has ";
	cout<<myIterator->size()<< " letters in it.\n";
	
	cout<<"\nYou recover a crossbow from a slain enemy.";
	inventory.insert(inventory.begin(), "crossbow");
	cout<<"\nYour items:\n";
	for(iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	
	cout<<"\nYour armor was destroyed in a fierce battle.";
	inventory.erase((inventory.begin()+2));
	cout<<"\nYour items:\n";
	for(iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	
	return 0;
}
*/

//								High Scores code

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	vector<int>::const_iterator iter;
	
	cout<<"Creating a list of scores.";
	vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);
	
	cout<<"\nHigh Scores:\n";
	for(iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	
	cout<<"\nFinding a score.";
	int score;
	cout<<"\nEnter a score to find: ";
	cin>>score;
	iter = find(scores.begin(), scores.end(), score);
	if(iter != scores.end())
	{
		cout<<"Score found.\n";
	}
	else
	{
		cout<<"Score not found.\n";
	}
	
	cout<<"\nRandomizing Scores.";
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(scores.begin(), scores.end());
	cout<<"\nHigh Scores: \n";
	for(iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	
	cout<<"\nSorting scores.";
	sort(scores.begin(), scores.end());
	cout<<"\nHigh Scores:\n";
	for(iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	
	return 0;
}
*/

//								Hangman code


/*
	Create a group of words
	Pick a random word from the group as the 'secret word'
	while player hasn't made too many incorrect guesses AND hasn't guessed the secret word
		tell player how many incorrect guesses they have left
		show player the letters they have guessed
		show player how much of the secret word they have guessed
		get player's next guess
		while player has entered a letter that they have guessed
			get player's guess
		add the new guess to the group of used letters
		if the guess is in the secret word
			tell the player they guessed correctly
			update the word guessed so far with the new letter
		otherwise
			tell the player they guessed incorrectly
			increment the number of incorrect guesses the player has made
	if the player has made too many incorrect guesses
		tell the player that they have been hanged
	otherwise
		congratulate the player on guessing the secret word
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype> //contains algorithms for converting characters to uppercase
using namespace std;

int main()
{
	//setup
	const int MAX_WRONG = 8; 	//maximum number of incorrect guesses allowed
	
	vector<string> words; 					//collection of possible words to guess
	words.push_back("JACKSON");
	words.push_back("VIKINGS");
	words.push_back("RAIDERS");
	
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0]; 	//word to guess
	int wrong = 0; 						//current number of incorrect guesses
	string soFar(THE_WORD.size(), '-'); //word guessed so far
	string used = ""; 					//letters already used
	
	cout<<"Welcome to Hangman.Good luck!\n";
	
	//main loop
	while((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout<<"\n\nYou have "<<(MAX_WRONG - wrong);
		cout<<" incorrect guesses remaining.\n";
		cout<<"\n You've used the following letters:\n"<<used<<endl;
		cout<<"\nSo far, the word is:\n"<<soFar<<endl;
	
	
		//getting the players guess
		char guess;
		cout<<"\n\nEnter your guess: ";
		cin>>guess;
		guess = toupper(guess);								//make uppercase because the secret word is uppercase
		while(used.find(guess) != string::npos)
		{
			cout<<"\nYou've already guessed "<<guess<<endl;
			cout<<"Enter your guess: ";
			cin>>guess;
			guess = toupper(guess);
		}
	
		used += guess;
		
		if(THE_WORD.find(guess) != string::npos)
		{
			cout<<"That's right! "<<guess<<" is in the word.\n";
		
			//update soFar to include newly guessed letter
			for(int i = 0; i < THE_WORD.length(); ++i)
			{
				if(THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout<<"Sorry, "<<guess<<" is not in the word.\n";
			++wrong;
		}
	
	}
	
	//shut down
	if(wrong == MAX_WRONG)
	{
		cout<<"\nYou have been hanged. Game Over :(";
	}
	else
	{
		cout<<"\nYou guessed it! :)";
	}
	
	cout<<"\nThe word was "<<THE_WORD<<endl;
	
	return 0;
}
