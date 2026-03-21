#include <bits/stdc++.h>
using namespace std;

// Context holds variable bindings
class Context {
    unordered_map<string, int> vars;
public:
    void set(const string& name, int value) { vars[name] = value; }
    int get(const string& name) const {
        auto it = vars.find(name);
        if (it == vars.end()) throw runtime_error("Undefined variable: " + name);
        return it->second;
    }
};

// Expression interface
class Expression {
public:
    virtual int interpret(const Context& ctx) const = 0;
    virtual ~Expression() = default;
};

class NumberExpression : public Expression {
    int value;
public:
    explicit NumberExpression(int value) : value(value) {}
    int interpret(const Context&) const override { return value; }
};

class VariableExpression : public Expression {
    string name;
public:
    explicit VariableExpression(string name) : name(std::move(name)) {}
    int interpret(const Context& ctx) const override { return ctx.get(name); }
};

class AddExpression : public Expression {
    unique_ptr<Expression> left, right;
public:
    AddExpression(unique_ptr<Expression> l, unique_ptr<Expression> r)
        : left(std::move(l)), right(std::move(r)) {}
    int interpret(const Context& ctx) const override {
        return left->interpret(ctx) + right->interpret(ctx);
    }
};

class SubtractExpression : public Expression {
    unique_ptr<Expression> left, right;
public:
    SubtractExpression(unique_ptr<Expression> l, unique_ptr<Expression> r)
        : left(std::move(l)), right(std::move(r)) {}
    int interpret(const Context& ctx) const override {
        return left->interpret(ctx) - right->interpret(ctx);
    }
};

// A tiny parser for expressions like "a + 3 - b"
vector<string> tokenize(const string& s) {
    vector<string> tokens;
    string cur;
    for (char c : s) {
        if (isspace(c)) continue;
        if (c == '+' || c == '-') {
            if (!cur.empty()) { tokens.push_back(cur); cur.clear(); }
            tokens.emplace_back(1, c);
        } else {
            cur.push_back(c);
        }
    }
    if (!cur.empty()) tokens.push_back(cur);
    return tokens;
}

unique_ptr<Expression> parse(const vector<string>& tokens) {
    // left-associative chain of + and -
    auto toExpr = [](const string& tok) -> unique_ptr<Expression> {
        if (isdigit(tok[0]) || (tok.size()>1 && tok[0]=='-' && isdigit(tok[1]))) {
            return make_unique<NumberExpression>(stoi(tok));
        }
        return make_unique<VariableExpression>(tok);
    };

    if (tokens.empty()) throw runtime_error("Empty expression");
    auto expr = toExpr(tokens[0]);
    for (size_t i = 1; i + 1 < tokens.size(); i += 2) {
        string op = tokens[i];
        auto rhs = toExpr(tokens[i+1]);
        if (op == "+") expr = make_unique<AddExpression>(std::move(expr), std::move(rhs));
        else if (op == "-") expr = make_unique<SubtractExpression>(std::move(expr), std::move(rhs));
        else throw runtime_error("Unknown operator: " + op);
    }
    return expr;
}

int main() {
    Context ctx;
    ctx.set("a", 10);
    ctx.set("b", 4);

    string input = "a + 3 - b";
    auto tokens = tokenize(input);
    auto expression = parse(tokens);
    int result = expression->interpret(ctx);

    cout << "Expression: " << input << "\n";
    cout << "a = " << ctx.get("a") << ", b = " << ctx.get("b") << "\n";
    cout << "Result: " << result << "\n";
    return 0;
}
