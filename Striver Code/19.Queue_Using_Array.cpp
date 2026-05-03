// Implement Queue using Arrays

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    int q[130];
    int f = -1;
    int r = -1;
    solution(){

    }

    void push(int data){
        if(r > 130 ){
            cout << "FULL";
            return;
        }
        r++;
        q[r] = data;
    }

    int pop(){
        if(f == r){
            cout << "EMPTY";

            // VERY VERY IMPORTANT
            f = r = -1;
            return -1;
        }
        f++;
        int a = q[f];
        return a;
    }

    void display(){
        for(int i = f+1; i <= r; i++){
            cout << q[i] << " ";
        }
    }
   
};

int main()
{

    return 0;
}
