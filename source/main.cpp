/* -----------------------------------------------------------------------------
 * ut
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

// Global Variables
#define VERTEX_AMOUNT 5
#define BIG_NUMBER 10000
enum cities {Reno, San_Francisco, Salt_Lake_City, Seattle, Las_Vegas};
std::string cities[5] = {"Reno","San_Francisco","Salt_Lake_City","Seattle","Las_Vegas"};

// Prototypes
void addEdge(const std::string city1, const std::string city2, const int miles, int adjacency_matrix[][VERTEX_AMOUNT]);
int TSP(int graph[][VERTEX_AMOUNT], int start, std::fstream &outFile);

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int main(void)
{
	std::string city1, city2;
	std::string Reno, San_Francisco, Salt_Lake_City, Seattle, Las_Vegas;
	int miles;
	int start = 0;
	int milesPerGallon = 40;

	// Open up the file input operator
	std::fstream inFile;
	inFile.open("mileInput.txt", std::ios::in);
	if (!inFile)
	{
		std::cout << "\nError Opening File.\n\n";
		return 0;
	}

	// Open up file output operator
	std::fstream outFile;
	outFile.open("TSP_Results.txt", std::ios::out);

	
	/* Create adjacency_matrix */
	//int adjacency_matrix[][VERTEX_AMOUNT] = { { 0, 218, 518, 704, 439 },
	                                          //{ 218, 0, BIG_NUMBER, 808, 569},
	                                          //{ 518, BIG_NUMBER, 0, 830, 421 },
	                                          //{ 704, 808, 830, 0, BIG_NUMBER },
	                                          //{ 439, 569, 421, BIG_NUMBER, 0 } };

	int adjacency_matrix[VERTEX_AMOUNT][VERTEX_AMOUNT] = {0};
	adjacency_matrix[1][2] = BIG_NUMBER;
	adjacency_matrix[2][1] = BIG_NUMBER;
	adjacency_matrix[3][4] = BIG_NUMBER;
	adjacency_matrix[4][3] = BIG_NUMBER;

	// Read in cities and miles and create edges
	while (inFile >> city1)
	{
		inFile >> city2;
		inFile >> miles;
		addEdge(city1, city2, miles, adjacency_matrix);
	}

	// Go to TSP algorithm 
	int the_chosen_one = TSP(adjacency_matrix, start, outFile);

	// Output results to screen and file
	std::cout << the_chosen_one << " miles travelled during shortest route." << std::endl;
    std::cout << (the_chosen_one / milesPerGallon) << " gallons used during shortest route." << std::endl;
	outFile << the_chosen_one << " miles travelled during shortest route." << std::endl;
	outFile << (the_chosen_one / milesPerGallon) << " gallons used during shortest route." << std::endl; 

	// Close files
	inFile.close();
	outFile.close();
	
	

	

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          addEdge()
DESCRIPTION:       Creates edges and matrix
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void addEdge(const std::string city1, const std::string city2, const int miles, int adjacency_matrix[][VERTEX_AMOUNT])
{

	if ((city1 == cities[Reno]) && (city2 == cities[San_Francisco]))
	{
		adjacency_matrix[Reno][San_Francisco] = miles;
		adjacency_matrix[San_Francisco][Reno] = miles;
		
	}

	else if ((city1 == cities[Reno]) && (city2 == cities[Salt_Lake_City]))
	{
		adjacency_matrix[Reno][Salt_Lake_City] = miles;
		adjacency_matrix[Salt_Lake_City][Reno] = miles;
	}

	else if ((city1 == cities[Reno]) && (city2 == cities[Seattle]))
	{
		adjacency_matrix[Reno][Seattle] = miles;
		adjacency_matrix[Seattle][Reno] = miles;
	}

	else if ((city1 == cities[Reno]) && (city2 == cities[Las_Vegas]))
	{
		adjacency_matrix[Reno][Las_Vegas] = miles;
		adjacency_matrix[Las_Vegas][Reno] = miles;
	}

	else if ((city1 == cities[San_Francisco]) && (city2 == cities[Seattle]))
	{
		adjacency_matrix[San_Francisco][Seattle] = miles;
		adjacency_matrix[Seattle][San_Francisco] = miles;
	}
	
	else if ((city1 == cities[San_Francisco]) && (city2 == cities[Las_Vegas]))
	{
		adjacency_matrix[San_Francisco][Las_Vegas] = miles;
		adjacency_matrix[Las_Vegas][San_Francisco] = miles;
	}
	
	else if ((city1 == cities[Salt_Lake_City]) && (city2 == cities[Seattle]))
	{
		adjacency_matrix[Salt_Lake_City][Seattle] = miles;
		adjacency_matrix[Seattle][Salt_Lake_City] = miles;
	}

	else if ((city1 == cities[Salt_Lake_City]) && (city2 == cities[Las_Vegas]))
	{
		adjacency_matrix[Salt_Lake_City][Las_Vegas] = miles;
		adjacency_matrix[Las_Vegas][Salt_Lake_City] = miles;
	}

	else
	{
		std::cout << "Unable to Add edge" << std::endl;
	}

}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
int TSP(int graph[][VERTEX_AMOUNT], int start, std::fstream &outFile)
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
	outFile << "Paths: " << std::endl;

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
			outFile << "Reno -> ";
			
			for ( int n = 0; n < 4; n++ )
			{
				std::cout << path[n] << " -> ";
				outFile << path[n] << " -> ";
			}
			
			std::cout << "Reno";
			outFile << "Reno";
			
			std::cout << ": " << miles << " miles" << std::endl;
			outFile << ": " << miles << " miles" << std::endl; 
			
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
	outFile << std::endl;
	
	std::cout << "Shortest Path = Reno -> ";
	outFile << "Shortest Path = Reno -> ";
    for (int n = 0; n < 4; n++)
	{
		std::cout << path_best[n] << " -> ";
		outFile << path_best[n] << " -> ";
	}
	std::cout << "Reno" << std::endl;
	outFile << "Reno" << std::endl;
	


	/* return minimum path */
    return minimum_path;
}
