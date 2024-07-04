#include "autocomplete.c"

int main(void)
{
    struct term *terms;
    int nterms;
    read_in_terms(&terms, &nterms, "C:\\Users\\lcxbr\\Desktop\\EngSci\\1W\\ESC190\\Projects\\Project 1\\cities.txt");
    printf("%d\n", lowest_match(terms, nterms, "Tor"));
    printf("%d\n", highest_match(terms, nterms, "Tor"));

    lowest_match(terms, nterms, "'s");
    highest_match(terms, nterms, "'s");
    
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    printf(answer[0].term);
    //free allocated blocks here -- not required for the project, but good practice
    return 0;
}

