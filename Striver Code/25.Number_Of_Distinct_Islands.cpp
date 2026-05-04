// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

//Using dfs, push the coordinates of all the connected components, then reduce the array by subtracting with first element of the array, then push it into the set, this ensures that only distinct shapes are in the set, at end return the the number of elements in the set

class Solution {
  public:
  
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, 
    vector<pair<int,int>>& arr,int row, int col){
        
        visited[row][col] = 1;
        
        
        arr.push_back({row,col});
        
        int r[] = {0,-1,0,1};
        int c[] = {-1,0,1,0};
        
          for(int i = 0 ; i < 4; i++){
            
            int nrow = row + r[i];
            int ncol = col + c[i];

            if(nrow >= 0 && nrow < grid.size()
            && ncol >= 0 && ncol < grid[0].size()
            && visited[nrow][ncol] == 0
            && grid[nrow][ncol] == 1){

                dfs(grid,visited,arr,nrow,ncol);
            }
        }
    
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        
        set<vector<pair<int,int>>> s;
        
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    
                    vector<pair<int,int>> arr;
                    
                    dfs(grid,visited,arr,i,j);
                    
                    for(int k = 0 ; k < arr.size() ; k++){
                        arr[k].first -= arr[0].first;
                        arr[k].second -= arr[0].second;
                    }
                    
                    s.insert(arr);
                }
            }
        }
        
        return s.size();
    }
};
