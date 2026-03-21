#include <bits/stdc++.h>
using namespace std;

class User;

// Mediator interface
struct ChatMediator {
    virtual void broadcast(const string& from, const string& message) = 0;
    virtual void addUser(User* user) = 0;
    virtual ~ChatMediator() = default;
};

class User {
    string name;
    ChatMediator* mediator;
public:
    User(string name, ChatMediator* mediator) : name(std::move(name)), mediator(mediator) {
        mediator->addUser(this);
    }
    string getName() const { return name; }
    void send(const string& message) { mediator->broadcast(name, message); }
    void receive(const string& from, const string& message) {
        if (from == name) return; // don't echo self
        cout << "[" << name << " receives] " << from << ": " << message << endl;
    }
};

class ChatRoom : public ChatMediator {
    vector<User*> users;
public:
    void broadcast(const string& from, const string& message) override {
        cout << "-- " << from << " says: " << message << " --" << endl;
        for (auto* user : users) {
            user->receive(from, message);
        }
    }

    void addUser(User* user) override {
        users.push_back(user);
        cout << user->getName() << " joined the room." << endl;
    }
};

int main() {
    ChatRoom room;
    User alice("Alice", &room);
    User bob("Bob", &room);
    User carol("Carol", &room);

    alice.send("Hi all!");
    bob.send("Hey Alice!");
    carol.send("Ready for the meeting?");

    return 0;
}
