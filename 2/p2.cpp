#include <bits/stdc++.h>
using namespace std;

int main(){

    ifstream infile;
    string command;
    int value;
    int height,aim,distance = 0;
    long long ans;
    infile.open("input.txt");
    if(infile.is_open()){
       while(infile >> command >> value){
           if(command == "forward"){
               distance+=(value);
               height+=(value*aim);
           }
           else if(command == "up")
               aim-=value;
           else if(command == "down")
               aim+=value;
           //cout << aim << endl;
       }
       infile.close();
    }
    ans = distance * height;
    cout << "distance multiplied by the height is: " << ans << endl;
    //cout << "distance is: " << distance << " height is: " << height << endl;
    return 0;
}
