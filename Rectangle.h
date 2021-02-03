#ifndef _RECTANGLE
#define _RECTANGLE

#include <string>
#include "Shape.h"

using namespace std;

class Rectangle : public Shape {
private:
	double dblBase, dblHeight;
public:
	Rectangle(double dblBase, double dblHeight) { // parameterized constructor
		this->dblBase = dblBase;
		this->dblHeight = dblHeight;
	}
	double GetArea() {
		if (IsValidShape(dblBase, dblHeight, 1))
			return dblBase * dblHeight;
		return 0;
	}
	string GetInfo() { // override base class implemenation
		return "\nObject Type: Rectangle\nArea: " + to_string(GetArea());
	}
};
#endif
