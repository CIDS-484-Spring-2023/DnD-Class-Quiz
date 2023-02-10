//								Score Rater code

/*
#include <iostream>
using namespace std;

int main(){
	
	if (true){
		cout<<"This is always displayed.\n\n";
	}
	
	if (false){
		cout<<"This is never displayed.\n\n";
	}
	
	int score = 1000;
	
	if (score){
		cout<<"At least you didn't score zero.\n\n";
	}
	
	if (score>=250){
		cout<<"You scored 250 or more. Decent.\n\n";
	}
	
	if (score>=500){
		cout<<"You scored 500 or more. Nice!\n\n";
	}
	
	if (score>=1000){
		cout<<"You scored 1000 or more. Impressive!\n\n";
	}
	
	return 0;
}
*/

//								Score Rater 2.0 code

/*
#include <iostream>
using namespace std;

int main(){
	
	int score;
	cout<<"Please Enter Your Score: ";
	cin>>score;
	
	if (score>=1000){
		cout<<"You scored 1000 or more. Impressive!\n\n";
	}
	else{
		cout<<"You scored less than 1000.\n\n";
	}
	
	return 0;
}
*/

//								Score Rater 3.0 code

/*
#include <iostream>
using namespace std;

int main(){
	
	int score;
	cout<<"Enter your Score: ";
	cin>>score;
	
	if (score>=1000){
		cout<<"You scored 1000 or more. Impressive!\n";
	}
	else if (score>=500){
		cout<<"You scored 500 or more. Nice.\n";
	}
	else if (score>=250){
		cout<<"You scored 250 or more. Decent.\n";
	}
	else{
		cout<<"You scored less than 250. Nothing to brag about.\n";
	}
	
	return 0;
}
*/

//								Menu Chooser code

/*
#include <iostream>
using namespace std;

int main(){
	
	cout<<"Difficulty Levels\n\n";
	cout<<"1 - Easy\n";
	cout<<"2 - Normal\n";
	cout<<"3 - Hard\n\n";
	
	int choice;
	cout<<"Choice: ";
	cin>>choice;
	
	switch (choice){
		
		case 1:
			cout<<"You picked Easy.\n";
			break;
			
		case 2:
			cout<<"You picked Normal.\n";
			break;
			
		case 3:
			cout<<"You picked Hard.\n";
			break;
			
		default:
			cout<<"You made an illegal choice.\n";
	}
	
	return 0;
}
*/

//								Play Again code

/*
#include <iostream>
using namespace std;

int main(){
	
	char again = 'y';
	while (again == 'y'){
		cout<<"\n**Played an exciting game**";
		cout<<"\nDo you want to play again? (y/n): ";
		cin>>again;
	}
	
	cout<<"\nOkay, bye.";
	
	return 0;
}
*/

//								Play Again 2.0 code

/*
#include <iostream>
using namespace std;

int main(){
	
	char again;
	do{
		cout<<"\n**Played an Exciting Game**";
		cout<<"\nDo you want to play again? (y/n): ";
		cin>>again;
	} while (again == 'y');
	
	cout<<"\nOkay, bye.";
	
	return 0;
}
*/

//								Finicky Counter code

/*
#include <iostream>
using namespace std;

int main(){
	
	int count = 0;
	while (true){
		
		count+=1;
		
		if (count > 10){
			break;
		}
		
		if (count == 5){
			continue;
		}
		
		cout<<count<<endl;
	}
	
	return 0;
}
*/

//								Designers Network code

/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string username;
	string password;
	bool success;
	
	cout<<"\tGame Designer's Network\n";
	
	do{
		
		cout<<"\nUsername: ";
		cin>>username;
		
		cout<<"\nPassword: ";
		cin>>password;
		
		if (username=="J.Gergen" && password=="captain"){
			cout<<"\nHello, Master Jackson.";
			success = true;
		}
		
		else if (username=="Guest" && password=="guest"){
			cout<<"\nHello, Guest.";
			success = true;
		}
		
		else{
			cout<<"\nYour login has failed, please try again.";
			success = false;
		}
	} while (!success);
	
	return 0;
}
*/

//								Die Roller code

/*
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	
	srand(static_cast<unsigned int>(time(0))); //seed random number generator
	
	int randomNumber = rand();
	
	int die = (randomNumber%6)+1;
	cout<<"You rolled a "<<die<<endl;
	
	return 0;
}
*/

//								Guess My Number code

/*
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	
	srand(static_cast<unsigned int>(time(0)));
	
	int secretNumber = rand()%100+1;
	int tries = 0;
	int guess;
	
	cout<<"\tWelcome to Guess My Number\n\n";
	
	do{
		cout<<"Enter a guess: ";
		cin>>guess;
		++tries;
		
		if (guess>secretNumber){
			cout<<"Too high!\n\n";
		}
		
		else if (guess<secretNumber){
			cout<<"Too low!\n\n";
		}
		
		else{
			cout<<"\nThat's it! You got it in "<<tries<<" guesses!\n";
		}
	} while (guess != secretNumber);
	
	return 0;
}
*/

//								Guess My Number - Reversed Roles

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
	
	int tries = 0;
	int min = 1;
	int max = 100;
	int currentGuess = 50;
	string answer;
	char ready;
	
	cout<<"\tWelcome to Guess YOUR Number: The famous sequel of \'Guess My Number\'!\n\n";
	
	cout<<"Do you have a number between 1 and 100? (y/n): ";
	cin>>ready;
	
	if (ready == 'y'){
		
		do{
			
			cout<<"\nIs your number "<<currentGuess<<"? (high/low/correct): ";
			cin>>answer;
			++tries;
			
			if (answer == "high"){
				max = currentGuess;
				currentGuess = (min+max)/2;
				cout<<"\nDarn it!\n";
			}
			
			else if (answer == "low"){
				min = currentGuess;
				currentGuess = (min+max)/2;
				cout<<"\nDarn it!\n";
			}
			
		} while (answer != "correct");
		
		cout<<"\n\nHooray! I guessed your number in "<<tries<<" guesses! Good Game!";
	}
	
	else{
		cout<<"Okay, take your time...";
	}
	
	return 0;
}































