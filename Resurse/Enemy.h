#pragma once
#include"Setari.h"
#include<random>
#include<time.h>
#include"Ententy.h"


struct EnemyManager
{
    Entity Enemys[Enemy_Max_Count_Cap];
    int count = 0 ;
};



//Functie pentru desenarea player
void DrawEnemy(EnemyManager* manager);

//Functia pentru initializarea managerului de enemys
void InitEnemy(Entity * enemy);
void InitEnemyManager(EnemyManager * manager);

//Actualizarea inamicului
void DelletEnemy(EnemyManager* manager ,unsigned int index);
void UpdateEnemy(EnemyManager * manager , Vector2 Player_Pos);
void SpawnEnemy(EnemyManager * manager);


//Debug Functions
inline void Kill(EnemyManager * manager){
    Vector2 MousePos = GetMousePosition();
    Rectangle M = {MousePos.x , MousePos.y , 1 , 1};

    for(int i = 0 ; i < manager->count ; i++){
        Entity e = manager->Enemys[i];
        Rectangle Target = {e.Pos.x , e.Pos.y ,e.Size.x , e.Size.y};
        
        if(CheckCollisionRecs(M , Target) ){
            manager->Enemys[i]._Color = {20 , 220 , 50 , 255};

            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) DelletEnemy(manager , i);
        }
        else
            manager->Enemys[i]._Color = _Enemy_Color;
    } 

}



