#include <iostream>
#include "primes_and_pow.hpp"
#include "diffie-hellman.hpp"
#include "aes.hpp"
#include "rsa.hpp"


# define BITS 1024


int main() {


    rsa::User stepa(BITS);
    mpz_class message;
    auto key = stepa.share_my_public_key();
    std::cout << "->public key:\n" << key[0] << "\nand\n" << key[1] << '\n';

    std::cout << "\n->enter your message:\t";
    std::cin >> message;

    auto encrypt = rsa::encrypt_message(message, key[0], key[1]);
    std::cout << "\n->encrypted message:\n" << encrypt;

    std::cout << "\n\n->decrypted message:\t" << stepa.decript_message(encrypt) << '\n';

    return 0;
}
