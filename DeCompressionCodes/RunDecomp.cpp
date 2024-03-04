#include <bits/stdc++.h>
using namespace std;
namespace fs = std::filesystem;
string Decode(string Encode)
{
    string decoded = "";
    int n = Encode.length();
    for (int i = 0; i < n; i++)
    {
        if (isdigit(Encode[i]))
        {
            int cnt = 0;
            char temp = Encode[i - 1];
            while (i < n && isdigit(Encode[i]))
            {
                cnt = cnt * 10 + (Encode[i] - '0');
                i++;
            }
            decoded += string(cnt, temp);
        }
    }
    return decoded;
}
int main()
{
    // Define input and output directories
    string input_dir = "../Output_Runlength_Compressing";    // Path to the Testcase folder outside CompressionCodes
    string output_dir = "../Output_Runlength_DeCompressing"; // Path to the Output folder outside CompressionCodes

    // Create output directory if it doesn't exist
    fs::create_directory(output_dir);
    for (int i = 1; i <= 3; i++)
    {
        string inputFileName = input_dir + "/Testcase" + to_string(i) + "_Comp_RLE.txt";
        string outputFileName = output_dir + "/Testcase" + to_string(i) + "_DeComp_RLE.txt";
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
        string word;
        vector<string> words;
        while (inputFile >> word)
        {
            words.push_back(word);
        }
        for (const string &w : words)
        {
            string compressedWord = Decode(w);
            outputFile << compressedWord;
        }
        inputFile.close();
        outputFile.close();
        cout << "Decompression completed successfully." << endl;
    }
    return 0;
}