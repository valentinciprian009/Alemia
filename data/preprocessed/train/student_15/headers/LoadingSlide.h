#pragma once
#include "Slide.h"

class LoadingSlide : public Slide
{
private:
	int startTitle = 10;
	int rowTitle = 26;
	int colCenter = 73;
	int starDistance = 5;

private:
	void doLoadingBar();

public:
	LoadingSlide();
	void update();
	~LoadingSlide();
};
