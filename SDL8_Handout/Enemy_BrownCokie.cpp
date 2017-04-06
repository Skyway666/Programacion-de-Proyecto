#include "Application.h"
#include "Enemy_BrownCokie.h"
#include "ModuleCollision.h"


Enemy_BrownCokie::Enemy_BrownCokie(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5,72,21,22});
	fly.speed = 0.2f;
     animation = &fly;


    movement.PushBack({ -1.0f, -0.5f }, 100);
	movement.PushBack({ -1.0f, 0.5f }, 80);
	movement.PushBack({ -1.0f, 1.0f }, 80);
	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

    original_pos.x = x;
	original_pos.y = y;
	
}

void Enemy_BrownCokie::Move()
{
 	position = original_pos + movement.GetCurrentPosition();
}