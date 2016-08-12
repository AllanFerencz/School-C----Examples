/** lab6.cpp
 *
 * This program reads points from a file, then stores them in a map. It calculates the distance between each point.
 *    
 * @author	Julien Ouimet, Allan Ferencz
 *
 * @since	Nov 2014
 *
 */

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <fstream>
#include <map>

#include "CartesianPoint.h"
 
using namespace std;

int main()
{
	// TEMPORARILY HOLDS EACH CARTESIAN POINT
	CartesianPoint point; 
	// TEMPORARILY HOLDS THE NAME OF THE POINT
	string name;
	// MAP TO HOLD THE POINT NAME AND THE CARTESIAN POINT ITSELF
	map<string, CartesianPoint> pointMap;
	// ITERATOR TO TRAVERSE THE MAP
	map<string, CartesianPoint>::iterator mapIterator;
	// HOLDS THE DISTANCES CALCULATED
	double mapDistances = 0;
	double mapDistanceTotal = 0;
	double userDistance = 0;	
	// HOLDS CARTESIAN POINTS 
	CartesianPoint pointA;
	CartesianPoint pointB;	
	// HOLDS USER INPUT POINT
	string userInput;
		
	try
	{
		// OPEN THE INPUT FILE
		ifstream inFile;
		inFile.open("PointData.dat");
		
		// IF THE FILE CAN'T BE OPENED, SHOW ERROR MESSAGE
		if (inFile.fail()) 
		{
		  cerr << "Unable to open the data file for reading. Check if file exists." << endl;
		}
	
		// IF NO FILE ERRORS, CONTINUE
		else
		{		
			// INPUT FILE DATA INTO MAP	
			while (inFile >> name >> point) 
			{
				pointMap[name] = point;
			}
		    // IF THE FILE IS EMPTY
		}
		if (pointMap.size() == 0)
		{
			cerr << "The map is empty. Check that the file contains valid data in the correct format." << endl;	
		} 
		else
		{
			// ITERATE THROUGH MAP FIDING THE DISTANCE BETWEEN EACH POINT  
			for(mapIterator = pointMap.begin(); mapIterator != pointMap.end();)
			{
				pointA = mapIterator->second;
				mapIterator++;	
				
				// IF ON THE LAST POINT DON'T COMPARE IT TO THE BLANK LINE AFTER IT
				if(mapIterator != pointMap.end())
				{
					pointB = mapIterator->second;
								
					// FIND THE DISTANCE BETWEEN TWO SUCCESSIVE POINTS	    		
					mapDistances = pointA-pointB;
					mapDistanceTotal += mapDistances;
				}
			}  
		  
		  	cout << "The map contains " << pointMap.size() << " points for a total distance of " << mapDistanceTotal << "." << endl;
		  
			// LOOP UNTIL USER TYPES QUIT.
		  	while(userInput != "quit")
		  	{
		  		cout << "\n\nEnter the label of a point (type \"quit\" to end): ";
		  		cin >> userInput;
		  		
		  		// CHECK IF POINT ENTERED EXISTS
		  		if(pointMap.find(userInput) != pointMap.end())
		  		{
		  			pointA = pointMap[userInput];
		  			pointB = pointMap["AA"];
					  
					// FIND DISTANCE BETWEEN AA AND ENTERED POINT
					userDistance = pointA-pointB;
					
					// OUTPUT THE DISTANCE
					cout << "\n          The distance between AA (0, 0) and " << userInput << " " << pointMap[userInput] << " is " << userDistance << endl;
								
		  		}
		  		else
		  		{
		  			// IF THE POINT IS NOT IN THE MAP, DISPLAY ERROR
		  			if(userInput != "quit")
		  			{
						cerr << "\n          There is no point labelled \"" << userInput << "\" in the map." << endl;
					}
		  		}
		  	}
	 	 }
	}
	// CATCH ANY ERRORS
	catch(...)
	{
		cerr << "\n\nA run-time error occured." << endl;	
	}
	return 0;
};
