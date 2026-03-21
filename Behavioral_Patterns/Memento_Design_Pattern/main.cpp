#include <bits/stdc++.h>
using namespace std;

// Memento stores snapshot of DB state
class Memento {
    map<string, string> dataSnapshot; // ordered for deterministic prints
public:
    explicit Memento(map<string, string> data) : dataSnapshot(std::move(data)) {}
    const map<string, string>& getState() const { return dataSnapshot; }
};

class Database {
    map<string, string> data;
public:
    void set(const string& key, const string& value) { data[key] = value; }
    string get(const string& key) const {
        auto it = data.find(key);
        return it == data.end() ? "" : it->second;
    }
    unique_ptr<Memento> save() const { return make_unique<Memento>(data); }
    void restore(const Memento& m) { data = m.getState(); }
    void print() const {
        cout << "DB: ";
        for (const auto& kv : data) cout << kv.first << "=" << kv.second << " ";
        cout << endl;
    }
};

// Caretaker
class TransactionManager {
    Database& db;
    unique_ptr<Memento> backup;
public:
    explicit TransactionManager(Database& db) : db(db) {}
    void begin() { backup = db.save(); cout << "Begin transaction" << endl; }
    void commit() { backup.reset(); cout << "Commit" << endl; }
    void rollback() {
        if (backup) {
            db.restore(*backup);
            cout << "Rollback" << endl;
            backup.reset();
        } else {
            cout << "Nothing to rollback" << endl;
        }
    }
};

int main() {
    Database db;
    TransactionManager tx(db);

    db.set("user:1", "Alice");
    db.set("balance:1", "100");
    db.print();

    tx.begin();
    db.set("balance:1", "-50"); // bad update
    db.set("audit", "failed");
    db.print();
    tx.rollback();
    db.print();

    tx.begin();
    db.set("balance:1", "120");
    db.print();
    tx.commit();
    db.print();
    return 0;
}
