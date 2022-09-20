//Dgthhaivu 9/20/2022

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* original_decrypt(char* code) {
    int hash = ((strlen(code) - 3) / 3) + 2;
    char* decrypt = malloc(hash);
    char* toFree = decrypt;
    char* word = code;
    for (int ch = *code; ch != '\0'; ch = *(++code))
    {
        if((code - word + 2) % 3  == 1){
            *(decrypt++) = ch - (word - code + 1) - hash;
        }
    }
    *decrypt = '\0';
    return toFree;
}

char* decrypt(char* code) {
    int length = strlen(code) / 3 + 1;
    char* decrypt = malloc(length);

    int d = 0;
    for (int c = 2; c < strlen(code); c+=3)
    {
        decrypt[d++] = code[c] + c - length - 1;
    }

    decrypt[d] = '\0';
    return decrypt;
}
    
char *encrypt(char* decrypt) {
    int length = strlen(decrypt) + 1;
    char* code = malloc(length * 3);
    
    int c = -1;
    for (int d = 0; d < length; d++)
    {
        code[++c] = '*'; // or rand()%94+33;
        code[++c] = '*'; // or rand()%94+33;
        code[++c] = decrypt[d] - c + length + 1;
    }

    code[c] = '\0';
    return code;
}

char values[10][256] = 
{"N~mqOlJ^tZletXodeYgs"
,"gCnDIfFQe^CdP^^B{hZpeLA^hv"
,"7urtrtwQv{dt`>^}FaR]i]XUug^GI"
,"aSwfXsxOsWAlXScVQmjAWJG"
,"cruD=idduvUdr=gmcauCmg]"
,"BQt`zncypFVjvIaTl]u=_?Aa}F"
,"iLvkKdT`yu~mWj[^gcO|"
,"jSiLyzJ=vPmnv^`N]^>ViAC^z_"
,"xo|RqqhO|nNstjmzfiuoiFfhwtdh~"
,"OHkttvxdp|[nnW]Drgaomdq"
};
                                
int main()
{
    for(int i=0;i<10; i++)
    {
        char *decrypted = decrypt(values[i]);
        char *encrypted = encrypt(decrypted);
        printf("%-30s %-10s %-30s\n",values[i],decrypted,encrypted);
        free(decrypted);
        free(encrypted);
    }
    return 0;
}