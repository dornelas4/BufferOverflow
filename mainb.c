#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/sha.h>

int main(int argc, char** argv) {
    int i; //for loop index
    int length; //length of string to hash./
    unsigned char buffer[1024] = {0};
    char userid[16] = {0};
    char targetuid[] = "user1\n";
    char pw[16] = {0}; //password entered by user    
    char hash[33] = {0}; //SHA256 hash of pw in bytes (32 bytes)
    char t[22] = {0};
    char hashhex[65] = {0}; //hash[] as a 64 long hex string
    char target[] = "c25884e9ff834aef05d18ceb87d924617c2c9b3101c5d6e8961e1b4b99ce447b";
    int v = 0;
    char* hash_ptr;
    
    printf("userid: ");   
    fgets(buffer, 1024, stdin);
    strcpy(userid, buffer);

    printf("password: ");
    fgets(buffer, 1024, stdin); 
    strcpy(pw, buffer);
    
    length = strlen(pw) - 1;
    if (length > 16)
        length = 16;
    SHA256(pw, length, hash);
    i = 0;   
    hash_ptr = hashhex;
    for (i = 0; i < 32; i++) {
        hash_ptr += sprintf(hash_ptr, "%02hhx", hash[i]);
    }
    hashhex[64] = 0;

    if (v==0 && strncmp(userid, targetuid, 16) == 0 &&
            strncmp(target, hashhex, 64) == 0) {
        printf("access granted\n");
        FILE * fp;
        fp = fopen("/home/user38b/flagb","r");
        char str[50];
        fgets(str, 50, fp);
        printf("%s", str);
        fclose(fp);
    }
    else
        printf("authentication failed.\n");
}
















































