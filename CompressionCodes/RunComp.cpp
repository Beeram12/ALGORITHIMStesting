#include <bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;
template <typename T>
// Run length encoding
string Encode(const T &s)
{
    int size = s.size();
    string encoded = "";
    int count = 1;
    encoded += s[0];
    if (size == 0)
        return "";
    for (int i = 0; i < size; i++)
    {
        if (s[i] != s[i + 1])
        {
            encoded += to_string(count);
            encoded += s[i + 1];
            count = 1;
        }
        else
        {
            count++;
        }
    }
    return encoded;
}
int main()
{
    // Define input and output directories
    string input_dir = "../TestCases";                     // Path to the Testcase folder outside CompressionCodes
    string output_dir = "../Output_Runlength_Compressing"; // Path to the Output folder outside CompressionCodes

    // Create output directory if it doesn't exist
    fs::create_directory(output_dir);

    for (int i = 1; i <= 3; ++i)
    {
        string inputFileName = input_dir + "/Testcase" + to_string(i) + ".txt";
        string outputFileName = output_dir + "/Testcase" + to_string(i) + "_Comp_RLE.txt";

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
            string compressedWord = Encode(word);
            outputFile << compressedWord << " ";
        }

        inputFile.close();
        outputFile.close();
        cout << "Compression for " << inputFileName << " completed successfully." << endl;
    }

    return 0;
}