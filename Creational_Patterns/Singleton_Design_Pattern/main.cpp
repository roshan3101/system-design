#include<bits/stdc++.h>
using namespace std;

// class Singleton
// {
// 	private:
// 		static Singleton* instance;
// 		static mutex mtx; // mutex for thread safety
// 		Singleton()
// 		{
// 			cout<<"Constructor called"<<endl;
// 		}
		
// 	public:
// 		static Singleton* getInstance()
// 		{
// 			if(instance == nullptr) 
// 			{
// 				lock_guard<mutex> lock(mtx); // lock the mutex to ensure thread safety
// 				if(instance == nullptr) // double-checked locking
// 				{
// 					instance = new Singleton();
// 				}
// 			}
// 			return instance;
// 		}
// };

// Singleton* Singleton::instance = nullptr;
// mutex Singleton::mtx; // initialize the mutex

// int main() 
// {
// 	Singleton* s1 = Singleton::getInstance();
// 	Singleton* s2 = Singleton::getInstance();
	
// 	cout<<(bool)(s1 == s2); // true, both s1 and s2 point to the same instance of Singleton
// }


class Singleton
{
	private:
	Singleton()
	{
		cout<<"Constructor called"<<endl;
	}
	
	public:
	static Singleton& getInstance()
	{
		static Singleton instance; // Guaranteed to be destroyed and instantiated on first use.
		return instance;
	}
};


int main() 
{
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();
	
	cout<<(bool)(&s1 == &s2); // true, both s1 and s2 refer to the same instance of Singleton
}