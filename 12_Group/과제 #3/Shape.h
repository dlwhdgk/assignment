#pragma once
#include <iostream>

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint();
};
