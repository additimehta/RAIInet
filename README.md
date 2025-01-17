# RAIInet: Strategic Dual

RAIInet is a turn-based strategy game developed in C++ that offers dynamic perspectives for two players. Featuring text-based and graphical interfaces, the game emphasizes strategic gameplay through customizable abilities and unique player interactions.

## Gameplay Commands
Players interact with the game using the following text-based commands:
- `move <link> <dir>`: Moves the specified link (`a-g` for player 1, `A-G` for player 2) in the given direction (`u`, `d`, `l`, `r` for up, down, left, and right, respectively).
- `abilities`: Displays available ability cards, their IDs (`1-5`), and usage status.
- `ability <N> [target]`: Activates ability card with ID `N`. Certain abilities require a target (e.g., a link or board cell):
  - Use link codes (e.g., `b`) or board coordinates (e.g., `1 3`) for targeting.
- `board`: Displays the current game board.
- `sequence <file>`: Executes a series of commands listed in the specified file, useful for testing.
- `quit` or `Ctrl-d`: Exits the game.

## Abilities
The game features a variety of abilities that add strategic depth. Here’s a brief overview of each:

1. **Link Boost**: Enhances a controlled link to move an extra square in each direction when moving. This enables it to “jump over” obstacles but may prevent it from reaching the opponent's server port. The effect lasts until the link is downloaded.

2. **Firewall**: Places a firewall on an empty square (excluding server ports). Opponent links passing through the square are revealed and, if viruses, immediately downloaded. Firewalls are displayed as "m" for Player 1 and "w" for Player 2 but are replaced by any link occupying the square. Firewalls also provide defensive benefits during battles.

3. **Download**: Instantly downloads an opponent's targeted link without requiring it to be revealed.

4. **Polarize**: Converts a targeted data link into a virus or a virus into a data link, maintaining the same strength.

5. **Scan**: Reveals the type and strength of any targeted link on the board, excluding your own.

6. **Amplifier**: Places an amplifier marker ("A") on an empty cell (excluding server ports, firewalls, or other amplifiers). Links entering this cell gain a permanent +2 boost to their strength. Amplifier effects stack, and the cell displays the link if occupied.

7. **Warp Shift**: Relocates any active link (yours or the opponent's) to a random empty cell (excluding server ports). Initially planned to end the player’s turn, this ability now allows the turn to continue after use.

8. **Zigzag**: Empowers one of your own links to move diagonally in addition to the standard cardinal directions for the rest of the game.

## How to Play
1. Clone the repository:
    ```bash
    git clone https://github.com/username/raiinet.git
    cd raiinet
    ```
2. Build the project using the provided `Makefile`:
    ```bash
    make
    ```
3. Run the game with desired options:
    ```bash
    ./RAIInet [options]
    ```
   Options include:
   - `-ability1 <order>`: Specify abilities for player 1 (e.g., `LFDSP`).
   - `-ability2 <order>`: Specify abilities for player 2.
   - `-link1 <placement-file>`: Define link configurations for player 1.
   - `-link2 <placement-file>`: Define link configurations for player 2.
   - `-graphics`: Enable graphical display.

## Development Highlights
- **Team Collaboration**: Created UML diagrams to establish clear architecture and design principles before implementation.
- **Smart Memory Management**: Utilized `std::unique_ptr` for ownership and to prevent memory leaks.
- **Observer Design Pattern**: Implemented for synchronized updates across text and graphical displays.
- **Balanced Gameplay**: Designed abilities and mechanics for strategic depth and fairness.
