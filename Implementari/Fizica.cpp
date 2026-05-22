#include"Fizica.h"


//Finctia care se va ocupa de coliziuni
Rectangle GetColision(Vector2 Pos1 , Vector2 Size1 , Vector2 Pos2 , Vector2 Size2){
    Rectangle Box1 = {Pos1.x , Pos1.y , Size1.x , Size1.y};
    Rectangle Box2 = {Pos2.x , Pos2.y , Size2.x , Size2.y};
    return GetCollisionRec(Box1 , Box2);
}
bool CheckColision(Vector2 Pos1 , Vector2 Size1 , Vector2 Pos2 , Vector2 Size2){
    Rectangle Box1 = {Pos1.x , Pos1.y , Size1.x , Size1.y};
    Rectangle Box2 = {Pos2.x , Pos2.y , Size2.x , Size2.y};
    return CheckCollisionRecs(Box1 , Box2);
}

// Player and e2->enemy hub
void FIzicHub(Entity * e1 , Entity * e2 ){
    
    //Ne ocupam cu coliziunile dintre imanic si 
    HandleColision(e1 , e2);

}

void HandleColision(Entity* e1 , Entity * e2 ){ // Trebuie sa primeasca un obicet general 
    if(CheckColision(e1->Pos , e1->Size , e2->Pos , e2->Size)){
        e1->Color = {255 , 125 , 125 , 150};
        Cloide = true;
        e2->HP -= e1->Damage;
    }
    else{
        if(e1->type == EntityType::ENTITY_PLAYER && !Cloide )
            e1->Color = _Player_Color;
        else if (!Cloide)
            e1->Color = _Enemy_Color;
    }

}

