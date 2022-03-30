#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "header.h"
int i=0;
char checker[30]; 
static int z=0;
int ch;
char x;
char c;
char uname[30], upass[20]; 
int e=0;
int checku,checkp;
struct detail
{
char name[30],pass[20];
}w;
void reg(){
    FILE *fp;
    if(fp == NULL){
      fp=fopen("Web_reg.txt", "w");
      goto a;
    }
    else{
      fp=fopen("Web_reg.txt", "a");
      goto a;
    }a:
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\t\t\t\tWELCOME TO THE REGISTERATION");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    for(i=0;i<100;i++){
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%29s",checker);
      while(!feof(fp) ){ 
        if(strcmp(checker,w.name) == 0){
          printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
          reg();
        }
        else{
          strcpy(w.name,checker);
          break;
        }
      }
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13){
          w.pass[z++]=c;
          printf("%c",'*');
        }
      fprintf(fp,"\t%s %s\n", w.name, w.pass);
      fclose(fp);
      printf("\n\t\t\tSUCCESSFULLY REGISTERED");
      login();
        break;
      }system("cls");
    getch();
  }
void login(){
  FILE *fp;
  fp=fopen("Web_reg.txt", "r+");
  if(fp == NULL){
    printf("\t\t\tfile does not found !");
    exit(1);
  } 
  else{
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^\n\n\t\t\t\tWELCOME TO LOG IN ZONE\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%29s",uname);
    while( (c = fgetc(fp)) != EOF){
      fscanf(fp,"%29s %29s",w.name,w.pass);
      if(strcmp(w.name, uname) == 0){
        checku=0;
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13){
          upass[e++]=c;
          printf("%c",'*');
        }
          upass[e]='\0';
          printf("%s", w.pass);
          checkp=strcmp(w.pass,upass);
          break;}}}
if(checku==0&&checkp==0){
  printf("\n\n\n\t\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
  printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
  system("cls");
}
else if(checku==0&&checkp!=0){
  printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",uname);
  printf("\n\n\t\t\t\t  (Press 'y' to re-enter password)");
  getch();
  login();
}
else if(checku!=0){
  printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
  if(getch()==13)
    reg();
}}
