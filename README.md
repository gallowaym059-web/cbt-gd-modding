# Click Before Tick (CBT) - Geometry Dash Mod

A Geode mod for Geometry Dash implementing **click-before-tick** mechanics with a mature TPS bypass and built-in safe mode.

## Features

- **Click Before Tick (CBT)**: Register player input *before* the game's physics tick for improved timing
- **TPS Bypass**: Speed up or slow down gameplay with a configurable multiplier (0.5x - 4.0x)
- **Safe Mode**: Disable mod features in online/competitive contexts to prevent abuse

## Building

### Prerequisites
- Geode SDK installed
- CMake 3.21+
- C++20 compatible compiler

### Build Steps

```bash
git clone https://github.com/gallowaym059-web/cbt-gd-modding.git
cd cbt-gd-modding
mkdir build
cd build
cmake ..
cmake --build .