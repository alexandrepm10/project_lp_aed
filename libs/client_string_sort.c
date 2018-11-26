//
// Created by alexa on 22/11/2018.
//

#include "client_string_sort.h"

//
// Created by AndrÃ© Pinto on 19/10/18.
//

#include "client_string_sort.h"
#include "lib_util.h"
#include "stringsorting.h"

int clientLSDSORT() {
    int i,N=10,fixed_string_with=3;
    char * strings[] = {
            "dab",
            "add",
            "cab",
            "fad",
            "fee",
            "bad",
            "dad",
            "bee",
            "fed",
            "bed"
    };
    StringElementsArray a;
    createStringElementsArrayAndFill(&a, N, strings);

    printf("\n-----------------\nLSD Input List:\n");
    for (i = 0; i < N; i++)
        printf("\t%s\n",a.str[i]);

    lsd_sort(&a, fixed_string_with, CHAR_8BIT_RADIX);

    printf("\n-----------------\nLSD Sorted List:\n");
    for (i = 0; i < N; i++)
        printf("\t%s\n",a.str[i]);

    return 0;
}

int clientKEYCOUNT() {
    int i, N=20;
    char * strings[] = {
            "Anderson",
            "Brown",
            "Davis",
            "Garcia",
            "Harris",
            "Jackson",
            "Johnson",
            "Jones",
            "Martin",
            "Martinez",
            "Miller",
            "Moore",
            "Robinson",
            "Smith",
            "Taylor",
            "Thomas",
            "Thompson",
            "White",
            "Williams",
            "Wilson",
    };
    int keys[] = {2,3,3,4,1,3,4,3,1,2,2,1,2,4,3,4,4,2,3,4};

    StringKeyElementsArray a;
    createStringKeyElementsArrayAndFill(&a, N, strings, keys);

    printf("\n-----------------\nInput String-Key List:\n");
    for (i = 0; i < N; i++)
        printf("\t%s, %d\n",a.str[i],a.keys[i]);

    key_index_counting(&a, N, KEY_INDEX_RADIX);

    printf("\n-----------------\nSorted String-Key List:\n");
    for (i = 0; i < N; i++)
        printf("\t%s, %d\n",a.str[i],a.keys[i]);

    return 0;
}

int clienteMSDSORT_WHITHOUT_CUTOFF_example() {
    int i,N=14;
    StringElementsArray a;
    StringElementsArray aux; // aux Array
    char * strings[] = {
        "she",
        "sells",
        "seashells",
        "by",
        "the",
        "sea",
        "shore",
        "the",
        "shells",
        "she",
        "sells",
        "are",
        "surely",
        "seashells",
    };

    createStringElementsArrayAndFill(&a, N, strings);
    createStringElementsArray(&aux,N); // create aux array

    printf("Original List:\n");
    for (i = 0; i < N; i++)
        printf("\t%s, %d\n",a.str[i],a.len[i]);

    msd_sort_whithout_cutoff(&a, &aux, 0, N-1, 0, CHAR_8BIT_RADIX); // MSD sort

    printf("\n-------------\nMSD Sorted List Final:\n");
    for (i = 0; i < N; i++)
        printf("\t%s, %d\n",a.str[i],a.len[i]);

    freeStringElementsArray(&a);
    freeStringElementsArray(&aux);
    return 0;
}

char ** clienteMSDSORT_WHITHOUT_CUTOFF(char **strings, int N) {
    int i;
    StringElementsArray a;
    StringElementsArray aux; // aux Array

    createStringElementsArrayAndFill(&a, N, strings);
    createStringElementsArray(&aux,N); // create aux array

//    printf("Original List:\n");
//    for (i = 0; i < N; i++)
//        printf("\t%s, %d\n",a.str[i],a.len[i]);

    msd_sort_whithout_cutoff(&a, &aux, 0, N-1, 0, CHAR_8BIT_RADIX); // MSD sort

//    printf("\n-------------\nMSD Sorted List Final:\n");
    for (i = 0; i < N; i++) {
//        printf("\t%s, %d\n", a.str[i], a.len[i]);
        *(strings+i)=(a.str[i]);
    }
    freeStringElementsArray(&a);
    freeStringElementsArray(&aux);

    return strings;
}