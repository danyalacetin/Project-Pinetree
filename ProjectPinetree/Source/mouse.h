#ifndef __MOUSE_H__
#define __MOUSE_H__

// Local Includes
#include "Utilities/gameutils.h"

// Forward Declarations
class Sprite;
class BackBuffer;

class MousePointer
{
	// Member Methods
public:
	MousePointer();
	~MousePointer();

	bool Initialise(Sprite* pSprite);
	void Process(float fDeltaTime);
	void Draw(BackBuffer& backBuffer);

	void SetPosition(Vector2f v2fNewPosition);
	Vector2f GetPosition() const;

private:

	// Member Data
protected:
	Sprite* m_pSprite;
	Vector2f m_v2fPosition;
};

#endif // !__MOUSE_H__
