#pragma once
#include <iostream>
using namespace std;

class Line : public Shape {
protected:
	virtual void draw();
};
