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
void DelletEnemy(EnemyManager* manager ,unsigned int index);
void UpdateEnemy(EnemyManager * manager , Vector2 Player_Pos);
void SpawnEnemy(EnemyManager * manager);
Vector2 GetEnemyPos(EnemyManager * manager , int index);

void PrintEnemyInfo(EnemyManager * manager);
