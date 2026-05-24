#include"Setari.h"
#include"Player.h"
#include"Enemy.h"
#include"Fizica.h"
#define FULL_SCREEN_MODE_D 


int main(){
    EnemyManager manager;
    Entity player;

    //Initializam inamici 
    InitEnemyManager(&manager);
    InitPlayer(&player);
    float dt = 0.0f;
    
    //Task 1 Opan a window 
    #if defined(FULL_SCREEN_MODE_D)
        SetConfigFlags(FLAG_FULLSCREEN_MODE);
        WindowHeight = GetScreenHeight();
        WindowLenght = GetScreenWidth();
        InitWindow(WindowLenght, WindowHeight, WindowName);

    #else
        InitWindow(WindowLenght , WindowHeight , WindowName);
    #endif

    SetTargetFPS(FrameRate);
    
    while(!WindowShouldClose()){
        if(!IsWindowHidden()){

            if(Debug_Mode){
                DrawText(TextFormat("Spawn : %d" , Enemy_Spwning) , 10 , 40 , 30 , BLACK);
                if(IsKeyPressed(KEY_S) ){
                    if(Enemy_Spwning){
                        Enemy_Spwning = false;
                    }
                    else{
                        Enemy_Spwning = true;
                    }
                }
                if(!Enemy_Spwning) Kill(&manager);

            }


            dt += GetFrameTime();
            if (dt >= 5.0f){
                SpawnEnemy(&manager);
                //PrintEnemyInfo(&manager);
                dt = 0 ;
            }
                        
            UpdateEnemy(&manager , GetEntityCenter(&player));
            PlayerMove(&player);

            for(auto & e : manager.Enemys)
                HandleColision(&player, &e);
            Cloide = false;
            
            BeginDrawing();
                ClearBackground(_Background_Color);

                DrawEnemy(&manager);
                DrawPlayer(&player);
    
                //For debug 
                DrawText(TextFormat("Player Pos : x: %f y: %f " , GetEntityPos(&player).x , GetEntityPos(&player).y ), 10 ,10 , 30 , BLACK);
    
            EndDrawing();
        }

    }
    CloseWindow();


    
    return 0;
}