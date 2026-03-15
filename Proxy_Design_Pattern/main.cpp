#include <bits/stdc++.h>
using namespace std;

class Image {
public:
	virtual ~Image() = default;
	virtual void display() = 0;
};

class RealImage : public Image {
	string filename;
	bool loaded;

	void loadFromDisk() {
		cout << "[RealImage] Loading " << filename << " from disk (heavy)\n";
		loaded = true;
	}
	

public:
	explicit RealImage(string filename) : filename(std::move(filename)), loaded(false) {}

	void display() override {
		if (!loaded) {
			loadFromDisk();
		}
		cout << "[RealImage] Displaying " << filename << "\n";
	}
};

class ProxyImage : public Image {
	string filename;
	unique_ptr<RealImage> real;

public:
	explicit ProxyImage(string filename) : filename(std::move(filename)) {}

	void display() override {
		if (!real) {
			cout << "[Proxy] Lazy-loading image on first display\n";
			real = make_unique<RealImage>(filename);
		} else {
			cout << "[Proxy] Using cached RealImage\n";
		}
		real->display();
	}
};

int main() {
	cout << "=== Proxy Pattern: Lazy Image Loader ===\n\n";

	ProxyImage galleryThumb("album_cover.png");

	cout << "First render (should trigger load):\n";
	galleryThumb.display();

	cout << "\nSecond render (should reuse cache):\n";
	galleryThumb.display();

	return 0;
}
