#include<bits/stdc++.h>

using namespace std;

//Grid = 5 x 5
int m = 5;
int n = 5;

//Direction: Up, Down, Left, Right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Cell{
    public:
    int x, y, g, h;
    Cell* parent;

    Cell(int x, int y, int g, int h, Cell* p = nullptr) : x(x), y(y), g(g), h(h), parent(p) {};

    int f() const{
        return g + h;
    }
};

//compare function for min-heap (to store lowest f() value at the top);
struct compare{
    bool operator()(Cell* a, Cell* b){
        return a->f() > b->f();
    }
};

//Funtion to tell whether a cell is valid or not;
bool isValid(int x, int y, vector<vector<int>>& grid){
    if(x>=0 && x<5 && y>=0 && y<5 && grid[x][y] == 0)
        return true;
    else
        return false;
}

//Heuristic Function to calculate Estimated Cost of each cell (i.e. Node to Goal);
//Manhatten Distance
int heuristic(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

//Funtion to Print the Path;
//Back track from goal to start using Parent pointers, reverse and then print Path;
void printPath(Cell* goal){
    vector<pair<int, int>> path;

    while(goal != nullptr){
        path.push_back({goal->x, goal->y});
        goal = goal->parent;
    }

    reverse(path.begin(), path.end());

    cout<<"Path: ";
    for(auto [x, y] : path){
        cout<<"("<<x<<","<<y<<") ";
    }
}

//Main A* Algorithm
void a_star(vector<vector<int>> grid, pair<int, int> start, pair<int, int> goal){
    //Create a min-heap to basically give us the cell with lowest f()
    priority_queue<Cell*, vector<Cell*>, compare> open;

    //Visited set to keep track of visited cells
    vector<vector<bool>> visited (5, vector<bool>(5, false));

    //Initialize the starting cell and push it list OPEN list;
    Cell* startcell = new Cell(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second));
    open.push(startcell);

    while(!open.empty()){
        Cell* current = open.top();
        open.pop();
        
        //If visited: skip the current cell (i.e. skip current iteration)
        if(visited[current->x][current->y])
            continue;
        visited[current->x][current->y] = true;

        //Then check if current cell is the goal
        if(current->x == goal.first && current->y == goal.second){
            //Print the path and return
            printPath(current);
            return;
        }

        for(int i=0; i<4; i++){
            //Calculate new x,y for all neighbours 
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];
            
            //Check if new position is valid
            if(isValid(nx, ny, grid) && !visited[nx][ny]){
                //Calculate its g, h and f() value
                int ng = current->g + 1;
                int nh = heuristic(nx, ny, goal.first, goal.second);

                //Create new cell and push it in OPEN list
                Cell* newCell = new Cell(nx, ny, ng, nh, current);
                open.push(newCell);

                cout<<"Node: ("<<nx<<","<<ny<<") g: "<<ng<<" h: "<<nh<<" f: "<<ng+nh<<endl;
            }
        }
    }

    //If it comes out of this loop, it means path was not found
    cout << "No path found" << endl;
}

int main(){
    //Create a grid of cells 
    vector<vector<int>> grid={
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    //Define start and goal
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    //Call the A* Algo function
    a_star(grid, start, goal);

    return 0;
}
