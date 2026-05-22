#include"Enemy.h"

void DrawEnemy(EnemyManager * manager){
    for(int i = 0 ; i < manager->count ; i++){
        Entity * e = &manager->Enemys[i];
        if(e->StilAlive)
            DrawRectangle(e->Pos.x , e->Pos.y , e->Size.x ,e->Size.y , e->Color );
    }
}

void InitEnemyManager(EnemyManager * manager){
    manager->count = 0;
}

void DelletEnemy(EnemyManager* manager , unsigned int index){
    if(manager->count < 1){return ;} // Daca numarul de inamici este mai mic ca unu nu avem ce sa eliminam 

    //Luam ultimul inamic , il punem in locul inamicului eliminat si scadem numarul de inamici 
    Entity temp = manager->Enemys[manager->count - 1];
    manager->Enemys[index] = temp;
    manager->count--;

}
Vector2 GetEnemyPos(EnemyManager * manager , int index){
    return manager->Enemys[index].Pos;
}
void SpawnEnemy(EnemyManager * manager){
    printf("Sa spawnat un nou winamic \n");
    if(manager->count >= Enemy_Max_Count_Cap) return;
    Entity  enemy ;
    //Initializam cu valori de baza inamici la spown
    InitEnemy(&enemy);

    // Trebuie sa generam numere random pentru locul unde se spawnwaza inamici , dimensiunea lor etc
    static std::mt19937 generator(time(NULL));
    std::uniform_int_distribution<int> dis(Enemy_Min_Size , Enemy_Max_Size);
    std::uniform_int_distribution<int> dis_x(-400 ,WindowLenght + 400);
    std::uniform_int_distribution<int> dis_y( -400 ,WindowHeight + 400);   
    std::uniform_int_distribution<int> dis_dir( 1 , 2); // Acesta ne va genera directia stanga sau dreapta    
    Vector2 Pos = {(float)dis_x(generator) , (float)dis_y(generator)};
    if (Pos.x > 0 && Pos.x < WindowLenght){
        int dir = dis_dir(generator);
        if(dir == 1){Pos.x = (WindowLenght - Pos.x) - 400;}
        if(dir == 2){Pos.x = (WindowLenght - Pos.x) + Pos.x + 400;}
    }
    if (Pos.y > 0 && Pos.y < WindowHeight){
        int dir = dis_dir(generator);
        if(dir == 1){Pos.y = (WindowHeight - Pos.y) - 400;}
        if(dir == 2){Pos.y = (WindowHeight - Pos.y) + Pos.y+ 400;}
    }
    int Size = dis(generator);

    enemy.StilAlive = true;
    enemy.Size = {(float)Size , (float)Size};
    enemy.Pos = Pos;

    enemy.Damage = Size  * 0.6;
    enemy.HP = Size ;
    enemy.Speed = Enemy_Speed_Constant / Size;
    enemy.Speed = fmaxf(15.0f , fminf(enemy.Speed , Enemy_Max_Speed_Cap));

    manager->Enemys[manager->count] = enemy;
    manager->count++;
}

void UpdateEnemy(EnemyManager * manager , Vector2 Player_Pos){
    if(manager->count == 0) return;
    float dt = GetFrameTime();

    Entity * guy = nullptr;
    for(int i = 0 ; i < manager->count; i++){
        guy = &manager->Enemys[i];
        Vector2 Target = {Player_Pos.x  - guy->Size.x / 2 ,Player_Pos.y - guy->Size.y / 2}  ; //Temporar facem asta , va trebui sa schimb mai tarziu ca sa verific coliziunile 
        //========LIFE===========
        if(guy->HP <= 0){
            DelletEnemy(manager , i);
            i--;
            continue;
        }


        //============MoveMent==============

        //Calculam directia in care vrem sa ne indreptam 
        float distance = Vector2Distance(guy->Pos , Target);
        
        
        if (distance < 2.0f) {
            guy->Pos= Target  ; //Temporar facem asta , va trebui sa schimb mai tarziu ca sa verific coliziunile 
            continue;
        }
        else{
            Vector2 Directie = Vector2Subtract(Target , guy->Pos);
            Directie = Vector2Normalize(Directie);

            Vector2 velocity = Vector2Scale(Directie, guy->Speed * dt);
            guy->Pos = Vector2Add(guy->Pos , velocity);
        }
    }


}


void PrintEnemyInfo(EnemyManager * manager){
    printf("Exista %d inamici \n" , manager->count);
    for(int i = 0 ; i < manager->count ; i++){
        Entity  e= manager->Enemys[i];
        printf("Entity [%d] \nPos : x: %f y:%f \n" , i , e.Pos.x , e.Pos.y);
    }

}


void InitEnemy(Entity * enemy){
    //Setam entitatea ca fiind o entitate de tip player 
    enemy->type = EntityType::ENTITY_ENEMY;
    enemy->Color = _Enemy_Color;
    enemy->Pos = {WindowLenght / 2 , WindowHeight / 2};
    enemy->HP = 100;
    enemy->Damage = 15;
    enemy->Speed = 400;
    enemy->Size = {40.0f , 40.0f};
    enemy->StilAlive = true;
}
