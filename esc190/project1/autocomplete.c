#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpterms(const void* term1, const void* term2){
    term* t1 = (term*)term1;
    term* t2 = (term*)term2;
    return strcmp(t1->term, t2->term);
}

int cmpweight(const void* term1, const void* term2){
    term* t1 = (term*)term1;
    term* t2 = (term*)term2;
    int weight1 = (int)t1->weight;
    int weight2 = (int)t2->weight;
    return (weight2 - weight1);
}

void read_in_terms(term** terms, int* pnterms, char* filename){
    FILE* fp = fopen(filename, "r");
    char line[200];
    if(!(fgets(line, sizeof(line), fp))) {
        return;
    };
    *pnterms = atoi(line); //first line is the number of terms in ther file, so we malloc that much
    if(*pnterms == 0){
        return;
    }
    *terms = (term*)malloc(sizeof(term) * (*pnterms));  //allocating memory
    char* token;  //this is what strtok returns (stuff before the token)

    for(int i = 0; i < (*pnterms); i++){ //increments through each line
        fgets(line, sizeof(line), fp);
        token = strtok(line, "\t");
        (*terms)[i].weight = atof(token);
        token = strtok(NULL, "\n");
        strcpy((*terms)[i].term, token);
    }
    /*for (int j = 0; j < *pnterms; j++) {
        printf("Number: %f\n", (*terms)[j].weight);
        printf("City: %s\n", (*terms)[j].term);
    }*/ //for testing
    
    qsort(*terms, *pnterms, sizeof(term), cmpterms);
    /*for (int j = 82640; j < 82821; j++) {
        printf("Number: %f\n", (*terms)[j].weight);
        printf("City: %s\n", (*terms)[j].term);
    }*/ //also testing
    fclose(fp);
}

int lowest_match(struct term *terms, int nterms, char *substr){
    int right = nterms - 1;
    int left = 0;
    int mid;
    int len = strlen(substr);
    while(left <= right){
        mid = (right + left) / 2;
        if(strncmp(terms[mid].term, substr, len) < 0){
            left = mid + 1;
            //printf("compared %s and %s, left is now: %d\n", terms[mid].term, substr, left);  //testing purposes
        }
        else{
            right = mid - 1;
            //printf("compared %s and %s, right is now: %d\n", terms[mid].term, substr, right);  //testing purposes
        }
    }
    //printf("%d\n", left);  //testing purposes
    return left;
}

int highest_match(struct term *terms, int nterms, char *substr){
    int right = nterms - 1;
    int left = 0;
    int mid;
    int len = strlen(substr);
    while(left <= right){
        mid = (right + left) / 2;
        if(strncmp(terms[mid].term, substr, len) > 0){
            right = mid - 1;
            //printf("compared %s and %s, right is now: %d\n", terms[mid].term, substr, right);   //testing purposes        
        }
        else{

            left = mid + 1;
            // printf("compared %s and %s, left is now: %d\n", terms[mid].term, substr, left); //testing purposes
        }
    }
    //printf("%d\n", right);  //testing purposes
    return right;
}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){
    int lowest = lowest_match(terms, nterms, substr);
    int highest = highest_match(terms, nterms, substr);
    *n_answer = highest - lowest + 1;
    *answer = (term*)malloc(sizeof(term) * (*n_answer)); //mallocating space
    for(int i = 0; i < *n_answer; i++){
        strcpy((*answer)[i].term, terms[i + lowest].term); //moves the term at lowest index in terms to first index of answer
        (*answer)[i].weight = terms[i + lowest].weight;
    }
    /*for (int j = 0; j < *n_answer; j++) {
        printf("Weight: %f,  City: %s\n", (*answer)[j].weight, (*answer)[j].term);
    }*/ //testing
    qsort(*answer, *n_answer, sizeof(term), cmpweight);
    /*for (int j = 0; j < *n_answer; j++) {
        printf("Weight: %f,  City: %s\n", (*answer)[j].weight, (*answer)[j].term);
    }*/ //testing
}