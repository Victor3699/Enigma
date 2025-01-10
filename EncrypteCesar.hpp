#include "package.hpp"
#include "Encrypt.hpp"

class CaesarEncrypt : public Encrypt {
private:
    int _shift;
public:
    CaesarEncrypt(int shift = 3);
    
    std::string encode(std::string plain) override;
    std::string decode(std::string cipher) override;
    std::string breakCesar(std::string _cipher); // Méthode pour casser le code César sans avoir la clef au préalable
};

