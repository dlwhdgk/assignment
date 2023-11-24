#pragma once
#include <iostream>
#include "Shape.h"

class Line : public Shape {
protected:
	virtual void draw();
};
