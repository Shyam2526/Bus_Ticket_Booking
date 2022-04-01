#include "header.h"
#include "unity.h"
void manual_test_checking(){
    if(checking("shyam")==0)
        printf("\nFunctions Work\n");
    else
        printf("\nFunctions Not Work\n");
    if(checking("sssss")==0)
        printf("\nFunctions Work\n");
    else
        printf("\nFunctions Not Work\n");
}
void manual_test_pass(){
    if(checkpass("26")==0)
        printf("\nFunctions Work\n");
    else
        printf("\nFunctions Not Work\n");
    if(checkpass("25")==0)
        printf("\nFunctions Work\n");
    else
        printf("\nFunctions Not Work\n");
    if(checkpass("1111")==1)
        printf("\nFunctions Work\n");
    else
        printf("\nFunctions Not Work\n");
}
void manual_test_login(){
    if(checking("shyam")==0 && checkpass("26")==0){
        printf("\nLOGIN FUNCTION WORKS\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
    if(checking("shyam")==0 && checkpass("14")==0){
        printf("\nLOGIN FUNCTION WORKS FOR SAME USERNAME\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
    if(checking("rohit")==0 && checkpass("sharma")==0){
        printf("\nPASSWORD WITH NAME\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
    if(checking("IPL")==0 && checkpass("shyam25")==0){
        printf("\nPASSWORD WITH NAME\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
}