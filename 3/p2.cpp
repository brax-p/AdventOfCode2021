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

vector<vector<int>> solveOxygen(int iteration, vector<vector<int>> lines) {
    int numZeros = 0, numOnes = 0;
    if(lines.size() == 1)
        return lines;
    else{
        vector<vector<int>> newList;
       for(int i = 0; i < lines.size(); i++) {
            if(lines[i][iteration] == 0)
                numZeros++;
            else
                numOnes++;
       }
       //cout << "at index: " << iteration << endl;
       //cout << "numZeros: " << numZeros << endl << "numOnes: " << numOnes << endl;
       int most = 0;
       if(!(numZeros > numOnes))
           most =1;
       for(int i = 0; i < lines.size(); i++) {
           if(lines[i][iteration] == most)
               newList.push_back(lines[i]);
       }
       /*for(int j = 0; j < newList.size(); j++){
               printVec(newList[j]);
       }
       cout << endl;*/
    return(solveOxygen(iteration+1, newList));
    }
}

vector<vector<int>> solveCarbon(int iteration, vector<vector<int>> lines) {
    int numZeros = 0;
    int numOnes = 0;
    if(lines.size() == 1)
        return lines;
    else{
        vector<vector<int>> newList;
       for(int i = 0; i < lines.size(); i++) {
            if(lines[i][iteration] == 0)
                numZeros++;
            else
                numOnes++;
       }
       //cout << "at index: " << iteration << endl;
       int most = 0;
       //cout << "numZeros: " << numZeros << endl << "numOnes: " << numOnes << endl;
       if((numZeros > numOnes))
           most =1;
       for(int i = 0; i < lines.size(); i++) {
           if(lines[i][iteration] == most)
               newList.push_back(lines[i]);
       }
       /*for(int j = 0; j < newList.size(); j++){
               printVec(newList[j]);
       }*/
    return(solveCarbon(iteration+1,newList));
    }
}

int main() {
    
    ifstream infile;
    infile.open("input.txt");
    int count = 0;
    int sizeStrings = 0;
    vector<vector<int>> inputs;
    bool ansFound = false;
    if(infile.is_open()){
        string line;
        while(infile >> line) {
           vector<int> tempLine;
           for(int i = 0; i < line.length(); i++){
                if(line[i] == '0')
                    tempLine.push_back(0);
                else
                    tempLine.push_back(1);
                    
           }
           inputs.push_back(tempLine);

        }
        infile.close();
    }
    vector<vector<int>> oxygen = solveOxygen(0,inputs);
    vector<vector<int>> carbon = solveCarbon(0,inputs);
    //printVec(oxygen[0]);
    //printVec(carbon[0]);
    vector<int> oxygenrating = oxygen[0];
    vector<int> carbonrating = carbon[0];
    cout << "ans is: " << getDecimal(oxygenrating) * getDecimal(carbonrating) << endl;
    /*for(auto i: inputs)
        printVec(i);*/
    return 0;
}

