// Chapter 9 code

//								Critter Farm program

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Critter
{
	public:
		Critter(const string& name = "");
		string GetName() const;
		
	private:
		string m_Name;
};

Critter::Critter(const string& name):
	m_Name(name)
{}

inline string Critter::GetName() const
{
	return m_Name;
}

class Farm
{
	public:
		Farm(int spaces = 1);
		void Add(const Critter& aCritter);
		void RollCall() const;
		
	private:
		vector<Critter> m_Critters;
};

Farm::Farm(int spaces)
{
	m_Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter)
{
	m_Critters.push_back(aCritter);
}

void Farm::RollCall() const
{
	for(vector<Critter>::const_iterator iter = m_Critters.begin();
		iter != m_Critters.end(); ++iter)
	{
		cout<<iter->GetName()<<" here.\n";
	}
}

int main()
{
	Critter crit("Poochie");
	cout<<"My critter's name is "<<crit.GetName()<<endl;
	
	cout<<"Creating critter farm.\n";
	Farm myFarm(3);
	
	cout<<"\nAdding three critters to the farm.\n";
	myFarm.Add(Critter("Moe"));
	myFarm.Add(Critter("Larry"));
	myFarm.Add(Critter("Curly"));
	
	cout<<"\nCalling Roll...\n";
	myFarm.RollCall();
	
	return 0;
}
*/

//								Friend Critter program

/*
#include <iostream>
#include <string>
using namespace std;

class Critter
{
	//make following global functions friends of the Critter class
	friend void Peek(const Critter& aCritter);
	friend ostream& operator<<(ostream& os, const Critter& aCritter);
	
	public:
		Critter(const string& name = "");
		
	private:
		string m_Name;
};

Critter::Critter(const string& name):
	m_Name(name)
{}

void Peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);

int main()
{
	Critter crit("Poochie");
	
	cout<<"Calling Peek() to access crit's private data member, m_Name:\n";
	Peek(crit);
	
	cout<<"\nSending crit object to cout with the << operator:\n";
	cout<<crit;
	
	return 0;
}

//global friend function that can access all of a Critter object's members
void Peek(const Critter& aCritter)
{
	cout<<aCritter.m_Name<<endl;
}

//global friend function that can access all of a Critter object's members
//overloads the '<<' operator so you can send a Critter object to cout
ostream& operator<<(ostream& os, const Critter& aCritter)
{
	os<<"Critter Object - ";
	os<<"m_Name: "<<aCritter.m_Name;
	return os;
}
*/

//								Heap program

/*
#include <iostream>
using namespace std;

int* intOnHeap();		//returns an int on the heap
void leak1();			//creates memory leak
void leak2();			//creates another memory leak

int main()
{
	int* pHeap = new int;
	*pHeap = 10;
	cout<<"*pHeap: "<<*pHeap<<"\n\n";
	
	int* pHeap2 = intOnHeap();
	cout<<"*pHeap2: "<<*pHeap2<<"\n\n";
	
	cout<<"Freeing memory pointed to by pHeap.\n\n";
	delete pHeap;
	
	cout<<"Freeing memory pointed to by pHeap2.\n\n";
	delete pHeap2;
	
	//get rid of dangling pointers
	pHeap=0;
	pHeap2=0;
	
	return 0;
}

int* intOnHeap()
{
	int* pTemp = new int(20);
	return pTemp;
}

void leak1()
{
	int* drip1 = new int(30);
}

void leak2()
{
	int* drip2 = new int(50);
	drip2 = new int(100);
	delete drip2;
}
*/

//								Heap Data Member program

/*
#include <iostream>
#include <string>
using namespace std;

class Critter
{
	public:
		Critter(const string& name="", int age=0);
		~Critter();										//destructor prototype
		Critter(const Critter& c);						//copy constructor prototype
		Critter& operator=(const Critter& c);	//overloaded assignment operator
		void Greet() const;
		
	private:
		string* m_pName;
		int m_Age;	
};

Critter::Critter(const string& name, int age)
{
	cout<<"Constructor called\n";
	m_pName = new string(name);
	m_Age = age;
}

Critter::~Critter()										//destructor definition
{
	cout<<"Destructor called\n";
	delete m_pName;
}

Critter::Critter(const Critter& c)						//copy constructor definition
{
	cout<<"Copy constructor called\n";
	m_pName = new string(*(c.m_pName));
	m_Age = c.m_Age;
}

Critter& Critter::operator=(const Critter& c)			//overloaded assignment operator definition
{
	cout<<"Overloaded assignment operator called\n";
	if(this != &c)
	{
		delete m_pName;
		m_pName = new string(*(c.m_pName));
		m_Age = c.m_Age;
	}
	
	return *this;
}

void Critter::Greet() const
{
	cout<<"I'm "<<*m_pName<<" and I'm "<<m_Age<<" years old. ";
	cout<<"&m_pName: "<<&m_pName<<endl;
}

void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

int main()
{
	testDestructor();
	cout<<endl;
	
	Critter crit("Poochie", 5);
	crit.Greet();
	testCopyConstructor(crit);
	crit.Greet();
	cout<<endl;
	
	testAssignmentOp();
	
	return 0;
}

void testDestructor()
{
	Critter toDestroy("Rover", 3);
	toDestroy.Greet();
}

void testCopyConstructor(Critter aCopy)
{
	aCopy.Greet();
}

void testAssignmentOp()
{
	Critter crit1("crit1", 7);
	Critter crit2("crit2", 9);
	crit1 = crit2;
	crit1.Greet();
	crit2.Greet();
	cout<<endl;
	
	Critter crit3("crit3", 11);
	crit3 = crit3;
	crit3.Greet();
}
*/

//								Game Lobby program


#include <iostream>
#include <string>
using namespace std;

class Player
{
	public:
		Player(const string& name="");
		string GetName() const;
		Player* GetNext() const;
		void SetNext(Player* next);
		
	private:
		string m_Name;
		Player* m_pNext;	//pointer to next player in list
};

Player::Player(const string& name):
	m_Name(name),
	m_pNext(0)
{}

string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}

class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);
	
	public:
		Lobby();
		~Lobby();
		void AddPlayer();
		void RemovePlayer();
		void Clear();
		
	private:
		Player* m_pHead;		//first person in line
};

Lobby::Lobby():
	m_pHead(0)
{}

Lobby::~Lobby()
{
	Clear();
}

void Lobby::AddPlayer()
{
	//create new player node
	cout<<"Please enter the name of the new player: ";
	string name;
	cin>>name;
	Player* pNewPlayer = new Player(name);
	
	//if list is empty, make head of list this new player
	if(m_pHead == 0)
	{
		m_pHead = pNewPlayer;
	}
	//otherwise find the end of the list and add the player there
	else
	{
		Player* pIter = m_pHead;
		while(pIter->GetNext() != 0)
		{
			pIter = pIter->GetNext();
		}
		pIter->SetNext(pNewPlayer);
	}
}

void Lobby::RemovePlayer()
{
	if(m_pHead == 0)
	{
		cout<<"The game lobby is empty. No one to remove.\n";
	}
	else
	{
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

void Lobby::Clear()
{
	while(m_pHead != 0)
	{
		RemovePlayer();
	}
}

ostream& operator<<(ostream& os, const Lobby& aLobby)	//if 'cout' is on left side of '<<' operator and a Lobby object is on the other side,
														//run the following
{
	Player* pIter = aLobby.m_pHead;
	
	os<<"\nHere's who's in the game lobby:\n";
	if(pIter == 0)
	{
		os<<"The lobby is currently empty.\n";
	}
	else
	{
		while(pIter != 0)
		{
			os<<pIter->GetName()<<endl;
			pIter = pIter->GetNext();
		}
	}
	
	return os;
}

int main()
{
	Lobby myLobby;
	int choice;
	
	do
	{
		cout<<myLobby;									//this activates the overloaded assignment operator function
		cout<<"\nGAME LOBBY\n";
		cout<<"0 - Exit the Program\n";
		cout<<"1 - Add a Player to the Lobby\n";
		cout<<"2 - Remove a Player from the Lobby\n";
		cout<<"3 - Clear the Lobby\n";
		cout<<endl<<"Enter choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 0: cout<<"Good-bye\n"; break;
			case 1: myLobby.AddPlayer(); break;
			case 2: myLobby.RemovePlayer(); break;
			case 3: myLobby.Clear(); break;
			default: cout<<"That was not a valid choice\n";
		}
	}
	while(choice != 0);
	
	return 0;
}
