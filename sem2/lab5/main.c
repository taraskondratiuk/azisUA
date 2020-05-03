#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct List {
    struct Vector *head;
    struct Vector *tail;
};

struct Vector {
    double x, y, z;
    struct Vector *next;
};

struct Vector *createVector(double x, double y, double z) {
    struct Vector *temp = (struct Vector *) malloc(sizeof(struct Vector));
    temp->x = x;
    temp->y = y;
    temp->z = z;
    temp->next = NULL;
    return temp;
}

struct List *createList() {
    struct List *l = (struct List *) malloc(sizeof(struct List));
    l->head = l->tail = NULL;
    return l;
}


void printVector(struct Vector *v) {
    printf("[%f, %f, %f]", v->x, v->y, v->z);
}

int getLen(struct List *l) {
    int len = 0;
    if (l->head == NULL) {
        return len;
    } else {
        struct Vector *temp = l->head;
        do {
            len++;
            temp = temp->next;
        } while (temp != NULL);
    }
    return len;
}

void printList(struct List *l) {
    printf("\nlist: ");
    if (l->head == NULL) {
        return;
    }

    struct Vector *temp = l->head;
    do {
        printVector(temp);
        temp = temp->next;
    } while (temp != NULL);
}

void add(struct List *l, struct Vector *v) {
    if (l->head == NULL) {
        l->head = v;
        l->tail = v;
    } else {
        l->tail->next = v;
        l->tail = v;
    }
}


double getDotProduct(struct Vector *v1, struct Vector *v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

double getVectorLen(struct Vector *v) {
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

double getAngleBetweenVectors(struct Vector *v1, struct Vector *v2) {
    double cos = getDotProduct(v1, v2) / (getVectorLen(v1) * getVectorLen(v2));
    return acos(cos);
}

struct Vector *writeSum(struct Vector *v1, struct Vector *v2, struct Vector *res) {
    if (v1 == NULL || v2 == NULL) {
        return NULL;
    }
    res = createVector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
    return res;
}

struct Vector *writeProductOnScalar(struct Vector *v, double scalar, struct Vector *res) {
    if (v == NULL) {
        return NULL;
    }
    res = createVector(v->x * scalar, v->y * scalar, v->z * scalar);
    return res;
}


int main() {
    struct List *vectors = createList();

    FILE *f = fopen("../15v14.txt", "r");

    int bufferLength = 255;
    char buffer[bufferLength];
    for (int i = 0; i < 255; ++i) {
        buffer[i] = '\0';
    }
    while (fgets(buffer, bufferLength, f)) {
        double nums[3];
        int i = 0;
        char *num = strtok(buffer, " \n");

        while (num != NULL) {
            nums[i] = strtod(num, NULL);
            i++;
            num = strtok(NULL, " \n");
        }
        add(vectors, createVector(nums[0], nums[1], nums[2]));
    }
    printList(vectors);
    printf("\nlist len: %d", getLen(vectors));

    printf("\nfirst and last dot product: %f", getDotProduct(vectors->head, vectors->tail));

    return 0;
}