#include<raylib.h>
#include<cmath>
using namespace std;

constexpr int canvasWidth=800;
constexpr int canvasHeight=600;

enum GameState{
    Title,
    Playing
};
class TitleScreen{
    public:
        Rectangle Startbutton;
        bool isButtonClicked = false;
        void Draw()
        {
            DrawRectangle(0,0,canvasWidth, canvasHeight, PINK);
            DrawRectangleRec(Startbutton, YELLOW);
        }
        void Update(float scale, int offsetX, int offsetY)
        {
            Vector2 mouse = GetMousePosition();
            mouse.x -= offsetX;
            mouse.y -= offsetY;

            mouse.x /= scale;
            mouse.y /= scale;

            bool hover = CheckCollisionPointRec(mouse, Startbutton);
            if(hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                isButtonClicked = true;
            }
        }
};

TitleScreen TS;
int main()
{
    SetTargetFPS(60);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(canvasWidth, canvasHeight, "Tryan");
    MaximizeWindow();
    Color screencolor;
    GameState currentState = GameState::Title;
    Texture2D bg = LoadTexture("../assets/i_background.jpg");
    if(bg.id==0) { CloseWindow; return -1;}
    RenderTexture2D target = LoadRenderTexture(canvasWidth, canvasHeight);
    TS.Startbutton = {(canvasWidth-200)/2, (canvasHeight-100)/2, 200, 100};

    while(!WindowShouldClose())
    {
        if(!IsWindowMaximized()) screencolor = LIME;
        else screencolor = BLUE;

        float scale = fminf((float)GetScreenWidth() / (float)canvasWidth, (float)GetScreenHeight() / (float)canvasHeight);
        Vector2 fit = {canvasWidth*scale, canvasHeight*scale};
        int offsetX = (GetScreenWidth() - (int)(fit.x))/2;
        int offsetY = (GetScreenHeight()- (int)(fit.y))/2;

        BeginTextureMode(target);
    
        ClearBackground(RAYWHITE);
        if(currentState == GameState::Title)
        {
            TS.Update(scale, offsetX, offsetY);
            TS.Draw();

            if(TS.isButtonClicked) currentState = GameState::Playing;
        }
        if(currentState == GameState::Playing){
            DrawRectangle(0, 0, fit.x, fit.y, screencolor);
        }
            
        EndTextureMode();

        BeginDrawing();
        ClearBackground(RAYWHITE);
         DrawTexturePro(bg, {0,0, (float)bg.width, (float)bg.height},
                        {0,0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                        {0,0}, 0, RAYWHITE);

        DrawText(TextFormat("%d", GetFPS()), 10, 10, 100, RED);

        Rectangle src = {0,0, (float)canvasWidth, -(float)canvasHeight };
        Rectangle dest = {(float)offsetX, (float)offsetY, fit.x, fit.y};

        DrawTexturePro(target.texture, src, dest, {0,0}, 0, WHITE);

        EndDrawing();
    }
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}