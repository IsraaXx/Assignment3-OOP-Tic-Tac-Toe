// File name: A3_SheetPb6_20221252.cpp
// Purpose: change the state of the cell according to the neighbors of the cell
// Author(s): Israa Mohamed Elsayed Mohamed
// ID(s): 20221252
// Section: S1,2
// Date: 9/12/2023
//#include <iostream>
//using namespace std;
//#include <vector>
//class universe {
//private:
//    int row;
//    int column;
//    vector<vector<int>> grid; // 2d vector
//public:
//    universe(int R, int C) : row(R), column(C),grid(R, vector<int>(C,0)) {} // has r rows each row jas c elements are zeros
//    void Initialize(int cells) { // initialize the start of the game by the user , choose cells and make them alive
//        cout<<"Enter the position of each cell to make it alive :\n";
//        while (cells--){
//        int r,c;
//        cin>>r>>c;
//        grid[r][c]=1;}
//        cout<<"The state after your initialization :\n";
//        display();
//
//    }
//    void Reset() { // set all the cells as dead (0)
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < column; ++j) {
//                grid[i][j] = 0;
//            }
//        }
//    }
//    void display() { // show the grid if the cell is alive so print '*' if dead print '.'
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < column; ++j) {
//                if (grid[i][j] == 1)
//                    cout << '*';
//                else
//                    cout << '.';
//            }
//            cout << "\n";
//        }
//    }
//    // grid.size() returns number of rows // grid[0].size() returns number of columns (elements in that row)
//    int count_neighbors(int r, int c) { // i ,j  are the positions of the cell that the user want to start play with
//        int cnt =0;  // -1:1 because neighbors are either in the same row but (+-) column or same column and(+-)row
//        for (int x = -1; x <= 1; ++x) { // or they both (+-) in the grid
//            for (int y = -1; y <= 1; ++y) {
//                if((x==0&&y==0)|| (r+x<0) || (r+x>=grid.size()) || (c+y<0) || (c+y>=grid[0].size()) ){
//                    continue;}
//                if(grid[r+x][c+y])
//                    cnt++;
//            }
//        }
//        return cnt;
//    }
//    void next_generation() { // this function is to check the rules of the game as is given and set the new generation
//        vector<vector<int>> newGrid(row, vector<int>(column)); // in a new grid and then set it to the old one
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < column; ++j) {
//                int neighbors = count_neighbors(i,j);
//                if (grid[i][j] == 1) {
//                    if (neighbors < 2 || neighbors > 3)
//                        newGrid[i][j] = 0;
//                    else
//                        newGrid[i][j] = 1;
//                } else {
//                    if (neighbors == 3){
//                    newGrid[i][j] = 1;}
//                    else
//                        newGrid[i][j]=0;
//                }
//            }
//        }
//        grid=newGrid;
//    }
//    void run(int iterations ) { // run means the game will run number of iterations the user
//        for (int i = 0; i < iterations; ++i) {  // enter it and every iteration it prints the first state of the game
//            cout<<"Next generation:\n"; // and then print the next generation
//            next_generation();
//            display();
//        }
//    }
//};
//int main() {
//    universe s(30, 30);
//    cout<<"Current state: \n";
//    s.display();
//    cout<<"Enter the number of cells you want to initialize : \n";
//    int n;
//    cin>>n;
//    s.Initialize(n);
//    cout<<"Enter the number of iterations to keep the game on: \n";
//    int itr;
//    cin>>itr;
//    s.run(itr);
//
//}


