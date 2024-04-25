#include "repository_bin.h"
#include <stdio.h>
#include <string.h>

void createUser(User user) {
    FILE *binFileWriter;
    long fileSize;
    int structUserSize = sizeof(User);
    int elements;

    binFileWriter = fopen("database.bin", "ab");
    if (binFileWriter == NULL) {
        perror("repository: error to open bin file");
        return;
    }

    fseek(binFileWriter, 0, SEEK_END);
    fileSize = ftell(binFileWriter);
    elements = fileSize / structUserSize;
    if (elements > 255) {
        perror("repository: bin file reached max number of users");
        fclose(binFileWriter);
        return;
    }

    fwrite(&user, structUserSize, 1, binFileWriter);
    fclose(binFileWriter);
    
    return;
};

User* getAllUsers(int *numUsers) {
    FILE *binFileReader;
    long fileSize;
    int structUserSize = sizeof(User);
    int elements;
    User *users;

    binFileReader = fopen("database.bin", "rb");
    if (binFileReader == NULL) {
        perror("repository: error to open bin file");
        *numUsers = 0;
        return NULL;
    }

    fseek(binFileReader, 0, SEEK_END);
    fileSize = ftell(binFileReader);
    elements = fileSize / structUserSize;
    *numUsers = elements;

    rewind(binFileReader);

    users = (User *)malloc(*numUsers * structUserSize);
    fread(users, structUserSize, *numUsers, binFileReader);

    fclose(binFileReader);

    return users;
};

void deleteUserByPhone(char phoneNumber[12]) {
    FILE *binFileReader, *binFileWriter;
    User user;
    int found = 0;
    int structUserSize = sizeof(User);

    binFileReader = fopen("database.bin", "rb");
    if (binFileReader == NULL) {
        perror("repository: error to open bin file");
        return;
    }

    binFileWriter = fopen("database_aux.bin", "ab");
    if (binFileWriter == NULL) {
        perror("repository: error to open bin file");
        fclose(binFileReader);
        return;
    }

    while(fread(&user, structUserSize, 1, binFileReader) == 1) {
        if (strcmp(user.phoneNumber, phoneNumber) != 0) {
            fwrite(&user, structUserSize, 1, binFileWriter);
        } else {
            found = 1;
        }
    }

    fclose(binFileReader);
    fclose(binFileWriter);

    if(!found) {
        remove("database_aux.bin");
    } else {
        remove("database.bin");
        rename("database_aux.bin", "database.bin");
    }
};