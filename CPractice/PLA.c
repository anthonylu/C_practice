//
//  PLA.c
//  CPractice
//
//  Perceptron learning algorithm
//
//  Created by ChangChun Lu on 4/6/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "PLA.h"

void printPLANode(PLANode* n) {
    int i;
    while (n != NULL) {
        for (i = 0; i < n->vector->dim; ++i)
            printf("%lf ", n->vector->elem[i]);
        printf("%d\n",n->label);
        n = n->next;
    }
}

void freePLANode(PLANode* n) {
    freeVector(n->vector);
    free(n);
}

void clearAll(Vector* w, PLANode* head) {
    PLANode *n;
    
    freeVector(w);
    while (head != NULL) {
        n = head;
        head = head->next;
        freePLANode(n);
    }
}

int adjustWeight(PLANode* n, Vector* w, double alpha, int rounds, int isAdjust) {
    PLANode* head = n;
    int sign, isWeightUpdated = 0, count = 0, totalUpdate = 1;
    
    while (n != NULL) {
        if (count >= rounds) break;
        sign = dotProduct(n->vector, w)>=0?1:-1;
        if (sign != n->label) {
            ++isWeightUpdated;
            if (isAdjust)
                vectorAddWithScalar(w, n->vector, 1.0, n->label*alpha);
        }
        
        if (n->next == NULL) {
            ++count;
            n = head;
            if (isWeightUpdated > 0) {
                totalUpdate += isWeightUpdated;
                isWeightUpdated = 0;
            } else break;
        } else
            n = n->next;
    }
    //printf("Total rounds: %d\nWeight: ", count);
    //printVector(w);
    
    return totalUpdate;
}

Vector* createWeight(PLANode* head) {
    return duplicateVector(head->vector);
}

PLANode* createNode(FILE *fp, int dim) {
    PLANode* n = malloc(sizeof(PLANode));
    n->vector = getVectorInstance(dim);
    
    int i;
    n->vector->elem[0] = 1.0;
    for (i = 1; i < dim; ++i) {
        if (fscanf(fp, "%lf", n->vector->elem+i) == EOF)
            return NULL;
    }
    if (fscanf(fp, "%d", &n->label) == EOF)
        return NULL;
    n->next = NULL;

    return n;
}

PLANode* parseFile(FILE *fp, int dim) {
    PLANode *n = createNode(fp, dim), *head;
    head = n;
    while (!feof(fp)) {
        n->next = createNode(fp, dim);
        n = n->next;
    }
    //printPLANode(head);
    
    return head;
}

int pla(int dimension, FILE *fp) {
    int result = -1;
    PLANode* head = parseFile(fp, dimension);
    if (head == NULL) {
        printf("No data read\n");
        return result;
    }
    
    Vector* weight = createWeight(head);
    int totalUpdate = adjustWeight(head, weight, 1.0, 150, 1);
    printf("Total updates: %d\n",totalUpdate);
    clearAll(weight, head);
    
    return result;
}

// Fisher-Yates shuffle
void shuffle(PLANode** nodes, int size) {
    int i = 0, idx = 0;
    PLANode* tmp;
    srand((unsigned int) time(NULL));
    
    for (i = size-1; i > 0; --i) {
        idx = rand()%(i+1);
        tmp = nodes[i];
        nodes[i] = nodes[idx];
        nodes[idx] = tmp;
    }
}

PLANode* shufflePLANode(PLANode* head) {
    PLANode* tmp = head;
    int size = 0;
    
    // get size
    while (tmp != NULL) {
        tmp = tmp->next;
        ++size;
    }
    // shuffle nodes
    PLANode *nodes[size];
    int i = 0;
    for (i = 0, tmp = head; i < size; ++i) {
        nodes[i] = tmp;
        tmp = tmp->next;
    }
    shuffle(nodes, size);
    /*for (i = 0; i < size; ++i)
        printf("%d ", seq[i]);
    printf("\n");*/
    // shuffle nodes
    for (i = 0; i < size-1; ++i) {
        nodes[i]->next = nodes[i+1];
    }
    nodes[i]->next = NULL;
    //printPLANode(nodes[0]);
    //printf("\n");
    
    return nodes[0];
}

int randomPLA(int dimension, FILE *fp, int rounds, double alpha) {
    int result = -1, totalUpdate = 0, i = rounds;
    PLANode* head = parseFile(fp, dimension);
    if (head == NULL) {
        printf("No data read\n");
        return result;
    }
    
    Vector* weight = NULL;
    while (i > 0) {
        --i;
        if (weight != NULL) freeVector(weight);
        head = shufflePLANode(head);
        weight = createWeight(head);
        totalUpdate += adjustWeight(head, weight, alpha, 150, 1);
    }
    printf("Total updates: %d\n",totalUpdate/rounds);
    clearAll(weight, head);
    
    return result;
}

int adjustWeightWithPocket(PLANode* n, Vector* w, double alpha, int rounds, int isPocket) {
    PLANode* head = n;
    Vector* pocketWeight = duplicateVector(w);
    int sign, isWeightUpdated = 0, count = 0, totalUpdate = 1, update4new, update4old;
    
    update4old = adjustWeight(head, w, alpha, 1, 0);
    while (n != NULL) {
        if (count >= rounds) break;
        sign = dotProduct(n->vector, w)>=0?1:-1;
        if (sign != n->label) {
            ++isWeightUpdated;
            vectorAddWithScalar(w, n->vector, 1.0, n->label*alpha);
            update4new = adjustWeight(head, w, alpha, 1, 0);
            if (update4new < update4old) {
                update4old = update4new;
                replaceByVector(pocketWeight, w);
            }
            if (isWeightUpdated >= rounds-totalUpdate) break;
        }
        
        if (n->next == NULL) {
            ++count;
            n = head;
            if (isWeightUpdated > 0) {
                totalUpdate += isWeightUpdated;
                isWeightUpdated = 0;
            } else break;
        } else
            n = n->next;
    }
    if (isPocket)
        replaceByVector(w, pocketWeight);
    freeVector(pocketWeight);
    //printf("Total rounds: %d\nWeight: ", count);
    //printVector(w);
    
    return totalUpdate;
}

int pocketPla(int dimension, FILE *ftrain, FILE *ftest, int rounds, int updates, double alpha, int isPocket) {
    int result = -1, totalUpdate = 0, i = rounds;
    PLANode* head = parseFile(ftrain, dimension);
    PLANode* test = parseFile(ftest, dimension);
    if (head == NULL || test == NULL) {
        printf("No data read\n");
        return result;
    }
    
    Vector* weight = NULL;
    while (i > 0) {
        --i;
        if (weight != NULL) freeVector(weight);
        head = shufflePLANode(head);
        weight = createWeight(head);
        adjustWeightWithPocket(head, weight, alpha, updates, isPocket);
        totalUpdate += adjustWeight(test, weight, alpha, 1, 0);
    }
    printf("Total updates: %lf\n",(double)totalUpdate/(rounds*500));
    clearAll(weight, head);
    
    return result;
}

int pla_main(int argc, const char * argv[]) {
    int dim = atoi(argv[1])+1, repeat = atoi(argv[3]);
    FILE *file = fopen(argv[2],"r");
    FILE *ftrain = fopen(argv[4], "r");
    FILE *ftest = fopen(argv[5], "r");
    
    if (file != NULL) {
        pla(dim, file);
        rewind(file);
        randomPLA(dim, file, repeat, 1.0);
        rewind(file);
         randomPLA(dim, file, repeat, 0.5);
        pocketPla(dim, ftrain, ftest, 200, 50, 1.0, 1);
        rewind(ftrain);
        rewind(ftest);
        pocketPla(dim, ftrain, ftest, 200, 50, 1.0, 0);
        rewind(ftrain);
        rewind(ftest);
        pocketPla(dim, ftrain, ftest, 200, 100, 1.0, 1);
    } else {
        // get current working directory
        char cwd[1024];
        getcwd(cwd,sizeof(cwd));
        printf("File is not found. %s", cwd);
    }
    fclose(file);
    fclose(ftrain);
    fclose(ftest);
    return 0;
}