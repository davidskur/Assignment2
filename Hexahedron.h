#ifndef _HEXAHEDRON
#define _HEXAHEDRON

#include <string>
#include "Shape.h"

using namespace std;

class Hexahedron : public Shape {
private:
	double dblBase, dblHeight, dblDepth;
public:
	Hexahedron(double dblBase, double dblHeight, double dblDepth) { // parameterized constructor
		this->dblBase = dblBase;
		this->dblHeight = dblHeight;
		this->dblDepth = dblDepth;
	}
	double GetVolume() { // exposed public method to calculate volume
		if (IsValidShape(dblBase, dblHeight, dblDepth))
			return dblBase * dblHeight * dblDepth;
		return 0;
	}
	string GetInfo() { // override base class 
		return "\nObject Type: Hexahedron\nVolume: " + to_string(GetVolume());
	}
};
#endif
