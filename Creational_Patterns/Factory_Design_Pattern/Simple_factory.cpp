#include<bits/stdc++.h>
using namespace std;

class Burger
{
	public:
	virtual void prepare() = 0;
	virtual ~Burger() {}
};

class BasicBurger : public Burger
{
	public:
	void prepare() override
	{
		cout<<"Preparing basic burger with bun and patty." << endl;
	}
};

class StandardBurger : public Burger
{
	public:
	void prepare() override
	{
		cout<<"Preparing standard burger with bun, patty, lettuce, and tomato." << endl;
	}
};

class DeluxeBurger : public Burger
{
	public:
	void prepare() override
	{
		cout<<"Preparing deluxe burger with bun, patty, lettuce, tomato, cheese, and bacon." << endl;
	}
};

class BurgerFactory
{
	public:
	static Burger* createBurger(string type)
	{
		if(type == "basic") 
		{
			return new BasicBurger();
		}
		else if(type == "standard") 
		{
			return new StandardBurger();
		}
		else if(type == "deluxe") 
		{
			return new DeluxeBurger();
		}
		
		return nullptr;
	}
};

int main()
{
	string type = "basic";
	BurgerFactory* factory = new BurgerFactory();
	Burger* myBurger = factory -> createBurger(type);
	if(myBurger) 
	{
		myBurger -> prepare();
		delete myBurger;
	}
	else 
	{
		cout<<"Invalid burger type." << endl;
	}
}