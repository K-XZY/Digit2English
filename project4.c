#include <stdio.h>
#include <string.h>

int main()
{
    // create a vocabulary for English numbers
    char d0[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char d1[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                       "seventeen", "eighteen", "nineteen"};
    char d2[10][10] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char d3[10][10] = {"hundred", "thousand", "million", "billion", "trillion"};
    char de[10][10] = {"and", "negative"};

    // accept inputs from users
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // check positivity
    int is_negative = 0;
    if (number < 0)
    {
        number = -number;
        is_negative = 1;
    }

    // convert the input into strings
    char str_number[100];
    sprintf(str_number, "%d", number); // sprintf is used to convert int to string
    // turn the string into a multiple of 3
    int len = strlen(str_number);
    int extra_len = (3 - len % 3) % 3;
    printf("extra_len needed : %d\n", extra_len);
    char new_str[1000] = "";
    for (int i = 0; i < extra_len; i++)
    {
        strcat(new_str, "0");
    }
    strcat(new_str, str_number);
    printf("new_str : %s\n", new_str);

    // break the string into triplets
    int new_len = strlen(new_str);
    int triplet_count = new_len / 3;
    char triplets[1000][400];
    for (int i = 0; i < triplet_count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            triplets[i][j] = new_str[i * 3 + j];
        }
    }
    // display the triplets for verification
    for (int i = 0; i < triplet_count; i++)
    {
        printf("{ %s } ", triplets[i]);
    }
    printf("\n");

    // convert the triplets into words by going through each triplet
    char words[10000] = "";
    if (is_negative)
        printf("%s ", de[1]);
    for (int i = 0; i < triplet_count; i++)
    {
        char triplet[200];
        strcpy(triplet, triplets[i]);
        int triplet_len = strlen(triplet);
        // convert the triplet into words
        char word[1000] = "";
        if (triplet[0] != '0')
        {
            printf("%s ", d0[triplet[0] - '0']);
            printf("%s ", d3[0]);
        }
        if (triplet[1] != '0')
        {
            if (triplet[1] == '1')
            {
                printf("%s ", d1[triplet[2] - '0']);
            }
            else if (triplet[1] > '1')
            {
                printf("%s ", d2[triplet[1] - '2']);
                if (triplet[2] != '0')
                {
                    printf("%s ", d0[triplet[2] - '0']);
                }
            }
        }
        else if (triplet[2] != '0')
        {
            if (triplet[1] != '0')
            {
                // printf("%s ", "and");
            }
            printf("%s ", d0[triplet[2] - '0']);
        }
        // print the magnitude of the triplet
        if (triplet[0] + triplet[1] + triplet[2] != '0' + '0' + '0' && triplet_count - i - 1 != 0)
            printf("%s ", d3[triplet_count - i - 1]);
    }
}