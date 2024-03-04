#include <bits/stdc++.h>
namespace fs = std::filesystem;
using namespace std;
vector<int> compressionDict(string s)
{
    vector<int> compression;
    unordered_map<string, int> dictionary;
    int dictSize = 256;
    for (int i = 0; i < dictSize; i++)
    {
        dictionary[string(1, i)] = i;
    }
    string result;
    for (auto it : s)
    {
        string word = result + it;
        if (dictionary.find(word) != dictionary.end())
        {
            result = word;
        }
        else
        {
            compression.push_back(dictionary[result]);
            dictionary[word] = dictSize++;
            result = string(1, it);
        }
    }
    if (!result.empty())
    {
        compression.push_back(dictionary[result]);
    }
    return compression;
}
int main()
{
    // Define input and output directories
    string input_dir = "../TestCases";                      // Path to the Testcase folder outside CompressionCodes
    string output_dir = "../Output_Dictionary_Compressing"; // Path to the Output folder outside CompressionCodes

    // Create output directory if it doesn't exist
    fs::create_directory(output_dir);

    for (int i = 1; i <= 3; i++)
    {
        string inputFileName = input_dir + "/Testcase" + to_string(i) + ".txt";
        string outputFileName = output_dir + "/Testcase" + to_string(i) + "_Comp_Dict.txt";

        ifstream inputFile(inputFileName);
        ofstream outputFile(outputFileName);

        if (!inputFile)
        {
            cerr << "Error: Unable to open input file " << inputFileName << "." << endl;
            return 1;
        }

        if (!outputFile)
        {
            cerr << "Error: Unable to create output file " << outputFileName << "." << endl;
            return 1;
        }

        string word;
        while (inputFile >> word)
        {
            vector<int> compressedWord = compressionDict(word);
            for (int num : compressedWord)
            {
                outputFile << num << "  ";
            }
            outputFile << -1 << " ";
        }

        inputFile.close();
        outputFile.close();
        cout << "Compression for " << inputFileName << " completed successfully." << endl;
    }
    return 0;
}