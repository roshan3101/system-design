#include <bits/stdc++.h>
using namespace std;

struct Visitor; // forward

struct DocumentPart {
    virtual void accept(Visitor& v) = 0;
    virtual ~DocumentPart() = default;
};

struct Text : public DocumentPart {
    string content;
    explicit Text(string c) : content(std::move(c)) {}
    void accept(Visitor& v) override;
};

struct Image : public DocumentPart {
    string name;
    size_t bytes;
    Image(string name, size_t bytes) : name(std::move(name)), bytes(bytes) {}
    void accept(Visitor& v) override;
};

struct Visitor {
    virtual void visit(Text& text) = 0;
    virtual void visit(Image& image) = 0;
    virtual ~Visitor() = default;
};

struct SizeVisitor : public Visitor {
    size_t totalBytes = 0;
    void visit(Text& text) override {
        totalBytes += text.content.size();
    }
    void visit(Image& image) override {
        totalBytes += image.bytes;
    }
};

struct CompressVisitor : public Visitor {
    void visit(Text& text) override {
        cout << "Compressing text to gzip: " << text.content.substr(0, min<size_t>(15, text.content.size())) << "..." << endl;
    }
    void visit(Image& image) override {
        cout << "Compressing image " << image.name << " (" << image.bytes << " bytes) to WebP." << endl;
    }
};

struct Document {
    vector<unique_ptr<DocumentPart>> parts;
    void add(unique_ptr<DocumentPart> part) { parts.push_back(std::move(part)); }
    void accept(Visitor& v) {
        for (auto& part : parts) part->accept(v);
    }
};

// accept definitions
void Text::accept(Visitor& v) { v.visit(*this); }
void Image::accept(Visitor& v) { v.visit(*this); }

int main() {
    Document doc;
    doc.add(make_unique<Text>("Design patterns make code safer."));
    doc.add(make_unique<Image>("diagram.png", 12000));
    doc.add(make_unique<Text>("Visitor lets you add operations."));

    SizeVisitor sizeVisitor;
    doc.accept(sizeVisitor);
    cout << "Total size: " << sizeVisitor.totalBytes << " bytes" << endl;

    CompressVisitor compressVisitor;
    doc.accept(compressVisitor);
    return 0;
}
