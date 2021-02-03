#pragma once
#include "MouseHandler.h"
#include "Entity.h"
#define MOUSE_CLICK 0
#define MOUSE_MOVE 1
#define MOUSE_DOUBLE_CLICK 2

class InputProcesser : public Entity
{
	MouseHandler& localMouseHandler;
public:
	InputProcesser() = default;
	InputProcesser(const InputProcesser&) = delete;
	InputProcesser& operator=(const InputProcesser&) = delete;
	~InputProcesser() 
	{
		localMouseHandler.releaseInstance();
	}
	virtual void onMouseClick() = 0;
	virtual void onClickOutOfRange() = 0;
	void processMouseInput()
	{
		int result = localMouseHandler.getProcessedInput();
		switch (result)
		{
		case MOUSE_CLICK:
		{
			if (isMouseInRange())
				onMouseClick();
			else
				onClickOutOfRange();
			break;
		}
		case MOUSE_MOVED:
		{
			break;
		}
		case MOUSE_DOUBLE_CLICK:
		{
			break;
		}
		default:
		{
			break;
		}
		}
			
	}

	bool isMouseInRange()
	{
		int mousePosX = localMouseHandler.getPosX();
		int mousePosY = localMouseHandler.getPosY();
		if (mousePosX == getX() && mousePosY==getY())
			return true;
	}
};