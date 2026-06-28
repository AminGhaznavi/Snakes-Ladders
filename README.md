# 🎲 Advanced Snakes and Ladders 

Welcome to **Advanced Snakes & Ladders**, a terminal-based reimagining of the classic board game written in pure C. This isn't just your ordinary luck-based game—it introduces an **In-game Economy, Power-ups, Shields, Mystery Events, and an AI Opponent** to add strategy and depth to every single move!

---

## ✨ Features

* **🎮 Game Modes:** Play head-to-head with a friend (**2-Player Mode**) or challenge the **Computer AI Mode**.
* **💰 In-Game Shop & Economy:** Collect coins on the board and spend them strategically to modify your dice, buy shields, or reroll.
* **🛡️ Shield System:** Protect yourself from snake bites or aggressive tile landings by buying a shield.
* **⚡ Dynamic Tiles:**
    * `C` **Coins:** Boosts your wallet.
    * `T` **Trampolines (Ladders):** Launch yourself forward.
    * `s` **Snakes:** Pulls you backward (unless protected by a shield).
    * `E` **Mystery Events:** Random occurrences that can turn the tide of the game instantly!
* **💾 Save & Load System:** Running out of time? Save your game state to a file (`save.dat`) and resume exactly where you left off.
* **🗺️ Visual CLI Board:** Features a dynamically rendered 10x10 board layout to track player positions in real-time.

---

## 🛒 The Marketplace (Shop Menu)

When it's your turn, your hard-earned coins can be spent on game-changing modifiers:

| Item / Action | Cost | Effect |
| :--- | :--- | :--- |
| **1. Reroll** | 3 Coins | Discard your current dice and roll a new one. |
| **2. +1 Modifier** | 2 Coins | Increase your dice value by 1 (Max 6). |
| **3. -1 Modifier** | 1 Coin | Decrease your dice value by 1 (Min 1). |
| **4. Buy Shield** | 4 Coins | Acquire a shield to block the next snake attack. |
| **5. Never Mind** | Free | Decline shopping and proceed with your current move. |
| **6. Save & Exit** | Free | Saves current progress to `save.dat` and closes the game. |

---

## 🚀 Getting Started

### Prerequisites
You need a C compiler installed on your system (such as `gcc`).


---

## 🕹️ Game Rules & How To Play

Follow these simple steps to get your game running and understand the core mechanics:

* **1. Launching the Game**
  Choose whether to **Load a Saved Game** (resuming your previous session) or start a fresh **New Game** from scratch.

* **2. Setup & Configuration**
  Select your preferred mode—either **Player vs Player (PvP)** or **vs Computer (AI)**—and enter custom names for the players.

* **3. Turn-Based Gameplay**
  On every single turn, the dice rolls automatically. If you have collected enough coins, the game will present the **Shop Menu** where you can strategically alter your fate before moving.

> ⚔️ **The Ultimate PvP Mechanic:** If you land on the **exact same tile** as your opponent, you will aggressively kick them back to **Square 1**! However, if they bought a **Shield** from the shop, it will absorb the impact, break the shield, and save their position.

* **4. Winning Condition**
  The first player to navigate through the chaos and land exactly on **Tile 100** wins the match!

---

## 🛠️ Code Architecture Overview

Here is a quick look under the hood at how the core game logic is structured in C:

### Data Structures
* `struct player` — Manages the state of each player, tracking their current position, shield status, wallet balance (coins), and turn skips.
* `struct map` — Defines the properties, contents, and event triggers for each individual square on the 100-tile grid.

### Core Functions
* `move_player()` — The heart of the game logic. It calculates new positions, processes dynamic tile landings (Snakes, Trampolines, Coins), and handles player collision checking.
* `shop()` — Powers the interactive CLI marketplace menu, handling item selection and real-time wallet deductions.
* `save_game()` / `load_game()` — Manages data persistence by reading and writing raw struct data directly to a binary file (`save.dat`).

---

## 🤝 Contributing & Support

Have an idea to make this game even wilder? Contributions are highly appreciated! 

* 🐛 Found a bug? Open an **Issue**.
* 💡 Want to add new custom events, board layouts, or fancy ASCII graphics? Fork the repo and submit a **Pull Request**.

---

### *May the RNG gods be forever in your favor!* 🎲
