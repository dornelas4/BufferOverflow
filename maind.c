#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/sha.h>

int main(int argc, char** argv) {
    int i; //for loop index
    void * p;
    int length; //length of string to hash./
    unsigned char buffer[1024] = {0};
    char userid[16] = {0};
    char targetuid[] = "user1\n";
    char pw1[16] = {0}; //password entered by user
    short v1=6628;
    char hash2[33] = {0};
    char pw2[16] = {0};
    char hash3[33] = {0};
    short v2=6348;
    char target1[] = "a2c0d8de990ef812e79d75e96d37f9556fd71a59f8e2ff7eb6865d412c4ddfcc";
    char hash2hex[65] = {0};
    char hash1[33] = {0}; 
    char hash1hex[65]={0}; 
    char hash3hex[65] = {0};
    char target2[] = "27fd7273e471fe5a0eef0fcb5e366fd22a880ec53a30fad0f0cf9b31a0ebb7e2";
    char target3[] = "7c9587b1172a5e66a5c127347cc729b094a8a59a754090180a36efdf9f699cc2";
    short v3=3047;
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
    
    // force allocation of variables v1, v2 and v3
    p=(void *) &v1;
    p=(void *) &v2;
    p=(void *) &v3;
    
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
 
    if (v1==6628 && v2==6348 && v3==3047 &&
        strncmp(userid, targetuid,16)==0 &&
        strncmp(target1, hash1hex, 64)==0 &&
        strncmp(target2, hash2hex, 64)==0 &&
        strncmp(target3, hash3hex, 64)==0) {
        printf("access granted\n");
        FILE * fp;
        fp = fopen("/home/user38b/flagd","r");
        char str[50];
        fgets(str, 50, fp);
        printf("%s", str);
        fclose(fp);
    }
    else
        printf("authentication failed.\n");
}
