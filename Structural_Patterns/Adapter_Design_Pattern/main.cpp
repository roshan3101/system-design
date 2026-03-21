#include <bits/stdc++.h>
using namespace std;

// Target interface expected by clients
class MediaPlayer {
public:
    virtual void play(const string& audioType, const string& fileName) = 0;
    virtual ~MediaPlayer() = default;
};

// Adaptee interface (advanced players with specific formats)
class AdvancedMediaPlayer {
public:
    virtual void playVlc(const string& fileName) = 0;
    virtual void playMp4(const string& fileName) = 0;
    virtual ~AdvancedMediaPlayer() = default;
};

class VlcPlayer : public AdvancedMediaPlayer {
public:
    void playVlc(const string& fileName) override {
        cout << "Playing vlc file: " << fileName << "\n";
    }
    void playMp4(const string&) override { /* not supported */ }
};

class Mp4Player : public AdvancedMediaPlayer {
public:
    void playVlc(const string&) override { /* not supported */ }
    void playMp4(const string& fileName) override {
        cout << "Playing mp4 file: " << fileName << "\n";
    }
};

// Adapter converts the simple MediaPlayer request into advanced calls
class MediaAdapter : public MediaPlayer {
private:
    unique_ptr<AdvancedMediaPlayer> advancedPlayer;

public:
    explicit MediaAdapter(const string& audioType) {
        if (audioType == "vlc") {
            advancedPlayer = make_unique<VlcPlayer>();
        } else if (audioType == "mp4") {
            advancedPlayer = make_unique<Mp4Player>();
        }
    }

    void play(const string& audioType, const string& fileName) override {
        if (audioType == "vlc") {
            advancedPlayer->playVlc(fileName);
        } else if (audioType == "mp4") {
            advancedPlayer->playMp4(fileName);
        }
    }
};

// Concrete player uses adapter when needed
class AudioPlayer : public MediaPlayer {
public:
    void play(const string& audioType, const string& fileName) override {
        if (audioType == "mp3") {
            cout << "Playing mp3 file: " << fileName << "\n";
            return;
        }

        if (audioType == "vlc" || audioType == "mp4") {
            MediaAdapter adapter(audioType);
            adapter.play(audioType, fileName);
            return;
        }

        cout << "Invalid media. " << audioType << " format not supported\n";
    }
};

int main() {
    AudioPlayer player;

    player.play("mp3", "beyond_the_horizon.mp3");
    player.play("mp4", "alone.mp4");
    player.play("vlc", "far_far_away.vlc");
    player.play("avi", "mind_me.avi");

    return 0;
}
