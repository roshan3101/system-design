#include <bits/stdc++.h>
using namespace std;

class INotification
{
	public:
		virtual string getContent() const = 0;
		virtual ~INotification() {}
};

class SimpleNotification : public INotification
{
	private:
		string text;
	
	public:
		SimpleNotification(const string& s) 
		{
			text = s;
		}
		
		string getContent() const override
		{
			return text;
		}
};

class INotificationDecorator : public INotification
{
	protected:
		INotification* notification;
		
	public:
		INotificationDecorator(INotification* n) 
		{
			notification = n;
		}
		
		virtual ~INotificationDecorator()
		{
			delete notification;
		}
};

class TimestampDecorator : public INotificationDecorator
{
	public:
		TimestampDecorator(INotification* n) : INotificationDecorator(n) { }
		
		string getContent() const override
		{
			return "[11:03:2026-14:45:02]" + notification -> getContent();
		}
};

class SignatureDecorator : public INotificationDecorator
{
	private:
		string signature;
	public:
		SignatureDecorator(INotification* n, const string& sig) : INotificationDecorator(n) {
			signature = sig;
		 }
		
		string getContent() const override
		{
			return notification -> getContent() + "\n--- " + signature + "---\n";
		}
};

class IObserver
{
	public:
		virtual void update() = 0;
		virtual ~IObserver() {}
};

class IObservable 
{
	public:
		virtual void add(IObserver* observer) = 0;
		virtual void remove(IObserver* observer) = 0;
		virtual void notifyObservers() = 0;	
		virtual ~IObservable() {}
	};

class NotificationObservable : public IObservable
{
	private:
		vector<IObserver*> observers;
		INotification* currentNotification;
		
	public:
		NotificationObservable() 
		{
			currentNotification = nullptr;
		}
		
			void add(IObserver* observer) override
			{
				observers.push_back(observer);
			}
		
	void remove(IObserver* observer) override
	{
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}
		
		void notifyObservers() override
		{
			for(auto obs : observers) 
			{
				obs->update();
			}
		}
		
		void setNotification(INotification* n) 
		{
			if(currentNotification != nullptr)
			{
				delete currentNotification;
			}
			currentNotification = n;
			notifyObservers();
		}
		
		INotification* getNotification()
		{
			return currentNotification;
		}
		
	string getNotificationContent()
	{
		return currentNotification->getContent();
	}
	
	~NotificationObservable() override
	{
		if(currentNotification != nullptr) delete currentNotification;
	}
};

class Logger : public IObserver {
private:
	NotificationObservable* notificationObservable;

public:
	Logger(NotificationObservable* observable) {
		this->notificationObservable = observable;
	}

	void update() {
		cout << "Logging New Notification : \n" << notificationObservable->getNotificationContent();
	}
};

class INotificationStrategy 
{
	public:
		virtual void sendNotification(string content) = 0;
		virtual ~INotificationStrategy() {}
	};

class EmailStrategy : public INotificationStrategy
{
	private:
		string emailId;
	public:
		EmailStrategy(string emailId) 
		{
			this->emailId = emailId;
		}
		
		void sendNotification(string content) override
		{
			cout<<"Sending email notification to "<<emailId<<"\n"<<content<<endl;
		}
};

class SMSStrategy : public INotificationStrategy
{
	private:
		string phone;
	public:	
		SMSStrategy(string phone) 
		{
			this->phone = phone;
		}
		
		void sendNotification(string content) override
		{
			cout<<"Sending SMS Notification to "<<phone<<"\n"<<content<<endl;
		}
};

class PopUpStrategy : public INotificationStrategy
{
	public:	
		
		void sendNotification(string content) override
		{
			cout<<"Sending PopUp Notification\n"<<content<<endl;
		}
};

class NotificationEngine : public IObserver {
	
private:
	NotificationObservable* notificationObservable;
	vector<INotificationStrategy*> notificationStrategies;

	public:
		NotificationEngine(NotificationObservable* observable) {
			this->notificationObservable = observable;
		}

		void addNotificationStrategy(INotificationStrategy* ns) {
			this->notificationStrategies.push_back(ns);
		}

		void update() {
			string notificationContent = notificationObservable->getNotificationContent();
			for(const auto notificationStrategy : notificationStrategies) {
				notificationStrategy->sendNotification(notificationContent);
			}
		}

		~NotificationEngine() {
			for(auto strategy : notificationStrategies) {
				delete strategy;
			}
		}
	};


class NotificationService {
private:
	NotificationObservable* observable;
	static NotificationService* instance;

	NotificationService() {
		observable = new NotificationObservable();
	}

public:
	static NotificationService* getInstance() {
		if(instance == nullptr) {
			instance = new NotificationService();
		}
		return instance;
	}

	NotificationObservable* getObservable() {
		return observable;
	}

	void sendNotification(INotification* notification) {
		observable->setNotification(notification);
	}

	~NotificationService() {
		delete observable;
	}
};

NotificationService* NotificationService::instance = nullptr;

int main()
{
	NotificationService* notificationService = NotificationService::getInstance();

    NotificationObservable* notificationObservable = notificationService->getObservable();
   
    Logger* logger = new Logger(notificationObservable);

    NotificationEngine* notificationEngine = new NotificationEngine(notificationObservable);

    notificationEngine->addNotificationStrategy(new EmailStrategy("random.person@gmail.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("+91 9876543210"));
    notificationEngine->addNotificationStrategy(new PopUpStrategy());

	    notificationObservable->add(logger);
	    notificationObservable->add(notificationEngine);

    INotification* notification = new SimpleNotification("Your order has been shipped!");
	    notification = new TimestampDecorator(notification);
    notification = new SignatureDecorator(notification, "Customer Care");
    
    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}
