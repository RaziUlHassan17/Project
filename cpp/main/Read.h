#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

// Simple structure to store coordinates
struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

class MazeSolver {
private:
    static const int MAX_SIZE = 200;  // Maximum maze size
    
    char maze[MAX_SIZE][MAX_SIZE];    // 2D array to store maze
    bool visited[MAX_SIZE][MAX_SIZE]; // Track visited cells
    Point parent[MAX_SIZE][MAX_SIZE]; // For path reconstruction
    
    int rows, cols;                   // Maze dimensions
    Point start, end;                 // Start and end positions
    vector<Point> solutionPath;       // Store the solution path
    
    // Direction vectors for movement (up, right, down, left)
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    // Helper functions
    bool isValid(int x, int y);
    void findStartAndEnd();
    bool solveBFS();
    void reconstructPath();

public:
    MazeSolver();
    bool loadMaze(const string& filename);
    bool solve();
    void printOriginalMaze();
    void printSolutionMaze();
    void reset();
};