/*
Authors:
	-David Schreur
	-Cody Rockwell

Class: CIS227-6800
Assignment 2: Arrays and Command Line Arguments
Professor Joseph Carmon
Date: 2/3/21
*/

#include <iostream>
#include <vector>

#include "Triangle.h"
#include "Trapezoid.h"
#include "Rectangle.h"
#include "Hexahedron.h"
#include "Parameters.h"

using namespace std;

// function declaration
void DisplayWelcome();
double CheckInput(string strPrompt);

int main(int argc, char* argv[]) {

	CheckForCommandLineParameters(argc, argv);

	// sequence container of base object pointers.
	vector<Shape*> shapeContainer;

	// main program loop
	bool bRunAgain;
	do {
		bRunAgain = false;
		DisplayWelcome(); // for readability

		// get user input
		int intSelection = CheckInput("\nSelection: "); // possible data loss is acceptable here (double -> int)

		// decision logic
		switch (intSelection) {
        	case 0: // Arrays. This is begging to be cleaned up. Rushed work will do that :-/
        	{
           		bool bViewAgain;
            		string wordArray[12];
            		for (int i = 0; i < sizeof(wordArray)/sizeof(wordArray[0]); i++) {
                		cout << "\nEnter a string (" << (i+1) << " of 12): ";
                		cin >> wordArray[i];
            		}       
            		do {
                		bViewAgain = false;
                		int iIndexSelection;
                		cout << "\nSelect an index (1-12) to view that word in your array: ";
                		cin >> iIndexSelection;
                		for (int i = 0; i < sizeof(wordArray)/sizeof(wordArray[0]); i++) {
                    			if (i + 1 == iIndexSelection) {
                        			cout << "\nYour word: " << wordArray[i] << endl;
                    			}
                		}
                		// check for another run
		        	string strResponse;
		        	cout << "\nCheck array again? (y/n) ";
		        	cin >> strResponse;
		        	if (strResponse == "y" || strResponse == "yes") bViewAgain = true;
            		} while (bViewAgain);
            		break;
        	}
		case 1: // triangle
		{
			double dblSide1, dblSide2;
			cout << "\n--- Calculate a Hypotenuse ---" << endl;
			dblSide1 = CheckInput("\nEnter triangle side 1: ");
			dblSide2 = CheckInput("Enter triangle side 2: ");

			//Create a new triangle object and add it to the collection. 
			//Cool Feature Note: I could construct the object in place like so: shapeContainer.push_back(Triangle(dblSide1, dblSide2));
			Triangle* triangle = new Triangle(dblSide1, dblSide2);
			shapeContainer.push_back(triangle); // insert obj

			double dblHypotenuse = triangle->GetHypotenuse(); // need to use arrow operator because I'm dealing with pointers
			if (dblHypotenuse > 0)
				cout << "\nThe hypotenuse of the created right triangle is " << dblHypotenuse << endl;
			else
				cout << "\nSupplied dimensions do NOT a triangle make!";
			break;
		}
		case 2: // trapezoid
		{
			double dblBase1, dblBase2, dblHeight;
			cout << "\n--- Calculate Trapezoid Area---" << endl;
			dblBase1 = CheckInput("\nEnter base length: ");
			dblBase2 = CheckInput("Enter a parallel base length: ");
			dblHeight = CheckInput("Enter the trapezoid's height: ");

			// Create a new trapezoid object and add it to the collection
			Trapezoid* trapezoid = new Trapezoid(dblBase1, dblBase2, dblHeight);
			shapeContainer.push_back(trapezoid);

			double dblArea = trapezoid->GetArea();
			if (dblArea > 0)
				cout << "\nThe area of the created trapezoid is " << dblArea << endl;
			else
				cout << "\nSupplied dimensions cannot be used to make a trapezoid!" << endl;
			break;
		}
		case 3: // Regular rectangle
		{
			double dblLength, dblHeight;
			cout << "\n--- Calculate Rectangle Area ---" << endl;
			dblLength = CheckInput("\nEnter the shape's length: ");
			dblHeight = CheckInput("Enter the shape's height: ");

			// Create a new rectangle object and add it to the collection
			Rectangle* rectangle = new Rectangle(dblLength, dblHeight);
			shapeContainer.push_back(rectangle);

			double dblVolume = rectangle->GetArea();
			if (dblVolume > 0)
				cout << "\nThe area of the rectangle is " << dblVolume << endl;
			else
				cout << "\nSupplied dimensions cannot be used to make a rectangle!" << endl;
			break;
		}
		case 4: // Rectangular hexahedron (cuboid). Assuming he meant 'volume' in the requirements given that it's a 3D figure.
		{
			double dblLength, dblHeight, dblDepth;
			cout << "\n--- Calculate Rectangular Hexahedron Volume ---" << endl;
			dblLength = CheckInput("\nEnter the shape's length: ");
			dblHeight = CheckInput("Enter the shape's height: ");
			dblDepth = CheckInput("Enter the shape's depth: ");

			// Create a new hexahedron object and add it to the collection
			Hexahedron* hexahedron = new Hexahedron(dblLength, dblHeight, dblDepth);
			shapeContainer.push_back(hexahedron);

			double dblVolume = hexahedron->GetVolume();
			if (dblVolume > 0)
				cout << "\nThe volume of the hexahedron is " << dblVolume << endl;
			else
				cout << "\nSupplied dimensions cannot be used to make a hexahedron!" << endl;
			break;
		}
		case 5:
		{
			cout << "\n----------- Shapes -----------" << endl;
			cout << "\nShape Collection Size: " << shapeContainer.size() << endl;
			for (Shape* shape : shapeContainer) // also could use (auto element : shapeContainer)
				cout << shape->GetInfo() << endl; // polymorphic call to derived implementation
			break;
		}
		case 6:
			cout << "\nHave a nice day!";
			return 0; // could also #include <cstdlib> and call exit(0);

		default:
			cout << "\nUnknown input! Please try another selection.";
			break;
		} // end switch

		// check for another run
		string strResponse;
		cout << "\nRun program again? (y/n) ";
		cin >> strResponse;
		if (strResponse == "y" || strResponse == "yes") bRunAgain = true;

	} while (bRunAgain); // end do-while

	return 0; // end main
}
// functions
double CheckInput(string strPrompt) {
	string strInput;
	cout << strPrompt;
	cin >> strInput;
	return strtod(strInput.c_str(), NULL); // strtod doesn't throw exceptions
}
void DisplayWelcome() {
	cout << "\n|=======================|" << endl;
	cout << "|~~~~ Item Creator ~~~~~|" << endl;
	cout << "|=======================|" << endl;
	cout << "\nMake a selection:\n \n0) Array\n1) Triangle\n2) Trapezoid\n3) Rectangle\n4) Rectangular Hexahedron (Cuboid)\n5) Browse Collection\n6) Exit" << endl;
}
