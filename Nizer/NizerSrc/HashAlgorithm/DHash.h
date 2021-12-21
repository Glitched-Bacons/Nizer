#ifndef DHASH_H
#define DHASH_H

#include "HashAlgorithm.h"

class DHash : public HashAlgorithm
{
public:
    Hash hash(const std::string& imagePath) override;
};

#endif // DHASH_H
