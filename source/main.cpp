/* -----------------------------------------------------------------------------
FILE NAME: main.cpp
DESCRIPTION: main driver
USAGE: ./output
COMPILER: GNU g++ compiler on Linux
NOTES: 

MODIFICATION HISTORY:
Author             	Date               Version
---------------    	----------         --------------
Conner Fissell
NJ Pelpinosas     	4/27/2020          1.0  Original version
----------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#define VERTEX_AMOUNT 5
#define BIG_NUMBER 100000000

std::string cities[5] = {"Reno","San Francisco","Salt Lake City","Seattle","Las Vegas"};

int TSP( int graph[][VERTEX_AMOUNT], int start );

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main(void)
{
	int start = 0;
	/* Create adjacency_matrix */
	int adjacency_matrix[][VERTEX_AMOUNT] = { { 0, 218, 518, 704, 439 },
	                                          { 218, 0, BIG_NUMBER, 808, 569},
	                                          { 518, BIG_NUMBER, 0, 830, 421 },
	                                          { 704, 808, 830, 0, BIG_NUMBER },
	                                          { 439, 569, 421, BIG_NUMBER, 0 } };
	
	int the_chosen_one = TSP( adjacency_matrix, start );
	std::cout << the_chosen_one << " miles travelled" << std::endl;
    std::cout << the_chosen_one / 40 << " gallons used" << std::endl;
	
// 	std::string city1, city2;
// 	int miles;
// 	int cityIndex = 0;
// // 	/* Open up the file */
// 	std::fstream inFile;
// 	inFile.open("mileInput.txt", std::ios::in);
// 	if (!inFile)
// 	{
// 		std::cout << "\nError Opening File.\n\n";
// 	}
// 	/* Open up the file - end */
// 
// 	Read in cities and miles into vectors and create edges
// 	while (inFile >> city1)
// 	{
// 		inFile >> city2;
// 		inFile >> miles;
// 		addEdge(city1, city2, miles, graphite);
// 	}
	
	return 0;
}

int TSP( int graph[][VERTEX_AMOUNT], int start )
{
	std::string path[VERTEX_AMOUNT];
	std::string path_best[VERTEX_AMOUNT];
	std::vector<int> vertex;
	
	/* store vertexes except for the
	 *first one, which represents Reno */
	for( int n = 1; n != VERTEX_AMOUNT; n++ )
	{
		vertex.push_back(n);
	}
	
	int minimum_path = BIG_NUMBER;
	
	std::cout << "Paths: " << std::endl;
	
	do
	{
		/* store the amount of miles travelled */
		int miles = 0; // start off at Reno
		
		// current path weight compute
		// check to see if this works later
		int k = start;
		
		for( long unsigned int n = 0; n < vertex.size(); n++ )
		{
			miles += graph[k][vertex[n]];
			k = vertex[n];
			path[n] = cities[k];
		}
		
		miles += graph[k][start];
		minimum_path = std::min(minimum_path, miles);
		
		if( miles < BIG_NUMBER )
		{
			std::cout << "Reno -> ";
			
			for ( int n = 0; n < 4; n++ )
			{
				std::cout << path[n] << " -> ";
			}
			
			std::cout << "Reno";
			
			std::cout << ": " << miles << " miles" << std::endl;
			
			if (miles == minimum_path)
			{
				
				for (int i = 0; i < 4; i++)
				{
					path_best[i] = path[i];
				}
				
			}
		}
		
	} while( std::next_permutation( vertex.begin(), vertex.end() ) ); // check every possible combination
	
	std::cout << std::endl;
	
	std::cout << "Shortest Path = Reno -> ";
    for (int n = 0; n < 4; n++)
	{
		std::cout << path_best[n] << " -> ";
	}
	std::cout << "Reno" << std::endl;
	
	/* return minimum path */
    return minimum_path;
}
