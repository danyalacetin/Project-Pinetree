// COMP710 GP 2D Framework 2019

// This include:
#include "entity.h"

// Local includes:
#include "SDL Render/sprite.h"
#include "SDL Render/backbuffer.h"
#include "Utilities/gameutils.h"

// Library includes:
#include <cassert>

Entity::Entity()
: m_pSprite(0)
, m_x(0.0f)
, m_y(0.0f)
, m_velocityX(0.0f)
, m_velocityY(0.0f)
, m_dead(false)
{

}

Entity::~Entity()
{

}

bool
Entity::Initialise(Sprite* sprite)
{
	assert(sprite);
	m_pSprite = sprite;

	return (true);
}

void 
Entity::Process(float deltaTime)
{
	m_x += m_velocityX * deltaTime;
	m_y += m_velocityY * deltaTime;
}

void 
Entity::Draw(BackBuffer& backBuffer)
{
	assert(m_pSprite);
	m_pSprite->SetX(static_cast<int>(m_x));
	m_pSprite->SetY(static_cast<int>(m_y));
	m_pSprite->Draw(backBuffer);
}

bool
Entity::IsCollidingWith(Entity& e)
{
	return (false);
}

void 
Entity::SetDead(bool dead)
{
	m_dead = dead;
}

bool
Entity::IsDead() const
{
	
	return (m_dead);
}

void
Entity::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

void
Entity::SetPosition(Vector2f v2fPosition)
{
	m_x = v2fPosition.x;
	m_y = v2fPosition.y;
}

void
Entity::SetPositionX(float x)
{
	m_x = x;
}

void
Entity::SetPositionY(float y)
{
	m_y = y;
}

Vector2f
Entity::GetPositionV2f() const
{
	Vector2f v2fPosition = Vector2f(m_x, m_y);
	return (v2fPosition);
}

float 
Entity::GetPositionX() const
{
	return (m_x);
}

float 
Entity::GetPositionY() const
{
	return (m_y);
}

Vector2f
Entity::GetVelocity() const
{
	Vector2f v2fVelocity = Vector2f(m_velocityX, m_velocityY);
	return (v2fVelocity);
}

void Entity::SetVelocity(Vector2f velocity)
{
	SetHorizontalVelocity(velocity.x);
	SetVerticalVelocity(velocity.y);
}

float 
Entity::GetHorizontalVelocity() const
{
	return (m_velocityX);
}

float 
Entity::GetVerticalVelocity() const
{
	return (m_velocityY);
}

void 
Entity::SetHorizontalVelocity(float x)
{
	m_velocityX = x;
}

void 
Entity::SetVerticalVelocity(float y)
{
	m_velocityY = y;
}
