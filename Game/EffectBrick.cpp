#include "EffectBrick.h"
EffectBrick::EffectBrick(D3DXVECTOR2 position, int nx, int deflectFactorY)
{
	x = position.x;
	y = position.y;
	vx = 0.07f * nx;
	vy = -0.16f * deflectFactorY;
	this->SetAnimationSet(CAnimationSets::GetInstance()->Get(19));
}

void EffectBrick::Update(ULONGLONG dt, vector<LPGAMEENTITY>* coObjects)
{
	Entity::Update(dt);

	vy += 0.0009f * dt;

	x += dx;
	y += dy;

	/*if (y > CGame::GetInstance()->GetCamPosY() + SCREEN_HEIGHT / 2)
		isFinishedUsing = true;*/
}

void EffectBrick::Render()
{
	//RenderBoundingBox();
	animationSet->at(0)->Render(nx, x, y);
}

void EffectBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = t = r = b = 0;
}
