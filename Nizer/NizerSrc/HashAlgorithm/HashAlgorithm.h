#ifndef HASHALGORITHM_H
#define HASHALGORITHM_H

#include <string>

class Hash;

class HashAlgorithm
{
public:
    virtual ~HashAlgorithm() = default;
    virtual Hash hash(const std::string& imagePath) const = 0;
};

#endif // HASHALGORITHM_H
