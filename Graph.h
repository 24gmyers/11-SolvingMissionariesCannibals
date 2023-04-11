#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Spath.h"

using namespace std;



template <typename T>
class Graph{
    public:
        Graph(){
            size = 0;
            // dictionary.resize(20);
            // graph.resize(20);
            // for (int i = 0; i < graph.size()-1; i++){
            //     graph[i].resize(20);
            // }
            
            // graph[0][0] = 0;
        }
        // ~Graph(){
        //     cout << "stop";
        //     for (int i = graph.size()-1; i >= 0; i--){
        //         graph[i].~vector();
        //     }
        //     graph.~vector();
        //     dictionary.~vector();
            
        //     return;
        // }
        void addVertex(T vertex){
            // for (int i = 0; i < dictionary.size(); i++){
            //     if (dictionary)
            //     {
            //         /* code */
            //     }
                
            // }
            dictionary[size] = vertex;
            

            // dictionary.push_back(vertex);
            // graph.push_back(vector<int>());
            for (int i = 0; i < size; i++)
            {
                // graph[i].push_back(0);
                graph[size][i] = 0;
                graph[i][size] = 0;
            }
            size += 1;
            
            // dictionary.resize(dictionary.size()+1,vertex);
            // graph.resize(graph.size()+1, vector<int>());
            // graph[siz()-1].resize(graph.size()+1, 0);
            // graph[siz()][siz()] = 0;
            // graph[0][size()] = dictionary.size();
            // graph[size()][0] = dictionary.size();
        }
        void addEdge(T source, T target){
            // int sourceIndex;
            // int targetIndex;
            // for (int i = 0; i < size(); i++){
            //     if (dictionary[i] == source){
            //         sourceIndex = i;
            //         i = size();
            //     }   
            // }
            // for (int i = 0; i < size(); i++){
            //     if (dictionary[i] == target){
            //         targetIndex = i;
            //         i = size();
            //     }   
            // }
            graph[getVertexPos(source)][getVertexPos(target)]++;
            adj[source] += target;
            // graph[getVertexPos(target)][getVertexPos(source)]++;
        }
        int getVertexPos(T vertex){
            for (int i = 0; i < siz(); i++){
                if(dictionary[i] == vertex){
                    return i;
                }
            }
            return -1;
        }
        int getNumVertices(){
            return size;
        }


        vector<T> getPath(T source, T target){
            // vector<T> answer;
            // T curr = source;
            // bool visited[size];

            // while (curr != target){
            //     answer.push_back(curr);
            //     visited[getVertexPos(curr)] = true;
            //     for (int i = 0; i < size; i++){
            //         if(graph[getVertexPos(curr)][i] == 1 && !visited[i]){
            //             curr = dictionary[i];
            //             break;
            //         }
            //     }
            // }
            
            // answer.push_back(target);
            // return answer;


            
            Spath<T> ans;
            return ans.printShortestDistance(adj, source, target, siz());
        };
        friend ostream& operator<< (ostream & out, Graph &g) {
            out << "Vertecies: ";
            for (int i = 0; i < g.siz() - 1; i++){
                out << g.dictionary[i];
                out << " ";
            }
            out << endl << "Edges: ";
            for (int i = 0; i < g.siz() - 1; i++){
                out << endl;
                for (int e = 0; e < g.siz() - 1; e++){
                    out << g.graph[e][i];
                    out << " ";
                }
            }
            return out;
        }
        bool isEdge(T source, T target){
            return graph[getVertexPos(source)][getVertexPos(target)] > 0;
        }
    private:
        // vector<vector<int>> graph;
        // vector<T> dictionary;
        int graph[20][20];
        int size;
        T dictionary[20];
        // array of vectors is used to store the graph
        // in the form of an adjacency list
        vector<int> adj[20];
        /*const int GRAPH_SIZE = 20;
int graph[GRAPH_SIZE][GRAPH_SIZE];
int size;

T dictionary[20];

int siz(){
    return GRAPH_SIZE; //Return the constant holding the size of the array.
}*/
        int siz(){
            // return graph.size();
            return size;
        }
        // resize(size){

        // }
};