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

class BasicWheatBurger : public Burger
{
	public:
	void prepare() override
	{
		cout<<"Preparing basic wheat burger with wheat bun and patty." << endl;
	}
};

class StandardWheatBurger : public Burger
{
	public:
	void prepare() override
	{
		cout<<"Preparing standard wheat burger with wheat bun, patty, lettuce, and tomato." << endl;
	}
};

class DeluxeWheatBurger : public Burger
{
	public:
	void prepare() override
	{
		cout<<"Preparing deluxe wheat burger with wheat bun, patty, lettuce, tomato, cheese, and bacon." << endl;
	}
};

class BurgerFactory
{
	public:
	virtual Burger* createBurger(string type) = 0;
	virtual ~BurgerFactory() {}
};

class SinghBurgerFactory : public BurgerFactory
{
	public:
	Burger* createBurger(string type) override
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
	};
};

class KingBurgerFactory : public BurgerFactory
{
	public:
	Burger* createBurger(string type) override
	{
		if(type == "basic") 
		{
			return new BasicWheatBurger();
		}
		else if(type == "standard") 
		{
			return new StandardWheatBurger();
		}
		else if(type == "deluxe") 
		{
			return new DeluxeWheatBurger();
		}
		
		return nullptr;
	};
};


int main() 
{
	string type = "basic";
	
	BurgerFactory* factory = new SinghBurgerFactory();
	Burger* burger1 = factory -> createBurger(type);
	burger1 -> prepare();
	delete burger1;
	delete factory;
	
	factory = new KingBurgerFactory();
	Burger* burger2 = factory -> createBurger(type);
	burger2 -> prepare();
	delete burger2;
	delete factory;
}