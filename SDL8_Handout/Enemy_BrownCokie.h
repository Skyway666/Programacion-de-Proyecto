


#include "Enemy.h"
class Enemy_BrownCokie : public Enemy
{
private:
	Animation fly;
    iPoint original_pos;
	Path movement;
public:

	Enemy_BrownCokie(int x, int y);
	void Move();
	
};

