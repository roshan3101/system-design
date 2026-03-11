#include <bits/stdc++.h>
using namespace std;

class ICommand 
{
	public:
		virtual void execute() = 0;
		virtual void undo() = 0;
		virtual ~ICommand() { }
};

class Light 
{
	public:
		void On() 
		{
			cout << "Light is turned ON\n";
		}
		
		void Off()
		{
			cout << "Light is turned OFF\n";
		}
};

class Fan 
{
	public:
		void On() 
		{
			cout << "Fan is turned ON\n";
		}
		
		void Off()
		{
			cout << "Fan is turned OFF\n";
		}
};


class LightCommand : public ICommand
{
	private:
		Light* light;
		
	public:
	
		LightCommand(Light* light) 
		{
			this -> light = light;
		}

		~LightCommand() override
		{
			delete light;
		}
		
		void execute() override
		{
			light -> On();
		}
		
		void undo() override
		{
			light -> Off();
		}
};

class FanCommand : public ICommand
{
	private:
		Fan* fan;
		
	public:
	
		FanCommand(Fan* f) 
		{
			fan = f;
		}

		~FanCommand() override
		{
			delete fan;
		}
		
		void execute() override
		{
			fan -> On();
		}
		
		void undo() override
		{
			fan -> Off();
		}
};

class RemoteControl 
{
	private:
		static constexpr int numButtons = 3;
		vector<ICommand*> commands;
		bool setTrue[numButtons];
		
	public:
		RemoteControl()
		{
			commands.resize(numButtons, nullptr);
			for(int i=0;i<numButtons;i++) setTrue[i]=false;
		}

		~RemoteControl()
		{
			for(auto cmd : commands)
			{
				delete cmd;
			}
		}
		
		void setCommand(ICommand* cmd, int index) 
		{
			if(index < 0 || index >= numButtons)
			{
				cout << "Invalid index\n";
				delete cmd;
				return;
			}

			if(commands[index] != nullptr) 
			{
				delete commands[index];
				setTrue[index] = false;
			}
			
			commands[index] = cmd;
		}
		
		void pressButton(int index) 
		{
			if(index < 0 || index >= numButtons)
			{
				cout << "Invalid Press\n";
				return;
			}

			if(commands[index] == nullptr) 
			{
				cout<<"Invalid Press";
				return;
			}
			
			if(setTrue[index]) 
			{
				commands[index]->undo();
				setTrue[index] = false;
			}
			else
			{
				commands[index]->execute();
				setTrue[index] = true;
			}
		}
	};

int main() 
{
	ICommand* light = new LightCommand(new Light());
	ICommand* fan = new FanCommand(new Fan());
	
	RemoteControl* remote = new RemoteControl();
	
	remote->setCommand(light, 0);
	remote->setCommand(fan, 1);
	
	cout<<"Simulating the light toggling"<<endl;
	
	remote->pressButton(0);
	remote->pressButton(0);
	
	remote->pressButton(1);
	remote->pressButton(1);
	
	remote->pressButton(2);

	delete remote;
}
