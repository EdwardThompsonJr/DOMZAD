// Task: create an Array of "structs" containing field
// with info about subscribers. Write 5 funcs to add,
// delete, search and output information about subscriber.
// Length of Array nust be 100;
// Date: 26.06.23-28.06.23
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define LENGTH 100
#define DIMENSION 84

typedef struct Subscriber {
    int id;
    char name[20];
    char surname[20];
    char number[20];
    char address[20];
    struct Subscriber* next;
} Subscriber;

Subscriber* get_last(Subscriber* head);
void push_back(Subscriber* head, int val);
Subscriber* get_nth(Subscriber* head, int val);
void fill(Subscriber* head);
void add_sub(Subscriber* head);
void output_all();
void search(Subscriber* head);
void search_by_name(Subscriber* head);
void search_by_surname(Subscriber* head);
void search_by_number(Subscriber* head);
void search_by_address(Subscriber* head);
void delete_sub(Subscriber* head);
int get_length(Subscriber* head);
void delete_all(Subscriber* head);

void main(void) {
    int choose = 0;
    Subscriber* s_begin = 
    (Subscriber*)malloc(sizeof(Subscriber));
    Subscriber* head = s_begin;
    // Subscriber** head_ptr = &head;
    fill(head);
    printf("LENGTH OF ARRAY IS %d\n", get_length(head));
    printf("Welcome to our database! Choose an option:\n");
    printf("1. Output all subscribers data%9s2. Search for subscribers account\n", " ");
    printf("3. Add new subscriber%18s4. Delete subscribers account\n", " ");
    printf("q. Exit database.\n");
    while(scanf("%d", &choose) && choose != 0) {
        switch (choose)
        {
        case 1:
            output_all(head);
            break;
        case 2:
            search(head);
            break;
        case 3:
            add_sub(head);
            break;
        case 4:
            delete_sub(head);
            break;
        default:
            break;
        }
        printf("Thank's for using our database! You can choose another one option:\n");
        printf("1. Output all subscribers data%9s2. Search for subscribers account\n", " ");
        printf("3. Add new subscriber%18s4. Delete subscribers account\n", " ");
        printf("q. Exit database.\n");
    }
    delete_all(s_begin);
}

Subscriber* get_last(Subscriber* head) {
    if(head == NULL) {
        return NULL;
    }
    while(head->next) {
        head = head->next;
    }
    return head;
}

int get_length(Subscriber* head) {
    int counter = 0;
    while(head) {
        counter++;
        head = head->next;
    }
    return counter;
}

void push_back(Subscriber* head, int val) {
    Subscriber* last = get_last(head);
    Subscriber* tmp = 
    (Subscriber*)malloc(sizeof(Subscriber));
    tmp->id = val;
    tmp->next = NULL;
    last->next = tmp;
}

Subscriber* get_nth(Subscriber* head, int val) {
    while(head->id != val) {
        head = head->next;
    }
    return head;
}

void fill(Subscriber* head) {
    char names[10][20] = {
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
    char surnames[10][20] = {
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
    char numbers[10][20] = {
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
    char addresses[10][20] = {
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
    for(int i = 0; i < LENGTH; i++) {
        push_back(head, i + 1);
    }
    for(int i = 0; i < LENGTH; i++) {
        head = head->next;
        int length = 0;
        int r = (rand() % 10);
        int counter = 1;
        for(int a = 0; a < 20; a++) {
            length++;
            if(names[r][a] == NULL) {
                length--;
                break;
            }
        }
        for(int j = 0; j < 20; j++) {
            if(counter < length) {
                head->name[j] += names[r][j];
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
                head->surname[j] += surnames[r][j];
            }
        }
        length = 0;
        r = (rand() % 10);
        counter = 1;
        for(int a = 0; a < 20; a++) {
            length++;
            if(numbers[r][a] == NULL) {
                length--;
                break;
            }
        }
        for(int j = 0; j < 20; j++) {
            if(counter < length) {
                head->number[j] += numbers[r][j];
            }
        }
        length = 0;
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
                head->address[j] += addresses[r][j];
            }
        }
        length = 0;
        r = (rand() % 10);
        counter = 1;
    }
}

void add_sub(Subscriber* head) {
    int length = get_length(head);
    char name[20] = {};
    char surname[20] = {};
    char number[20] = {};
    char address[20] = {};
    printf("Enter new subscriber's name: ");
    scanf("%s", name);
    printf("Enter new subscriber's surname: ");
    scanf("%s", surname);
    printf("Enter new subscriber's number: ");
    scanf("%s", number);
    printf("Enter new subscriber's address: ");
    scanf("%s", address);
    push_back(head, length);
    Subscriber* last = get_last(head);
    for(int i = 0; i < 20; i++) {
        last->name[i] = name[i];
    }
    for(int i = 0; i < 20; i++) {
        last->surname[i] = surname[i];
    }
    for(int i = 0; i < 20; i++) {
        last->number[i] = number[i];
    }
    for(int i = 0; i < 20; i++) {
        last->address[i] = address[i];
    }
    printf("You have added new subscriber:\n");
    printf("ID: %d\n", last->id);
    printf("NAME: %s\n", last->name);
    printf("SURNAME: %s\n", last->surname);
    printf("NUMBER: %s\n", last->number);
    printf("ADDRESS: %s\n", last->address);
    printf("Array length is %d now\n", get_length(head));
}

void output_all(Subscriber* head) {
    while(head != NULL) {
        printf("ID: %d \n", head->id);
        printf("NAME: %s \n", head->name);
        printf("SURNAME: %s \n", head->surname);
        printf("NUMBER: %s \n", head->number);
        printf("ADDRESS: %s \n", head->address);
        head = head->next;
    }
}

void search(Subscriber* head) {
    int choose = 0;
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
    while(scanf("%d", &choose) && choose != 0) {
        switch (choose)
        {
        case 1:
            search_by_name(head);
            break;
        case 2:
            search_by_surname(head);
            break;
        case 3:
            search_by_number(head);
            break;
        case 4:
            search_by_address(head);
            break;
        case 0:
            break;
        default:
            break;
        }
    }
}

void search_by_name(Subscriber* head) {
    int length = get_length(head);
    char search[20] = {};
    printf("Enter the name you are looking for: ");
    scanf("%s", search);
    printf("Results:\n");
    for(int i = 0; i < length; i++, head = head->next) {
        if(strcmp(search, head->name)) {

        } else {
            printf("ID: %d\n", head->id);
            printf("NAME: %s\n", head->name);
            printf("SURNAME: %s\n", head->surname);
            printf("NUMBER: %s\n", head->number);
            printf("ADDRESS: %s\n", head->address);
        }
    }
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
}

void search_by_surname(Subscriber* head) {
    int length = get_length(head);
    char search[20] = {};
    printf("Enter the name you are looking for: ");
    scanf("%s", search);
    printf("Results:\n");
    for(int i = 0; i < length; i++, head = head->next) {
        if(strcmp(search, head->surname)) {

        } else {
            printf("ID: %d\n", head->id);
            printf("NAME: %s\n", head->name);
            printf("SURNAME: %s\n", head->surname);
            printf("NUMBER: %s\n", head->number);
            printf("ADDRESS: %s\n", head->address);
        }
    }
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
}

void search_by_number(Subscriber* head) {
    int length = get_length(head);
    char search[20] = {};
    printf("Enter the name you are looking for: ");
    scanf("%s", search);
    printf("Results:\n");
    for(int i = 0; i < length; i++, head = head->next) {
        if(strcmp(search, head->number)) {

        } else {
            printf("ID: %d\n", head->id);
            printf("NAME: %s\n", head->name);
            printf("SURNAME: %s\n", head->surname);
            printf("NUMBER: %s\n", head->number);
            printf("ADDRESS: %s\n", head->address);
        }
    }
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
}

void search_by_address(Subscriber* head) {
    int length = get_length(head);
    char search[20] = {};
    printf("Enter the name you are looking for: ");
    scanf("%s", search);
    printf("Results:\n");
    for(int i = 0; i < length; i++, head = head->next) {
        if(strcmp(search, head->address)) {

        } else {
            printf("ID: %d\n", head->id);
            printf("NAME: %s\n", head->name);
            printf("SURNAME: %s\n", head->surname);
            printf("NUMBER: %s\n", head->number);
            printf("ADDRESS: %s\n", head->address);
        }
    }
    printf("What parametr do you prefer to search by?\n");
    printf("1. Name%17s2. Surname\n", " ");
    printf("3. Phone number%9s4. Address\n", " ");
    printf("0. Back\n");
}

void delete_sub(Subscriber* head) {
    int identificator = 0;
    printf("Enter subscriber's ID to delete an account: ");
    scanf("%d", &identificator);
    Subscriber* prev_nth_head = get_nth(head, identificator - 1);
    Subscriber* nth_head = prev_nth_head->next;
    printf("You have deleted subscriber's account:\n");
    printf("ID: %d\n", nth_head->id);
    printf("NAME: %s\n", nth_head->name);
    printf("SURNAME: %s\n", nth_head->surname);
    printf("NUMBER: %s\n", nth_head->number);
    printf("ADDRESS: %s\n", nth_head->address);
    prev_nth_head->next = nth_head->next;
    free(nth_head);
}

void delete_all(Subscriber* head) {
    Subscriber* prev = NULL;
    while(head->next) {
        prev = head;
        head = head->next;
        free(prev);
    }
    free(head);
}