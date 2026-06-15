// Leaders in an Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    vector<int> leaders(vector<int>& nums){
        reverse(nums.begin(),nums.end());
        vector <int> res;
        res.push_back(nums[0]);
        int greater = nums[0];

        for(int i = 1 ; i< nums.size(); i++){
            if(nums[i] > greater){
                res.push_back(nums[i]);
                greater = nums[i];
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{

    return 0;
}