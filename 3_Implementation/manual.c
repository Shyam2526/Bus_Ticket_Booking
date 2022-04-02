#include "header.h"
#include "unity.h"
void manual_test_checking(){
    if(checking("shyam")==0)
        printf("\nUSERNAME Works\n");
    else
        printf("\nUSERNAME Not Works\n");
    if(checking("sssss")==0)
        printf("\nFunctions Work\n");
    else
        printf("\nFunctions Not Work\n");
}
void manual_test_pass(){
    if(checkpass("26")==0)
        printf("\nPASSWORD Work\n");
    else
        printf("\nPASSWORD Not Work\n");
    if(checkpass("1111")==0)
        printf("\nPASSWORD Work\n");
    else
        printf("\nPASSWORD Not Work\n");
}
void manual_test_login(){
    if(checking("shyam")==0 && checkpass("26")==0){
        printf("\nLOGIN WITH CHAR and NUM\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
    if(checking("shyam")==0 && checkpass("14")==0){
        printf("\nLOGIN WITH SAME USERNAME DIFFERENT PASS\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
    if(checking("110")==0 && checkpass("shyam")==0){
        printf("\nLOGIN WITH NUM and CHAR\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
    if(checking("rohit")==0 && checkpass("sharma")==0){
        printf("\nLOGIN WITH BOTH CHAR\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
    if(checking("6379")==0 && checkpass("93613")==0){
        printf("\nLOGIN WITH BOTH NUM\n");
    }
    else{
        printf("\nLOGIN FUNCTION FAILED\n");
    }
}