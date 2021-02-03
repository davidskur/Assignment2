#ifndef _SHAPE
#define _SHAPE

#include <string>

using namespace std;

// abstract base class
class Shape {
private:
	double dblDimension1, dblDimension2, dblDimension3;
public:
	virtual bool IsValidShape(double dblDimension1, double dblDimension2, double dblDimension3) { // check for impossible dimensions
		if (dblDimension1 <= 0 || dblDimension2 <= 0 || dblDimension3 <= 0)
			return false;
		return true;
	}
	virtual string GetInfo() {
		return "\nObject Type: Shape";
	}
};
#endif
