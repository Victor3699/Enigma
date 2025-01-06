#include "package.hpp"
#include "Encrypt.hpp"

class CaesarEncrypt : public Encrypt {
public:
    CaesarEncrypt() {
        _plain = "";
        _cipher = "";
    }
    
    std::string get_plain() const override;
    std::string get_cipher() const override;
    std::string encode(std::string plain) override;
    std::string decode(std::string cipher) override;
    std::string read(const std::string& filename) override;  // Utiliser une référence constante
    void write(std::string filename) override;
};
