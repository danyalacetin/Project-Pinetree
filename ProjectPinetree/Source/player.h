#ifndef __PLAYER_H__
#define __PLAYER_H__

// Forward Declarations
#include "entity.h"

class Player : public Entity
{
	// Member Methods
public:
	Player();
	~Player();

protected:

private:
	Player(const Player& player);
	Player& operator=(const Player& player);

	// Member Data
public:

protected:

};

#endif // !__PLAYER_H__
