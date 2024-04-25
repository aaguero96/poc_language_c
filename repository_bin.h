#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    char phoneNumber[12];
    char email[50];
} User;

void createUser(User user);
User* getAllUsers(int *numUsers);
void deleteUserByPhone(char phoneNumber[12]);