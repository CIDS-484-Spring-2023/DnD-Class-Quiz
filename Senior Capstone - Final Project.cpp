// Senior Capstone - Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
using namespace std;

//The struct that contains the class information
struct classInfo
{
	string title;
	string trait;
	string description;
	int points;
};

//Declare classInfo array
classInfo classInfoArray[12] = {
	{"Barbarian", "fierce", "A warrior of great physical strength and ferocity, using their rage to fuel their attacks.", 0},						//0
	{"Bard", "charismatic", "A performer, who uses their magical music to inspire and enchant their allies.", 0},									//1				
	{"Cleric", "devout", "A holy warrior, empowered by their faith in their deity to perform miracles.", 0},										//2
	{"Druid", "connected", "A nature-based mage, able to transform into various animals and control nature itself.", 0},							//3
	{"Fighter", "courageous", "A martial warrior, trained in the arts of combat and warfare.", 0},													//4
	{"Monk", "disciplined", "An ascetic warrior, trained to use their body as a weapon and their mind as an ally.", 0},								//5
	{"Paladin", "noble", "A holy knight, sworn to a code of justice and using their faith to protect those in need.", 0},							//6
	{"Ranger", "independent", "A wilderness expert, who uses their knowledge of the land to survive and defeat their foes.", 0},					//7
	{"Rogue", "cunning", "A sneaky thief, whose skills in stealth and lockpicking allow them to get into places others can't.", 0},					//8
	{"Sorcerer", "mysterious", "A natural mage, who uses their bloodline to cast powerful spells.", 0},												//9
	{"Warlock", "ambitious", "A mage with a dark power, who made a pact with a powerful being in exchange for their power.", 0},					//10
	{"Wizard", "knowledgeable", "A self taught mage, these masters of the arcane arts are capable of learning and casting all magic.", 0}			//11
};

//Function Prototypes
void introduction();
void conclusion(classInfo info[]);

//constant variables
const int TOTAL_QUESTIONS = 20;
const int QUESTIONS_SELECTED = 10;

//Main Function
int main()
{
	vector<int> askedQuestions;

	srand(time(0)); //set a random seed, essentially resetting all values back to default, and emptying the askedQuestions array
	
	//Introduction
	introduction();

	//Questionnaire
	while (askedQuestions.size() < QUESTIONS_SELECTED)
	{
		int questionNumber;
		do
		{
			questionNumber = rand() % TOTAL_QUESTIONS;

		} while (find(askedQuestions.begin(), askedQuestions.end(), questionNumber) != askedQuestions.end());

		askedQuestions.push_back(questionNumber);

		char input; // initialize input variable, will read what user answers to each question
		switch (questionNumber)
		{
		case 0:
			cout << "A friend wants to bring you to a large party! How do you react?\n";
			cout << "\tA) Agree to go without hesitation\n";
			cout << "\tB) Ask for details about the party\n";
			cout << "\tC) Agree, but only if they promise not to leave you alone\n";
			cout << "\tD) Make up an excuse to avoid going\n";
			cout << "Answer: ";
			cin >> input;
			
			if (input == 'a' || input == 'A')
			{
				classInfoArray[9].points += 2;
				classInfoArray[1].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[8].points += 2;
				classInfoArray[2].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[3].points += 2;
				classInfoArray[7].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[5].points += 2;
				classInfoArray[11].points += 1;
			}
			
			cout << "\n\n";
			break;
		case 1:
			cout << "A test is coming up soon. How do you study for it?\n";
			cout << "\tA) Study hard every day\n";
			cout << "\tB) Study a little bit each day\n";
			cout << "\tC) Cram it all in at the last second\n";
			cout << "\tD) Meh, I'll wing it\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[11].points += 2;
				classInfoArray[2].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[5].points += 2;
				classInfoArray[6].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[9].points += 2;
				classInfoArray[0].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[4].points += 2;
				classInfoArray[10].points += 1;
			}
			cout << "\n\n";
			break;
		case 2:
			cout << "Do you like groan-inducing puns?\n";
			cout << "\tA) Love them\n";
			cout << "\tB) They're alright\n";
			cout << "\tC) Only when someone else makes them\n";
			cout << "\tD) Dear God, spare me\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[1].points += 2;
				classInfoArray[10].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[2].points += 2;
				classInfoArray[11].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[3].points += 2;
				classInfoArray[0].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[7].points += 2;
				classInfoArray[8].points += 1;
			}
			cout << "\n\n";
			break;
		case 3:
			cout << "What kind of food do you like the most?\n";
			cout << "\tA) Sweet\n";
			cout << "\tB) Spicy\n";
			cout << "\tC) Salty\n";
			cout << "\tD) ...yes...\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[7].points += 2;
				classInfoArray[1].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[8].points += 2;
				classInfoArray[10].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[6].points += 2;
				classInfoArray[4].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[0].points += 2;
				classInfoArray[5].points += 1;
			}
			cout << "\n\n";
			break;
		case 4:
			cout << "You witness a person getting robbed by a thug! What will you do?\n";
			cout << "\tA) Charge in to the rescue\n";
			cout << "\tB) Help them, even if it's scary\n";
			cout << "\tC) Call for help\n";
			cout << "\tD) Someone else will take care of it\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[6].points += 2;
				classInfoArray[0].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[4].points += 2;
				classInfoArray[2].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[10].points += 2;
				classInfoArray[11].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[8].points += 2;
				classInfoArray[9].points += 1;
			}
			cout << "\n\n";
			break;
		case 5:
			cout << "How quickly do you respond to text messages once you see them?\n";
			cout << "\tA) Reply right away\n";
			cout << "\tB) Wait an hour or so, don't want to seem desperate\n";
			cout << "\tC) May reply, may not\n";
			cout << "\tD) Give it 2-3 business days... or never\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[7].points += 2;
				classInfoArray[11].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[1].points += 2;
				classInfoArray[9].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[0].points += 2;
				classInfoArray[4].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[3].points += 2;
				classInfoArray[10].points += 1;
			}
			cout << "\n\n";
			break;
		case 6:
			cout << "It's a beautiful day at the beach! What do you do?\n";
			cout << "\tA) Jump right into the water\n";
			cout << "\tB) Lay out a towel and get a good tan\n";
			cout << "\tC) I'll do what everyone else is doing\n";
			cout << "\tD) Can we go home yet?\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[3].points += 2;
				classInfoArray[1].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[5].points += 2;
				classInfoArray[2].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[6].points += 2;
				classInfoArray[11].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[4].points += 2;
				classInfoArray[8].points += 1;
			}
			cout << "\n\n";
			break;
		case 7:
			cout << "You find yourself with nothing to do on a weekend...\n";
			cout << "\tA) Time for an adventure!\n";
			cout << "\tB) I wonder what my friends are up to...\n";
			cout << "\tC) Finally, some well-deserved me time!\n";
			cout << "\tD) Guess I'll sleep then\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[4].points += 2;
				classInfoArray[1].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[6].points += 2;
				classInfoArray[3].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[8].points += 2;
				classInfoArray[10].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[0].points += 2;
				classInfoArray[11].points += 1;
			}
			cout << "\n\n";
			break;
		case 8:
			cout << "Can you go into a haunted house?\n";
			cout << "\tA) The house should be afraid of me\n";
			cout << "\tB) As long as others go with me\n";
			cout << "\tC) I could, but I wouldn't enjoy it\n";
			cout << "\tD) Does a single step count as going in?\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[6].points += 2;
				classInfoArray[0].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[2].points += 2;
				classInfoArray[9].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[7].points += 2;
				classInfoArray[10].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[11].points += 2;
				classInfoArray[3].points += 1;
			}
			cout << "\n\n";
			break;
		case 9:
			cout << "You just won a free vacation to anywhere in the world! Where will you go?\n";
			cout << "\tA) Someplace exotic, like an island!\n";
			cout << "\tB) Somewhere with lots of important historical artifacts\n";
			cout << "\tC) Anywhere that has really good food\n";
			cout << "\tD) I bet I could sell this ticket for a lot of money on EBay...\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[7].points += 2;
				classInfoArray[3].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[5].points += 2;
				classInfoArray[9].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[0].points += 2;
				classInfoArray[4].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[8].points += 2;
				classInfoArray[10].points += 1;
			}
			cout << "\n\n";
			break;
		case 10:
			cout << "There is a fork in the crossroads, with an option to go either left or right. There is a sign\n",
					"that says there is treasure at the end of the right path. What do you do?\n";
			cout << "\tA) Free loot! Go right\n";
			cout << "\tB) It's a trap! Go left\n";
			cout << "\tC) This won't end well. Turn around\n";
			cout << "\tD) This sign can't stop me because I can't read! I go straight\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[9].points += 2;
				classInfoArray[4].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[5].points += 2;
				classInfoArray[10].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[2].points += 2;
				classInfoArray[11].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[0].points += 2;
				classInfoArray[7].points += 1;
			}
			cout << "\n\n";
			break;
		case 11:
			cout << "You are given a bucket, and are told to put water in it. How much do you fill the bucket?\n";
			cout << "\tA) To the brim\n";
			cout << "\tB) About 3/4 of the way\n";
			cout << "\tC) Half full / Half empty\n";
			cout << "\tD) A single drop\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[10].points += 2;
				classInfoArray[6].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[1].points += 2;
				classInfoArray[2].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[9].points += 2;
				classInfoArray[8].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[3].points += 2;
				classInfoArray[5].points += 1;
			}
			cout << "\n\n";
			break;
		case 12:
			cout << "There is someone you like, but you're unsure of how they feel about you. How do you approach them?\n";
			cout << "\tA) Saunter up to them and bravely declare my feelings\n";
			cout << "\tB) Might try to get their contact info from a friend, and DM them\n";
			cout << "\tC) Get your friends to figure out if they like you back\n";
			cout << "\tD) Me? Approach them?\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[6].points += 2;
				classInfoArray[4].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[1].points += 2;
				classInfoArray[9].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[2].points += 2;
				classInfoArray[7].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[11].points += 2;
				classInfoArray[5].points += 1;
			}
			cout << "\n\n";
			break;
		case 13:
			cout << "You hear a scream from behind a door!\n";
			cout << "\tA) Open the door and face whatever danger lurks behind it\n";
			cout << "\tB) Run and get help\n";
			cout << "\tC) Scream with them\n";
			cout << "\tD) Oh, looks like it's occupied, I'll try another door\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[6].points += 2;
				classInfoArray[0].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[1].points += 2;
				classInfoArray[9].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[3].points += 2;
				classInfoArray[7].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[8].points += 2;
				classInfoArray[10].points += 1;
			}
			cout << "\n\n";
			break;
		case 14:
			cout << "You find a wallet lying in the middle of the sidewalk. What do you do?\n";
			cout << "\tA) Immediately turn it in to the police\n";
			cout << "\tB) Take a peek inside, but don't take anything, and turn it in\n";
			cout << "\tC) Take a peek inside, and help yourself to a finder's fee BEFORE turning it in\n";
			cout << "\tD) Dibs!\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[2].points += 2;
				classInfoArray[5].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[11].points += 2;
				classInfoArray[10].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[4].points += 2;
				classInfoArray[1].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[8].points += 2;
				classInfoArray[9].points += 1;
			}
			cout << "\n\n";
			break;
		case 15:
			cout << "You receive a gift from a complete stranger. What do you do with it?\n";
			cout << "\tA) Open it now\n";
			cout << "\tB) Open it later\n";
			cout << "\tC) Ask someone else to open it for you\n";
			cout << "\tD) Toss it in the trash\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[4].points += 2;
				classInfoArray[9].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[7].points += 2;
				classInfoArray[6].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[2].points += 2;
				classInfoArray[1].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[10].points += 2;
				classInfoArray[5].points += 1;
			}
			cout << "\n\n";
			break;
		case 16:
			cout << "Your date fails to show up on time. How do you react?\n";
			cout << "\tA) They might just be running a little late...\n";
			cout << "\tB) To hell with this, I'm out of here\n";
			cout << "\tC) I'll just call them once, or twice, or 80 times...\n";
			cout << "\tD) Well, I'm here already, might as well enjoy myself\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[5].points += 2;
				classInfoArray[11].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[9].points += 2;
				classInfoArray[1].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[7].points += 2;
				classInfoArray[1].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[4].points += 2;
				classInfoArray[0].points += 1;
			}
			cout << "\n\n";
			break;
		case 17:
			cout << "You're the hypeman / hypewoman for your friend in a rap battle! What do you do?\n";
			cout << "\tA) Give them encouragement\n";
			cout << "\tB) Heckle their opponent\n";
			cout << "\tC) Get the crowd fired up for your side\n";
			cout << "\tD) Be the strong and silent type\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[3].points += 2;
				classInfoArray[2].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[1].points += 2;
				classInfoArray[8].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[1].points += 2;
				classInfoArray[10].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[6].points += 2;
				classInfoArray[0].points += 1;
			}
			cout << "\n\n";
			break;
		case 18:
			cout << "You come across an unlocked treasure chest on the beach! What do you do?\n";
			cout << "\tA) Open it up, obviously!\n";
			cout << "\tB) Get some other people to help figure out what to do\n";
			cout << "\tC) Leave it alone, it's probably empty\n";
			cout << "\tD) Bury it, because that's what you do with treasure\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[9].points += 2;
				classInfoArray[4].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[11].points += 2;
				classInfoArray[6].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[3].points += 2;
				classInfoArray[10].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[8].points += 2;
				classInfoArray[5].points += 1;
			}
			cout << "\n\n";
			break;
		case 19:
			cout << "What would you say is your best quality?\n";
			cout << "\tA) I'm incredibly smart, and can solve almost any problem through logic\n";
			cout << "\tB) Nothing can stand in the way of my brute strength\n";
			cout << "\tC) My mom always said I was a handsome / beautiful child\n";
			cout << "\tD) I'm good at avoiding these kind of questions\n";
			cout << "Answer: ";
			cin >> input;

			if (input == 'a' || input == 'A')
			{
				classInfoArray[11].points += 2;
				classInfoArray[2].points += 1;
			}
			else if (input == 'b' || input == 'B')
			{
				classInfoArray[0].points += 2;
				classInfoArray[4].points += 1;
			}
			else if (input == 'c' || input == 'C')
			{
				classInfoArray[10].points += 2;
				classInfoArray[3].points += 1;
			}
			else if (input == 'd' || input == 'D')
			{
				classInfoArray[7].points += 2;
				classInfoArray[5].points += 1;
			}
			cout << "\n\n";
			break;
		default: // will occur if error is in code
			cout << "ERROR HAS OCCURED HERE";
			break;
		}
	}

	//Conclusion
	conclusion(classInfoArray);

	return 0;
} // end of main program loop


//Introduction
void introduction()
{
	string name;

	cout << "Welcome to the Dungeons and Dragons Class Quiz!\n";
	cout << "Please enter your name: ";
	cin >> name;

	cout << "\nWelcome, " << name << "!\n";
	cout << "This quiz will ask you a series of questions, and based on your answers, will determine which Dungeons and Dragons class you are best suited to.\n";
	cout << "It is important that you answer these questions truthfully, or else the results will not me accurate...\n";
	cout << "Let's get started!\n\n";
}

//Conclusion
void conclusion(classInfo info[])
{
	int highestPoints = classInfoArray[0].points;
	string highestClass;
	int classCounter = 0;
	bool tie = false;

	//Find highest points
	for (int i = 1; i < 12; i++)
	{
		if (info[i].points > highestPoints)
		{
			highestPoints = info[i].points;
			highestClass = info[i].title;
			classCounter++;
			tie = false;
		}
		else if (info[i].points == highestPoints)
		{
			tie = true;
		}
	}

	//Display conclusion
	cout << "\nYou scored the highest in the " << highestClass << " class!\n";
	cout << classInfoArray[classCounter].description << "\n";

	if (tie)
	{
		cout << "\nYou also tied in the following class options:\n";
		for (int i = 0; i < 13; i++)
		{
			if (info[i].points == highestPoints && info[i].title != highestClass)
				cout << info[i].title << ": " << info[i].description << "\n";
		}

		cout << "\nYou have the rare ability to multiclass! Congratulations!";
	}

	cout << "\nWould you like to take the quiz again? (y/n): ";
	char input;
	cin >> input;

	if (input == 'y' || input == 'Y')
		main();
	else
		cout << "\nThank you for taking the quiz! Goodbye!";
}

