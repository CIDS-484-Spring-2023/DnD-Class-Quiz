/*
	Name: Pseudocode
	Author: Jackson Gergen
	Date: 26/01/23 14:27
	Description: Details project outline for a Dungeons and Dragons Character Class Personality Quiz
*/

/*
	Project: Dungeons and Dragons Class Quiz
	
	Purpose: By asking the user several questions, this program will be able to determine which class
	in the RPGTT Dungeons and Dragons best fits your personality
	
	Outline: 
	
	1)Introduction
		- this section of the code will contain methods that when called, output text to the screen that introduces the 
		program to the user, and explains what it does
		- *optional* program could ask for the user's name for a more personal touch
		
	2)Questionnaire
		-Program will take random questions from the Questionnaire block, and ask the user for their answer, one question
		at a time
		- questions will be in multiple choice format
		- each answer will add 1-2 points to 1 or more classes, depending on how they answer
			- example; someone who would pick the lock of a door rather than knock on the door to get it open would gain 
			points towards the Rogue class
		- at the end of the quiz, program will count which class has the highest amount of points, and tell the user
		that this would be the best class for them
			-each class, upon being assigned, will also have a brief description of the essence of that class
			-if there is a tie between two classes, program will announce a rare 'multiclass' occurence, and display
			both classes and their descriptions for the user
			
	3)Program loop
		-program would then ask the user if they would like to take the quiz again
			-if no, exit the program
			-if yes, get a new random selection of questions and begin again
	
	4)Inspiration
		- inspiration for this is taken from the Pokemon Mystery Dungeon Rescue Team quiz, which 
		asks questions, and assigns a pokemon to you depending on your answers
		-https://www.eurogamer.net/pokemon-mystery-dungeon-rescue-team-dx-personality-quiz-answers-playable-pokemon
		-johanngan user on GitHub has a decent setup of the pokemon quiz, plan to use similar template, but NOT same questions/answers
			-https://github.com/johanngan/pmd-quiz
		-additional website questionnaire
			-https://uquiz.com/quiz/eWDHo9/which-dnd-class-suits-your-personality
			
	5)Available Classes
		-Artificer
		-Barbarian
		-Bard
		-Cleric
		-Druid
		-Fighter
		-Monk
		-Paladin
		-Ranger
		-Rogue
		-Sorcerer
		-Warlock
		-Wizard	
*/

