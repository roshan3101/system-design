#include <bits/stdc++.h>
using namespace std;

class Character
{
	public:
		virtual string getAbilities() const = 0;
		virtual ~Character() {};
};

class Mario : public Character
{
	public:
		string getAbilities() const override
		{
			return "Mario";
		}
};

class CharacterDecorator : public Character
{
	protected:
		Character* character;
	public:
		CharacterDecorator(Character* c) 
		{
			character = c;
		}
};


class Heightup : public CharacterDecorator 
{
	public:
		Heightup(Character* c) : CharacterDecorator(c) {} 
		
		string getAbilities() const override
		{
			return character -> getAbilities() + " with height";
		}
};

class Gunpower : public CharacterDecorator
{
	public:
		Gunpower(Character* c) : CharacterDecorator(c) { }
		
		string getAbilities() const override
		{
			return character -> getAbilities() + " with gunpower";
		}
};

class Starpower : public CharacterDecorator 
{
	public:
		Starpower(Character* c) : CharacterDecorator(c) { }
		
		string getAbilities() const override
		{
			return character -> getAbilities() + " with Star Power";
		}
};


int main() 
{
	Character* mario = new Mario();
	cout<<"Basic Mario "<<mario -> getAbilities() <<endl;
	
	mario = new Heightup(mario);
	cout<<"Height up "<<mario -> getAbilities() <<endl;
	
	mario = new Gunpower(mario);
	cout<<"GUn Power "<<mario -> getAbilities() << endl;
	
	mario = new Starpower(mario);
	cout<<"Star POwer "<<mario -> getAbilities() <<endl;
	
	delete mario;
	
}