#pragma once


#include <vector>
#include <gmp.h>
#include <gmpxx.h>


namespace rsa {

	void ext_euclidean_algorithm(const mpz_class& a, const mpz_class& b, mpz_class& x, mpz_class& y, mpz_class& gcd);

    mpz_class encrypt_message(mpz_class message, mpz_class public_key, mpz_class mod);

	class User {
    private:
        mpz_class n;
        mpz_class fi_n;
        mpz_class e;
        mpz_class d;

    public:
        User(unsigned bits_size);

        std::vector<mpz_class> share_my_public_key();


        mpz_class decript_message(mpz_class message);
	};

}