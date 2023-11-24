#pragma once
#include <iostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape {
protected:
	virtual void draw();
};
