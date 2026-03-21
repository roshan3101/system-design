#include <bits/stdc++.h>
using namespace std;

class VendingMachine; // forward

// State interface
struct State {
    virtual void insertCoin(VendingMachine& machine) = 0;
    virtual void selectProduct(VendingMachine& machine, const string& product) = 0;
    virtual void dispense(VendingMachine& machine) = 0;
    virtual ~State() = default;
};

class VendingMachine {
    unique_ptr<State> state;
    int stock;
public:
    VendingMachine(int initialStock);
    void setState(unique_ptr<State> newState) { state = std::move(newState); }
    void insertCoin();
    void selectProduct(const string& product);
    void dispense();
    bool hasStock() const { return stock > 0; }
    void releaseItem(const string& product) {
        cout << "Dispensing " << product << "..." << endl;
        if (stock > 0) stock--; 
    }
    void refill(int count) { stock += count; }
    int inventory() const { return stock; }
};

// Concrete States
class NoCoinState : public State {
public:
    void insertCoin(VendingMachine& machine) override;
    void selectProduct(VendingMachine& machine, const string& product) override;
    void dispense(VendingMachine& machine) override;
};

class HasCoinState : public State {
public:
    void insertCoin(VendingMachine& machine) override;
    void selectProduct(VendingMachine& machine, const string& product) override;
    void dispense(VendingMachine& machine) override;
};

class DispensingState : public State {
    string queuedProduct;
public:
    explicit DispensingState(string product) : queuedProduct(std::move(product)) {}
    void insertCoin(VendingMachine& machine) override;
    void selectProduct(VendingMachine& machine, const string& product) override;
    void dispense(VendingMachine& machine) override;
};

class SoldOutState : public State {
public:
    void insertCoin(VendingMachine& machine) override;
    void selectProduct(VendingMachine& machine, const string& product) override;
    void dispense(VendingMachine& machine) override;
};

// VendingMachine definitions
VendingMachine::VendingMachine(int initialStock) : stock(initialStock) {
    if (stock > 0) state = make_unique<NoCoinState>();
    else state = make_unique<SoldOutState>();
}

void VendingMachine::insertCoin() { state->insertCoin(*this); }
void VendingMachine::selectProduct(const string& product) { state->selectProduct(*this, product); }
void VendingMachine::dispense() { state->dispense(*this); }

// NoCoinState behaviors
void NoCoinState::insertCoin(VendingMachine& machine) {
    cout << "Coin inserted." << endl;
    machine.setState(make_unique<HasCoinState>());
}

void NoCoinState::selectProduct(VendingMachine& machine, const string& product) {
    cout << "Insert coin first before selecting " << product << "." << endl;
}

void NoCoinState::dispense(VendingMachine& machine) {
    cout << "Insert coin and select product first." << endl;
}

// HasCoinState behaviors
void HasCoinState::insertCoin(VendingMachine& machine) {
    cout << "Coin already inserted; returning extra coin." << endl;
}

void HasCoinState::selectProduct(VendingMachine& machine, const string& product) {
    if (!machine.hasStock()) {
        cout << "Out of stock." << endl;
        machine.setState(make_unique<SoldOutState>());
        return;
    }
    cout << "Selected: " << product << endl;
    machine.setState(make_unique<DispensingState>(product));
    machine.dispense();
}

void HasCoinState::dispense(VendingMachine& machine) {
    cout << "Select a product before dispensing." << endl;
}

// DispensingState behaviors
void DispensingState::insertCoin(VendingMachine& machine) {
    cout << "Please wait, dispensing in progress." << endl;
}

void DispensingState::selectProduct(VendingMachine& machine, const string& product) {
    cout << "Already dispensing. Please wait." << endl;
}

void DispensingState::dispense(VendingMachine& machine) {
    machine.releaseItem(queuedProduct);
    if (machine.hasStock()) {
        machine.setState(make_unique<NoCoinState>());
    } else {
        cout << "Machine is now out of stock." << endl;
        machine.setState(make_unique<SoldOutState>());
    }
}

// SoldOutState behaviors
void SoldOutState::insertCoin(VendingMachine& machine) {
    cout << "Cannot accept coin; sold out." << endl;
}

void SoldOutState::selectProduct(VendingMachine& machine, const string& product) {
    cout << "Sold out; cannot select " << product << "." << endl;
}

void SoldOutState::dispense(VendingMachine& machine) {
    cout << "Sold out." << endl;
}

int main() {
    VendingMachine machine(2);

    machine.selectProduct("Soda");
    machine.insertCoin();
    machine.selectProduct("Soda");

    machine.insertCoin();
    machine.selectProduct("Chips");

    machine.insertCoin(); // should be sold out
    machine.selectProduct("Water");

    return 0;
}
