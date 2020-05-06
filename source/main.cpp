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
#include <array>
#include <utility>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/array.hpp>
#include <boost/graph/named_function_params.hpp>

// Define datatypes, listS is a selector for the container used to represent the edge list for each
// of the vertices. vecS is the selector for the conatainer used to represent the vertex list
// of the graph.
typedef boost::property<boost::edge_weight_t, int> EdgeWeightProperty;
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::bidirectionalS, boost::no_property, EdgeWeightProperty> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor vDescriptor;

// Global Enum
enum {reno, sf, slc, sea, lv, SIZE};


// Prototypes
void addEdge(std::string city1, std::string city2, int miles, Graph& graphite);
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
	std::vector<std::string> cities = {"Reno", "San_Francisco", "Salt_Lake_City", "Seattle", "Las_Vegas"};
	int miles;

	// Open up the file
	std::fstream inFile;
	inFile.open("mileInput.txt", std::ios::in);
	if (!inFile)
	{
		std::cout << "\nError Opening File.\n\n";
	}

	
	// Instantiate a Graph object named graphite
	Graph graphite(5);


	// Read in cities and miles and create edges
	while (inFile >> city1)
	{
		inFile >> city2;
		inFile >> miles;
		addEdge(city1, city2, miles, graphite);
	}


	boost::array<int, 5> predecessors;

	boost::dijkstra_shortest_paths(graphite, reno, boost::predecessor_map(predecessors.begin()));	






	

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          
DESCRIPTION:       
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
void addEdge(std::string city1, std::string city2, int miles, Graph& graphite)
{
	// std::string Reno, San_Francisco, Salt_Lake_City, Seattle, Las_Vegas;

	if ((city1 == "Reno") && (city2 == "San_Francisco"))
	{
		// Add weight edges to graphite
		// integers located in each line are the distances between the cities
		boost::add_edge(reno, sf, miles, graphite);
	}

	else if ((city1 == "Reno") && (city2 == "Salt_Lake_City"))
	{
		boost::add_edge(reno, slc, miles, graphite);
	}

	else if ((city1 == "Reno") && (city2 == "Seattle"))
	{
		boost::add_edge(reno, sea, miles, graphite);
	}

	else if ((city1 == "Reno") && (city2 == "Las_Vegas"))
	{
		boost::add_edge(reno, lv, miles, graphite);
	}

	else if ((city1 == "San_Francisco") && (city2 == "Seattle"))
	{
		boost::add_edge(sf, sea, miles, graphite);
	}

	else if ((city1 == "San_Francisco") && (city2 == "Las_Vegas"))
	{
		boost::add_edge(sf, lv, miles, graphite);
	}

	else if ((city1 == "San_Francisco") && (city2 == "Seattle"))
	{
		boost::add_edge(slc, sea, miles, graphite);
	}

	else if ((city1 == "Salt_Lake_City") && (city2 == "Las_Vegas"))
	{
		boost::add_edge(slc, lv, miles, graphite);
	}

	else if ((city1 == "Salt_Lake_City") && (city2 == "Seattle"))
	{
		boost::add_edge(slc, sea, miles, graphite);
	}

	else
	{
		std::cout << std::endl;
	}
	
}