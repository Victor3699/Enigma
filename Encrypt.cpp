#include "Encrypt.hpp"


std::string Encrypt::get_plain() const{
    return _plain;
}

std::string Encrypt::get_cipher() const{
    return _cipher;
}

std::string Encrypt::encode(std::string plain) {
    _plain = plain;
    _cipher.clear();
    for (char c : plain) {
        _cipher += (c + 3);  // Décalage de 3 caractères
    }
    return _cipher;
}

std::string Encrypt::decode(std::string cipher) {
    _cipher = cipher;
    _plain.clear();
    for (char c : cipher) {
        _plain += (c - 3);  // Décalage inverse
    }
    return _plain;
}

std::string Encrypt::read(const std::string& filename) {
    std::ifstream fichier(filename); // Ouverture du fichier
    if (!fichier) { // Vérifie si le fichier est ouvert correctement
        std::cerr << "Erreur d'ouverture du fichier: " << filename << std::endl;
        return ""; // Retourne une chaîne vide en cas d'erreur
    }

    std::stringstream buffer;
    buffer << fichier.rdbuf(); // Lit tout le contenu du fichier dans le buffer
    return buffer.str(); // Retourne le contenu du fichier sous forme de string
}
void Encrypt::write(std::string filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << _cipher;  // On écrit le texte chiffré dans le fichier
        file.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier pour l'écriture." << std::endl;
    }
}

