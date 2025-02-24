#include "FunctionExtractor.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <cstring>

using namespace std;

void extractFunctionNames(const char* filename, char*** functions, int* count) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        *functions = nullptr;
        *count = 0;
        return;
    }

    vector<string> functionNames;
    string line;
    regex functionRegex(R"(\b\w+\s+\w+\s*\([^)]*\)\s*\{?)");
    smatch match;

    while (getline(file, line)) {
        if (regex_search(line, match, functionRegex)) {
            functionNames.push_back(match.str(0));
        }
    }

    file.close();

    *count = functionNames.size();
    *functions = new char*[*count];

    for (int i = 0; i < *count; i++) {
        (*functions)[i] = new char[functionNames[i].size() + 1];
        strcpy((*functions)[i], functionNames[i].c_str());
    }
}

void freeFunctionNames(char** functions, int count) {
    for (int i = 0; i < count; i++) {
        delete[] functions[i];
    }
    delete[] functions;
}

