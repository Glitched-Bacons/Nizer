#ifndef HASHALGORITHM_H
#define HASHALGORITHM_H

#include <string>

class Hash;

class HashAlgorithm
{
public:
    virtual ~HashAlgorithm() = 0;
    virtual Hash hash(const std::string& imagePath) = 0;
};

#endif // HASHALGORITHM_H
