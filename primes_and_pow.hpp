#pragma once


#include <gmp.h>
#include <gmpxx.h>


mpz_class pow_by_mod(mpz_class base, mpz_class power, mpz_class mod);

bool is_prime(const mpz_class& n);

mpz_class generate_prime(unsigned int bits);
