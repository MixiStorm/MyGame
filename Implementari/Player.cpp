#include"Player.h"

//Creeam structul Entity
Vector2 MousePos = {0,0};
float Interati_in_PlayerMove = 0 ;

void DrawPlayer(Entity * player){
    DrawRectangle(player->Pos.x , player->Pos.y  , player->Size.x , player->Size.y , player->_Color);
    if(Debug_Mode){
        //PrintEntityInfo(player);
    }

}
void PlayerMove(Entity * player){
    float dt = GetFrameTime();

    //Modificam pozitia playerului 
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) ){
        //Obtinem pozitia mouseului 
        MousePos = GetMousePosition();

        MousePos.x -= player->Size.x / 2.0f;
        MousePos.y -= player->Size.y / 2.0f;

        player->IsMoving = true; // Incepem procesul de miscare
    }

    if(player->IsMoving){
        float distance = Vector2Distance(player->Pos , MousePos);
        
        // Testam putin niste mecanici 
        // Daca viteza playerului este direct proportionala cu distanta dintre mouse si player 
        player->Speed = distance * 4.5;
        player->Speed = fmaxf(50.0f , fminf(player->Speed , Player_Max_Speed_Cap));


        // Dacă suntem foarte aproape de țintă (sub 2 pixeli), ne oprim ca să evităm tremuratul (jitter)
        if (distance < 2.0f) {
            SetEntityPos(player, MousePos)   ;
            player->IsMoving = false;
        } else {
            // Obținem direcția (Vector2Normalize face automat împărțirea la lungime în siguranță)
            Vector2 direction = Vector2Subtract(MousePos, player->Pos);
            direction = Vector2Normalize(direction);

            // Modificăm poziția: NouaPoz = VecheaPoz + Directie * Viteza * DeltaTime
            Vector2 velocity = Vector2Scale(direction, player->Speed * dt);
            SetEntityPos(player ,  Vector2Add(player->Pos, velocity));
        }
    }
}
void InitPlayer(Entity * player){
    //Setam entitatea ca fiind o entitate de tip player 
    player->type = EntityType::ENTITY_PLAYER;
    player->_Color = _Player_Color;
    player->Pos = {WindowLenght / 2 , WindowHeight / 2};
    player->HP = 100;
    player->Damage = 15;
    player->Speed = 400;
    player->Size = {40.0f , 40.0f};
    player->StilAlive = true;

}


