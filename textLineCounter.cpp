#include <iostream>
#include <fstream>

using namespace std;
int main(){
    ifstream infile("input.txt");
    int lineCounter = 0;
    for(string line; getline(infile,line);){

        lineCounter++;
    }
    return lineCounter;
}

