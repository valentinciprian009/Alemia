#pragma once
#include "SegmentedContainer.h"
#include "Point.h"

	class IDrawable //interface class
	{
	public:
		virtual void Print(Point &p) = 0;
		virtual void Draw(SegmentedContainer &c)=0;
	};

