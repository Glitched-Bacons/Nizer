#include "Hash.h"

Hash::Hash(int hashValue)
    : mHash(hashValue < 0 ? -hashValue : hashValue)
{
}

bool Hash::operator==(const Hash &rhs) const
{
    return mHash == rhs.mHash;
}

int Hash::operator-(const Hash &rhs) const
{
    auto diff = mHash - rhs.mHash;
    return diff < 0 ? -diff : diff;
}
