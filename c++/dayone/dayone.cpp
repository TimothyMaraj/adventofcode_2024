#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 



int main() 
{
    

    // file i/o
    ifstream file("dayone_input.txt"); 
    if(!file.is_open())
    {
        cerr << "Unable To Open" << endl; 
    }
    // vector creation and file in
    vector<int> firstArr, secondArr;
    int firstNumber = 0, secondNumber =0; 

    while(file >> firstNumber >> secondNumber)
    {
        firstArr.push_back(firstNumber); 
        secondArr.push_back(secondNumber); 
    }

    sort(firstArr.begin(),firstArr.end());
    sort(secondArr.begin(),secondArr.end()); 


    long sum = 0; 
    auto it1 = firstArr.begin(); 
    auto it2 = secondArr.begin(); 

    for(; it1 != firstArr.end() && it2 != secondArr.end(); ++it1,++it2)
    {
        if(*it1 > *it2)
        {
            sum+=*it1-*it2;
        }
        else if(!(*it1 > *it2))
        {
            sum+=*it2-*it1;
        }
        else
        {
            sum+=0; 
        }
    }
    
    cout << sum << endl; 

}