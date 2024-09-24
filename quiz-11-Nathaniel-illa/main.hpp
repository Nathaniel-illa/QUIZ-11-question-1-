#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Struct definitions
struct Name {
    string stname;
    string gender;
    int year;
    string name;
    int count;
};

struct Result {
    string name;
    int count;
};

// Function declarations
vector<Name> rewritesplitwords(string filename, char delimiter);
vector<Result> MFN(vector<Name> namerecords, string stname, int thisyear);

// Helper function to split a string by a delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to read the file, split the records, and return a vector of Name structs
vector<Name> rewritesplitwords(string filename, char delimiter) {
    vector<Name> namerecords;
    ifstream infile(filename);
    ofstream outfile("split.txt");
    
    if (!infile.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return namerecords;
    }
    
    string line;
    while (getline(infile, line)) {
        vector<string> fields = split(line, delimiter);
        if (fields.size() == 5) {
            Name nameRecord;
            nameRecord.stname = fields[0];
            nameRecord.gender = fields[1];
            nameRecord.year = stoi(fields[2]);
            nameRecord.name = fields[3];
            nameRecord.count = stoi(fields[4]);
            
            namerecords.push_back(nameRecord);
            
            // Write the formatted data into "split.txt"
            outfile << nameRecord.stname << "\t" 
                    << nameRecord.gender << "\t" 
                    << nameRecord.year << "\t" 
                    << nameRecord.name << "\t" 
                    << nameRecord.count << endl;
        }
    }
    
    infile.close();
    outfile.close();
    
    return namerecords;
}

// Function to find the most frequently used names for male and female in a given state and year
vector<Result> MFN(vector<Name> namerecords, string stname, int thisyear) {
    Result maleResult = {"", 0};
    Result femaleResult = {"", 0};
    
    for (const Name& record : namerecords) {
        if (record.stname == stname && record.year == thisyear) {
            if (record.gender == "M" && record.count > maleResult.count) {
                maleResult.name = record.name;
                maleResult.count = record.count;
            }
            if (record.gender == "F" && record.count > femaleResult.count) {
                femaleResult.name = record.name;
                femaleResult.count = record.count;
            }
        }
    }
    
    return {maleResult, femaleResult};
}