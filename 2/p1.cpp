#include <bits/stdc++.h>
using namespace std;

int main(){

    ifstream infile;
    string command;
    int value;
    int height, distance = 0;
    infile.open("input.txt");
    if(infile.is_open()){
       while(infile >> command >> value){
           if(command == "forward")
               distance+=value;
           else if(command == "up")
               height-=value;
           else
               height+=value;
       //    cout << command << " " << value << endl;
       }
       infile.close();
    }
    cout << "distance multiplied by the height is: " << distance * height << endl;
    return 0;
}
