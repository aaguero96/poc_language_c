#include "service.h"

void main() {
    int endProgram = 0;
    int option;

    do {
        printf("Main menu\n");
        printf("1 - Create contact\n");
        printf("2 - List contacts\n");
        printf("3 - Delete contacts\n");
        printf("4 - Exit\n");

        printf("choose option: ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 1:
            create();
            break;

        case 2:
            read();
            break;

        case 3:
            deleteByPhone();
            break;
        
        case 4:
            endProgram = 1;
            break;
        
        default:
            printf("Invalid option!");
        }
    } while (endProgram == 0);
}