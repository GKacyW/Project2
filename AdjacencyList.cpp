//
// Created by kacyw on 11/7/2023.
//

#include "AdjacencyList.h"


void AdjacencyList::PageRank(int n){
    find_out_degree(); //finds the out-degree

    vector<double> matrix; // creates a 2d matrix for multiplication

    for(int i = 0; i < vertex; i++ ) // adds the value of 1/vertex for each vertex
        matrix.push_back(1.0/vertex);

    int count = 1;

    while(count < n){
        vector<double> temp;
        for(it = graph.begin(); it != graph.end(); it ++){

            double number = 0.0;

            for(int j = 0; j < it -> second.size(); j++){

                //matrix[placement.at.... is used to find what number it is supposed to be multiplying
                //since it's not an actual matrix, I need to know what is the placement of the vertex to multiply the correct numbers.

                number += it -> second[j].second * matrix[placement.at(it->second[j].first)];

            }

            temp.push_back(number);

        }

        for(int i = 0; i < vertex; i++) //copy vertex
            matrix[i] = temp[i];

        count ++;
    }

    count = 0;
    for(it = graph.begin(); it != graph.end(); it ++){
        cout << it -> first << " " << fixed << setprecision(2) << matrix[count] << endl; //print
        count ++;
    }


}

void AdjacencyList::addVertex(string name) {

    //creates a vertex in the graph and then adds it to the out-degree
    vector<pair<string, float>> Vector;
    graph.insert({name, Vector});
    outdegree.insert({name, 0});

    vertex++;

}
void AdjacencyList::addedge(string point_a, string point_b){

    //adds the vertex if it's not in the graph
    if(!find_vertex(point_a)) {
        addVertex(point_a);
    }
    if(!find_vertex(point_b)) {
        addVertex(point_b);
    }

    //creates in edge
    graph[point_b].push_back(make_pair(point_a, 0));
    outdegree.find(point_a) -> second += 1;
}

bool AdjacencyList::find_vertex(string name) {
    //to find if a vertex is in the graph
    if( graph.find(name) != graph.end()){
        return true;
    }
     return false;
}

void AdjacencyList::find_out_degree() {
    //placing the outdegree in the original graph

    for(it = graph.begin(); it != graph.end(); it ++){

        for(int j = 0; j < it -> second.size(); j++){

            string name = it -> second[j].first;
            it -> second[j].second = (1.0/outdegree.at(name));


        }

    }

    //this is to find the order of the vertex's in the ordered map
    int count = 0;
    for(it = graph.begin(); it != graph.end(); it ++){
        placement.insert({it -> first, count});
        count ++;
    }

}

