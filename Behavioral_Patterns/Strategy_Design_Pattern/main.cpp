#include<bits/stdc++.h>
using namespace std;

class Talkable
{
	public:
	virtual void talk() = 0;
	virtual ~Talkable() {}
};

class NormalTalk : public Talkable
{
	public:
	void talk() override
	{
		cout<<"Hello, how are you?" << endl;
	}
};

class NoTalk : public Talkable
{
	public:
	void talk() override
	{
		cout<<"..." << endl;
	}
};


class Walkable 
{
	public:
	virtual void walk() = 0;
	virtual ~Walkable() {}
};


class NormalWalk : public Walkable
{
	public:
	void walk() override
	{
		cout<<"Walking normally." << endl;
	}
};

class NoWalk : public Walkable
{
	public:
	void walk() override
	{
		cout<<"Cannot walk." << endl;
	}
};


class Flyable
{
	public:
	virtual void fly() = 0;
	virtual ~Flyable() {}
};


class NormalFly : public Flyable
{
	public:
	void fly() override
	{
		cout<<"Flying in the sky." << endl;
	}
};

class NoFly : public Flyable
{
	public:
	void fly() override
	{
		cout<<"Cannot fly." << endl;
	}
};


class Robot 
{
	private:
	Talkable* t;
	Walkable* w;
	Flyable* f;
	
	public:
	Robot(Talkable* talk, Walkable* walk, Flyable* fly) 
	{
		this->t = talk;
		this->w = walk;
		this->f = fly;
	}
	
	void walk() 
	{
		w->walk();
	}
	
	void talk() 
	{
		t->talk();
	}
	
	void fly() 
	{
		f->fly();
	}
	
	virtual void projection() = 0;
	
	~Robot() 
	{
		delete t;
		delete w;
		delete f;
	}
};


class CompositionRobot : public Robot
{
	public:
	CompositionRobot(Talkable* talk, Walkable* walk, Flyable* fly) : Robot(talk, walk, fly) {}
	void projection() override
	{
		cout<<"Projecting hologram." << endl;
	}
};


int main() 
{
	Robot* r1 = new CompositionRobot(new NormalTalk(), new NormalWalk(), new NormalFly());
	r1->talk();
	r1->walk();
	r1->fly();
	r1->projection();
	
	delete r1;

}