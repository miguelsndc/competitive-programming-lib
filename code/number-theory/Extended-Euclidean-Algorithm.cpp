/*
    Algoritmo Estendido de Euclides (Extended GCD)
    
    Complexidade: O(log(min(a, b)))

    Calcula os coeficientes x e y da equação diofantina:
        ax + by = gcd(a, b)
    
    Para resolver a equação ax + by = c, onde c é um valor dado:
    - Primeiro, é necessário que c % gcd(a, b) == 0.
    - Se sim, as soluções são:
        x *= c / gcd(a, b)
        y *= c / gcd(a, b)
    - Solução geral é
        x(t) = x0 + (b/gcd(a,b)) * t
        y(t) = y0 - (a/gcd(a,b)) * t
    
*/

int extendedGCD(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedGCD(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

