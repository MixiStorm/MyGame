#pragma once
#include"raylib.h"
#include"raymath.h"
#include<stdio.h>

//Setari pentru fereastra principala 
inline int WindowLenght = 1336;
inline int WindowHeight = 750;
inline char name[] = "My_game";
inline constexpr char* WindowName = name ;

inline constexpr int FrameRate = 60 ;

//Culori standard create de mine 
inline Color _Background_Color = {250, 215, 215 , 255};
inline Color _Player_Color = {76, 170, 207, 255};
inline Color _Enemy_Color = {50 , 250 , 80 , 255};
inline Color _Default_Color=  {50 , 50 , 50 , 255};

//Players settings 
inline float Player_Max_Speed_Cap = 1500.0f; // Aceasta limiteaza viteza maxima a playerului , foarte buna de modificat prin upgradeuri prin joc 


//Enemy Settings
inline constexpr int Enemy_Max_Count_Cap = 6; // Vom acea doar 500 de inamici maxim 
inline constexpr int Enemy_Max_Size = 150;
inline constexpr int Enemy_Min_Size = 15;
inline constexpr float Enemy_Speed_Constant = 5000.0f;
inline constexpr float Enemy_Max_Speed_Cap = 2500.0f; // Aceasta limiteaza viteza maxima a playerului , foarte buna de modificat prin upgradeuri prin joc 

//Variabile pentur debug
inline bool Debug_Mode = true;
inline bool Enemy_Spwning = true;