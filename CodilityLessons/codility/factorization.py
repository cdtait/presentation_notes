def arrayF(n):
    F = [0] * (n + 1)
    i=2
    while (i * i <= n):
        if (F[i] == 0):
            k=i * i
            while (k <= n):
                if (F[k] == 0):
                    F[k] = i;
                k += i
        i += 1
    return F

def factorization(x, F):
    primeFactors = []
    while (F[int(x)] > 0):
        primeFactors += [F[int(x)]]
        x /= F[int(x)]
    primeFactors += [int(x)]
    return primeFactors

if __name__ == '__main__':
    F = arrayF(66)
    print(F)
    primeFactors = factorization(15, F)
    print(primeFactors)
