// Q1
void get_string(char **p_str, int *sz)
{
    printf("Enter the number of characters in the string: ");
    scanf("%d", sz);
    *p_str = (char *)malloc(*sz * (sizeof(char)+1));
    for (int i = 0; i < *sz; i++){
        printf("Enter character %d: ", i);
        scanf(" %c", &(*p_str)[i]);
    }
    (*p_str)[*sz] = '\0';
}



int main()
{
    char *my_str;
    int sz;
    get_string(&my_str, &sz);
    printf("%s", my_str);
    free(my_str);
}




// Q2
char *my_strcat(char *dest, char *src)
{
    // concatenate src to dest
    // assume there is enough space in dest for dest + src + the trailing NULL
    int i = 0;
    while (dest[i] != '\0'){
        i++;
    }
    int j = 0;
    while (src[j] != '\0'){
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}


void my_strcat2(char *dest, char *src)
{
    while(*dest){
        dest++;
    }

    do{
      *dest = *src;
      dest++;
      src++;
    } while(*src);
}


// Q3

int strcmp_rec(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0'){
        return 0;
    }
    if (*s1 == '\0'){
        return -1;
    }
    if (*s2 == '\0'){
        return 1;
    }
    if (*s1 < *s2){
        return -1;
    }
    if (*s1 > *s2){
        return 1;
    }
    return strcmp_rec(s1+1, s2+1);
}

// s1 == s2 is true iff s1 and s2 are the same address. It would be false for strings that happen to have the same contents, but are stored in different place
// *s1 == *s2 is true iff the first characters of s1 and s2 are the same. s1 and s2 could be different in terms of everything but the first character, and *s1==*s2 would still be true
// strcmp(s1, s2) is 0 if s1 and s2 have the same contents and nonzero otherwise. s1 and s2 could be stored at different addresses but still can have the same contents


