#include <bits/stdc++.h>
using namespace std;

class IComponentItem 
{
	public:
		virtual ~IComponentItem() {}
		virtual void ls(int indent = 0) = 0;
		virtual void openAll(int indent = 0) = 0;
		virtual int getSize() = 0;
		virtual IComponentItem* cd(const string& name) = 0;
		virtual string getName() = 0;
		virtual bool isFolder() = 0;
};


class File : public IComponentItem 
{
	private:
		string name;
		int size;
		
	public:
		File(const string& name, int size) 
		{
			this->name = name;
			this->size = size;
		}
		
		void ls(int indent = 0) override 
		{
			cout << string(indent, ' ') << name << endl;
		}
		
		void openAll(int indent = 0) override 
		{
			cout << string(indent, ' ') << name << endl;
		}
		
		int getSize() override 
		{
			return size;
		}
		
		IComponentItem* cd(const string&) override
		{
			return nullptr;
		}
		
		string getName() override
		{
			return name;
		}
		
		bool isFolder() override
		{
			return false;
		}
};

class Folder : public IComponentItem 
{
	private:
		string name;
		vector<IComponentItem*> children;
		
	public:
		Folder(const string& name) 
		{
			this->name = name;
		}
		
		~Folder()
		{
			for(auto& item : children) delete item;
		}
		
		void add(IComponentItem* newChild) 
		{
			children.push_back(newChild);
		}
		
		void ls(int indent = 0) override 
		{	
			for(auto child : children) 
			{
				if(child->isFolder()) 
				{
					cout<< string(indent, ' ') << " + " << child -> getName() << endl;
				}
				else
				{
					cout<< string(indent, ' ') << child -> getName() << endl;
				}
			}
		}
		
		void openAll(int indent = 0) override 
		{
			cout << string(indent, ' ') << " + " << name << endl;
			for(auto child : children) 
			{
				child -> openAll(indent + 4);
			}
		}
		
		int getSize() override
		{
			int total = 0;
			for(auto child : children) total += (child -> getSize());
			return total;
		}
		
		IComponentItem* cd(const string& name) override 
		{
			for(auto child : children) 
			{
				if(child->isFolder() && child -> getName() == name) 
					return child;
			}
			return nullptr;
		}
		
		string getName()
		{
			return name;
		}
		
		bool isFolder()
		{
			return true;
		}
};


int main() 
{
	Folder* root = new Folder("root");
	root -> add(new File("File1.txt", 1));
	root -> add(new File("File2.txt", 1));
	
	Folder* docs = new Folder("docs");
	docs -> add(new File("File3.txt", 2));
	docs -> add(new File("File4.txt", 3));
	root -> add(docs);
	
	Folder* desktop = new Folder("desktop");
	desktop -> add(new File("File5.txt", 4));
	root -> add(desktop);
	
	root -> ls();
	
	docs -> ls();
	
	root -> openAll();
	
	IComponentItem* cwd = root -> cd("docs");
	if(cwd != nullptr) 
	{
		cwd -> ls();
	}
	else
	{
		cout<< "\n Could not cd into docs"<<endl;
	}
	
	
	cout<<root->getSize()<<endl;
}
