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
