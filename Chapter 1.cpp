//								GAME OVER code

/*

#include <iostream>

int main(){
	std::cout << "GAME OVER!" << std::endl;
	return 0;
}

*/

//								GAME OVER 2.0 code

/*
#include <iostream>
using namespace std;

int main(){
	cout<<"GAME OVER!"<<endl;
	return 0;
}

*/

//								GAME OVER 3.0 code

/*
#include <iostream>
using std::cout;
using std::endl;

int main(){
	cout<<"GAME OVER!"<<endl;
	return 0;
}
*/

//								Expensive Calculator code

/*
#include <iostream>
using namespace std;

int main(){
	cout<<"7+3="<<7+3<<endl;
	cout<<"7-3="<<7-3<<endl;
	cout<<"7*3="<<7*3<<endl;
	cout<<"7/3="<<7/3<<endl;
	cout<<"7.0/3.0="<<7.0/3.0<<endl;
	cout<<"7%3="<<7%3<<endl;
	cout<<"7+3*5="<<7+3*5<<endl;
	cout<<"(7+3)*5="<<(7+3)*5<<endl;
	return 0;	
}

*/

//								Game Stats code

/*
#include <iostream>
using namespace std;

int main(){
	int score;
	double distance;
	char playAgain;
	bool shieldsUp;
	
	short lives, aliensKilled;
	
	score = 0;
	distance = 1200.76;
	playAgain = 'y';
	shieldsUp = true;
	lives = 3;
	aliensKilled = 10;
	
	double engineTemp = 6572.89;
	
	cout<<"\nscore: "	<<score<<endl;
	cout<<"distance: "	<<distance<<endl;
	cout<<"playAgain: "	<<playAgain<<endl;
	//skipping shieldsUp since you don't generally print Boolean values
	cout<<"lives: "	<<lives<<endl;
	cout<<"aliensKilled: "	<<aliensKilled<<endl;
	cout<<"engineTemp: "	<<engineTemp<<endl;
	
	int fuel;
	cout<<"\nHow much fuel?";
	cin>>fuel;
	cout<<"fuel: "<<fuel<<endl;
	
	typedef unsigned short int ushort;
	ushort bonus = 10;
	cout<<"\nbonus: "<<bonus<<endl;
	
	return 0;
}

*/

//								Game Stats 2.0 code

/*
#include <iostream>
using namespace std;

int main(){
	
	unsigned int score = 5000;
	cout<<"score: "<<score<<endl;
	
	//altering value of variable
	score = score+100;
	cout<<"score: "<<score<<endl;
	
	//combined assignment operator
	score += 100;
	cout<<"score: "<<score<<endl;
	
	//increment operations
	int lives = 3;
	++lives;
	cout<<"lives: "<<lives<<endl;
	
	lives = 3;
	int bonus = ++lives*10;
	cout<<"lives, bonus = "<<lives<<", "<<bonus<<endl;
	
	lives = 3;
	bonus = lives++*10;
	cout<<"lives, bonus = "<<lives<<", "<<bonus<<endl;
	
	//integer wrap around
	score = 4294967295;
	cout<<"score: "<<score<<endl;
	++score;
	cout<<"score: "<<score<<endl;
	
	return 0;
	
}
*/

//								Game Stats 3.0 code

/*
#include <iostream>
using namespace std;

int main(){
	
	const int ALIEN_POINTS = 150;
	int aliensKilled = 10;
	int score = aliensKilled*ALIEN_POINTS;
	cout<<"score: "<<score<<endl;
	
	enum difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE}; // novice is to 0, easy is to 1, and so on
	difficulty myDifficulty = EASY;
	
	enum shipCost {FIGHTER_COST=25, BOMBER_COST, CRUISER_COST=50};
	shipCost myShipCost = BOMBER_COST;
	cout<<"\nTo upgrade my ship to a Cruiser will cost "
		<<(CRUISER_COST-myShipCost)<<" Resource Points.\n";
		
	return 0;
}
*/

//								Lost Fortune code

/*
#include <iostream>
#include <string> //can use a string object to access a string through a variable, more in Chapter 3

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	
	const int GOLD_PIECES = 900;
	int adventurers, killed, survivors;
	string leader;
	
	//get information
	cout<<"Welcome to Lost Fortune\n\n";
	cout<<"Please enter the following for your personalized adventure\n";
	
	cout<<"Enter a number: ";
	cin>>adventurers;
	
	cout<<"Enter a number smaller than the first: ";
	cin>>killed;
	
	survivors = adventurers - killed;
	
	cout<<"Enter your last name: ";
	cin>>leader;
	
	//tell the story
	cout<<"\nA brave group of "<<adventurers<<" set out on a quest ";
	cout<<"-- in search of the lost treasure of the Ancient Dwarves. ";
	cout<<"The group was led by the legendary rogue, "<<leader<<". \n";
	cout<<"\nAlong the way, a band of marauding ogres ambushed the party. ";
	cout<<"All fought bravely under the command of "<<leader;
	cout<<", and the ogres were defeated, but at a cost. ";
	cout<<"Of the adventurers, "<<killed<<" were vanquished. ";
	cout<<"leaving just "<<survivors<<" in the group.\n";
	
	cout<<"\nThe party was about to give up all hope. ";
	cout<<"But while laying the deceased to rest, ";
	cout<<" they stumbled upon the buried fortune. ";
	cout<<"So the adventurers split "<<GOLD_PIECES<<" gold pieces. ";
	cout<<leader<<" held on to the extra "<<(GOLD_PIECES%survivors);
	cout<<" pieces to keep things fair, of course.\n";
	
	return 0;
}
*/

//								Exercises

#include <iostream>

using namespace std;

int main(){
	
	short int val1;
	short int val2;
	short int val3;
	short int totalScore;
	
	cout<<"Please enter the score of your first game: ";
	cin>>val1;
	
	cout<<"\nPlease enter the score of your second game: ";
	cin>>val2;
	
	cout<<"\nPlease enter the score of your third game: ";
	cin>>val3;
	
	totalScore = (val1+val2+val3)/3;
	
	cout<<"\nGreat Job! Your average score was "<<totalScore<<" points!";
	
	return 0;
}



//End of Chapter 1




