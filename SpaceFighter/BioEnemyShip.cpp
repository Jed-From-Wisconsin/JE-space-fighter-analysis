
#include "BioEnemyShip.h"
#include "Level.h"


BioEnemyShip::BioEnemyShip()
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}


void BioEnemyShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float time = gameTime.GetTotalTime();

		float x = sin(time * Math::PI + GetIndex());
		float y = cos(time * Math::PI + GetIndex()); //Adding y-axis to fly in annyoing circular motion

		//Circle size
		x *= GetSpeed() * gameTime.GetElapsedTime() * 2.4f;
		y *= GetSpeed() * gameTime.GetElapsedTime() * 1.4;

		//Speed it moves down
		y += GetSpeed() * gameTime.GetElapsedTime() * 1.4; 

		TranslatePosition(x, y);

		if (!IsOnScreen()) Deactivate();
	}
	EnemyShip::Update(gameTime);
}


void BioEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
