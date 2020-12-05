#include "MonneyEffect.h"

MonneyEffect::MonneyEffect()
{
	this->SetAnimationSet(CAnimationSets::GetInstance()->Get(22));
}
void MonneyEffect::Update(DWORD dt, vector<LPGAMEENTITY>* coObjects)
{
	if (!isdone)
	{
		Entity::Update(dt);
		if (start_y == 0)
			start_y = y;
		vy = -0.1;
		if (start_y - y > 30)
			isdone = true;
		x += dx;
		y += dy;
	}
}

void MonneyEffect::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	/*left = x;
	top = y;
	right = x + 8;
	bottom = y + 8;*/
}

void MonneyEffect::Render()
{
	if (!isdone)
		animationSet->at(state)->Render(nx, x, y);
}

void MonneyEffect::SetState(int State)
{
	Entity::SetState(State);
	switch (State)
	{
	case MAKE_100:
		break;
	case MAKE_200:
		break;
	case MAKE_400:
		break;
	case MAKE_800:
		break;
	case MAKE_1000:
		break;
	case MAKE_2000:
		break;
	case MAKE_4000:
		break;
	case MAKE_8000:
		break;
	}
}
