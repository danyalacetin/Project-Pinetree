// COMP710 GP 2D Framework 2019
#ifndef __ENTITY_H__
#define __ENTITY_H__

// Forward Declarations:
class BackBuffer;
class Sprite;

struct Vector2f;

class Entity
{
	//Member Methods:
public:
	Entity();
	~Entity();

	bool Initialise(Sprite* sprite);

	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void SetDead(bool dead);
	bool IsDead() const;

	bool IsCollidingWith(Entity& e);

	void SetPosition(float x, float y);
	void SetPosition(Vector2f v2fPosition);
	void SetPositionX(float x);
	void SetPositionY(float y);

	Vector2f GetPositionV2f() const;
	float GetPositionX() const;
	float GetPositionY() const;

	Vector2f GetVelocity() const;

	float GetHorizontalVelocity() const;
	void SetHorizontalVelocity(float x); 

	float GetVerticalVelocity() const;
	void SetVerticalVelocity(float y);

protected:

private:
	Entity(const Entity& entity);
	Entity& operator=(const Entity& entity);

	//Member Data:
public:

protected:
	Sprite* m_pSprite;

	float m_x;
	float m_y;

	float m_velocityX;
	float m_velocityY;

	bool m_dead;

private:

};

#endif //__ENTITY_H__
