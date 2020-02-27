#include <stdio.h>
#include <stdlib.h>
#define len 29  //as 29 bytes*8 gives 232 bits



int main()
{  FILE *randfile, *outfile;
    int i;
    unsigned char next;
    randfile =fopen("/dev/urandom","r"); //if the operating system is linux
    //generating random keys
     int length;
    char str[] = "0123456789ABCDEF";

    srand((unsigned int) time(0) + getpid());
    length = rand() % 15 + 48;
unsigned char temp;
    while(length--) {

        putchar(str[rand() % 16]);
         srand(rand());
 //       outfile = fopen("key.txt","w");
   //     fprintf(outfile,"%02X", temp);

    }
    printf("\n");
    //trying to write console output to key.txt file but it doesn't work :((



    outfile = fopen("key.txt","w");
    if( (randfile==NULL)|| (outfile==NULL)){
        printf("file error \n");
        return;
    }
    for(i=0;i<len;i++){
        fscanf(randfile,"%c",&next);
        fprintf(outfile,"%02X",next);

    }
    fclose(randfile);
    fclose(outfile);

    FILE *keyfile, *plaintextfile, *ciphertextfile;
    unsigned char c1;
    char c2;
    keyfile = fopen("key.txt","r");
    plaintextfile = fopen("plaintextfile.txt","w");
    ciphertextfile = fopen("ciphertextfile.txt","r");

    if( (keyfile==NULL)|| (ciphertextfile==NULL)){
        printf("file error \n");
        return;
    }
//  int i;
    for(i=0;i<len;i++){
        fscanf(keyfile,"%2hhX",&c1);
        fscanf(ciphertextfile,"%c",&c2);
       //c1=0xAEDE0273C4C0DA3477F919018A05DA71A2530F5A0020E4E0ACA80FF2DE;
       //c2=0xA8C80426C2DEC16D31F90D1497129475A45447561D74EEF1B8BF0FFCDC;
        fprintf(plaintextfile,"%02X", c1^c2);
    }
    //CONVERT EL HEXADECIMAL TO ASCII STRING.....
    fclose(keyfile);
    fclose(plaintextfile);
    fclose(ciphertextfile);

    return 0;
}
