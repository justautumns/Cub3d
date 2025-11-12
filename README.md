# 🧱 Cub3D

A 3D raycasting game inspired by **Wolfenstein 3D**, built as part of the **42 Vienna** curriculum.  
The goal of this project is to explore **raycasting**, **graphics rendering**, and **game engine basics** using the **MiniLibX** graphics library.

---

## 🎯 Project Overview

Cub3D is a simple 3D game engine that renders a maze-like world using **raycasting**.  
It allows the player to move through a 2D map as if it were a 3D environment, with real-time rendering of walls, textures, and sprite objects.

This project is a deep dive into:
- Computer graphics fundamentals  
- Vector math & geometry  
- Game loop structure  
- Keyboard/mouse event handling  
- Efficient rendering in C  

---

## 🧩 Features

- Real-time **raycasting engine**  
- **Textured walls**, **floors**, and **ceilings**  
- **Player movement** and rotation  
- **Sprite rendering** (enemies, items, etc.)  
- **Minimap** (optional)  
- **Error handling** for invalid maps or configuration files  
- **Configurable map files** (`.cub`)

---

## 🗺️ Map Format (`.cub`)

Each map file defines the world layout and textures.  

- `NO`, `SO`, `WE`, `EA` → Texture paths for each wall direction  
- `F`, `C` → Floor and ceiling colors (RGB)  
- `1` = wall, `0` = empty space, `N/S/E/W` = player start direction  

---

## ⚙️ Installation

### Requirements
- **macOS** or **Linux**
- **gcc / clang**
- **Make**
- **MiniLibX** library (included or provided by 42)

### Build
```bash
mak
RUN
./cub3D maps/map.cub
[ Example: ./Texture.png ]

