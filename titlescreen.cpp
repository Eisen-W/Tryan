#include "game.hpp"

// Title Screen control
TitleScreen::TitleScreen() 
{
    Startbutton = { (canvasWidth-200)/2.0f, (canvasHeight-100)/2.0f, 200, 100 };
    isButtonClicked = false;
}

void TitleScreen::Update(float scale, int offsetX, int offsetY) 
{
    Vector2 mouse = GetMousePosition();
    mouse.x = (mouse.x - offsetX)/scale;
    mouse.y = (mouse.y - offsetY)/scale;

    if (CheckCollisionPointRec(mouse, Startbutton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
    {
        isButtonClicked = true;
    }
}

void TitleScreen::Draw(Font font) 
{
    DrawRectangle(0,0, canvasWidth, canvasHeight, PINK);
    DrawRectangleRec(Startbutton, BLACK);
    DrawTextPro(font, "Start", {(canvasWidth-150)/2.0f,(canvasHeight-50)/2.0f}, {0,0}, 0, 50, 5, RAYWHITE);
}