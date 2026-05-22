#pragma once
#include"Setari.h"


//Enum pentru a tine cont de toate tipurile de entitati 
enum class EntityType{
    ENTITY_PLAYER,
    ENTITY_ENEMY,
    ENTITY_ENEMY_MANAGER
};

// Structul ce va deveni sturctura de entitati 
struct Entity{
    //Tip topitie si dimensiune 
    EntityType type;
    Vector2 Pos;
    Vector2 Size;
    float Radius = 0 ;

    //Specifice pentru player si enemy 
    //Initiaizam cu 0 absolut totul pentru ca vom folosi aceasi structura si pentru pereti si obstacole 
    float Speed = 0;
    float Damage = 0;
    float HP = 0;
    Color Color = _Default_Color;


    bool IsMoving = false;
    bool StilAlive ;
};

