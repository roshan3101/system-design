#include "MusicPlayerApplication.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    auto* app = MusicPlayerApplication::getInstance();

    // 12-song library
    app->createSongInLibrary("Blinding Lights", "The Weeknd", "/music/blinding_lights.mp3");
    app->createSongInLibrary("Levitating", "Dua Lipa", "/music/levitating.mp3");
    app->createSongInLibrary("As It Was", "Harry Styles", "/music/as_it_was.mp3");
    app->createSongInLibrary("bad guy", "Billie Eilish", "/music/bad_guy.mp3");
    app->createSongInLibrary("Shivers", "Ed Sheeran", "/music/shivers.mp3");
    app->createSongInLibrary("Heat Waves", "Glass Animals", "/music/heat_waves.mp3");
    app->createSongInLibrary("Starboy", "The Weeknd", "/music/starboy.mp3");
    app->createSongInLibrary("Watermelon Sugar", "Harry Styles", "/music/watermelon_sugar.mp3");
    app->createSongInLibrary("Don't Start Now", "Dua Lipa", "/music/dont_start_now.mp3");
    app->createSongInLibrary("Believer", "Imagine Dragons", "/music/believer.mp3");
    app->createSongInLibrary("Stressed Out", "Twenty One Pilots", "/music/stressed_out.mp3");
    app->createSongInLibrary("Viva La Vida", "Coldplay", "/music/viva_la_vida.mp3");

    // 3 playlists
    app->createPlaylist("Workout");
    app->createPlaylist("Chill");
    app->createPlaylist("Favorites");

    // Populate playlists
    app->addSongToPlaylist("Workout", "Believer");
    app->addSongToPlaylist("Workout", "Blinding Lights");
    app->addSongToPlaylist("Workout", "Heat Waves");
    app->addSongToPlaylist("Workout", "Starboy");

    app->addSongToPlaylist("Chill", "Viva La Vida");
    app->addSongToPlaylist("Chill", "Stressed Out");
    app->addSongToPlaylist("Chill", "Watermelon Sugar");
    app->addSongToPlaylist("Chill", "As It Was");

    app->addSongToPlaylist("Favorites", "Levitating");
    app->addSongToPlaylist("Favorites", "Don't Start Now");
    app->addSongToPlaylist("Favorites", "bad guy");
    app->addSongToPlaylist("Favorites", "Shivers");

    auto run = [&](const char* label, auto&& fn) {
        std::cout << "\n=== " << label << " ===\n";
        try {
            fn();
        } catch (const std::exception& e) {
            std::cout << "[ERROR] " << e.what() << "\n";
        }
    };

    run("Device: Bluetooth + play/pause single song", [&] {
        app->connectAudioDevice(DeviceType::BLUETOOTH);
        app->playSingleSong("Blinding Lights");
        app->pauseCurrentSong("Blinding Lights");
        app->playSingleSong("Blinding Lights"); // resumes in AudioEngine if same pointer
    });

    run("Strategy: SEQUENTIAL on Workout", [&] {
        app->selectPlayStrategy(StrategyType::SEQUENTIAL);
        app->loadPlaylist("Workout");
        app->playAllTracksInPlaylist();
    });

    run("Strategy: RANDOM on Chill", [&] {
        app->selectPlayStrategy(StrategyType::RANDOM);
        app->loadPlaylist("Chill");
        app->playAllTracksInPlaylist();
    });

    run("Device: Wired + Strategy: CUSTOM queue on Favorites", [&] {
        app->connectAudioDevice(DeviceType::WIRED);
        app->selectPlayStrategy(StrategyType::CUSTOM);
        app->loadPlaylist("Favorites");

        // Test enqueueNext behavior (should play these earlier depending on strategy implementation)
        app->queueSongNext("Viva La Vida");
        app->queueSongNext("Believer");

        app->playAllTracksInPlaylist();
    });

    run("Device: Headphones + play next/previous", [&] {
        app->connectAudioDevice(DeviceType::HEADPHONES);
        app->selectPlayStrategy(StrategyType::SEQUENTIAL);
        app->loadPlaylist("Chill");
        app->playAllTracksInPlaylist();
    });

    return 0;
}
