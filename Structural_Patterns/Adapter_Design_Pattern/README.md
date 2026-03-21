# Adapter Design Pattern – Media Player

Wraps format-specific players (`VlcPlayer`, `Mp4Player`) behind a common `MediaPlayer` interface so clients can call `play(type, file)` uniformly.

## Structure
- `MediaPlayer` – target interface clients expect.
- `AdvancedMediaPlayer` – adaptee interface with format-specific operations.
- `VlcPlayer`, `Mp4Player` – adaptees.
- `MediaAdapter` – adapts `MediaPlayer` calls to the appropriate advanced player.
- `AudioPlayer` – client-facing player that delegates to `MediaAdapter` for non-mp3 formats.

## Build & Run
```bash
g++ -std=c++17 -Wall -Wextra -o adapter main.cpp
./adapter
```

## Expected Output
```
Playing mp3 file: beyond_the_horizon.mp3
Playing mp4 file: alone.mp4
Playing vlc file: far_far_away.vlc
Invalid media. avi format not supported
```

## Notes
- Uses `std::unique_ptr` in the adapter to avoid manual deletes.
- Extendable: add a new format by implementing `AdvancedMediaPlayer` and branching in `MediaAdapter`.
