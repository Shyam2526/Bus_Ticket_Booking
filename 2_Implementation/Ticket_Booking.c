#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"
#include "unity.h"
extern int testcode();
struct bus{
  char code[20];
  char pp[20];
  char des[20];
  int cost;
  int seat_no[20];
}bu;
int mrp;
extern void reg();
extern void admin();
int n;
static int count=0;
int ch;
char name[21], mobile[11];
int  total_amount=0;
int main(void)
{
testcode();
printf("\n\t\t\t===========================");
printf("\n\t\t\tWELCOME TO THE HOLIDAYS BUS");
printf("\n\t\t\t===========================");
call();
return 0;
}
void call(){
  XY:
printf("\n\n\n\t\t\t1. REGISTER\n\t\t\t2. LOGIN\n\t\t\t3. ADMIN\n\t\t\t4. Exit");
printf("\n\n\n\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&n);
switch(n)
  {
    case 1:
        reg();
        break;
    case 2:
        login();
        break;
    case 3:
        admin();
        break;
    case 4:
        exit(0);
        break;
    default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        goto XY;
  }
 do{
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t\tBus Ticket booking\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  printf("\n\t\t\tEnter >1< To Book Ticket");
  printf("\n\t\t\tEnter >2< To View All Route");
  printf("\n\t\t\tEnter >0< Go To Main Menu");
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
    		call();
    		break;
    default:
    		printf("\n\t\tWrong choice !");
    		break;
    }
 }while(ch!=0);
}
 char u;
void viewAll_route()
{
  FILE *fp;
 
  fp=fopen("project.txt", "r");
  if(fp == NULL)
  {
    printf("\t\t\tfile does not found !");
    exit(1);
  }
  else
  {
	  while( ( u = fgetc(fp) ) != EOF )
    	printf("%c",u);
  }
  fclose(fp);
}
void ticket_booking(){
  FILE *fp=fopen("project.txt", "r");
  if(fp == NULL){
	printf("\t\t\tfile does not found !");
    	exit(1);}
  else{
    while( ( ch = fgetc(fp) ) != EOF )
   		printf("%c",ch);}
  fclose(fp);
  printf("\n\n\n\t\t For Book ticket Choice Route\n\n\t\t Enter Route code :");
  scanf("%20s",bus_code);
  fp=fopen("project.txt", "r");
  if(fp == NULL){
    printf("\t\t\tfile does not found !");
    exit(1);}
  else{
    while(getc(fp) != EOF){
	    fscanf(fp,"%20s %20s %20s %d",bu.code,bu.pp,bu.des,&bu.cost);
	    if(strcmp(bu.code,bus_code) == 0){
		    printf("\n Choice Found\n\n\t\tRoute Code ::%s\n\t\tDepature Place ::%s\n\t\tArrival Place ::%s\n\t\tPrice of ticket::%d",bu.code,bu.pp,bu.des,bu.cost);
		    bu.cost=mrp;
        break;}}}
  printf("\n\n\n* Person Deatails  *");
	printf("\n\t\t your name :");
	scanf("%20s",name);
  x:
	printf("\n\t\t mobile number :");
	scanf("%10s",mobile);
  if(strlen(mobile)==10){
    for(int j=0; j<10; j++){
      if(!(mobile[j]>='0' && mobile[j]<='9')){
        printf("INVALID MOBILE NUMBER");
        goto x;}}}
  else{
    printf("Enter Valid Mobile Number");
    goto x;}
	fclose(fp);
  buses();
}
void buses(){
	int sr;
	FILE *sfp;
  printf("\nAVALIABLE SEATS ::%d", 30-count);
  printf("\n\t\t Total number of tickets :: ");
	scanf("%d",&total_seat);
  printf("\n\t\t<1>\tAC BUS");
  printf("\n\t\t<2>\tSLEEPER COACH");
  printf("\n\t\t<3>\tSEATER\n\t\tENTER YOUR CHOICE :: ");
  scanf("%d", &sr);
  switch(sr){
    case 1:
      total_amount = ac(total_seat,bus_code,mrp);
      break;
    case 2:
      total_amount = sleeper(total_seat, bus_code,mrp);
      break;
    case 3:
      total_amount = seater(total_seat, bus_code,mrp);
      break;
    default:
      printf("\n\t\tWRONG OPTION");
      break;}
	printf("\n\t\tTOTAL AMOUNT :: %d\n\n\n\t\t ENJOY YOUR JOURNEY %s\n", total_amount, name);
  sfp=fopen("histroy.txt", "a");
  if(sfp == NULL){
		printf("FIle not Found");}
	else{
		fprintf(sfp,"\nNAME ::%s\nMOBILE_NUMBER ::%s\nTOTAL_SEAT ::%d\nTOTAL_AMOUONT ::%d\nBUS CODE ::%s\nPRICE PER TICKET ::%d\n",name,mobile,total_seat,total_amount,bu.code, bu.cost);
		for(int k=0; k<total_seat; k++)
      fprintf(sfp,"Seat Number :: %d\n", bu.seat_no[k]);
    printf("\n\t\tRoutes insert Sucessfull to the Histroy file\n");
	fclose(sfp);
	}
}
int ac(int total_seat, char bus_code[],int mrp){
  if(total_seat<=30){
    for(int k=0; k<total_seat; k++){
      printf("Seat Number :: ");
      scanf("%d", &bu.seat_no[k]);
      if(bu.seat_no[k]>30)
        printf("\n\t\tMAXIMUM SEAT EXCEED");
      count++;
    }
  }
  else{
    return -1;
  }
  bu.cost=mrp;
  return total_seat*mrp + 200;
}
int sleeper(int total_seat, char bus_code[],int mrp){
  if(total_seat<=30){

    for(int k=0; k<total_seat; k++){
      printf("Seat Number :: ");
      scanf("%d", &bu.seat_no[k]);
      if(bu.seat_no[k]>30)
        printf("\n\t\tMAXIMUM SEAT EXCEED");
      count++;
    }
  }
  return total_seat*mrp + 100;
}
int seater(int total_seat, char bus_code[],int mrp){
  if(total_seat<=30){

    for(int k=0; k<total_seat; k++){
      c: printf("Seat Number :: ");
      scanf("%d", &bu.seat_no[k]);
      if(bu.seat_no[k]>30){
        printf("\n\t\tMAXIMUM SEAT EXCEED");
        goto c;
      }
      count++;
    }
  }
  bu.cost=mrp;
  return total_seat*mrp;
}
