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
#ifndef __EDGE_H__
#define __EDGE_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/graph/adjacency_list.hpp>

class Edge
{
public:
    int miles;
    std::string city1;
    std::string city2;
};

#endif