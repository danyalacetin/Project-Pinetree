#ifndef __OBJECTPOOL_H__

#define __OBJECTPOOL_H__

// Local includes
#include "../sprite.h"

// Library includes
#include <cassert>

/// Type parameter must have members:
/// void Initialise(Sprite*);
/// bool IsDead();
template<typename T>
class ObjectPool
{
	// Member methods
public:
	ObjectPool()
	: m_pCurrentIndex(0)
	, m_pSprite(0)
	, m_iSize(0)
	, m_pObjectArray(0)
	{

	}

	~ObjectPool()
	{
		delete[] m_pObjectArray;
		m_pObjectArray = 0;

		m_pCurrentIndex = 0;

		m_pSprite = 0;
	}

	bool Initialise(Sprite* pSprite, int iSize)
	{
		assert(pSprite);
		m_pSprite = pSprite;

		m_iSize = iSize;
		m_pObjectArray = new T[m_iSize];
		m_pCurrentIndex = 0;

		return (true);
	}

	bool GetObj(T** pObject)
	{
		bool bHasObject = GetObj(pObject, m_pSprite);

		return (bHasObject);
	}

	bool GetObj(T** pObject, Sprite* pSprite)
	{
		bool bIsDead = false;
		bool bHasObject = true;
		int loopCounter = 0;

		while (!bIsDead && bHasObject)
		{
			*pObject = &m_pObjectArray[m_pCurrentIndex];
			bIsDead = (*pObject)->IsDead();

			if (loopCounter > m_iSize)
			{
				bHasObject = false;
				*pObject = 0;
			}
			else if (bIsDead)
			{
				(*pObject)->Initialise(pSprite);
			}
			else
			{
				IncrementCurrentIndex();
			}

			++loopCounter;
		}

		return bHasObject;
	}

private:
	void IncrementCurrentIndex()
	{
		m_pCurrentIndex = (m_pCurrentIndex + 1) % m_iSize;
	}

	// Member data:
protected:
	Sprite* m_pSprite;
	int m_pCurrentIndex;
	T* m_pObjectArray;

	int m_iSize;
};

template<>
class ObjectPool<Sprite>
{
	// Member methods
public:
	ObjectPool()
		: m_pCurrentIndex(0)
		, m_iSize(0)
		, m_pObjectArray(0)
	{

	}

	~ObjectPool()
	{
		delete[] m_pObjectArray;
		m_pObjectArray = 0;

		m_pCurrentIndex = 0;
	}

	bool Initialise(int iSize)
	{
		m_iSize = iSize;
		m_pObjectArray = new Sprite[m_iSize];
		m_pCurrentIndex = 0;

		return (true);
	}

	bool GetObj(Sprite** pObject)
	{
		bool bIsDead = false;
		bool bHasObject = true;
		int loopCounter = 0;

		while (!bIsDead && bHasObject)
		{
			*pObject = &m_pObjectArray[m_pCurrentIndex];
			//bIsDead = !(*pObject)->InUse();
			bIsDead = true;

			if (loopCounter > m_iSize)
			{
				bHasObject = false;
				*pObject = 0;
			}
			else if (!bIsDead)
			{
				IncrementCurrentIndex();
			}

			++loopCounter;
		}

		return bHasObject;
	}

private:
	void IncrementCurrentIndex()
	{
		m_pCurrentIndex = (m_pCurrentIndex + 1) % m_iSize;
	}

	// Member data:
protected:
	int m_pCurrentIndex;
	Sprite* m_pObjectArray;

	int m_iSize;
};

#endif // !__OBJECTPOOL_H__


