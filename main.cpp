// Tryan Visual Novel Engine
// Copyright (c) 2025 Eisen-W ()
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include<raylib.h>
#include "game.hpp"
#include "config.hpp"
using namespace std;



int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(canvasWidth, canvasHeight, "Tryan");
    SetTargetFPS(60);
    MaximizeWindow();

    Game game;

    while(!WindowShouldClose())
    {
        game.Update();
        game.Draw();
    }

    CloseWindow();
    return 0;
}