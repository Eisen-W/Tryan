#pragma once
#include <raylib.h>
#include "config.hpp"

enum class GameState { Title, Playing };

class TitleScreen {
public:
    TitleScreen();
    ~TitleScreen() = default;

    
    bool isButtonClicked;
    void Draw(Font font);
    void Update(float scale, int offsetX, int offsetY);

    private:
    Rectangle Startbutton;
};

class Game {
public:
    Game();
    ~Game();

    void Draw();
    void Update();

    bool run;
    Color screencolor;
    GameState currentState;

private:
    void InitGame();

    TitleScreen TS;
    Font GBFont;
    Texture2D bg;
    RenderTexture2D target;

    float scale;
    Vector2 fit;
    int offsetX, offsetY;
};
