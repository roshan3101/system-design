#include <bits/stdc++.h>
using namespace std;

// Logger interface
struct Logger {
    virtual void info(const string& msg) = 0;
    virtual void error(const string& msg) = 0;
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
    void info(const string& msg) override { cout << "[INFO] " << msg << endl; }
    void error(const string& msg) override { cerr << "[ERROR] " << msg << endl; }
};

class NullLogger : public Logger {
public:
    void info(const string& msg) override { /* no-op */ }
    void error(const string& msg) override { /* no-op */ }
};

class PaymentService {
    Logger& logger;
public:
    explicit PaymentService(Logger& logger) : logger(logger) {}
    void process(int amount) {
        if (amount <= 0) {
            logger.error("Invalid amount");
            return;
        }
        logger.info("Processing payment of $" + to_string(amount));
        // pretend to call gateway
        logger.info("Payment successful");
    }
};

int main() {
    ConsoleLogger console;
    NullLogger silent;

    PaymentService noisy(console);
    PaymentService quiet(silent);

    cout << "-- With logging --" << endl;
    noisy.process(100);
    noisy.process(-5);

    cout << "-- No logging (Null Object) --" << endl;
    quiet.process(50);
    quiet.process(-1);
    return 0;
}
