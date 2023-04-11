You will use a graph search to solve the Missionaries Cannibals problem.

In this problem, three missionaries and three cannibals must cross a river using a boat which can carry at most two people, under the constraint that, for both banks, that the missionaries present on the bank cannot be outnumbered by cannibals. The boat cannot cross the river by itself with no people on board.

![Missionaries Cannibals Problem](https://github.com/24gmyers/11-SolvingMissionariesCannibals/blob/master/mc-search-space.png?raw=true "Missionaries Cannibals Problem")

Each of the vertices on the graph represents a snapshot of the game state.  There is a variable for the number of missionaries, cannibals, and a side that the boat is parked.

3, 3, true, means that there are three missionaries, three cannibals, and the boat is on the left. This is noted in the console as in the statement below (the water is the squiggly lines.

```MMM CCC B ~~~~~~~ ```

Suppose you have 2, 1 false.  It would be denoted in the console as

```MM C ~~~~~~~ B M CC  ```
 

The code has been created for you.  Your job is to create a path such that you navigate through the graph starting at the start state (3, 3, true) to the end state (0, 0, false); Then return the solution.

__Starter Code__

* [MissionariesCannibalsTester.cpp](https://weber.instructure.com/courses/564343/files/107306213/download?wrap=1)
* [GameState.h](https://weber.instructure.com/courses/564343/files/107306219/download?wrap=1)
* [MC.h](https://weber.instructure.com/courses/564343/files/107306220/download?wrap=1)

__Requirements__

Create a templated Graph class.  You may use an adjacency Matrix or an adjacency list started in the No Brainer.  The Graph class should have the following methods. 

If using one of the No-Brainers, the only thing you will need to do is the method in getPath() method in bold. The copy constructor and overload= operator are only necessary if you create any pointers as private variables.  

* Graph: Constructor to create an empty graph.
* void addVertex(Type vertex): Adds a vertex to the graph
* void addEdge(T source, T target): adds an edge from the source to the target.
* int getVertexPos(T  vertex): Helper method to allow you to find where the vertex is contained within the list of vertices
* int getNumVertices(): Returns the number of vertices contained in the graph
* __vector<T> getPath(T source, T target): returns all vertices in the shortest path from the source to the target (includes source and target)__
* ostream& operator << (ostream & out, Graph<T> g): used for debugging, displays a list of vertices and edges
* Add any private helper methods as necessary (recommended)

__Hints for getPath()__

The getPath method will return the shortest path from source to dest.  For the additional challenge, try using the Shortest Path First algorithm.  However, you are welcome to use any solution not limited to the following, depth-first search to traverse the graph to find the solution, breadth-first, or any other graph algorithm.

You will return a vector with the solution from the source to the destination.

IE: The source will be in position 1 the destination is in the last position of the solution, and each node in between
are the vertices it will travel to get to the destination. There will not be any other vertices in the list.

Given the test graph:

![Graph](https://github.com/24gmyers/11-SolvingMissionariesCannibals/blob/master/Graph-2.png?raw=true "Graph")

getPath(0, 5) should return the shortest path of

0 -> 1 -> 4 -> 5 __-OR-__ 0 -> 3 -> 6 -> 5