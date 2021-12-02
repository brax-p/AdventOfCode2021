#include <bits/stdc++.h>
using namespace std;

int main(){

    ifstream infile;
    string line;
    int count, ans = 0;
    int prev;
    infile.open("input.txt");
    if(infile.is_open()){
        while(getline(infile,line)) {
            if(count == 0)
                prev = stoi(line);
            if(count > 0){
               int curr = stoi(line);
               if(curr > prev)
                   ans++;
               prev = curr;
            }
            count++;
        }
        infile.close();
    }
    cout << "The number of increasing measurments is: " << ans << endl;
    return 0;
}
