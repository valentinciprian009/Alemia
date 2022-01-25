#pragma once


class CObject
{protected:
	int x, y;
	char CH;
public:
	CObject(int row, int col);
	

	virtual ~CObject();
	friend class CGame;
};

