// COMP710 GP 2D Framework 2019
#ifndef __STATE_H__
#define __STATE_H__


class BackBuffer;

class State
{
public:
	//Member Methods:
	State();
	virtual ~State() = 0;

	virtual bool Initialise();
	virtual void Process(float deltaTime);
	virtual void Draw(BackBuffer& backBuffer);

	virtual void InitialiseControls();

protected:

private:

	//Member Data:
public:

protected:

private:

};

#endif // __GAMESTATE_H__


