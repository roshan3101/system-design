#include <bits/stdc++.h>
using namespace std;

class AsteriodExtrensicContext
{
	public:
	int x;
	int y;
	AsteriodExtrensicContext(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
};

class Asteriod
{
	private:
		int height;
		int width;
		int weight;
		string color;
		string type;
	
	public:
	Asteriod(int height,int width,int weight,string color,string type)
	{
		this->height = height;
		this->width = width;
		this->weight = weight;
		this->color = color;
		this->type = type;
	}
	
	void display(AsteriodExtrensicContext *context)
	{
		cout<<"Asteriod of type "<<type<<" with color "<<color<<" and weight "<<weight<<" is at position ("<<context->x<<","<<context->y<<")"<<endl;
	}
};

class AsteroidFlyweightFactory
{
	private:
	map<string,Asteriod*> m;
	
	public:
	Asteriod* getAsteriod(int height,int width,int weight,string color,string type)
	{
		string key = to_string(height)+"-"+to_string(width)+"-"+to_string(weight)+"-"+color+"-"+type;
		if(m.find(key) == m.end())
		{
			m[key] = new Asteriod(height,width,weight,color,type);
		}
		return m[key];
	}
};

int main()
{
	int asteriodsCount = 1000000;
	AsteroidFlyweightFactory *factory = new AsteroidFlyweightFactory();
	
	for(int i=0;i<asteriodsCount;i++)
	{
		int height = rand()%100 + 1;
		int width = rand()%100 + 1;
		int weight = rand()%1000 + 1;
		string color = (rand()%2 == 0) ? "Red" : "Green";
		string type = (rand()%2 == 0) ? "Type A" : "Type B";
		
		Asteriod *asteriod = factory->getAsteriod(height,width,weight,color,type);
		AsteriodExtrensicContext *context = new AsteriodExtrensicContext(rand()%1000,rand()%1000);
		asteriod->display(context);
	}
}