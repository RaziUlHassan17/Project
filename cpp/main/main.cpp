#include "Read.h"

// Constructor - initialize everything to default values
MazeSolver::MazeSolver() {
    rows = 0;
    cols = 0;
    
    // Initialize start and end positions
    start = Point(0, 0);
    end = Point(0, 0);
    
    // Clear arrays
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            maze[i][j] = '#';
            visited[i][j] = false;
            parent[i][j] = Point(-1, -1);
        }
    }
}

// Load maze from file
bool MazeSolver::loadMaze(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Cannot open file " << filename << endl;
        return false;
    }
    
    string line;
    rows = 0;
    
    // Read maze line by line
    while (getline(file, line) && rows < MAX_SIZE) {
        cols = min((int)line.length(), MAX_SIZE);
        
        for (int j = 0; j < cols; j++) {
            maze[rows][j] = line[j];
        }
        rows++;
    }
    
    file.close();
    
    if (rows == 0) {
        cout << "Error: Empty maze file" << endl;
        return false;
    }
    
    findStartAndEnd();
    return true;
}

// Find start (S) and end (E) positions
void MazeSolver::findStartAndEnd() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'S') {
                start = Point(i, j);
            }
            else if (maze[i][j] == 'E') {
                end = Point(i, j);
            }
        }
    }
}

// Check if position is valid
bool MazeSolver::isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && 
           maze[x][y] != '#' && !visited[x][y];
}


