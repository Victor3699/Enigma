#include "Encrypt.hpp"

// Implémentation de CaesarEncrypt

std::string Encrypt::get_plain() {
    return _plain;
}

std::string Encrypt::get_cipher() {
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

// Lecture d'un fichier entier dans _plain
void Encrypt::read(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();  // Lit tout le contenu du fichier
        _plain = buffer.str();   // Stocke le contenu dans _plain
        file.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier pour la lecture." << std::endl;
    }
}

// Écriture dans un fichier (création du fichier s'il n'existe pas)
void Encrypt::write(std::string filename) {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);  // Crée le fichier s'il n'existe pas, écrase s'il existe
    if (file.is_open()) {
        file << _cipher;  // Écrit le texte chiffré dans le fichier
        file.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier pour l'écriture." << std::endl;
    }
}
