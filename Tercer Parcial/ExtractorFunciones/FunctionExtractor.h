#ifndef FUNCTIONEXTRACTOR_H
#define FUNCTIONEXTRACTOR_H

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

extern "C" {
    EXPORT void extractFunctionNames(const char* filename, char*** functions, int* count);
    EXPORT void freeFunctionNames(char** functions, int count);
}

#endif // FUNCTIONEXTRACTOR_H

