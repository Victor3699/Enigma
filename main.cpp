#include "package.hpp"
#include "EncrypteCesar.hpp" // Inclure uniquement le fichier d'en-tête

int main() {
    CaesarEncrypt encrypt(3);
    // Test de la méthode encode

    std::string plaintext = encrypt.read("_cipher.txt");
    std::string cipher = encrypt.encode(plaintext);
    std::cout << "Texte chiffré : " << cipher << std::endl;

    // Test de la méthode decode
    std::string broken = encrypt.breakCesar(cipher);
    std::cout << "Ceci fonctionne" << std::endl;
    std::cout << "Texte déchiffré : " << broken << std::endl;


    return 0;
}
