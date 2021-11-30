#ifndef HASH_H
#define HASH_H

class HashAlgorithm;

class Hash
{
public:
    bool operator==(const HashAlgorithm& rhs);
    int operator-(const HashAlgorithm& rhs);

private:
    int mHash;
};

#endif // HASH_H
