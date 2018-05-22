#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/sha.h>

int main(int argc, char** argv) {
    char *v[2];
    int i; //for loop index
    int length; //length of string to hash./
    unsigned char buffer[1024] = {0};
    char userid[16] = {0};
    char targetuid[] = "user1\n";
    char pw[16] = {0}; //password entered by user
    char hash[33] = {0}; //SHA256 hash of pw in bytes (32 bytes)
    char hashhex[65] = {0}; //hash[] as a 64 long hex string
    //pw: abcdefghi
    char target[] = "19cc02f26df43cc571bc9ed7b0c4d29224a3ec229529221725ef76d021c8326f";
    char* hash_ptr;
    printf("i addr: %p\n",(void *) &i);
    printf("len addr: %p\n",(void *) &length);

    printf("userid: ");
    fgets(buffer, 1024, stdin);
    printf("%s", buffer);
    printf("buffer: ");
    for (i=0; i < 32; i++)
       printf("%02hhx", buffer[i]);
    printf("\n");
    strcpy(userid, buffer);

    printf("password: ");
    fgets(buffer, 1024, stdin);
    printf("%s", buffer);
    printf("buffer: ");
    for (i=0; i < 32; i++)
        printf("%02hhx", buffer[i]);
    printf("\n");
    strcpy(pw, buffer);
        i=123;
        printf("i addr: %p\n",(void *) &i);
        printf("i contents: %08x\n", i);
        long *ptr= (long *) buffer;
        for (i=0; i<8; i++){
          printf("address %p is %08x\n",
                     (void *) (ptr+i),
                   (unsigned int) (*(ptr+i)));
        }

    length = strlen(pw) - 1;
    if (length > 16)
        length = 16;
    SHA256(pw, length, hash);
    i = 0;
    //    printf("pw1: ");
    //    for (i=0; i < 16; i++)
    //        printf("%02hhx", pw1[i]);
    //    printf("\n");
    //    printf("hash1: ");
    //    for (i=0; i < 32; i++)
    //        printf("%02hhx", hash1[i]);
    //    printf("\n");
    hash_ptr = hashhex;
    for (i = 0; i < 32; i++) {
        hash_ptr += sprintf(hash_ptr, "%02hhx", hash[i]);
    }
    hashhex[64] = 0;
    //printf("target: %s\n", target);
    //printf("hashhex:  %s\n", hashhex);

    if (strncmp(userid, targetuid, 16) == 0 &&
            strncmp(target, hashhex, 64) == 0) {
        printf("access granted\n");
        FILE * fp;
        fp = fopen("/home/user2/flag", "r");
        char str[50];
        fgets(str, 50, fp);
        printf("%s", str);
        fclose(fp);
    }
    else
        printf("authentication failed.\n");
        
}
