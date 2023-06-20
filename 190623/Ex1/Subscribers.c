// Task: create an Array of "structs" containing field
// with info about subscribers. Write 5 funcs to add,
// delete, search and output information about subscriber.
// Length of Array nust be 100;
// Date: 19.06.23-20.06.23
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH 100
void fill(char** ptr);                                                                          // to fill an array with some data
void output_all();                                                                              // output all of 100 "accounts"
void search();                                                                                  // switch to search menu
void search_by_name(int struct_length);                                                         // searching by name
void search_by_surname(int struct_length);                                                      // searching by surname
void search_by_phone(int struct_length);                                                        // searching by number
void search_by_address(int struct_length);                                                      // searching by address
void add();
void delete();

struct subscriber {                                                                             // struct with data of subscriber ("account")
    int id;
    unsigned char number[20];
    unsigned char address[20];
    unsigned char name[20];
    unsigned char surname[20];
};

struct subscriber directory[LENGTH];                                                            // "array" of structs

int main(void) {
    int struct_length = LENGTH;                                                                 // I have no idea why I did this...
    int choose = 0;                                                                             // to control menu
    char* ptr1 = (char*)&directory;                                                             // pointer to first value in array of structs
    char** ptr2 = (char**)&ptr1;                                                                // pointer to pointer to first value of structs
    fill(ptr2);                                                                                 // filling array of structs with data
    printf("Welcome to our database! Choose an option:\n");                                     // greeting of main menu
    printf("1. Output all subscribers data%9s2. Search for subscribers account\n", " ");
    printf("3. Add new subscriber%18s4. Delete subscribers account\n", " ");
    printf("q. Exit database.\n");
    while(scanf("%d", &choose) && choose != 0) {                                                // main menu
        switch (choose)
        {
        case 1:
            output_all();
            break;
        case 2:
            search(struct_length);
            break;
        case 3:
            add();
            break;
        case 4:
            delete();
            break;
        default:
            break;
        }
        printf("Thank's for using our database! You can choose another one option:\n");         // repeating "greetings" to continue work with menu 
        printf("1. Output all subscribers data%9s2. Search for subscribers account\n", " ");    // after choosing one of values
        printf("3. Add new subscriber%18s4. Delete subscribers account\n", " ");
        printf("q. Exit database.\n");
    }
    printf("\n\n");
}

void fill(char** ptr) {
    char names[10][20] = {                                                                      // some crap...
        {'I', 'v', 'a', 'n'},
        {'P', 'h', 'i', 'l', 'l', 'i', 'p'},
        {'D', 'a', 'n', 'i', 'i', 'l'},
        {'A', 'l', 'e', 'x', 'a', 'n', 'd', 'e', 'r'},
        {'L', 'a', 'v', 'r', 'e', 'n', 't', 'y', 'i'},
        {'M', 'a', 'x'},
        {'P', 'e', 't', 'r'},
        {'P', 'a', 'v', 'e', 'l'},
        {'V', 'l', 'a', 'd', 'y', 'm', 'i', 'r'},
        {'N', 'i', 'k', 'i', 't', 'a'}
    };
    char surnames[10][20] = {                                                                    // more crappy info...
        {'P', 'e', 't', 'r', 'o', 'v'},
        {'P', 'a', 't', 'r', 'u', 's', 'h', 'e', 'v'},
        {'N', 'a', 'r', 'y', 's', 'h', 'k', 'i', 'n'},
        {'B', 'o', 'r', 't', 'n', 'i', 'k', 'o', 'v'},
        {'L', 'a', 'v', 'r', 'o', 'v'},
        {'L', 'v', 'o', 'v'},
        {'B', 'e', 'l', 'o', 'v'},
        {'H', 'i', 'n', 's', 't', 'e', 'i', 'n'},
        {'G', 'u', 'r', 'u', 'l', 'e', 'v'},
        {'A', 'r', 'b', 'u', 'z', 'o', 'v'}
    };
    char numbers[10][20] = {                                                                      // and more...
        {'(','7','2','2',')',' ','2','3','6','-','7','0','4','9'}, 
        {'(','6','6','3',')',' ','9','5','4','-','6','8','8','4'}, 
        {'(','2','4','6',')',' ','2','6','8','-','7','7','9','5'},
        {'(','5','3','1',')',' ','4','3','5','-','0','9','8','8'}, 
        {'(','4','7','3',')',' ','5','0','0','-','4','9','4','9'}, 
        {'(','5','8','4',')',' ','2','8','5','-','3','6','7','4'}, 
        {'(','3','0','5',')',' ','7','5','7','-','8','6','0','9'}, 
        {'(','3','1','5',')',' ','5','9','0','-','9','4','3','9'}, 
        {'(','5','7','6',')',' ','3','8','7','-','1','1','1','6'}, 
        {'(','4','6','7',')',' ','8','8','1','-','2','7','2','1'}
    };
    char addresses[10][20] = {                                                                     // is this enough? My fingers hurt.
        {'P', 'u', 's', 'h', 'k', 'i', 'n', 'a'},
        {'K', 'o', 'l', 'o', 't', 'u', 's', 'h', 'k', 'i', 'n', 'a'},
        {'L', 'e', 'n', 'i', 'n', 'a'},
        {'M', 'a', 'r', 'x', 'a'},
        {'S', 't', 'a', 'l', 'i', 'n', 'a'},
        {'H', 'r', 'u', 's', 'h', 'e', 'v', 'a'},
        {'G', 'o', 'r', 'b', 'a', 'c', 'h', 'e', 'v', 'a'},
        {'J', 'u', 'k', 'o', 'v', 'a'},
        {'P', 'e', 't', 'r', 'o', 'v', 's', 'k', 'a', 'y', 'a'},
        {'R', 'a', 'z', 'u', 'm', 'o', 'v', 's', 'k', 'a', 'y', 'a'}
    };
    for(int i = 0; i < LENGTH; i++) {                                                               // finally filling an array
        **ptr = i + 1;                                                                              // using this to set up ID (we have 100 account so 1st byte is more than enough)
        *ptr += 4;                                                                                  // shifting to 1st char byte
        int length = 0;                                                                             // using this to undestand the length of a reading "word"
        int r = (rand() % 10);                                                                      // random value to get RaNdOm-GeNeRaTiOn WoW !!1
        int counter = 1;                                                                            // using this to undestand the length of a final "word"
        for(int a = 0; a < 20; a++) {                                                               // finding "length"
            length++;
            if(numbers[r][a] == NULL) {
                length--;
                break;
            }
        }
        for(int j = 0; j < 20; j++) {                                                               // filling 20 bytes of 1st char field
            if(counter < length) {                                                                  // making a final "word"
                **ptr = numbers[r][j];                                                              // getting value from rendom *hehe* line
                *ptr += 1;                                                                          // anyway +1 to move to the next byte 
            } else {
                **ptr = NULL;                                                                       // if reading "word" is over
                *ptr += 1;
            }
        }
        length = 0;                                                                                 // repeating from 110th line
        r = (rand() % 10);
        counter = 1;
        for(int a = 0; a < 20; a++) {
            length++;
            if(addresses[r][a] == NULL) {
                length--;
                break;
            }
        }
        for(int j = 0; j < 20; j++) {
            if(counter < length) {
                **ptr = addresses[r][j];
                *ptr += 1;
            } else {
                **ptr = NULL;
                *ptr += 1;
            }
        }
        length = 0;
        r = (rand() % 10);
        counter = 1;
        for(int a = 0; a < 20; a++) {
            length++;
            if(names[r][a] == NULL) {
                length--;
                break;
            }
        }
        for(int j = 0; j < 20; j++) {
            if(counter < length) {
                **ptr = names[r][j];
                *ptr += 1;
            } else {
                **ptr = NULL;
                *ptr += 1;
            }
        }
        length = 0;
        r = (rand() % 10);
        counter = 1;
        for(int a = 0; a < 20; a++) {
            length++;
            if(surnames[r][a] == NULL) {
                length--;
                break;
            }
        }
        for(int j = 0; j < 20; j++) {
            if(counter < length) {
                **ptr = surnames[r][j];
                *ptr += 1;
            } else {
                **ptr = NULL;
                *ptr += 1;
            }
        }
    }
}

void output_all() {                                                                         // outputting all values THAT EZ !!1!
    for(int i = 0; i < LENGTH; i++) {
        printf("ID: %d\n", directory[i].id);
        printf("NAME: %s\n", directory[i].name);
        printf("SURNAME: %s\n", directory[i].surname);
        printf("NUMBER: %s\n", directory[i].number);
        printf("ADDRESS: %s\n", directory[i].address);
    }
}

void search(int struct_length) {                                                            // searching by values
    int choose = 0;
    printf("What parametr do you prefer to search by?\n");                                  // greetings of inner menu
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
    while(scanf("%d", &choose) && choose != 0) {                                            // loop of inner search menu
        switch (choose)
        {
        case 1:
            search_by_name(struct_length);                                                  // 4 funcs for each paramert of searching
            break;
        case 2:
            search_by_surname(struct_length);
            break;
        case 3:
            search_by_phone(struct_length);
            break;
        case 4:
            search_by_address(struct_length);
            break;
        case 0:
            break;
        default:
            break;
        }
    }
}

void search_by_name(int struct_length) {
    char search[20] = {NULL};
    printf("Enter the name you are looking for: ");
    scanf("%s", search);
    printf("Results:\n");
    for(int i = 0; i < struct_length; i++) {
        if(strcmp(search, directory[i].name)) {
            continue;
        } else {
            printf("ID: %d\n", directory[i].id);
            printf("NAME: %s\n", directory[i].name);
            printf("SURNAME: %s\n", directory[i].surname);
            printf("NUMBER: %s\n", directory[i].number);
            printf("ADDRESS: %s\n", directory[i].address);
        }
    }
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
}

void search_by_surname(int struct_length) {
    char search[20] = {NULL};
    printf("Enter the surname you are looking for: ");
    scanf("%s", search);
    printf("Results:\n");
    for(int i = 0; i < struct_length; i++) {
        if(strcmp(search, directory[i].surname)) {
            continue;
        } else {
            printf("ID: %d\n", directory[i].id);
            printf("NAME: %s\n", directory[i].name);
            printf("SURNAME: %s\n", directory[i].surname);
            printf("NUMBER: %s\n", directory[i].number);
            printf("ADDRESS: %s\n", directory[i].address);
        }
    }
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
}

void search_by_phone(int struct_length) {
    char search[20] = {NULL};
    printf("Enter phone number you are looking for: ");
    scanf("%s", search);
    printf("Results:\n");
    for(int i = 0; i < struct_length; i++) {
        if(strcmp(search, directory[i].number)) {
            continue;
        } else {
            printf("ID: %d\n", directory[i].id);
            printf("NAME: %s\n", directory[i].name);
            printf("SURNAME: %s\n", directory[i].surname);
            printf("NUMBER: %s\n", directory[i].number);
            printf("ADDRESS: %s\n", directory[i].address);
        }
    }
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
}

void search_by_address(int struct_length) {
    char search[20] = {NULL};
    printf("Enter address you are looking for: ");
    scanf("%s", search);
    printf("Results:\n");
    for(int i = 0; i < struct_length; i++) {
        if(strcmp(search, directory[i].address)) {
            continue;
        } else {
            printf("ID: %d\n", directory[i].id);
            printf("NAME: %s\n", directory[i].name);
            printf("SURNAME: %s\n", directory[i].surname);
            printf("NUMBER: %s\n", directory[i].number);
            printf("ADDRESS: %s\n", directory[i].address);
        }
    }
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
}

void add() {
    static int identificator = 1;
    char name[20] = {NULL};
    char surname[20] = {NULL};
    char number[20] = {NULL};
    char address[20] = {NULL};
    printf("Enter new subscriber's name: ");
    scanf("%s", name);
    printf("Enter new subscriber's surname: ");
    scanf("%s", surname);
    printf("Enter new subscriber's number: ");
    scanf("%s", number);
    printf("Enter new subscriber's address: ");
    scanf("%s", address);
    for(int i = 0; i < LENGTH; i++) {
        if(directory[i].id == identificator) {
            char* dir_ptr1 = (char*) &directory[i];
            char** dir_ptr = &dir_ptr1;
            *dir_ptr += 4;
            char* number_ptr = &number;
            for(int a = 0; a < 20; a++) {
                **dir_ptr = *number_ptr;
                *dir_ptr += 1;
                number_ptr += 1;
            }
            char* address_ptr = &address;
            for(int a = 0; a < 20; a++) {
                **dir_ptr = *address_ptr;
                *dir_ptr += 1;
                address_ptr += 1;
            }
            char* name_ptr = &name;
            for(int a = 0; a < 20; a++) {
                **dir_ptr = *name_ptr;
                *dir_ptr += 1;
                name_ptr += 1;
            }
            char* surname_ptr = &surname;
            for(int a = 0; a < 20; a++) {
                **dir_ptr = *surname_ptr;
                *dir_ptr += 1;
                surname_ptr += 1;
            }
            break;
        }
    }
    printf("You have added new subscriber:\n");
    printf("ID: %d\n", directory[identificator-1].id);
    printf("NAME: %s\n", directory[identificator-1].name);
    printf("SURNAME: %s\n", directory[identificator-1].surname);
    printf("NUMBER: %s\n", directory[identificator-1].number);
    printf("ADDRESS: %s\n", directory[identificator-1].address);
    identificator++;
}

void delete() {
    int identificator = 0;
    char name[20] = {'D', 'E', 'L', 'E', 'T', 'E', 'D'};
    char surname[20] = {'D', 'E', 'L', 'E', 'T', 'E', 'D'};
    char number[20] = {'D', 'E', 'L', 'E', 'T', 'E', 'D'};
    char address[20] = {'D', 'E', 'L', 'E', 'T', 'E', 'D'};
    printf("Enter subscriber's ID to delete an account: ");
    scanf("%d", &identificator);
    printf("You have deleted subscriber's account:\n");
    printf("ID: %d\n", directory[identificator-1].id);
    printf("NAME: %s\n", directory[identificator-1].name);
    printf("SURNAME: %s\n", directory[identificator-1].surname);
    printf("NUMBER: %s\n", directory[identificator-1].number);
    printf("ADDRESS: %s\n", directory[identificator-1].address);
    for(int i = 0; i < LENGTH; i++) {
        if(directory[i].id == identificator) {
            char* dir_ptr1 = (char*) &directory[i];
            char** dir_ptr = &dir_ptr1;
            *dir_ptr += 4;
            char* number_ptr = &number;
            for(int a = 0; a < 20; a++) {
                **dir_ptr = *number_ptr;
                *dir_ptr += 1;
                number_ptr += 1;
            }
            char* address_ptr = &address;
            for(int a = 0; a < 20; a++) {
                **dir_ptr = *address_ptr;
                *dir_ptr += 1;
                address_ptr += 1;
            }
            char* name_ptr = &name;
            for(int a = 0; a < 20; a++) {
                **dir_ptr = *name_ptr;
                *dir_ptr += 1;
                name_ptr += 1;
            }
            char* surname_ptr = &surname;
            for(int a = 0; a < 20; a++) {
                **dir_ptr = *surname_ptr;
                *dir_ptr += 1;
                surname_ptr += 1;
            }
            break;
        }
    }
    identificator++;
}