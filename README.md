# Run-Length Encoding (RLE) and Dictionary Encoding (LZW) Implementation in C++

## Introduction
This C++ program provides implementations for both Run-Length Encoding (RLE) and Dictionary Encoding (LZW), two widely used data compression techniques.

## 1. Run-Length Encoding (RLE)
Run-Length Encoding is a simple form of data compression where sequences of the same data value are stored as a single data value and count, rather than the original sequence. For instance, a sequence like "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

### Implementation
The RLE implementation consists of two functions:
- `Encode(string input)`: This function takes an input string and returns its RLE encoded version.
- `Decode(string input)`: This function takes an RLE encoded string and decodes it to its original form.

## 2. Dictionary Encoding (LZW)
Dictionary Encoding, also known as Lempel-Ziv-Welch (LZW) compression, is a more advanced compression technique that builds a dictionary of strings encountered in the data stream and replaces repeated strings with references to the dictionary.

### Implementation
The LZW implementation includes the following functions:
- `compressionDict(string input)`: This function takes an input string and returns its LZW encoded version.
- `DeCompression(string input)`: This function takes an LZW encoded string and decodes it to its original form.

## How to Run This Project
1. Clone the repository.
2. For compression:
   - Compile and run the `DictComp.cpp` file and `RunComp.cpp` file present in `CompressionCodes` directory to compress the test cases.
3. For decompression:
   - Compile and run the `DictDecomp.cpp` file and `RunDecomp.cpp` file in `DeCompressionCodes` directory.
4. The compressed testcases for Dictionary Coding are stored in `Output_Dictionary_Compressing` directory while Runlength encoded outputs are stored in `Output_Runlength_Compressing`.
5. The decompressed testcases for Dictionary Coding are stored in `Output_Dictionary_DeCompressing` directory while Runlength encoded outputs are stored in `Output_Runlength_DeCompressing`.

