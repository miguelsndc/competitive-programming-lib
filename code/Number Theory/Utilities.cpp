// O(sqrt(n))
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

// O(log(min(a, b)))
ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

// O(log(min(a, b)));
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}