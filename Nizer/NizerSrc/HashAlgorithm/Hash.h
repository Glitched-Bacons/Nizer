#ifndef HASH_H
#define HASH_H

class HashAlgorithm;

class Hash
{
public:
    Hash(int hashValue);

    bool operator==(const Hash& rhs) const;
    int operator-(const Hash& rhs) const;

private:
    int mHash;
};

#endif // HASH_H
