# cub3d

A first-person 3D raycasting engine inspired by Wolfenstein 3D, built in C using the MLX42 graphics library. Developed as part of the [42 / Hive School](https://www.hive.fi) curriculum.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Map Format](#map-format)
- [Bonus Mode](#bonus-mode)
- [What I Did](#what-i-did)
- [What I Learned](#what-i-learned)
- [What I Would Do Differently](#what-i-would-do-differently)
- [License](#license)

---

## Overview

cub3d renders a 3D-perspective view of a 2D maze using raycasting — the same technique used by classic games like Wolfenstein 3D and Doom. Each frame, rays are cast from the player's viewpoint to calculate wall distances, which are then used to draw textured vertical slices at the correct perspective-corrected height.

The project was built as a two-person team effort. Responsibilities included implementing the raycasting engine, correct texture projection onto surfaces, player movement, and a minimap overlay.

## Features

- Raycasting-based 3D rendering with perspective correction
- Textured walls (North, South, East, West faces rendered individually)
- Smooth player movement and camera rotation
- Mouse-look support for camera rotation
- Interactive doors (openable with `Space`)
- Minimap overlay
- Configurable maps via `.cub` scene files
- Bonus mode: dynamic lighting that slowly dims over time

## Project Structure

```
cub3d/
├── MLX42/           # Graphics library (submodule)
├── includes/        # Header files
├── libft/           # Custom C standard library
├── maps/            # Scene/map files (.cub)
├── sources/         # Core raycasting and rendering source files
├── sources_bonus/   # Bonus mode source files
├── textures/        # Wall and sprite textures
└── Makefile
```

## Requirements

- GCC or Clang
- Make
- CMake (for building MLX42)
- OpenGL and GLFW (required by MLX42)

Install dependencies on Debian/Ubuntu:

```bash
sudo apt install cmake libglfw3-dev libgl1-mesa-dev
```

On macOS (with Homebrew):

```bash
brew install cmake glfw
```

## Installation

Clone the repository (including submodules):

```bash
git clone --recurse-submodules https://github.com/joellehtonen/cub3d.git
cd cub3d
make
```

To build the bonus version:

```bash
make bonus
```

## Usage

Run the program with a `.cub` map file as an argument:

```bash
./cub3d maps/simple.cub
```

A window will open with the 3D view. Use the controls below to navigate.

## Controls

| Key / Input | Action |
|---|---|
| `W` | Move forward |
| `A` | Strafe left |
| `S` | Move backward |
| `D` | Strafe right |
| `←` / `→` Arrow keys | Rotate camera |
| Mouse | Rotate camera |
| `Space` | Open/close door |
| `Esc` | Quit |

## Map Format

Maps are defined in `.cub` scene files. A valid file specifies textures, floor/ceiling colors, and a 2D grid layout:

```
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png

F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111
```

The map grid uses `1` for walls, `0` for open space, and a cardinal letter (`N`, `S`, `E`, `W`) to set the player's starting position and facing direction. The map must be fully enclosed by walls.

## Bonus Mode

Build with `make bonus` to enable the bonus version, which features a dynamic lighting effect — the ambient light slowly dims over time, creating a tense atmosphere. This lays the groundwork for a survival-style game loop where a player would search for keys and supplies before the light runs out completely.

## What I Did

This was a team project with [ethan-berkowitz](https://github.com/ethan-berkowitz). I was responsible for the raycasting engine and rendering textures correctly onto surfaces. The project also used parts of my earlier Hive game project, So Long, as a foundation for player movement and controls.

## What I Learned

- Using trigonometry to calculate ray trajectories introduced me to more complex math than I had worked with before
- Debugging the rays was a surprisingly involved process that pushed my logical thinking further
- This was one of the first projects where performance was a real concern — many coding decisions were made with efficiency and framerate in mind
- Getting a first-person perspective to look right involves a lot of subtle movements across multiple axes

## What I Would Do Differently

- I'd explore a different or more efficient approach to calculating ray trajectories, as that was the biggest hurdle of the project
- The door-opening mechanism was a simple, last-minute solution — something more elegant would have been nice given more time
- The minimap works well, but it would be better if it stayed centered on the player at all times
- Some other students added enemies and weapons, which would be a fun future challenge to incorporate
- The bonus mode (slowly dimming light) could easily be expanded into a proper survival loop where the player searches for keys and lighter fluid to escape before the light goes out completely

## License

This project was developed as part of the 42 / Hive School curriculum. No license is explicitly provided.
