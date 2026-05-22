#include"Setari.h"
#include"Player.h"
#include"Enemy.h"
#include"Fizica.h"


int main(){
    EnemyManager manager;
    Entity player;
    
    //Task 1 Opan a window 
    InitWindow(WindowLenght , WindowHeight , WindowName);
    SetTargetFPS(FrameRate);
    

    //Initializam inamici 
    InitEnemyManager(&manager);
    InitPlayer(&player);
    float dt = 0.0f;

    while(!WindowShouldClose()){
        dt += GetFrameTime();
        if (dt >= 5.0f){
            SpawnEnemy(&manager);
            //PrintEnemyInfo(&manager);
            dt = 0 ;
        }
        UpdateEnemy(&manager , GetPlayerPos(&player));
        PlayerMove(&player);
        for(auto & e : manager.Enemys)
            HandleColision(&player, &e);
        Cloide = false;
        
        BeginDrawing();
        ClearBackground(_Background_Color);
        

            DrawEnemy(&manager);
            DrawPlayer(&player);

            //For debug 
            DrawText(TextFormat("Player Pos : x: %f y: %f " , GetPlayerPos(&player).x , GetPlayerPos(&player).y ), 10 ,10 , 30 , BLACK);

        EndDrawing();

    }
    CloseWindow();


    
    return 0;
}