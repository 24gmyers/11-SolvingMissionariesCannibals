#pragma once
#include <iostream>
#include <string>
#include <vector>

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
            vector<T> answer;
            T curr = source;
            vector<T> open;
            vector<T> closed;
            int parents[size];
            for (int i = 0; i < size; i++){
                parents[i] = -1;
            }
            
            open.push_back(source);
            while (!open.empty()){ //while open has items
                curr = open.front(); // curr = open.front()
                open.erase(open.begin()); //open.pop()
                closed.push_back(curr); //mark curr as visited
                for (int i = 0; i < size; i++){ //for all children of curr
                    if (graph[getVertexPos(curr)][i] == 1){ // children
                        if (!inVector(closed, dictionary[i])){
                            if (open.front() != dictionary[i]){
                                open.push_back(dictionary[i]);
                            }
                            if (parents[i] == -1){
                                parents[i] = getVertexPos(curr);
                            }
                        }
                        // for (int j = 0; j < closed.size(); j++){
                        //     if (closed[j] == dictionary[i]){
                        //         break;
                        //     } else {
                        //         if (open.front() != dictionary[i]){
                        //             open.push_back(dictionary[i]);
                        //         }
                        //         if (parents[i] == -1){
                        //             parents[i] = getVertexPos(curr);
                        //             break;
                        // }
                        //     }
                        // }
                    }
                }
                if (parents[getVertexPos(target)] != -1){
                    break;
                }
                // for (int i = 0; i < open.size(); i++){
                //     for (int j = 0; j < closed.size(); j++){
                //         if (open[i] == closed[j]){
                //             open.erase(open.begin() + i - 1);
                //         }    
                //     }
                // }
                
            }

            curr = target;

            while (curr != source){
                answer.push_back(curr);
                curr = dictionary[parents[getVertexPos(curr)]];
            }
            vector<T> solution;
            solution.push_back(source);
            for (int i = answer.size() - 1; i >= 0; i--){
                solution.push_back(answer[i]);
            }
            
            return solution;
        }
        bool inVector(vector<T> vec, T t){
            for (int i = 0; i < vec.size(); i++){
                if (vec[i] == t){
                    return true;
                }
            }
            return false;
        }
        friend ostream& operator<< (ostream & out, Graph &g) {
            
            out << "Vertecies: ";
            for (int i = 0; i < g.siz(); i++){
                out << g.dictionary[i];
                out << " ";
            }
            out << endl << "Edges: ";
            for (int i = 0; i < g.siz(); i++){
                out << endl;
                for (int e = 0; e < g.siz(); e++){
                    if (g.graph[e][i] != 1 && g.graph[e][i] != 0){
                        g.graph[e][i] = 0;
                    }
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
        int siz(){
            // return graph.size();
            return size;
        }
        // resize(size){

        // }
};