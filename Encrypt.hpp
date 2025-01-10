#ifndef Encrypt_hpp
#define Encrypt_hpp

#include "package.hpp"

class Encrypt {
protected:
    std::string _plain;
    std::string _cipher;

public:
    virtual ~Encrypt() = default;

    std::string get_plain() const;
    std::string get_cipher() const;
    virtual std::string encode(std::string plain) = 0; 
    virtual std::string decode(std::string cipher) = 0; 
    std::string read(const std::string& filename);
    void write(std::string filename);
};

#endif // Encrypt_hpp
