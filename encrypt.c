#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(int argc, char *argv[])
{
    int numArgs = argc-1;
    if (numArgs == 2)
    {
        char *msg = argv[2]; // the message to encrypt
        int msg_len = strlen(msg);
        int n = atoi(argv[1]); //shift value
        char enc[msg_len+1];
        enc[msg_len] = '\0'; //null terminate string
        for (int i = 0; i <msg_len; i++)
        {
            msg[i]=toupper(msg[i]);
        }
        for (int i = 0; i < msg_len; i++)
        {
            if (isalnum(msg[i]) && !(isdigit(msg[i])))
            {
                if (((msg[i])+n-65) < 0)
                {
                    enc[i] = (((msg[i])+n-65) + 26 + 65); // a mod b = a + b when |a| < b and a < 0
                }
                else
                {
                    enc[i] = (((msg[i])+n-65)%26 + 65); //enc[i] = (x+n)mod26 where x is the letter to be encrypted and n is the shift val
                }
            }
            else
            {
                enc[i]=msg[i];
            }
        }
        for (int i = 0; i  < msg_len; i++)
        {
            printf("%c", enc[i]);
        }
    }
    else
    {
        fprintf(stderr, "Wrong number of commandline arguments.");
        printf("\n");
        exit(1);
    }
    printf("\n");
}

