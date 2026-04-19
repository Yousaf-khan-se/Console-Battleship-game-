# Console-Battleship-game-
This is my university project of Programming Fundamentals, where I created a console game in c++.  

---

# Battleship-CPP 🚢

A classic, interactive **2-Player Battleship Game** built in C++ for the Windows console. This project features a custom-built UI engine that handles real-time keyboard input, animated welcome screens, and dynamic grid rendering.

## 🚀 Features

* **Interactive Menu:** A keyboard-driven main menu (Arrow keys + Enter) for a smooth user experience.
* **Dynamic UI:** Custom text-centering logic and color formatting to make the console interface more engaging.
* **Strategic Gameplay:** * Two-player local multiplayer mode.
    * Manual ship placement for three different vessel types: **Patrol Boat (2), Submarine (3), and Helicarrier (4)**.
    * Directional placement (Vertical/Horizontal) with boundary and collision detection.
* **Combat System:** Turn-based bombardment with "Hit" (H) and "Miss" (M) tracking across dual grids.
* **Real-time Controls:** Uses `windows.h` and `conio.h` to capture non-buffered keyboard hits for fluid navigation.

## 🕹️ How to Play

1.  **Start:** Enter names for both Captains.
2.  **Placement:** Use the **Arrow Keys** to move the cursor (`o`) and **Enter** to select a starting point. Then, press an Arrow Key to choose the direction to lay your ship.
3.  **Battle:** On your turn, navigate the opponent's grid and press **Enter** to fire a bomb.
4.  **Win:** The game tracks hits and misses. The player with the highest score after all bombs are spent (or all ships are sunk) wins!

## 🛠️ Requirements

* **OS:** Windows (uses `<windows.h>` and `<conio.h>`).
* **Compiler:** Any C++ compiler (GCC/MinGW recommended).

## 📂 Code Structure

* `WelcomeScreen()` / `Menu()`: Handles the visual entry point and user navigation.
* `ShipPlacement()`: Contains the logic for validating and storing ship coordinates.
* `ShipBombardment()`: The core game loop where players take turns attacking.
* `DisplayDoubleGrid()`: Renders both players' tactical maps side-by-side during the attack phase.

---
