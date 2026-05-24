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
    Color _Color = _Default_Color;


    bool IsMoving = false;
    bool StilAlive ;
};

//Getere
inline Vector2 GetEntityPos(Entity * entitate){return entitate->Pos;}
inline Vector2 GetEntitySize(Entity * entitate){return entitate->Size;}
inline float GetEntityHP(Entity * entitate){return entitate->HP;}
inline float GetEntityRadius(Entity * entitate){return entitate->Radius;}
inline float GetEntityDamage(Entity * entitate){return entitate->Damage;}
inline float GetEntitySpeed(Entity * entitate){return entitate->Speed;}
inline EntityType GetEntityType(Entity * entitate){return entitate->type;}
inline bool GetEntityIsMoving(Entity * entitate){return entitate->IsMoving;}
inline bool GetEntityStilAlive(Entity * entitate){return entitate->StilAlive;}
inline Vector2 GetEntityCenter(Entity * entitate) {
    return { entitate->Pos.x + (entitate->Size.x / 2.0f), entitate->Pos.y + (entitate->Size.y / 2.0f) };
}


//Setere
inline void SetEntityPos(Entity * entitate , Vector2 new_pos){entitate->Pos = new_pos;}
inline void SetEntityPosAtEntityCenter(Entity * entitate){entitate->Pos = GetEntityCenter(entitate);}
inline void SetEntitySize(Entity * entitate , Vector2 Size){entitate->Size = Size;}
inline void SetEntityHP(Entity * entitate ,float HP){entitate->HP = HP;}
inline void SetEntityRadius(Entity * entitate , float radius){entitate->Radius = radius;}
inline void SetEntityDamage(Entity * entitate , float damage){entitate->Damage = damage;}
inline void SetEntitySpeed(Entity * entitate , float speed){entitate->Speed = speed;}



//Functi de debug
inline void PrintEntityInfo(Entity * entitate){
    Vector2 e_pos = GetEntityPos(entitate);
    Vector2 e_size= GetEntitySize(entitate);
    float HP = GetEntityHP(entitate);
    float Speed = GetEntitySpeed(entitate);
    float Damage = GetEntityDamage(entitate);
    int Font_Size = 20;

    //Desenam in dreapa enitati datele despre ea
    Vector2 Draw_Pos = {e_pos.x + e_size.x + 5 , e_pos.y};
    DrawText(TextFormat("POS X: %f Y: %f" , e_pos.x , e_pos.y) , Draw_Pos.x , Draw_Pos.y , Font_Size , BLACK);
    DrawText(TextFormat("Size L: %f H: %f" , e_size.x , e_size.y) , Draw_Pos.x , Draw_Pos.y + (Font_Size * 1) + 2 , Font_Size , BLACK);
    DrawText(TextFormat("HP : %f" , HP) , Draw_Pos.x , Draw_Pos.y + (Font_Size * 2) + 2 , Font_Size , BLACK);
    DrawText(TextFormat("Damage : %f" , Damage) , Draw_Pos.x , Draw_Pos.y + (Font_Size * 3) + 2 , Font_Size , BLACK);
    DrawText(TextFormat("SPEED : %f" , Speed) , Draw_Pos.x , Draw_Pos.y + (Font_Size * 4) + 2 , Font_Size , BLACK);    

}