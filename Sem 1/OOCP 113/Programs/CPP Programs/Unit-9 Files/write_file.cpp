#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("data.txt"); // Create/open file

    file << "Hello file handling!"; // Write to file

    file.close(); // Close file
    return 0;
}
