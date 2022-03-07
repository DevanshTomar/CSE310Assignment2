//
// Created by devansh tomar on 3/4/22.
//

#include <iostream>
#include <string>
#include <sstream>
#include "earnings.h"

string readInput(string line){
    // Used for breaking words
    stringstream s(line);

    // To store individual words
    string word;
    string result = " ";

    int count = 1;
    while (s >> word)
    {
        if (count == 2)
        {
            if (word == "ratio")
            {
                result = word;
            }
            else{
                result = word;
            }
        }
        if (count == 3 || count == 4)
        {
            result = result + " " + word;
        }
        count++;
    }
    return result;
}