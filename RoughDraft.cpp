/*
	Name: Rough Draft
	Author: Jackson Gergen
	Date: 01/02/23 14:07
	Description: This is a rough draft of what the code will look like. Not fully set on the point system yet,
					but this is a start!
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//The struct that contains the class information
struct classInfo
{
	string title;
	string description;
	int points;
};

//Function Prototypes
void introduction();
void questionnaire(classInfo& info);
void conclusion(classInfo info[]);

//Main Function
int main() 
{
	srand(time(0)); //Random seed
	
	//Declare classInfo array
	classInfo classInfoArray[12] = {
		{"Artificer", "A mage-like engineer who uses their magical knowledge to create magical items.", 0},
		{"Barbarian", "A warrior of great physical strength and ferocity, using their rage to fuel their attacks.", 0},
		{"Bard", "A performer, who uses their magical music to inspire and enchant their allies.", 0},
		{"Cleric", "A holy warrior, empowered by their faith in their deity to perform miracles.", 0},
		{"Druid", "A nature-based mage, able to transform into various animals and control nature itself.", 0},
		{"Fighter", "A martial warrior, trained in the arts of combat and warfare.", 0},
		{"Monk", "An ascetic warrior, trained to use their body as a weapon and their mind as an ally.", 0},
		{"Paladin", "A holy knight, sworn to a code of justice and using their faith to protect those in need.", 0},
		{"Ranger", "A wilderness expert, who uses their knowledge of the land to survive and defeat their foes.", 0},
		{"Rogue", "A sneaky thief, whose skills in stealth and lockpicking allow them to get into places others can't.", 0},
		{"Sorcerer", "A natural mage, who uses their bloodline to cast powerful spells.", 0},
		{"Warlock", "A mage with a dark power, who made a pact with a powerful being in exchange for their power.", 0}
	};
	
	//Introduction
	introduction();
	
	//Questionnaire
	for(int i = 0; i < 12; i++)
	{
		cout << endl;
		questionnaire(classInfoArray[i]);
	}
	
	//Conclusion
	conclusion(classInfoArray);
	
	return 0;
}


//Introduction
void introduction()
{
	string name;
	
	cout << "Welcome to the Dungeons and Dragons Class Quiz!\n";
	cout << "Please enter your name: ";
	cin >> name;
	
	cout << "\nWelcome, " << name << "!\n";
	cout << "This quiz will ask you a series of questions, and based on your answers, will determine which Dungeons and Dragons class you are best suited to.\n";
	cout << "Let's get started!\n";
}

//Questionnaire
void questionnaire(classInfo &info)
{
	int input;
	
	cout << "\nQuestion for the " << info.title << " class:" << endl;
	
	//Randomly selects a question
	int questionNumber = rand() % 5;
	switch(questionNumber)
	{
		case 0:
			cout << "You are exploring a dungeon, and you come across a group of goblins. How do you handle the situation?\n";
			cout << "A) Attack them head on\n";
			cout << "B) Sneak past them\n";
			cout << "C) Try to talk with them\n";
			cout << "D) Run away\n";
			cin >> input;
			if(input == 'a' || input == 'A')
				info.points += 2;
			else if(input == 'b' || input == 'B')
				info.points += 1;
			break;
		case 1:
			cout << "You are in a city, and you come across a person in need. How do you respond?\n";
			cout << "A) Ignore the person\n";
			cout << "B) Offer them help\n";
			cout << "C) Give them money\n";
			cout << "D) Ask them what they need\n";
			cin >> input;
			if(input == 'b' || input == 'B')
				info.points += 2;
			else if(input == 'c' || input == 'C' || input == 'd' || input == 'D')
				info.points += 1;
			break;
		case 2:
			cout << "You are in a forest and you come across a creature that you have never seen before. What do you do?\n";
			cout << "A) Attack it\n";
			cout << "B) Run away\n";
			cout << "C) Observe it from a distance\n";
			cout << "D) Try to communicate with it\n";
			cin >> input;
			if(input == 'c' || input == 'C' || input == 'd' || input == 'D')
				info.points += 2;
			else if(input == 'a' || input == 'A')
				info.points += 1;
			break;
		case 3:
			cout << "You are walking through a town, and you come across a group of thugs. How do you respond?\n";
			cout << "A) Attack them head on\n";
			cout << "B) Try to talk them out of their plans\n";
			cout << "C) Try to sneak past them\n";
			cout << "D) Run away\n";
			cin >> input;
			if(input == 'b' || input == 'B')
				info.points += 2;
			else if(input == 'c' || input == 'C' || input == 'd' || input == 'D')
				info.points += 1;
			break;
		case 4:
			cout << "You are walking through a forest, and you come across a group of bandits. How do you handle the situation?\n";
			cout << "A) Attack them head on\n";
			cout << "B) Try to talk to them\n";
			cout << "C) Try to sneak past them\n";
			cout << "D) Run away\n";
			cin >> input;
			if(input == 'c' || input == 'C')
				info.points += 2;
			else if(input == 'a' || input == 'A' || input == 'd' || input == 'D')
				info.points += 1;
			break;
		default:
			//Error
			break;
	}
}

//Conclusion
void conclusion(classInfo info[])
{
	int highestPoints = 0;
	string highestClass;
	bool tie = false;
	
	//Find highest points
	for(int i = 0; i < 12; i++)
	{
		if(info[i].points > highestPoints)
		{
			highestPoints = info[i].points;
			highestClass = info[i].title;
			tie = false;
		}
		else if(info[i].points == highestPoints)
		{
			tie = true;
		}
	}
	
	//Display conclusion
	cout << "\nYou scored the highest in the " << highestClass << " class!\n";
	cout << "The " << highestClass << " is a " << info[0].description << "\n";
	
	if(tie)
	{
		cout << "\nYou also tied in the following class:\n";
		for(int i = 0; i < 12; i++)
		{
			if(info[i].points == highestPoints && info[i].title != highestClass)
				cout << info[i].title << ": " << info[i].description << "\n";
		}
		
		cout << "\nYou have the rare ability to multiclass! Congratulations!";
	}
	
	cout << "\nWould you like to take the quiz again? (y/n): ";
	char input;
	cin >> input;
	
	if(input == 'y' || input == 'Y')
		main();
	else
		cout << "\nThank you for taking the quiz! Goodbye!";
}

