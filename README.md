# 🎲 Advanced Snakes and Ladders (CLI Edition)

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

### Compilation
Open your terminal or command prompt, navigate to the project directory, and compile the source code:



🕹️ How To Play
1. Launch: Choose whether to Load a Saved Game or start a New Game.

2. Setup: Choose your mode (PvP or vs Computer) and enter player names.

3. Turns: On each turn, a dice is automatically rolled. You can then access the Shop to alter your fate if you have enough coins.

4. PVP Mechanic: Landing on the exact same tile as your opponent will kick them back to square 1 (unless they have a shield to absorb the impact!).

5. Winning: The first player to reach exactly tile 100 wins the game.

🛠️ Code Structure Overview
struct player: Manages player states including positions, shield status, coin balance, and turn skips.

struct map: Defines the 100-tile grid properties and contents.

move_player(): Handles game logic, tile landing actions, and collision detection between players.

shop(): Implements the interactive marketplace menu.

save_game() / load_game(): Handles binary file handling for game state persistence.

🤝 Contributing
Contributions, bugs, and feature requests are welcome! Feel free to check the issues page or submit a pull request if you want to enhance the terminal graphics or add more wacky board events.

Enjoy the game, and may the RNG gods be in your favor! 🎲
