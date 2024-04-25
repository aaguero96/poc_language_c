#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "service.h"
#include "repository_bin.h"

void create() {
    User user;

    printf("first name: ");
    scanf("%s", user.firstName);

    printf("last name: ");
    scanf("%s", user.lastName);

    printf("phone number: ");
    scanf("%s", user.phoneNumber);

    printf("email: ");
    scanf("%s", user.email);
    
    createUser(user);
    return;
};

void read() {
    int numUsers;
    User *users;

    users = getAllUsers(&numUsers);
    for (int i = 0; i < numUsers; i += 1) {
        printf(
            "Name: %s %s, Phone number: %s, Email: %s\n",
            users[i].firstName,
            users[i].lastName,
            users[i].phoneNumber,
            users[i].email
        );
    }

    return;
};

void deleteByPhone() {
    char phoneNumber[12];

    printf("phone number: ");
    scanf("%s", phoneNumber);

    deleteUserByPhone(phoneNumber);
    return;
};