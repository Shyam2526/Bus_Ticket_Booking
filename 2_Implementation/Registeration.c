#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "header.h"
static int i=0;
int ch;
char x;
struct detail
{
char name[30],pass[30];
}w;
void reg()
  {
    FILE *fp;
    char checker[30]; 
    static int z=0;
    if(fp == NULL){
      fp=fopen("Web_reg.txt", "w");
      goto a;
    }
    else{
      fp=fopen("Web_reg.txt", "a");
      goto a;
    }
    a:
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\n\t\t\t\tWELCOME TO THE REGISTERATION");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    for(i=0;i<100;i++)
    {
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%30s",checker);
      while(!feof(fp) )
    	{ 
        if(strcmp(checker,w.name) == 0)
        {
          printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
          reg();
        }
        else
        {
          strcpy(w.name,checker);
          break;
        }
      }
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          w.pass[z++]=c;
          printf("%c",'*');
        }
      fprintf(fp,"\t%s %s\n", w.name, w.pass);
      fclose(fp);
      printf("SUCCESSFULLY REGISTERED");
      login();
        break;
      }
    getch();
  }
void login()
{
  FILE *fp;
  char c,name[30],pass[30]; int z=0;
  int checku,checkp;
  fp=fopen("Web_reg.txt", "r+");
  if(fp == NULL)
  {
    printf("\t\t\tfile does not found !");
    exit(1);
  } 
  else
  {
    printf("\n\n\t\t\t\tWELCOME TO LOG IN ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\n\t\t\t\t  ENTER USERNAME: ");
    scanf("%30s",name);
    while( (c = fgetc(fp)) != EOF)
    {
      fscanf(fp,"%30s %30s",w.name,w.pass);
      if(strcmp(w.name, name) == 0)
      {
        checku=0;
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
          pass[z]='\0';
          printf("%s", w.pass);
          checkp=strcmp(w.pass,pass);
          break;
        }
      }
  }
if(checku==0&&checkp==0)
{
  printf("\n\n\n\t\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
  printf("\n\n\n\t\t\t\tWELCOME, HAVE A NICE DAY");
  system("cls");
 do{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n");	
	printf("\t\t\tBus Ticket booking ");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	
	printf("\n\t\t\tEnter >1< To Book Ticket");
  printf("\n\t\t\tEnter >2< To View All Route");
  printf("\n\t\t\tEnter >0< To Exit ");

   	printf("\n\t\t\tEnter your Choice ::");
   	scanf("%d",&ch); 
	  switch(ch){
    case 1 :
    		ticket_booking();
   		  break;
		case 2:
    		viewAll_route();
   		  break;		
    case 0:
    		main();
    		break;

    default:
    		printf("\n\t\tWrong choice !");
    		break;
   	}
       
 }while(ch!=0);
}
else if(checku==0&&checkp!=0)
{
  printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
  printf("\n\n\t\t\t\t  (Press 'y' to re-enter password)");
  getch();
  login();
}
else if(checku!=0)
{
  printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
  if(getch()==13)
    reg();
}
getch();
}
