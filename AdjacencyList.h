//
// Created by kacyw on 11/7/2023.
//

#ifndef PROJECT2_ADJACENCYLIST_H
#define PROJECT2_ADJACENCYLIST_H
#include <vector>
#include <iostream>
#include <map>
#include <iterator>
#include <iomanip>
using namespace std;


class AdjacencyList {
    private:
    int vertex = 0;

    //string hold the website name, the pairs hold who is pointing to it with the name of the vertex and the outdegree of it under one.
    map<string, vector<pair<string, float>>> graph; //from Amon's lecture slides
    map<string, vector<pair<string, float>>>::iterator it;

    //used these to store information about the graph - now that I realize it, I should have used nodes to hold more info,
    //or combine using a pair of ints, one of them being the outdegree and one the placement.
    map<string, int> outdegree;
    map<string, int> placement;

    //no need for them to be public, so I put them to be private
    bool find_vertex(string name);
    void find_out_degree();
    void addVertex(string name);

    public:
    void PageRank(int n);
    void addedge(string point_a, string point_b);

};


#endif //PROJECT2_ADJACENCYLIST_H
