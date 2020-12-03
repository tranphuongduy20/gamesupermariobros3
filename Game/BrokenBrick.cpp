#include "BrokenBrick.h"
BrokenBrick::BrokenBrick(int id_state)
{
	tag = EntityType::BROKENBRICK;
	id_broken_state = id_state;
	if (this->id_broken_state == 1)
		SetState(STATE_BRICK_NORMAL);
	/*else if (this->id_brick_items == 2)
		SetState(STATE_COIN_NO_ROTATE);*/
	this->SetAnimationSet(CAnimationSets::GetInstance()->Get(12));
	//DebugOut(L"Gia tri cua state %d \n", id_broken_state);

}

void BrokenBrick::Update(ULONGLONG dt, vector<LPGAMEENTITY>* coObjects)
{
	//DebugOut(L"Gia tri cua state %d \n", id_broken_state);
	/*if (isDestroyed)
		DebugOut(L"dasdasdasdasda");*/

	for (int i = 0; i < listPiece.size(); i++)
	{
		listPiece[i]->Update(dt, coObjects);
	}

	if (tranformation && GetTickCount64() - timeTranformation < 10000 && timeTranformation != 0 && !hasTranformation)
	{
		//DebugOut(L"aaaaaaaaaaaaa");
		if (GetState() == STATE_BRICK_NORMAL)
			SetState(STATE_COIN_NO_ROTATE);
		else if (GetState() == STATE_COIN_ROTATE)
			SetState(STATE_BRICK_NORMAL);
		hasTranformation = true;
	}
	if (GetTickCount64() - timeTranformation > 10000 && timeTranformation != 0)
	{

		tranformation = false;
		timeTranformation = 0;
		if (GetState() == STATE_BRICK_NORMAL)
			SetState(STATE_COIN_NO_ROTATE);
		else if (GetState() == STATE_COIN_NO_ROTATE)
			SetState(STATE_BRICK_NORMAL);
	}
}

void BrokenBrick::Render()
{
	RenderBoundingBox();
	if (!isDestroyed)
		animationSet->at(0)->Render(nx, x, y);
	//DebugOut(L"Gia tri cua state %d \n", state);
	for (LPGAMEENTITY piece : listPiece)
	{
		piece->Render();
	}
}
void BrokenBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (isDestroyed)
		return;
	l = x;
	t = y;
	r = x + 16;
	b = y + 16;
}
void BrokenBrick::SetState(int State)
{
	Entity::SetState(State);
	switch (State)
	{
	case STATE_BRICK_NORMAL:
		break;
	case STATE_COIN_NO_ROTATE:
		break;
	case STATE_COIN_ROTATE:
		break;
	case STATE_DESTROYED:
		//isDestroyed = true;
		EffectBrick* topLeftPiece = new EffectBrick({ x - 1, y - 2 }, -1, 2);
		EffectBrick* topRightPiece = new EffectBrick({ x + 9, y - 2 }, 1, 2);
		EffectBrick* bottomLeftPiece = new EffectBrick({ x - 1, y + 8 }, -1);
		EffectBrick* bottomRightPiece = new EffectBrick({ x + 9, y + 8 }, 1);
		listPiece = { topLeftPiece, topRightPiece, bottomLeftPiece, bottomRightPiece };
		break;


	}
	/*if (State == STATE_BRICK_NORMAL)
	{

	}
	else if (State == STATE_COIN_NO_ROTATE)
	{

	}*/

}
