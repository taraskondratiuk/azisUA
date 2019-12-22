#include <stdio.h>

int main() {

    int p1, p2, p3, a16;

    printf("Enter P1 [0, 3] ");
    scanf("%i", &p1);

    printf("\nEnter P2 [0, 31] ");
    scanf("%i", &p2);

    printf("\nEnter P3 [0, 255] ");
    scanf("%i", &p3);

    a16 = p3;
    a16 = (p1 << 8) | a16;
    a16 = (p2 << 11) | a16;

    printf("\nA16 : %x", a16);

    printf("\nEnter A16 [0, 65536] ");
    scanf("%x", &a16);


    p2 = a16 >> 11;
    p1 = a16 >> 8 & 3;
    p3 = a16 & 255;


    switch (p1) {
        case (0):
            printf("\nP1 = 0");
            break;
        case (1):
            printf("\nP1 = 1");
            break;
        case (2):
            printf("\nP1 = 2");
            break;
        case (3):
            printf("\nP1 = 3");
            break;
    }

    printf(", P2 = %d, P3 = %d", p2, p3);

    return 0;
}