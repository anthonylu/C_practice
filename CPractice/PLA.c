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
#include "PLA.h"

void freePLANode(PLANode* n) {
    freeVector(n->vector);
    free(n);
}

void adjustWeight(PLANode* n, Vector* w) {
    PLANode* head = n;
    int sign, isWeightChanged = 0, count = 0;
    
    while (n != NULL && count < 150000) {
        sign = dotProduct(n->vector, w)>=0?1:-1;
        if (sign != n->label) {
            isWeightChanged = 1;
            if (n->label == 1)
                vectorAdd(w, n->vector);
            else if (n->label == -1)
                vectorSub(w, n->vector);
            else printf("wrong label");
        }
        
        if (n->next == NULL && isWeightChanged) {
            ++count;
            n = head;
            isWeightChanged = 0;
        } else
            n = n->next;
    }
    printf("Total rounds: %d\nWeight: ", count);
    printVector(w);
    // clean all
    freeVector(w);
    while (head != NULL) {
        freePLANode(head);
        head = head->next;
    }
}

Vector* createWeight(PLANode* head) {
    return duplicateVector(head->vector);
}

PLANode* createNode(FILE *fp, int dim) {
    PLANode* n = malloc(sizeof(PLANode));
    n->vector = getVectorInstance(dim);
    
    int i;
    for (i = 0; i < dim; ++i) {
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
    
    /*n = head;
    while (n != NULL) {
        int i;
        for (i = 0; i < dim; ++i) {
            printf("%lf ", n->vector->elem[i]);
        }
        printf("%d\n",n->label);
        n = n->next;
    }*/
    
    return head;
}

int pla(int dimension, FILE *fp) {
    int result = -1;
    PLANode* head = parseFile(fp, dimension);
    Vector* weight = createWeight(head);
    adjustWeight(head, weight);
    
    return result;
}

int pla_main(int argc, const char * argv[]) {
    int dim = atoi(argv[1]);
    FILE *file = fopen(argv[2],"r");
    
    if (file != NULL) {
        pla(dim, file);
    } else {
        // get current working directory
        char cwd[1024];
        getcwd(cwd,sizeof(cwd));
        printf("File is not found. %s", cwd);
    }
    fclose(file);
    return 0;
}