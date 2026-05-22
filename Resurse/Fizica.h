#pragma once 
#include"Setari.h"
#include"Ententy.h"


inline bool Cloide = false;

//Finctia care se va ocupa de coliziuni
Rectangle GetColision(Vector2 Pos1 , Vector2 Size1 , Vector2 Pos2 , Vector2 Size2); 
bool CheckColision(Vector2 Pos1 , Vector2 Size1 , Vector2 Pos2 , Vector2 Size2);

// Player and enemy hub
void FIzicHub(Entity* e1 , Entity * e2 ); 

void HandleColision(Entity* e1 , Entity * e2   ); // PE stands for Player Enemy 


