#ifndef Encrypt_hpp
#define Encrypt_hpp

#include "package.hpp"


class Encrypt {
protected:
    std::string _plain;
    std::string _cipher;

public:
    virtual ~Encrypt() = default;  // Destructeur virtuel pour la gestion correcte de la mémoire

    virtual std::string get_plain() const = 0;
    virtual std::string get_cipher() const = 0; 
    virtual std::string encode(std::string plain) = 0; 
    virtual std::string decode(std::string cipher) = 0;
    virtual std::string read(const std::string &filename) = 0;
    virtual void write(std::string filename) = 0;
};


#endif // Encrypt_hpp
