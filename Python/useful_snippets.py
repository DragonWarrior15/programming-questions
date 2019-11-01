# intersection of sets
    char1 = set(names[0])
    char2 = set(names[1])
    common = set.intersection(char1, char2)
    rem_x = len([x for x in names[0] if x not in common]) + \
            len([x for x in names[1] if x not in common])

long long fast_exponentiation(long long base, long long exponent){
    if(exponent == 0){
        return 1;
    }
    long long result = base, multiplier = 1; exponent--;
    while(exponent > 0){
        if(exponent%2 == 1){
            multiplier *= base; multiplier %= divide_by;
            exponent -= 1;
        }else{
            result *= result; result %= divide_by;
            exponent /= 2;
        }
    }
    return (result * multiplier)%divide_by;
}


# binary exponentiation
int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}

# gcd
int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
# useful for solving several equations
Ax + By = gcd(A, B)
int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
# useful for calculatin A**-1 % B
int d,x,y;
int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}


# primality testing
void checkprime(int N) {
        int count = 0;
        for( int i = 1;i * i <=N;++i ) {
             if( N % i == 0) {
                 if( i * i == N )
                         count++;
                 else       // i < sqrt(N) and (N / i) > sqrt(N)
                         count += 2;
              }
        }
        if(count == 2)
            cout << N << “ is a prime number.” << endl;
        else
            cout << N << “ is not a prime number.” << endl;
    }

# factorization in sqrt(n)
vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

This method of iterating over all subsets of some set using indicator vector is a super handy method and it is important to remember and master it. The idea is pretty simple, since there are 
2**n subsets of a set of n elements, each integer in a range [0, 2**n]
represents an indicator vector of one such subset when this integer is interpreted as a binary number.