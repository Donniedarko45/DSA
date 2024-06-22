#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
} Term;

// Function to create a new term
Term* createTerm(int coeff, int exp) {
    Term *newTerm = (Term*)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into the polynomial
void insertTerm(Term **poly, int coeff, int exp) {
    Term *newTerm = createTerm(coeff, exp);

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term *current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(Term *poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Term *poly = NULL;

    // Insert some terms into the polynomial
    insertTerm(&poly, 3, 2);
    insertTerm(&poly, -2, 1);
    insertTerm(&poly, 5, 0);

    // Display the polynomial
    displayPolynomial(poly);

    return 0;
}

