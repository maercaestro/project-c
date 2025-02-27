// Mac-compatible interactive Snake game
#include <ncurses.h>   // For real-time keyboard input
#include <stdlib.h>    // For rand()
#include <unistd.h>    // For usleep()
#include <ctype.h>     // For tolower()

// Game area size
#define HEIGHT 20
#define WIDTH 40

// Arrays for snake body positions
int snakeTailX[100], snakeTailY[100];
int snakeTailLen;

// Game variables
int gameover, key, score;
int x, y, fruitx, fruity;

// Function to initialize the game
void setup() {
    initscr();            // Start ncurses mode
    clear();              // Clear the screen
    noecho();             // Don't show key presses
    cbreak();             // Disable line buffering
    curs_set(0);          // Hide cursor
    nodelay(stdscr, TRUE); // Non-blocking input

    // Initialize game variables
    gameover = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitx = rand() % WIDTH;
    fruity = rand() % HEIGHT;
    while (fruitx == 0) fruitx = rand() % WIDTH;
    while (fruity == 0) fruity = rand() % HEIGHT;
    score = 0;
}

// Function to draw the game field
void draw() {
    clear();  // Clear screen before drawing

    // Top border
    for (int i = 0; i < WIDTH + 2; i++) printw("-");
    printw("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j <= WIDTH; j++) {
            // Draw borders
            if (j == 0 || j == WIDTH) printw("#");

            // Draw snake head
            else if (i == y && j == x) printw("O");

            // Draw fruit
            else if (i == fruity && j == fruitx) printw("*");

            // Draw snake body
            else {
                int prTail = 0;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        printw("o");
                        prTail = 1;
                    }
                }
                if (!prTail) printw(" ");
            }
        }
        printw("\n");
    }

    // Bottom border
    for (int i = 0; i < WIDTH + 2; i++) printw("-");
    printw("\n");

    // Display score and instructions
    printw("Score: %d\n", score);
    printw("Press W, A, S, D to move.\n");
    printw("Press X to quit.\n");

    refresh();  // Refresh screen with new frame
}

// Function to capture player input
void input() {
    int ch = getch();
    switch (tolower(ch)) {
        case 'a': if (key != 2) key = 1; break; // Left
        case 'd': if (key != 1) key = 2; break; // Right
        case 'w': if (key != 4) key = 3; break; // Up
        case 's': if (key != 3) key = 4; break; // Down
        case 'x': gameover = 1; break; // Exit
    }
}

// Function to handle movement and collisions
void logic() {
    // Update snake body
    int prevX = snakeTailX[0], prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;
    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move snake
    switch (key) {
        case 1: x--; break;
        case 2: x++; break;
        case 3: y--; break;
        case 4: y++; break;
    }

    // Collision detection
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) gameover = 1;
    for (int i = 0; i < snakeTailLen; i++)
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            gameover = 1;

    // Eating fruit
    if (x == fruitx && y == fruity) {
        fruitx = rand() % WIDTH;
        fruity = rand() % HEIGHT;
        while (fruitx == 0) fruitx = rand() % WIDTH;
        while (fruity == 0) fruity = rand() % HEIGHT;
        score += 10;
        snakeTailLen++;
    }
}

// Function to control game speed
void delay(int milliseconds) {
    usleep(milliseconds * 1000); // Convert to microseconds
}

// Main function
int main() {
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
        delay(100); // Adjust speed
    }

    // End ncurses mode and print game over message
    endwin();
    printf("Game Over! Final Score: %d\n", score);
    return 0;
}
