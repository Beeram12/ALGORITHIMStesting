#include <bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;
string DeCompression(vector<int> &compression)
{
    unordered_map<int, string> dictionary;
    int dictSize = 256;
    for (int i = 0; i < dictSize; i++)
    {
        dictionary[i] = string(1, i);
    }
    string w(1, compression[0]);
    string result = w;
    for (int i = 1; i < compression.size(); i++)
    {
        string temp;
        int k = compression[i];
        if (dictionary.find(k) != dictionary.end())
        {
            temp = dictionary[k];
        }
        else if (k == dictSize)
        {
            temp = w + w[0];
        }
        result += temp;
        dictionary[dictSize++] = w + temp[0];
        w = temp;
    }
    return result;
}
int main()
{
    // Define input and output directories
    string input_dir = "../Output_Dictionary_Compressing";    // Path to the Testcase folder outside CompressionCodes
    string output_dir = "../Output_Dictionary_DeCompressing"; // Path to the Output folder outside CompressionCodes

    // Create output directory if it doesn't exist
    fs::create_directory(output_dir);
    for (int i = 1; i <= 3; i++)
    {
        string inputFileName = input_dir + "/Testcase" + to_string(i) + "_Comp_Dict.txt";
        string outputFileName = output_dir + "/Testcase" + to_string(i) + "_DeComp_Dict.txt";
        ifstream inputFile(inputFileName);
        ofstream outputFile(outputFileName);
        if (!inputFile)
        {
            cerr << "Error: Unable to open input file." << endl;
            return 1;
        }
        if (!outputFile)
        {
            cerr << "Error: Unable to create output file." << endl;
            return 1;
        }
        int number;
        vector<int> numbers;
        while (inputFile >> number)
        {
            numbers.push_back(number);
        }
        string decompressedString = DeCompression(numbers);
        outputFile << decompressedString;
        inputFile.close();
        outputFile.close();
        cout << "Decompression completed successfully." << endl;
    }
    return 0;
}