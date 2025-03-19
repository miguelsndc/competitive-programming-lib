/*
Calcula o Inverso Modular de um número `a` mod `p`
pelo pequeno teorema de fermat.
*/

ll inv(ll a, ll p){ 
    return fexp(a, p - 2);
}

