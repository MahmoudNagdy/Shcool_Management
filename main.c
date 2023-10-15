#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "student.h"

void print_progress(int percent)
{
  const int mul = 2; // width factor
  percent = min(100, percent);

  // spinning animation
  static int spin_index = 0;
  char spinning[] = "_-\\|/-";

  // bar filler
  int len = (percent * mul / 10) + 1;
  char *bar = malloc(len);
  memset(bar, '<', len - 1);
  bar[len - 1] = 0;

  // write display

  printf("%c Loading: [%*s] %*d%%\r",
         percent == 100 ? ' ' : spinning[spin_index],
         mul * 10, bar,
         3, percent
        );
  spin_index = (spin_index + 1) % strlen(spinning);

  free(bar);
}


int main()
{
    int count = 0;

    struct student s1[500];
    struct student s2;

    printf("System Is Loading...\n");
    for (int i = 10; i <= 100; i += 5)
    {
        print_progress(i);
        Sleep(150);
    }

    system("cls");

    int op, edit, item, studentId, index;

    while(1){
        start_system();
        printf("Choose: ");
        scanf("%d", &op);

        if(op == 1){
            system("cls");
            s2 = student_scan();
            int x = student_checkExist(s1, s2.id, count);
            if(x == 0){

                s1[count] = s2;
                count++;

            }

            else{

                system("cls");
                printf("\n\n\033[1;31mThis ID Is Already Exist!\033[1;37m");

                Sleep(3000);

            }
            system("cls");
        }

        if(op == 2){
            system("cls");
            printf("ID: ");
            scanf("%d", &studentId);

            int flag = 0;

            for(int i = 0; i < count; i++){
                if(studentId == s1[i].id){
                    flag = 1;
                    index = i;
                    break;
                }
            }

            if(flag == 1){
                system("cls");
                printf("Options to edit: \n");
                printf("1- Name\n");
                printf("2- ID\n");
                printf("3- Age\n");
                printf("4- Phone\n\n");
                printf("Choose: ");
                scanf("%d", &edit);

                if(edit == 1){
                    edit_ItemName(s1, index);
                    system("cls");
                }

                if(edit == 2){
                    edit_ItemID(s1, index);
                    system("cls");
                }

                if(edit == 3){
                    edit_ItemAge(s1, index);
                    system("cls");
                }

                if(edit == 4){
                    edit_ItemPhone(s1, index);
                    system("cls");
                }

            }

        else{
            system("cls");
            printf("\n\033[1;31mNot Exist!\033[1;37m");
            Sleep(3000);
            system("cls");
        }


        }

        if(op == 3){
            system("cls");
            printf("ID: ");
            scanf("%d", &studentId);
            delete_item(s1, &count, studentId);
            system("cls");
        }

        if(op == 4){
            system("cls");
            printf("ID: ");
            scanf("%d", &studentId);
            printf("\n\n\n\n");
            print_student(s1, studentId, count);
        }

        if(op == 5){
            system("cls");
            printf("ID: ");
            scanf("%d", &studentId);
            system("cls");
            student_call(s1, studentId, count);
        }

        if(op == 6){
            system("cls");
            printf("ID: ");
            scanf("%d", &studentId);
            int x = student_checkExist(s1, studentId, count);

            if(x == 1){
                printf("\n\n\033[1;32mThis Student Is Already Exist\033[1;37m");
                Sleep(3000);
                system("cls");
            }
            else{
                printf("\n\n\033[1;31mNot Exist!\033[1;37m");
                Sleep(3000);
                system("cls");
            }
        }

        if(op == 7){
            system("cls");
            student_printAll(s1, count);
        }

    }


    return 0;
}
