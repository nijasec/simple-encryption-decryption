#include "base64.h"
#include <stdio.h>
#define KEY 12
char *encrypt(char *plain)
{
 int i;   
    if(plain==NULL)
        return plain;
    
    int length=strlen(plain);
    
    
    for(i = 0; (i < length && plain[i] != '\0'); i++)
    {
       // if((plain[i]+KEY)>125)
        plain[i] = plain[i] - KEY;
        //if(plain[i]>128)
           
    }   
    return plain;
}
char *decrypt(char *cipher)
{
    int i;
    if(cipher==NULL)
        return cipher;
    
    int length=strlen(cipher);
    
    
    for(i = 0; (i < length && cipher[i] != '\0'); i++)
        //if((cipher[i]+KEY)>125
        cipher[i] = cipher[i] + KEY;
        
    return cipher;
}
int setfilecontent(const char *filepath,unsigned char *t)
{
    FILE *fp;
    fp=fopen(filepath,"w");
    if(fp==NULL)
        return -1;
        
     int l=strlen(t);
fwrite(t,l,1,fp);
fclose(fp);
return 0;   
    
}
char * getfilecontent(const char *filepath)
{
   
    FILE *fp;
    long sz;
    fp=fopen(filepath,"r");
    if(fp==NULL)
    {
        return NULL;
    }
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    char *text=malloc(sz);
    rewind(fp);
    fread(text,sz,1,fp);
    fclose(fp);
    return text;
}

int main(int argc,char **argv)
{
   int i, x;
   char c[10];
   //char str[2000];
   printf("argc:%d",argc);
   if(argc==1){
       printf("Input required Usage :crypto.exe d file //for decryption \ncrypto.exe e file //for encryption \n ");
   return 0;
   }
/*if(strcmp(argv[1],"")==0){
    printf("enter input file\n");
    gets(c);
  //  return 0;
   * 
}*/

   printf("\nPlease enter a string:\t");
   //scanf("%10[0-9a-zA-Z ]",&str);
       //scanf("%[^\n]s",str);
       char *str=getfilecontent(argv[2]);
       if(strcmp(argv[1],"e")==0){
       
   //scanf("%d", &x);

   //using switch case statements
  
     encrypt(str);
    printf("\nEncrypted string: %s\n", str);
    setfilecontent("encryptedfile.bin",str);
    
       }
       else{
      decrypt(str);
          setfilecontent("plain.txt",str);

      printf("\nDecrypted string: %s\n", str);
       }
  
   
   
   return 0;
}
