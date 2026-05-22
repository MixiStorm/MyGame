#pragma once 
#include"Setari.h"
#include"Ententy.h"

void InitPlayer(Entity * player);

//Functie pentru desenarea player
void DrawPlayer(Entity * player);

//Functia necesara pentru miscarea playerului 
void PlayerMove(Entity * player);

//Returneaza pozitia playerului 
Vector2 GetPlayerPos(Entity * player);