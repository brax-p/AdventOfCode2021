#include <bits/stdc++.h>
using namespace std;



void printVec(vector<int> vec) {
    for(auto i: vec){
        cout << i << " ";
    }
    cout << endl;
}

long long getDecimal(vector<int> vec) {
    int pos = 0; 
    long long ans;
    for(int i = vec.size() - 1; i >= 0; i--) {
       ans += (vec[i] * pow(2,vec.size()-1-i));
    }
    return ans;
}

int main() {
    
    ifstream infile;
    infile.open("input.txt");
    int count = 0;
    int sizeStrings = 0;
    vector<int> ones;
    vector<int> zeros;
    if(infile.is_open()){
        string input;
        while(infile >> input){
            if(count == 0){
               sizeStrings = input.length(); 
               for(int i = 0; i < sizeStrings; i++) {
                    ones.push_back(0);
                    zeros.push_back(0);
               }
               count++;
            }
            else {
               for(int i = 0; i < input.length(); i++) {
                    if((input[i]) == '0')
                        zeros[i]++;
                    else
                        ones[i]++;
               }
            }
        }
        infile.close();
    }
    //get gamma -- most common char at each bit from ones/zeros
    vector<int> gamma;
    vector<int> epsilon;
    for(int i = 0; i < zeros.size(); i++){
        if(zeros[i] > ones[i]){
            gamma.push_back(0);
            epsilon.push_back(1);
        }
        else {
            gamma.push_back(1);
            epsilon.push_back(0);
        }
    }
    cout << "ans is: " << getDecimal(gamma) * getDecimal(epsilon) << endl;
    //printVec(ones);
    //printVec(zeros);
    //printVec(gamma);
    //printVec(epsilon);
    //cout << "the decimal representation of this binary string is: " << getDecimal(gamma) << endl;
    return 0;
}

