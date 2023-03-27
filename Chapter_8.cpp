//	Chapter 8 code

//								Simple Critter program

/*
#include <iostream>
using namespace std;

class Critter			//class definition--defines a new type, Critter
{
	public:
		int m_Hunger;	//data member
		void Greet();	//member function prototype
};

void Critter::Greet()	//member function definition
{
	cout<<"Hi. I'm a critter. My hunger level is "<<m_Hunger<<".\n";
}

int main()
{
	Critter crit1;
	Critter crit2;
	
	crit1.m_Hunger = 9;
	cout<<"crit1's hunger level is "<<crit1.m_Hunger<<".\n";
	
	crit2.m_Hunger = 3;
	cout<<"crit2's hunger level is "<<crit2.m_Hunger<<".\n\n";
	
	crit1.Greet();
	crit2.Greet();
	
	return 0;
}
*/

//								Constructor Critter program

/*
#include <iostream>
using namespace std;

class Critter
{
	public:
		int m_Hunger;
		Critter(int hunger=0);	//constructor prototype
		void Greet();
};

Critter::Critter(int hunger)	//constructor definition
{
	cout<<"A new critter has been born!"<<endl;
	m_Hunger = hunger;
}

void Critter::Greet()
{
	cout<<"Hi. I'm a critter. My hunger level is "<<m_Hunger<<".\n\n";
}

int main()
{
	Critter crit(7);
	crit.Greet();
	
	return 0;
}
*/

//								Private Critter program

/*
#include <iostream>
using namespace std;

class Critter
{
	public:							//begin public section
		Critter(int hunger=0);
		int GetHunger() const;
		void SetHunger(int hunger);
		
	private:						//begin private section
		int m_Hunger;	
};

Critter::Critter(int hunger):
	m_Hunger(hunger)
{
	cout<<"A new critter has been born!"<<endl;
}

int Critter::GetHunger() const
{
	return m_Hunger;
}

void Critter::SetHunger(int hunger)
{
	if(hunger<0)
	{
		cout<<"You cannot set a critter's hunger to a negative number.\n\n";
	}
	else
	{
		m_Hunger = hunger;
	}
}

int main()
{
	Critter crit(5);
	//cout<<crit.m_Hunger;		//illegal, m_Hunger is a private member of the Critter class
	cout<<"Calling GetHunger(): "<<crit.GetHunger()<<"\n\n";
	
	cout<<"Calling SetHunger() with 9.\n";
	crit.SetHunger(9);
	cout<<"Calling GetHunger(): "<<crit.GetHunger()<<"\n\n";
	
	return 0;
}
*/

//								Static Critter program

/*
#include <iostream>
using namespace std;

class Critter
{
	public:
		static int s_Total;		//static member variable declaration
								//total number of Critter objects in existence
		Critter(int hunger=0);
		static int GetTotal();
		
	private:
		int m_Hunger;
};

int Critter::s_Total = 0;		//static member variable initialization

Critter::Critter(int hunger):
	m_Hunger(hunger)
{
	cout<<"A critter has been born!"<<endl;
	++s_Total;
}

int Critter::GetTotal()			//static member function definition
{
	return s_Total;
}

int main()
{
	cout<<"The total number of critters is: ";
	cout<<Critter::s_Total<<"\n\n";
	
	Critter crit1, crit2, crit3;
	
	cout<<"\nThe total number of critters is: ";
	cout<<Critter::s_Total<<"\n";
	
	return 0;
}
*/

//								Critter Caretaker game


/*

Create a Critter
While the player doesn't want to quit the game
	Present a menu of choices to the player
	If the player wants to listen to the critter
		Make the critter talk
	If the player wants to feed the critter
		Make the critter eat
	If the player wants to play with the critter
		Make the critter play

*/

#include <iostream>
using namespace std;

class Critter
{
	public:
		Critter(int hunger=0, int boredom=0);
		void Talk();
		void Eat(int food=4);
		void Play(int fun=4);
		
	private:
		int m_Hunger;
		int m_Boredom;
		
		int GetMood() const;
		void PassTime(int time=1);
};

Critter::Critter(int hunger, int boredom):
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	cout<<"I'm a critter and I feel ";
	int mood = GetMood();
	
	if(mood>15)
	{
		cout<<"mad.\n";
	}
	else if(mood>10)
	{
		cout<<"frustrated.\n";
	}
	else if(mood>5)
	{
		cout<<"okay.\n";
	}
	else
	{
		cout<<"happy.\n";
	}
	
	PassTime();
}

void Critter::Eat(int food)
{
	cout<<"BUUURRRP.\n";
	
	m_Hunger -= food;
	if(m_Hunger<0)
	{
		m_Hunger = 0;
	}
	
	PassTime();
}

void Critter::Play(int fun)
{
	cout<<"WHEEEEEE!\n";
	
	m_Boredom -= fun;
	if(m_Boredom<0)
	{
		m_Boredom = 0;
	}
	
	PassTime();
}

int main()
{
	Critter crit;
	crit.Talk();
	
	int choice;
	do
	{
		cout<<"\nCritter Caretaker\n\n";
		cout<<"0 - Quit\n";
		cout<<"1 - Listen to your critter\n";
		cout<<"2 - Feed your critter\n";
		cout<<"3 - Play with your critter\n\n";
		
		cout<<"Choice: ";
		cin>>choice;
		cout<<"\n";
		
		switch(choice)
		{
			case 0:
				cout<<"Good-bye.\n";
				break;
			case 1:
				crit.Talk();
				break;
			case 2:
				crit.Eat();
				break;
			case 3:
				crit.Play();
				break;
			default:
				cout<<"\nSorry, but "<<choice<<" is not a valid choice.\n";
		}
	}while(choice != 0);
	
	return 0;
}
