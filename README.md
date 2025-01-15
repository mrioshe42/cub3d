# Cub3D

A 3D raycasting game written in C, inspired by the classic Wolfenstein 3D game engine. This project is developed using the MiniLibX graphics library.

## 🎮 Features

- First-person perspective raycasting engine
- Textured walls and environment
- Dynamic lighting effects with torches
- Enemy AI and movement
- Interactive gameplay with collision detection
- Custom map loading from configuration files
- Animated intro sequence
- Sound effects and background music

## 🛠️ Technical Requirements

- Linux/Unix-based system
- MinilibX graphics library
- C compiler (gcc recommended)
- X11 window system
- VLC media player (for audio playback)

## 🚀 Installation

1. Clone the repository:
```bash
git clone https://github.com/mrioshe42/cub3d.git
cd cub3d
Compile the project using make:
bash
make
🎯 Usage
Run the program with a map file:

bash
./cub3D path_to_map.cub
Controls
Use WASD keys for movement
Mouse for camera control
ESC to exit the game
🎨 Project Structure
main/: Contains the core game logic and raycasting engine
textures/: Game textures and sprites
audio/: Sound effects and music files
includes/: Header files
minilibx-linux/: Graphics library
📝 Notes
Game includes features like enemy AI, torch animations, and sound effects
Implements raycasting technique for 3D rendering
Uses MinilibX for graphics handling
Includes collision detection and game state management
🔑 License
This project is part of the 42 school curriculum.
