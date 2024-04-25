# poc_language_c

1. Definition
    - This project based on to create a simple user interface to create, list and delete contacts, the business rule consists on create with first name, last name, phone number (+DDD) and email, delete is based just on phone number (+DDD) and the persistance happen on binary file with max entries is 255.

2. Run local
- Recomendations
    - git installed on computer with version => git version 2.44.0.windows.1
    - gcc installed on computer with version => gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0

- Clone this repository:
    - `git clone https://github.com/aaguero96/poc_language_c.git` for HTTPS
    - `git clone git@github.com:aaguero96/poc_language_c.git` for SSH

- Generate main.exe
    - `gcc main.c service.c repository_bin.c -o main`

- Execute main
    - `./main`