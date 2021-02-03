#include "CBucketHead.h"



CBucketHead::CBucketHead(int row, int col): CZombie(row,col)
{
	CH = CHR_BUCKETHEAD;
	damage = 5;
	HP = 50;
	speed = 5;
}


CBucketHead::~CBucketHead()
{
}
