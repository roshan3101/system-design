#include<bits/stdc++.h>
using namespace std;

class DocumentElement 
{
	public:
	virtual string render() = 0;
};

class TextElement : public DocumentElement 
{
	private:
	string text;
	
	public:
	TextElement(string s) 
	{
		this->text = s;
	}
	
	string render() override
	{
		return text;
	}
};

class ImageElement : public DocumentElement
{
	private:
	string imagePath;
	
	public:
	ImageElement(string path) 
	{
		this->imagePath = path;
	}
	
	string render() override
	{
		return "[Image: " + imagePath + "]";
	}
};

class NewLineElement : public DocumentElement
{
	public:
	string render() override
	{
		return "\n";
	}
};

class TabElement : public DocumentElement
{
	public:
	string render() override
	{
		return "\t";
	}
};


class Document 
{
	private:
	vector<DocumentElement*> elements;
	
	public:
	void addElement(DocumentElement* element) 
	{
		elements.push_back(element);
	}
	
	string render()
	{
		string result;
		for(auto elt : elements) 
		{
			result += elt -> render();
		}
		
		return result;
	}
	
	~Document() 
	{
		for(auto elt : elements) 
		{
			delete elt;
		}
	}
};


class PersistanceManager
{
	public:
	virtual void save(string documentContent) = 0;
	virtual ~PersistanceManager() {}
};

class FileStorage : public PersistanceManager 
{
	public:
	void save(string documentContent) override
	{
		ofstream outFile("document.txt");
		if(outFile.is_open())
		{
			outFile << documentContent;
			outFile.close();
			cout<<"Document saved to document.txt" << endl;
		}
		else
		{
			cout<<"Error opening file for saving." << endl;
		}	
	}
};

class DBStroage : public PersistanceManager 
{
	public:
	void save(string documentContent) override
	{
		// Simulate saving to a database
		cout<<"Document saved to database: " << documentContent << endl;
	}
};


class DocumentEditor 
{
	private:
	Document* doc;
	PersistanceManager* storage;
	
	public:
	DocumentEditor(Document* document, PersistanceManager* storage) 
	{
		this->doc = document;
		this->storage = storage;
	}
	
	void addText(string text) 
	{
		doc -> addElement(new TextElement(text));
	}
	
	void addImage(string path) 
	{
		doc -> addElement(new ImageElement(path));
	}
	
	void addNewLine() 
	{
		doc -> addElement(new NewLineElement());
	}
	
	void addTab() 
	{
		doc -> addElement(new TabElement());
	}
	
	string renderDocument() 
	{
		return doc -> render();
	}
	
	void saveDocument()
	{
		storage -> save(renderDocument());
	}
};

int main() 
{
	Document* doc = new Document();
	PersistanceManager* storage = new FileStorage();
	DocumentEditor editor(doc, storage);
	
	editor.addText("Hello, World!");
	editor.addNewLine();
	editor.addText("This is a simple document editor.");
	editor.addNewLine();
	editor.addImage("image.png");
	editor.addTab();
	editor.addText("End of document.");
	
	cout << "Rendered Document: " << endl;
	cout << editor.renderDocument() << endl;
	
	editor.saveDocument();
	
	delete doc;
	delete storage;
	
	return 0;
}