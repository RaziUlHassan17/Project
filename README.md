# Maze Solver Project

A clean, efficient maze solving application with C++ backend and Java GUI frontend.

## 🎮 Quick Start

```bash
cd java-gui
run.bat
```

**Controls:** Use ARROW KEYS (UP/DOWN/LEFT/RIGHT) to navigate

## 📁 Project Structure

```
├── java-gui/              # Java GUI Game
│   ├── MazeGameSimple.java # Main game file  
│   ├── run.bat            # Windows launcher
│   └── README.md          # GUI documentation
├── cpp/                   # C++ Maze Solver
│   ├── main/              # Source code
│   │   ├── main.cpp       # BFS solver implementation
│   │   ├── Read.h         # Header file
│   │   └── main.sln       # Visual Studio solution
│   └── build.bat          # Build script
├── mazes/                 # Maze Files
│   ├── maze_21x21_*.txt   # Small mazes
│   ├── maze_41x41_*.txt   # Medium mazes  
│   ├── maze_81x81_*.txt   # Large mazes
│   └── maze_101x101_*.txt # Extra large mazes
└── README.md              # This file
```

## 🎯 Features

- **Dynamic Cell Sizing**: Automatically adjusts for maze size (21x21 to 101x101)
- **Arrow Key Controls**: Clean, intuitive navigation
- **BFS Algorithm**: Optimal pathfinding in C++ backend
- **Visual Solution**: Yellow path overlay
- **Responsive UI**: Scales perfectly for all maze sizes

## 🛠️ Requirements

- **Java**: JDK 8 or higher
- **C++ (Optional)**: Visual Studio or MinGW for solution feature

## 🚀 How to Play

1. Run `java-gui/run.bat`
2. Select maze size from dropdown
3. Click "Load Maze"
4. Use arrow keys to navigate from green start to red exit
5. Click "Show Solution" for optimal path (requires C++ compilation)

## 🔧 Technical Details

### Maze Format
- `#` = Walls (black)
- `X` = Paths (white)  
- `S` = Start (green)
- `E` = Exit (red)

### Algorithms
- **Java**: Real-time player movement and rendering
- **C++**: BFS (Breadth-First Search) for shortest path

## ✅ Recent Improvements

- ✅ Dynamic cell sizing for all maze sizes
- ✅ Arrow key only controls
- ✅ Cleaned up project structure
- ✅ Removed unnecessary files and folders
- ✅ Fixed 81x81 and 101x101 maze display issues
- ✅ Better error handling and path detection

## 🎮 Enjoy the Game!

Navigate through mazes of increasing difficulty and challenge yourself with the largest 101x101 mazes!