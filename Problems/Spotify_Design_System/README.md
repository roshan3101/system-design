# Spotify Design System (C++ demo)

Overview of a small, console-only Spotify-style player used to illustrate classic design patterns (Singleton, Facade, Factory, Strategy, Adapter). The code lives entirely in headers; `main.cpp` wires scenarios that exercise the patterns.

## Directory map
- `main.cpp` – scenario driver that seeds songs/playlists and runs demo flows.
- `MusicPlayerApplication.hpp` – top-level Singleton API used by `main.cpp`.
- `MusicPlayerFacade.hpp` – orchestration layer combining device, playlist, strategy, and audio engine.
- `core/AudioEngine.hpp` – minimal playback state (current song, pause/resume behavior).
- `models/` – `Song` data object and `Playlist` song container.
- `managers/` – singletons for playlists, devices, and strategies.
- `devices/` + `factory/DeviceFactory.hpp` – Adapter + Factory for Bluetooth/Wired/Headphone outputs backed by mock externals in `externals/`.
- `strategy/` – `PlayStrategy` interface with `Sequential`, `Random`, and `Custom (queue-next + history)` implementations.
- `enums/` – `DeviceType`, `StrategyType` selectors.
- `UML_DIAGRAM.excalidraw` – visual reference (not required to run).

## How the flow works
1) `main.cpp` grabs the `MusicPlayerApplication` Singleton and seeds a 12-track library plus three playlists.
2) When you connect a device (`connectAudioDevice`), `DeviceManager` uses `DeviceFactory` to build the right Adapter (e.g., `BluetoothAdapter` wraps `BluetoothAPI`).
3) Selecting a play strategy (`selectPlayStrategy`) pulls a shared instance from `StrategyManager` (Sequential, Random, Custom).
4) Loading a playlist pushes it into the chosen `PlayStrategy` and the `MusicPlayerFacade` remembers it.
5) Playback calls funnel through the Facade into `AudioEngine::play`, which hands songs to the active device adapter. Pause/resume is handled in `AudioEngine`.
6) Strategy behaviors:
   - **Sequential**: linear next/previous indices.
   - **Random**: shuffles remaining songs; maintains history stack for `previous`.
   - **Custom**: allows queueing arbitrary “play next” songs via `enqueueNext`, while still supporting sequential navigation and back-stack.

## Key patterns called out
- **Singleton**: `MusicPlayerApplication`, `PlaylistManager`, `DeviceManager`, `StrategyManager`, and `MusicPlayerFacade` expose global access with single instances.
- **Facade**: `MusicPlayerFacade` centralizes playlist loading, strategy selection, and device-aware playback so `MusicPlayerApplication` stays thin.
- **Factory + Adapter**: `DeviceFactory` instantiates concrete device adapters that wrap external APIs (`BluetoothAPI`, `WiredAPI`, `HeadphonesAPI`).
- **Strategy**: `PlayStrategy` interface with three interchangeable playback strategies.

## Running the demo
From `Spotify_Design_System/`:

```bash
g++ -std=c++17 main.cpp -o main
./main
```

The binary prints labeled scenarios showing device connections, strategy changes, queueing, and pause/resume behavior.

## Extending
- Add devices: implement `IAudioDevice`, extend `DeviceType`, and register in `DeviceFactory`.
- Add strategies: subclass `PlayStrategy`, register in `StrategyManager`, and select via a new `StrategyType`.
- Integrate real audio: replace mocks in `externals/` with real SDK bindings while keeping adapters stable.

