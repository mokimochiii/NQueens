#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <unordered_set>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
  // check upper element
  int tempRow = row;
  int tempCol = col;

  //checking first diagonal
  while (row >= 0 && col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    row--;
    col--;
  }

  //checking row
  col = tempCol;
  row = tempRow;
  while (col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    col--;
  }

  //checking second diagonal
  row = tempRow;
  col = tempCol;
  while (row < n && col >= 0) {
    if (board[row][col] == 'Q')
      return false;
    row++;
    col--;
  }
  return true;
}

vector<vector<vector<char>>> solveNQueens(int n) {
  vector<vector<vector<char>>> ans;
  vector<vector<char>> board(n, vector<char>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n ; j++){
      board[i][j] = '.';
    }
  }

  stack<pair<vector<vector<char>>, int>> stk;
  stk.push({board, 0});
  while(!stk.empty()){
    vector<vector<char>> currBoard = stk.top().first;
    int currCol = stk.top().second;
    stk.pop();

    if(currCol == n){
      ans.push_back(currBoard);
      continue;
    }

    for(int row = 0; row < n; row++){
      if(isSafe(row, currCol, currBoard, n)){
        currBoard[row][currCol] = 'Q';
        stk.push({currBoard, currCol + 1});
        currBoard[row][currCol] = '.';
      }
    }

  }
  return ans;
}

void printSolution(vector<vector<vector<char>>>& ans, vector<pair<int, int>>& startingPositions, ofstream& output){
  int counter = 0;
  int target = startingPositions.size();
  vector<vector<char>> trueSolution;
  for (size_t i = 0; i < ans.size(); i++) { //for each solution
    for(size_t j = 0; j < ans[0].size(); j++){ //for each column in the solution
      for(size_t k = 0; k < ans[0][0].size(); k++){ //for each index in the column
        if(ans[i][j][k] == 'Q'){ //if it is a queen
          for(pair<int, int> position : startingPositions){ 
            if(j+1 == (size_t)position.first && k+1 == (size_t)position.second){ //check if it is a position in startingPositions
              counter++;
            }
          }
        }
      }
    }
    if(counter == target) trueSolution = ans[i]; //if all contents of startingPositions have a match, it is a trueSolution
    counter = 0;
  }

  if(trueSolution.size() == 0){
    output << "No solution" << endl;
    return;
  }

  for(size_t i = 0; i < trueSolution.size(); i++){
    for(size_t j = 0; j < trueSolution[0].size(); j++){
      if(trueSolution[i][j] == 'Q'){
        output << i+1 << " " << j+1 << " ";
      }
    }
  }
  output << endl;
}

int main(int argc, char *argv[]) {
  if(argc < 3){
    throw std::invalid_argument("Usage: ./nqueens <input_file> <output_file>");
    return 1;
  }

  ifstream input(argv[1]);
  ofstream output(argv[2]);

  if(!input.is_open() || !output.is_open()){
    throw std::invalid_argument("Error opening files.");
    return 1;
  }

  string l;
  int n, col, row;
  vector<pair<int, int>> startingPositions;

  while(getline(input, l)){
    stringstream line(l);
    line >> n;
    while(line>>col>>row){
      startingPositions.push_back({col, row});
    }
    vector<vector<vector<char>>> ans = solveNQueens(n);
    printSolution(ans, startingPositions, output);

    startingPositions.clear();
  }
  input.close();
  output.close();
  return 0;
}
