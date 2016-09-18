#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unistd.h>

#include "message.hpp"

using namespace std;

Message Msg;
// Store the words from the two files into these two vectors
vector<string> DataArray;
vector<string> QueryArray;

void MovetoMsg(int case_no, int LoopIndex, string token);

int main()
{
    std::string line;
    std::string delimiter = " ";
    int BO_Count = 0;



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

        for(unsigned int i = 26; i < 27; i++)
        {
            //cout << "Length of DataArray [" << i << "] = " << DataArray[i].length() << std::endl;
            // cout << "First value of DataArray [" << i << "] = " << DataArray[i] << std::endl;
            size_t pos = 0;
            std::string token;
            int case_counter = 0;
            while((pos = DataArray[i].find(delimiter)) != std::string::npos)
            {

                token = DataArray[i].substr(0, pos);
                //std::cout << token << std::endl;
                DataArray[i].erase(0, pos + delimiter.length());
                if(token == "BO_")
                {
                    BO_Count++;
                }
                case_counter++;
                MovetoMsg(case_counter,i,token);

                //cout << "Length of DataArray [" << i << "] = " << DataArray[i].length() << std::endl;
                //cout << "value of DataArray [" << i << "] = " << DataArray[i] << std::endl;

            }
            //cout << "Splitted DataArray  = " << DataArray[i] << std::endl;
            //sleep(1);
        }
        cout << "Msg values are " << Msg.getId()<<" "<< Msg.getName()<<" "<< Msg.getDlc()<<" "<< Msg.getFrom() << std::endl;
        std::cout << "Total B0 count is "<<BO_Count << std::endl;

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

void MovetoMsg(int case_no, int LoopIndex, string token)
{
    switch(case_no)
    {
    case 1:
    {

    }
    break;
    case 2:
    {
        Msg.id = std::stoi(token);
    }
    break;
    case 3:
    {
        Msg.name = token;
    }
    break;
    case 4:
    {
        Msg.dlc = std::stoi(token);
        Msg.from = DataArray[LoopIndex];
    }
    break;
    case 5:
    {

    }
    break;
    default:
        break;

    }

}
