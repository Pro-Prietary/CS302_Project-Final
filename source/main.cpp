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
#include <boost/graph/adjacency_list.hpp>

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */

int main(void)
{
	
	int Reno = 0;
	int San_Francisco = 1;
	int Salt_Lake_City = 2;
	int Seattle = 3;
	int Las_Vegas = 4;
	int SIZE_OF_ENUM = 5;
	
	// Define datatypes
	typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
	typedef boost::adjacency_list<boost::listS, boost::vecS, boost::bidirectionalS, boost::no_property, EdgeWeightProperty> Graph;
	
	// Instantiate a Graph object named graphite
	Graph graphite(5);
	
	// Add weight edges to graphite
	// integers located in each line are the distances between the cities
	boost::add_edge( Reno, San_Francisco, 218, graphite );
	boost::add_edge( Reno, Salt_Lake_City, 518, graphite );
	boost::add_edge( Reno, Seattle, 704, graphite );
	boost::add_edge( Reno, Las_Vegas, 439, graphite );
	boost::add_edge( San_Francisco, Seattle, 808, graphite );
	boost::add_edge( San_Francisco, Las_Vegas, 569, graphite );
	boost::add_edge( Salt_Lake_City, Seattle, 830, graphite );
	boost::add_edge( Salt_Lake_City, Las_Vegas, 421, graphite );
	
	//boost::dijkstra_shortest_paths( graphite, kkkkkkkk) // eh, i'll commit and get to it laater
	
	
	return 0;
}
