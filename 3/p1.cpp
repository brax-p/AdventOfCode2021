#include <bits/stdc++.h>
using namespace std;


int toDecimal(string binary) {
    int ans = 0;
    int counter = binary.length() - 1;
    for(int i = binary.length()-1; i >=0 ; i--){
           ans+=(2^(counter-i)); 
    }
    return ans;
}


int main() {
    
    ifstream infile;
    infile.open("input.txt");
    vector<int>ones(7);
    vector<int>zeros(7);
    string gamma, epsilon = "";
    if(infile.is_open()){
        string input;
        while(infile >> input){
            for(int i = 0; i < input.length(); i++) {
               if(input[i] == '1') 
                   ones[i]+=1;
               else if(input[i] == '0')
                   zeros[i]+=1;
            }
            
        }
        infile.close();
    }
    for(int i = 0; i < 7; i++){
        if(ones[i] > zeros[i]) {
            gamma.append("1");
            epsilon.append("0");
        }
        else if(ones[i] < zeros[i]) {
            gamma.append("0");
            epsilon.append("1");
        }
    }
    cout << "gamma * epsilon rates = " << toDecimal(gamma) * toDecimal(epsilon) << endl;

    return 0;
}

