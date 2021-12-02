#include <bits/stdc++.h>
using namespace std;




int vecSum(vector<int> vec) {
    int sum = 0;
    for(auto i: vec){
        sum+=i;   
    }
    return sum;
}


int main(){

    ifstream infile;
    string line;
    int count, ans = 0;
    int prev;
    vector<int> prev;
    vector<int> curr;
    infile.open("input.txt");
    if(infile.is_open()){
        while(getline(infile,line)) {
            if(count  < 3)
                prev.push_back(stoi(line));
            if(!(count - 3) % 3 == 2){
                curr.push_back(stoi(line));
            }
            else{
                curr.push_back(stoi(line));
                if(vecSum(curr) > vecSum(prev)) 
                    ans++;

            }
            count++;
        }
        infile.close();
    }
    cout << "The number of increasing triplets is: " << ans << endl;
    return 0;
}
