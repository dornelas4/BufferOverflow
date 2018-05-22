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
    char pw1[16] = {0}; //password entered by user
    char pw2[16] = {0};
    char hash3[33] = {0};
    char hash2[33] = {0};
    char hash1hex[65]={0}; 
    char hash1[33] = {0}; 
    char hash3hex[65] = {0};
    char hash2hex[65] = {0};
    char target2[] = "0765878acf13afd84fa5aa2496bfb8d9439540cdd43a65d413d3d7ea79f728f0";
    char target3[] = "aa13f7abce753583299968247f0893c290a879459a52ef3a7fadfd886da38e34";
    char target1[] = "da698b0dbb1e59d0187f06f0748aba1ee2e680f7ec7d16838c8ede498e76eca0";
    char pw3[16] = {0};
    char* hash_ptr;

    printf("userid: ");
    fgets(buffer, 1024, stdin);
    strcpy(userid,buffer);
       
    printf("password1: ");
    fgets(buffer, 1024, stdin);
    strcpy(pw1,buffer);

    printf("password2: ");
    fgets(buffer, 1024, stdin);  
    strcpy(pw2,buffer);    

    printf("password3: ");
    fgets(buffer, 1024, stdin); 
    strcpy(pw3,buffer);
    
    length = strlen(pw1)-1;
    if (length>16)
        length=16;
    SHA256(pw1, length, hash1);
    i = 0;   
    hash_ptr = hash1hex;
    for (i=0; i < 32; i++){
        hash_ptr += sprintf(hash_ptr,"%02hhx", hash1[i]);
    }
    hash1hex[64]=0;
    
    length = strlen(pw2)-1;
    if (length>16)
        length=16;
    SHA256(pw2, length, hash2);
    i = 0; 
    hash_ptr = hash2hex;
    for (i=0; i < 32; i++){
        hash_ptr += sprintf(hash_ptr,"%02hhx", hash2[i]);
    }
    hash2hex[64]=0;
    
    length = strlen(pw3)-1;
    if (length>16)
        length=16;    
    SHA256(pw3, length, hash3);
    i = 0;    
    hash_ptr = hash3hex;
    for (i=0; i < 32; i++){
        hash_ptr += sprintf(hash_ptr,"%02hhx", hash3[i]);
    }
    hash3hex[64]=0;
 
    if (strncmp(userid, targetuid,16)==0 &&
        strncmp(target1, hash1hex, 64)==0 &&
        strncmp(target2, hash2hex, 64)==0 &&
        strncmp(target3, hash3hex, 64)==0) {
        printf("access granted\n");
        FILE * fp;
        fp = fopen("/home/user38b/flagc","r");
        char str[50];
        fgets(str, 50, fp);
        printf("%s", str);
        fclose(fp);
    }
    else
        printf("authentication failed.\n");
}










