# Tic Tac Toe Game vs Computer Using Heuristic Function
This code attempts to solve the traditional tic tac toe game using a heuristic function discussed in one of my classes at school.
The function helps the computer decide which move to play in order to maximize profit, but does not yet consider minimizing loss. This basically means that if the comp sees an opportunity at winning, it will choose the winning position, but if there is a situation where the player is winning, it may or may not be able to stop the player from winning.

The game is visualized as a 3x3 board populated by 0s by default (blank board). The player's moves are represented by "1" and the computer's move with "2". Input is expected as an index between 0-8 (representing a position in the grid).
