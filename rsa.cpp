#include <vector>
#include "primes_and_pow.hpp"
#include "rsa.hpp"


namespace rsa {

    void ext_euclidean_algorithm(const mpz_class& a, const mpz_class& b, mpz_class& x, mpz_class& y, mpz_class& gcd) {
        mpz_class r0, r1, r2;
        mpz_class x0, x1, x2;
        mpz_class y0, y1, y2;
        mpz_class q;

        if (a > b) {
            r0 = a;
            r1 = b;
        }
        else {
            r1 = a;
            r0 = b;
        }

        x0 = 1;
        x1 = 0;
        y0 = 0;
        y1 = 1;

        while (r1 != 0) {
            q = r0 / r1;
            r2 = r0 - q * r1;
            x2 = x0 - q * x1;
            y2 = y0 - q * y1;

            r0 = r1;
            r1 = r2;
            x0 = x1;
            x1 = x2;
            y0 = y1;
            y1 = y2;

        }
        gcd = r0;

        if (a > b) {
            x = x0;
            y = y0;
        }
        else {
            x = y0;
            y = x0;
        }

    }

    mpz_class encrypt_message(mpz_class message, mpz_class public_key, mpz_class mod) {
        return pow_by_mod(message, public_key, mod);
    }

    User::User(unsigned bits_size) {
        mpz_class p = generate_prime(bits_size);
        mpz_class q = generate_prime(bits_size);
        while (p == q)
            q = generate_prime(bits_size);

        n = p * q;
        fi_n = (p - 1) * (q - 1);

        e = generate_prime(bits_size / 2);
        mpz_class k;
        mpz_class gcd;

        ext_euclidean_algorithm(e, fi_n, d, k, gcd);

        if (d < 0) {
            d = d % (fi_n)+(fi_n);
        }
    }

    std::vector<mpz_class> User::share_my_public_key() {
        std::vector<mpz_class> key;
        key.push_back(e);
        key.push_back(n);
        return key;
    }

    mpz_class User::decript_message(mpz_class message) {
        return pow_by_mod(message, d, n);
    }
}


