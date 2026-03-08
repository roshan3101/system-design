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

class GarlicBread
{
	public:
	virtual void prepare() = 0;
	virtual ~GarlicBread() {}
};

class BasicGarlicBread : public GarlicBread
{
	public:
	void prepare() override
	{
		cout<<"Preparing basic garlic bread with baguette and garlic butter." << endl;
	}
};

class CheeseGarlicBread : public GarlicBread
{
	public:
	void prepare() override
	{
		cout<<"Preparing cheese garlic bread with baguette, garlic butter, and cheese." << endl;
	}
};


class BasicWheatGarlicBread : public GarlicBread
{
	public:
	void prepare() override
	{
		cout<<"Preparing basic wheat garlic bread with wheat baguette and garlic butter." << endl;
	}
};

class CheeseWheatGarlicBread : public GarlicBread
{
	public:
	void prepare() override
	{
		cout<<"Preparing cheese wheat garlic bread with wheat baguette, garlic butter, and cheese." << endl;
	}
};


class MealFactory
{
	public:
	virtual Burger* createBurger(string type) = 0;
	virtual GarlicBread* createGarlicBread(string type) = 0;
	virtual ~MealFactory() {}
};

class SinghMealFactory : public MealFactory
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
	
	GarlicBread* createGarlicBread(string type) override
	{
		if(type == "basic") 
		{
			return new BasicGarlicBread();
		}
		else if(type == "cheese") 
		{
			return new CheeseGarlicBread();
		}
		
		return nullptr;
	};
};


class KingMealFactory : public MealFactory
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
	
	GarlicBread* createGarlicBread(string type) override
	{
		if(type == "basic") 
		{
			return new BasicWheatGarlicBread();
		}
		else if(type == "cheese") 
		{
			return new CheeseWheatGarlicBread();
		}
		
		return nullptr;
	};
};


int main()
{
	string burgerType = "basic";
	string garlicBreadType = "cheese";
	
	MealFactory* factory = new SinghMealFactory();
	Burger* burger = factory->createBurger(burgerType);
	GarlicBread* garlicBread = factory->createGarlicBread(garlicBreadType);
	
	burger->prepare();
	garlicBread->prepare();
	
	delete burger;
	delete garlicBread;
	delete factory;
}