#include <SDL2/SDL.h>
#include "render.h"

// Constants for the window size
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int CELL_SIZE = 200;  // Each cell is 200x200 pixels

// Function to draw the game grid
void draw_grid(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color

    // Draw vertical lines
    for (int i = 1; i <= 2; i++) {
        SDL_RenderDrawLine(renderer, i * CELL_SIZE, 0, i * CELL_SIZE, SCREEN_HEIGHT);
    }

    // Draw horizontal lines
    for (int i = 1; i <= 2; i++) {
        SDL_RenderDrawLine(renderer, 0, i * CELL_SIZE, SCREEN_WIDTH, i * CELL_SIZE);
    }
}

// Function to draw X and O on the board
void draw_x(SDL_Renderer *renderer, int row, int col) {
    int x1 = col * CELL_SIZE + 20;
    int y1 = row * CELL_SIZE + 20;
    int x2 = (col + 1) * CELL_SIZE - 20;
    int y2 = (row + 1) * CELL_SIZE - 20;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red color
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y1, x1, y2);
}

void draw_o(SDL_Renderer *renderer, int row, int col) {
    int centerX = col * CELL_SIZE + CELL_SIZE / 2;
    int centerY = row * CELL_SIZE + CELL_SIZE / 2;
    int radius = CELL_SIZE / 2 - 20;

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Blue color

    // Draw a simple circle (approximate with lines)
    for (int i = 0; i < 360; i += 10) {
        double angle = i * 3.14159 / 180;
        double nextAngle = (i + 10) * 3.14159 / 180;
        SDL_RenderDrawLine(renderer,
            centerX + radius * cos(angle), centerY + radius * sin(angle),
            centerX + radius * cos(nextAngle), centerY + radius * sin(nextAngle));
    }
}
