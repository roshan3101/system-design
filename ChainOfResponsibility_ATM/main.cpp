#include <bits/stdc++.h>
using namespace std;

class CashHandler {
protected:
    int denomination;
    shared_ptr<CashHandler> next;

public:
    explicit CashHandler(int denom) : denomination(denom) {}

    void setNext(shared_ptr<CashHandler> n) { next = std::move(n); }

    virtual void dispense(int amount) {
        int numNotes = amount / denomination;
        int remainder = amount % denomination;

        if (numNotes > 0) {
            cout << "Dispensing " << numNotes << " x " << denomination << "\n";
        }
        if (remainder > 0 && next) {
            next->dispense(remainder);
        } else if (remainder > 0 && !next) {
            cout << "[ERROR] Cannot dispense remaining amount: " << remainder << "\n";
        }
    }
};

int main() {
    cout << "=== Chain of Responsibility: ATM Dispenser ===\n\n";

    auto h2000 = make_shared<CashHandler>(2000);
    auto h500  = make_shared<CashHandler>(500);
    auto h200  = make_shared<CashHandler>(200);
    auto h100  = make_shared<CashHandler>(100);

    h2000->setNext(h500);
    h500->setNext(h200);
    h200->setNext(h100);

    vector<int> requests = {3700, 600, 2300, 125, 4100};

    for (int amount : requests) {
        cout << "Request: " << amount << "\n";
        if (amount % 100 != 0) {
            cout << "[ERROR] ATM dispenses multiples of 100 only\n\n";
            continue;
        }
        h2000->dispense(amount);
        cout << "\n";
    }

    return 0;
}
