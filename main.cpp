#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unistd.h>


using namespace std;
int main()
{
     std::string line;

    // Store the words from the two files into these two vectors
    vector<string> DataArray;
    vector<string> QueryArray;

    ifstream myfile("BO_MSCAN.dbc");
    ifstream qfile("BO_MSCAN.dbc");


    while (getline(myfile, line))
    {
         //cout << "line " << line << std::endl;
        if ( !line.empty())
            DataArray.push_back(line);
    }

    try
    {

        cout << "DataArray size = " << DataArray.size() << std::endl;
        cout << "QueryArray size = " << QueryArray.size() << std::endl;

        for(unsigned int i = 0; i < DataArray.size(); i++)
        {
            cout << "value of DataArray [" << i << "] = " << DataArray[i] << std::endl;
            sleep(1);
        }

    }
    catch(...)
    {
        // deal with error here. Maybe:
        //   the input file doesn't exist
        //   the ifstream creation failed for some other reason
        //   the string reads didn't work
        cout << "Data Unavailable\n";
    }
}
