#include "MouseManager.h"

MouseManager::MouseManager()
{
	//keys = new bool[256];
	for(int i = 0; i < 256; i++)
	{
		keys[i] = false;
	}
}

MouseManager::~MouseManager()
{
	//delete[] keys;
}