# Snake & Ladder Game 🎲

## 📖 Description
This project is an advanced Snake & Ladder game implemented in C.  
The game runs on a 10×10 board and includes the following features:
- Event cells with random outcomes
- Snakes and ladders that change player positions
- A shop system to buy items using coins
- Save and load functionality

## ⚙️ How to Run
Compile and run the code with:

```bash
gcc Snakes-Laddersmain.c -o snake_ladder
./snake_ladder
```
🗂️ Project Structure
main.c → Main game logic

Functions for board setup, player movement, shop system, save/load

✨ Features
🎲 Virtual dice rolls

🪙 Coin system with shop (shield, dice modifiers, reroll)

🐍 Snake cells that move players backward

🪜 Ladder cells that move players forward

🎁 Event cells with random effects (move, coins, skip turn)

💾 Save & load game state from save.dat

👥 Two-player mode or play against computer

🗺️ Dynamic 10×10 board visualization with player positions

🚀 Future Plans
Add graphical interface using Allegro

Advanced save/load with multiple slots

Online multiplayer mode

Improved computer AI

🛠️ Tools & Libraries
C language

GCC Compiler

Standard C libraries (stdio, stdlib, time, string, stdbool)
