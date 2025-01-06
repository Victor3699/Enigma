#include "package.hpp"
#include "EncrypteCesar.hpp" // Inclure uniquement le fichier d'en-tête

int main() {
    CaesarEncrypt caesar;

    // Test de la méthode encode
    std::string plaintext = "Hello World!";
    std::string cipher = caesar.encode(plaintext);
    std::cout << "Texte chiffré : " << cipher << std::endl;

    // Test de la méthode decode
    std::string decoded = caesar.decode(cipher);
    std::cout << "Texte déchiffré : " << decoded << std::endl;

    // Test de la lecture et de l'écriture de fichiers
    caesar.write("ciphertext.txt");
    std::cout << caesar.read("ciphertext.txt");

    return 0;
}
