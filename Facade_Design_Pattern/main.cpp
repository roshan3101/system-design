#include <bits/stdc++.h>
using namespace std;

// Subsystems
class Amplifier {
public:
    void on() { cout << "Amplifier on\n"; }
    void setVolume(int v) { cout << "Amplifier volume set to " << v << "\n"; }
    void off() { cout << "Amplifier off\n"; }
};

class DvdPlayer {
public:
    void on() { cout << "DVD Player on\n"; }
    void play(const string& movie) { cout << "Playing \"" << movie << "\"\n"; }
    void stop() { cout << "DVD Player stopped\n"; }
    void off() { cout << "DVD Player off\n"; }
};

class Projector {
public:
    void on() { cout << "Projector on\n"; }
    void wideScreenMode() { cout << "Projector in widescreen mode\n"; }
    void off() { cout << "Projector off\n"; }
};

class TheaterLights {
public:
    void dim(int level) { cout << "Theater lights dimmed to " << level << "%\n"; }
    void on() { cout << "Theater lights on\n"; }
};

class Screen {
public:
    void down() { cout << "Screen going down\n"; }
    void up() { cout << "Screen going up\n"; }
};

// Facade
class HomeTheaterFacade {
private:
    Amplifier& amp;
    DvdPlayer& dvd;
    Projector& projector;
    TheaterLights& lights;
    Screen& screen;

public:
    HomeTheaterFacade(Amplifier& a, DvdPlayer& d, Projector& p, TheaterLights& l, Screen& s)
        : amp(a), dvd(d), projector(p), lights(l), screen(s) {}

    void watchMovie(const string& movie) {
        cout << "\nGet ready to watch a movie...\n";
        lights.dim(20);
        screen.down();
        projector.on();
        projector.wideScreenMode();
        amp.on();
        amp.setVolume(7);
        dvd.on();
        dvd.play(movie);
    }

    void endMovie() {
        cout << "\nShutting movie theater down...\n";
        dvd.stop();
        dvd.off();
        amp.off();
        projector.off();
        screen.up();
        lights.on();
    }
};

int main() {
    Amplifier amp;
    DvdPlayer dvd;
    Projector projector;
    TheaterLights lights;
    Screen screen;

    HomeTheaterFacade homeTheater(amp, dvd, projector, lights, screen);

    homeTheater.watchMovie("The Matrix");
    homeTheater.endMovie();

    return 0;
}
