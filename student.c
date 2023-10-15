#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

// Function to print the program options
void start_system(){

    printf("\n\nOptions:\n");
    printf("1- Enter 1 to Add Student\n");
    printf("2- Enter 2 to Edit Student\n");
    printf("3- Enter 3 to Delete Student\n");
    printf("4- Enter 4 to Print Student\n");
    printf("5- Enter 5 to Call Student\n");
    printf("6- Enter 6 to Search About Student\n");
    printf("7- Enter 7 to Print All Students\n\n\n");

}

// Function to scan Student Information
struct student student_scan(void){

    struct student s;

    printf("First Name: ");
    string_scan(s.firstName, 20);

    printf("Last Name: ");
    string_scan(s.lastName, 20);

    printf("ID: ");
    scanf("%d", &s.id);

    printf("Age: ");
    scanf("%d", &s.age);

    printf("Phone: ");
    string_scan(s.phone, 12);

    return s;

}

// Function to check if an id is exist or not
int student_checkExist(struct student *arr, int ID, int size){

    int idflag = 0;

    for(int i = 0; i < size; i++){

        if(arr[i].id == ID){

            idflag = 1;
            break;

        }

    }

    return idflag;

}

//function used to edit student name
struct student student_scanName(struct student *arr, int index){

    struct student s;

    printf("\n\nFirst Name: ");
    string_scan(s.firstName, 20);

    printf("Last Name: ");
    string_scan(s.lastName, 20);

    s.age = arr[index].age;
    s.id = arr[index].id;

    for(int i = 0; i < 12; i++){

        s.phone[i] = arr[index].phone[i];

    }

    return s;

}

// Function to edit student id
struct student student_scanID(struct student *arr, int index){

    struct student s;

    printf("\n\nID: ");
    scanf("%d", &s.id);

    for(int i = 0; i < 20; i++){

        s.firstName[i] = arr[index].firstName[i];
        s.lastName[i] = arr[index].lastName[i];

    }

    s.age = arr[index].age;
    for(int i = 0; i < 12; i++){

        s.phone[i] = arr[index].phone[i];

    }


    return s;

}

//function to edit student age
struct student student_scanAge(struct student *arr, int index){

    struct student s;

    printf("\n\nAge: ");
    scanf("%d", &s.age);

    for(int i = 0; i < 20; i++){

        s.firstName[i] = arr[index].firstName[i];
        s.lastName[i] = arr[index].lastName[i];

    }

    s.id = arr[index].id;
    for(int i = 0; i < 12; i++){

        s.phone[i] = arr[index].phone[i];

    }


    return s;

}

// Function to edit student phone
struct student student_scanPhone(struct student *arr, int index){

    struct student s;

    printf("\n\nPhone: ");
    string_scan(s.phone, 12);

    for(int i = 0; i < 20; i++){

        s.firstName[i] = arr[index].firstName[i];
        s.lastName[i] = arr[index].lastName[i];

    }
    s.id = arr[index].id;
    s.age = arr[index].age;


    return s;

}

// Function to print All Student
void student_printAll(struct student *arr, int size){

    printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");
    printf("\033[1;35m|     \033[1;31mFirst Name      |        \033[1;36mLast Name        |       \033[1;33mID        |     \033[1;32mAge       |           \033[1;34mPhone                |\n");
    printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < size; i++){

        printf("\033[1;35m|     \033[1;37m%-8s        \033[1;31m|        \033[1;37m%-8s         \033[1;36m|       \033[1;37m%-3d       \033[1;33m|     \033[1;37m%-3d       \033[1;32m|           \033[1;37m%-11s          \033[1;34m|\n", arr[i].firstName, arr[i].lastName,arr[i].id, arr[i].age, arr[i].phone);
        printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");

    }

}


void edit_ItemName(struct student *arr, int index){

    arr[index] = student_scanName(arr, index);

}

void edit_ItemID(struct student *arr, int index){

    arr[index] = student_scanID(arr, index);

}

void edit_ItemAge(struct student *arr, int index){

    arr[index] = student_scanAge(arr, index);

}


void edit_ItemPhone(struct student *arr, int index){

    arr[index] = student_scanPhone(arr, index);

}


// Function to delete student
void delete_item(struct student *arr, int *size, int studentID) {
    int index = -1;


    for (int i = 0; i < *size; i++) {
        if (arr[i].id == studentID) {
            index = i;
            break;
        }
    }

    // If the studentID is found, shift elements to the left
    if (index != -1) {
        for (int i = index; i < (*size - 1); i++) {
            arr[i] = arr[i + 1];
        }

        (*size)--;
    }
}

// Function to print one student
void print_student(struct student *arr,int ID, int size){

    int flag = 0, index;
    for(int i = 0; i < size; i++){

        if(arr[i].id == ID){
            flag = 1;
            index = i;
            break;
        }

    }

    if(flag == 1){

        printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");
        printf("\033[1;35m|     \033[1;31mFirst Name      |        \033[1;36mLast Name        |       \033[1;33mID        |     \033[1;32mAge       |           \033[1;34mPhone                |\n");
        printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");

        printf("\033[1;35m|     \033[1;37m%-8s        \033[1;31m|        \033[1;37m%-8s         \033[1;36m|       \033[1;37m%-3d       \033[1;33m|     \033[1;37m%-3d       \033[1;32m|           \033[1;37m%-11s          \033[1;34m|\n", arr[index].firstName, arr[index].lastName,arr[index].id, arr[index].age, arr[index].phone);
        printf(" \033[1;37m------------------------------------------------------------------------------------------------------------------\n");


    }

    else{
        printf("\n\033[1;31mNot Exist!\033[1;37m");
        Sleep(3000);
        system("cls");
        return;
    }


}

// Function to Call Student
void student_call(struct student *arr,int ID, int size){

    int c = 0, i = 0, flag = 0, index;

    for(int i = 0; i < size; i++){

        if(arr[i].id == ID){
            flag = 1;
            index = i;
            break;
        }

    }

    if(flag == 1){
        printf("\n\n%s ", arr[index].phone);
    }

    else{
        printf("\n\033[1;31mNot Exist!\033[1;37m");
        Sleep(3000);
        system("cls");
        return;
    }


    while(1){
        printf(".");
        Sleep(500);
        i++;
        if(i == 3){
            for(int i = 0; i < 3; i++){
                printf(" \b\b\b ");
                Sleep(500);
            }
            i = 0;
            c++;
        }

        if(c == 5){
            printf("\n\033[1;31mNo Reply\n\n\033[1;37m");
            Sleep(3000);
            system("cls");
            break;
        }

    }

}
