#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& arr, vector<int>& visited, int index, int parent) {
        
        visited[index] = 1;

        for(int i = 0 ; i < arr[0].size() ; i++ ){

            if(arr[index][i] == 1){

                if(visited[i] == 0){   // ✅ only go if not visited
                    bool b = dfs(arr,visited,i,index);
                    if(b == true){
                        return true;
                    }
                }
                else if(parent != i){  // ✅ cycle condition
                    return true;
                }

            }
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> arr(numCourses, vector<int>(numCourses, 0));
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int r = prerequisites[i][0];
            int c = prerequisites[i][1];

            arr[r][c] = 1;
            arr[c][r] = 1;
        }

        for(int i = 0 ; i < arr[0].size() ; i++){   // (your style kept)
            if(visited[i] == 0){
                if(dfs(arr, visited, i, -1) == true){   // ✅ start from i
                    return false;
                }
            }
        }

        return true;
    }
};