/*
    Calcula N escolhe K mod P
*/

ll fact[1000000]; // Pré computar fatoriais
ll comb(ll n, ll k, ll p) {
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}