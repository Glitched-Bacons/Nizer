#ifndef PHASH_H
#define PHASH_H

#include "HashAlgorithm.h"

class PHash : public HashAlgorithm
{
public:
    Hash hash(const std::string& imagePath) override;
};

#endif // PHASH_H
