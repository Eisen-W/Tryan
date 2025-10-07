#include "game.hpp"
#include<cmath>
using namespace std;

Game::Game()
{
    InitGame();
}

Game::~Game()
{
    UnloadFont(GBFont);
    UnloadTexture(bg);
    UnloadRenderTexture(target);
}

void Game::InitGame()
{
    target = LoadRenderTexture(canvasWidth, canvasHeight);
    bg = LoadTexture("../assets/i_background.jpg");
    GBFont = LoadFont("../assets/Fonts/ascii.png");

    currentState = GameState::Title;
    run = true;
    //screencolor = BLUE;
    scale = 1.0f;
    offsetX = offsetY = 0;
}

void Game::Update() {

    scale = fminf((float)GetScreenWidth()/canvasWidth, (float)GetScreenHeight()/canvasHeight);
    fit = {canvasWidth*scale, canvasHeight*scale};
    offsetX = (GetScreenWidth() - (int)(fit.x))/2;
    offsetY = (GetScreenHeight() - (int)(fit.y))/2;

    if(!IsWindowMaximized()) screencolor = LIME;
    else screencolor = BLUE;

    if (currentState == GameState::Title) {
        TS.Update(scale, offsetX, offsetY);
        if (TS.isButtonClicked) currentState = GameState::Playing;
    }
    else if (currentState == GameState::Playing) {
        DrawRectangle(0,0, canvasWidth, canvasHeight, screencolor);
    }
}

void Game::Draw() {
    
    BeginTextureMode(target);
    ClearBackground(RAYWHITE);

    if (currentState == GameState::Title)
        TS.Draw(GBFont);
    else if (currentState == GameState::Playing)
        DrawRectangle(0, 0, canvasWidth, canvasHeight, screencolor);

    EndTextureMode();

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexturePro(bg, {0,0,(float)bg.width,(float)bg.height},
                   {0,0,(float)GetScreenWidth(),(float)GetScreenHeight()},
                   {0,0},0,RAYWHITE);

    Rectangle src = {0,0, (float)canvasWidth, -(float)canvasHeight};
    Rectangle dest = {(float)offsetX, (float)offsetY, fit.x, fit.y};
    DrawTexturePro(target.texture, src, dest, {0,0}, 0, WHITE);

    if(IsWindowMaximized())
    DrawText(TextFormat("%d", GetFPS()), 10, 10, 30, RED);

    EndDrawing();
}