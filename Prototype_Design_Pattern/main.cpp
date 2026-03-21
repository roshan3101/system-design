#include <bits/stdc++.h>
using namespace std;

// Prototype interface
struct Prototype {
    virtual unique_ptr<Prototype> clone() const = 0;
    virtual void print() const = 0;
    virtual ~Prototype() = default;
};

// Concrete prototype: character loadout
class CharacterLoadout : public Prototype {
    string name;
    vector<string> items;
    int level;
public:
    CharacterLoadout(string name, vector<string> items, int level)
        : name(std::move(name)), items(std::move(items)), level(level) {}

    unique_ptr<Prototype> clone() const override {
        // deep copy vector
        return make_unique<CharacterLoadout>(name, items, level);
    }

    void addItem(const string& item) { items.push_back(item); }
    void setName(const string& newName) { name = newName; }
    void setLevel(int lvl) { level = lvl; }

    void print() const override {
        cout << name << " (lvl " << level << ") with items: ";
        for (size_t i = 0; i < items.size(); ++i) {
            cout << items[i];
            if (i + 1 < items.size()) cout << ", ";
        }
        cout << endl;
    }
};

int main() {
    // Base prototype
    CharacterLoadout mageTemplate("Base Mage", {"Staff", "Robe", "Health Potion"}, 10);
    mageTemplate.print();

    // Clone and customize
    auto fireMage = mageTemplate.clone();
    dynamic_cast<CharacterLoadout&>(*fireMage).setName("Fire Mage");
    dynamic_cast<CharacterLoadout&>(*fireMage).addItem("Fire Tome");
    fireMage->print();

    // Another clone
    auto iceMage = mageTemplate.clone();
    dynamic_cast<CharacterLoadout&>(*iceMage).setName("Ice Mage");
    dynamic_cast<CharacterLoadout&>(*iceMage).setLevel(12);
    dynamic_cast<CharacterLoadout&>(*iceMage).addItem("Frost Wand");
    iceMage->print();

    // Original untouched
    mageTemplate.print();
    return 0;
}
