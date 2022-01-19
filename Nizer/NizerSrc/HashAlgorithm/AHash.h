#ifndef AHASH_H
#define AHASH_H

#include "HashAlgorithm.h"

class AHash : public HashAlgorithm
{
public:
    Hash hash(const std::string& imagePath) const override;
};

#endif // AHASH_H
