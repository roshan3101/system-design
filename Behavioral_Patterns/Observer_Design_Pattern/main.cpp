#include <bits/stdc++.h>
using namespace std;

class IObserver;

class IObservable
{
	public:
		virtual void add(IObserver* o) = 0;
		virtual void remove(IObserver* o) = 0;
		virtual void notify() = 0;
		virtual ~IObservable() {}
};

class IObserver
{
	public:
		virtual void update(const string& channelName, const string& videoTitle) = 0;
		virtual ~IObserver() {}
};

class Channel : public IObservable
{
	private:
		vector<IObserver*> subscribers;
		string name;
		string latestVideoTitle;

		public:
			Channel(string channelName) : name(channelName), latestVideoTitle("")
			{
			}

			void add(IObserver* o) override
			{
				if (find(subscribers.begin(), subscribers.end(), o) == subscribers.end())
				{
					subscribers.push_back(o);
				}
			}

			void remove(IObserver* o) override
			{
				subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), o), subscribers.end());
			}

			void notify() override
			{
				for (IObserver* subscriber : subscribers)
				{
					subscriber->update(name, latestVideoTitle);
				}
			}

			void uploadVideo(const string& title)
			{
				latestVideoTitle = title;
				cout << "\n[Channel] New video uploaded: " << latestVideoTitle << "\n";
				notify();
 			}
};

class MobileSubscriber : public IObserver
{
	private:
		string subscriberName;

	public:
		MobileSubscriber(string name) : subscriberName(name) {}

		void update(const string& channelName, const string& videoTitle) override
		{
			cout << "[Mobile] Hi " << subscriberName << ", "
				 << channelName << " uploaded: " << videoTitle << "\n";
		}
};

class EmailSubscriber : public IObserver
{
	private:
		string emailId;

	public:
		EmailSubscriber(string email) : emailId(email) {}

		void update(const string& channelName, const string& videoTitle) override
		{
			cout << "[Email] To " << emailId << " -> New upload on "
				 << channelName << ": " << videoTitle << "\n";
		}
};

int main()
{
	Channel cppChannel("CodeWithCPP");

	MobileSubscriber user1("Aman");
	MobileSubscriber user2("Riya");
	EmailSubscriber user3("dev.raj@example.com");

	cppChannel.add(&user1);
	cppChannel.add(&user2);
	cppChannel.add(&user3);

	cppChannel.uploadVideo("Observer Pattern in 10 Minutes");

	cppChannel.remove(&user2);

	cppChannel.uploadVideo("Factory vs Observer: When to Use What");

	return 0;
}




