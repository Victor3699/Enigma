#include "Encrypt.hpp"
#include "EncrypteCesar.hpp"
#include "package.hpp"


CaesarEncrypt::CaesarEncrypt(int shift) : _shift(shift) {
        _plain = "";
        _cipher = "";
}

std::string CaesarEncrypt::encode(std::string plain) {
    _plain = plain;
    _cipher.clear();
    for (char c : plain) {
        _cipher += (c + _shift);  // Décalage de 3 caractères
    }
    return _cipher;
}

std::string CaesarEncrypt::decode(std::string cipher) {
    _cipher = cipher;
    _plain.clear();
    for (char c : cipher) {
        _plain += (c - _shift);  // Décalage inverse
    }
    return _plain;
}

std::string CaesarEncrypt::breakCesar(std::string cipher) {
    _cipher = cipher;
    _plain.clear();
    
    // Trouver le décalage basé sur la lettre la plus fréquente
    std::map<char, int> liste_occurence;
    for (char c : cipher) {
        liste_occurence[c]++;
    }
    
    // Identifier le caractère le plus fréquent (en supposant que c'est un espace ' ')
    char most_frequent = std::max_element(
        liste_occurence.begin(),
        liste_occurence.end(),
        [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second < b.second;
        }
    )->first;

    // Calculer le décalage en supposant que le caractère le plus fréquent est un espace ' '
    int shift = most_frequent - ' ';

    // Appliquer le décalage inverse à tous les caractères du texte chiffré
    for (char c : cipher) {
        _plain += (c - shift); // Décalage inverse appliqué à tout caractère
    }
    
    return _plain;
}
