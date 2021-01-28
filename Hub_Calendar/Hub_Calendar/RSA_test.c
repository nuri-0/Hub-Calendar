#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
//#include <iostream>
//using namespace std;

int e, d, n;
int FindT(int a, int m, int n);
int FastExponention(int bit, int n, int* y, int* a);

int gcd(int a, int b)
{
    int q, r1, r2, r;

    if (a > b) {
        r1 = a;
        r2 = b;
    }
    else {
        r1 = b;
        r2 = a;
    }

    while (r2 > 0) {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
    }

    return r1;
}

int PrimarityTest(int a, int i)
{
    int n = i - 1;
    int k = 0;
    int j, m, T;

    while (n % 2 == 0) {
        k++;
        n = n / 2;
    }

    m = n;
    T = FindT(a, m, i);

    if (T == 1 || T == i - 1)
        return 1;

    for (j = 0; j < k; j++) {
        T = FindT(T, 2, i);
        if (T == 1)
            return 0;
        if (T == i - 1)
            return 1;
    }
    return 0;
}

int FindT(int a, int m, int n)
{
    int r;
    int y = 1;

    while (m > 0) {
        r = m % 2;
        FastExponention(r, n, &y, &a);
        m = m / 2;
    }
    return y;
}

int FastExponention(int bit, int n, int* y, int* a)
{
    if (bit == 1)
        *y = (*y * (*a)) % n;

    *a = (*a) * (*a) % n;

    return 0;
}

int inverse(int a, int b)
{
    int inv = 0;
    int q, r, r1 = a, r2 = b, t, t1 = 0, t2 = 1;

    while (r2 > 0) {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (r1 == 1)
        inv = t1;

    if (inv < 0)
        inv = inv + a;

    return inv;
}

int KeyGeneration()
{
    int p, q;
    int phi_n;

    do {
        do
            p = rand();
        while (p % 2 == 0);

    } while (!PrimarityTest(2, p));

    do {
        do
            q = rand();
        while (q % 2 == 0);
    } while (!PrimarityTest(2, q));

    n = p * q;
    phi_n = (p - 1) * (q - 1);

    do
        e = rand() % (phi_n - 2) + 2; // 1 < e < phi_n
    while (gcd(e, phi_n) != 1);

    d = inverse(phi_n, e);

    printf("e = %d, d = %d, n = %d\n", e, d, n);

    return 0;
}

int Encryption(int value, FILE* EncryptText)
{
    int cipher;
    cipher = FindT(value, e, n);
    printf("%d ", cipher);
    fprintf(EncryptText, "%d ", cipher);

    return 0;
}

int Decryption(int value)
{
    int decipher;
    decipher = FindT(value, d, n);
    printf("%c", decipher);
    //printf("%d ", decipher);

    return 0;
}

int main(void)
{
    FILE* planeText = fopen("plain.txt", "r");  // plain text
    FILE* EncryptText = fopen("RSA_encrypt.txt", "w+");
    unsigned long long eTime = 0, dTime = 0;

    KeyGeneration();

    for (int cycle = 1; cycle <= 1; cycle++) {

        printf("plane Text: ");
        fseek(planeText, 0L, SEEK_SET);

        while (1) {
            char ch = getc(planeText);
            if (ch == -1) break;
            printf("%c", ch);
        }

        fseek(planeText, 0L, SEEK_SET);
        fseek(EncryptText, 0L, SEEK_SET);

        printf("\nEncryption: ");
        while (1) {
            char ch = getc(planeText);
            if (ch == -1)
                break;
            int value = toascii(ch);
            Encryption(value, EncryptText);
        }

        fseek(EncryptText, 0L, SEEK_SET);

        printf("\nDecryption: ");
        while (1) {
            int cip;
            if (fscanf(EncryptText, "%d", &cip) == -1)
                break;
            Decryption(cip);
        }

    }
    return 0;
}