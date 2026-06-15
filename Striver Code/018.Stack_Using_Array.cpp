// Implement Stack using Arrays

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    int s[130];
    int t = -1;
    solution(){

    }
    void push(int data){
        if(t >= 130){
            cout << "FULL";
            return; 
        }
        t++;
        s[t] = data;

    }
    int pop(){
        if(t == -1){
            return -1;
        }
        int a = s[t];
        t--;
        return a;
    }
    int top(){
        if(t == -1){
            return -1;
        }
        return s[t];
    }
    void display(){
        int i = t;
        while(i >= 0){
            cout << s[i] << " ";
            i--;
        }
    }
    
};

int main()
{

    return 0;
}