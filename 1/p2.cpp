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
    int tempSum;
    vector<int> nums;
    infile.open("input.txt");
    if(infile.is_open()){
        while(getline(infile,line)) {
            nums.push_back(stoi(line));    
        }
        infile.close();
    }

    for(int i = 3; i < nums.size(); i++) {
        if(nums[i] > nums[i-3]) //Since each triplet shares 2 integers, the difference between the third yields if increasing or not
            ans++;
    }


    cout << "The number of increasing triplets is: " << ans << endl;
    return 0;
}
