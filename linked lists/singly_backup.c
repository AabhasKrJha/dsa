#include <stdio.h>
#include <stdlib.h> // to use malloc()
#include <stdbool.h> // to use the bool data type

// -----------------------------------------------------------------

typedef struct Node{
    int element;
    struct Node * next;
} Node;

Node* linked_list;

// -----------------------------------------------------------------

Node* create_linked_list(int length){

    // returns the pointer for the head node of the linked list

    struct Node *head_node, *current_node, *temp_node;

    for (int index = 0; index <= length; index++){
        current_node = (Node *) malloc(sizeof(Node));
        if (index == 0){
            head_node = temp_node = current_node;
        } else{
            printf("Enter element for node-%d : ", index);
            scanf("%d", &current_node -> element);
            temp_node -> next = current_node;
            temp_node = current_node;
        }
    }

    return head_node;

}

// -----------------------------------------------------------------

int get_node_count(){

    Node* head_node = linked_list;
    linked_list = linked_list -> next;

    int count = 0;
    while (linked_list != NULL){
        count++;
        linked_list = linked_list -> next;
    }

    linked_list = head_node;

    return count;

}

// -----------------------------------------------------------------

void print_linked_list(){

    Node* head_node = linked_list;

    bool head_found = true;
    int node_count = 0;

    if (linked_list == NULL){
        printf("Linked List Empty");
    }

    while (linked_list != NULL){
        if (head_found){
            head_found = false;
            linked_list = linked_list -> next;
            continue;
        }
        node_count++;
        printf("Node %d : ", node_count);
        printf("%d\n", linked_list->element);
        linked_list = linked_list -> next; 
    }

    linked_list = head_node;

}

// -----------------------------------------------------------------

void search(){

    int element;
    printf("Enter element to find : ");
    scanf("%d", &element);

    bool head_node = true;
    int* positions = (int*) malloc(sizeof(int));
    int index = 0;
    int node_count = 0;

    while (linked_list != NULL){
        if (head_node){
            linked_list = linked_list -> next;
            head_node = false;
        }
        node_count ++;
        if (linked_list -> element == element){
            positions[index] = node_count;
            index++;
        }
        linked_list = linked_list -> next;
    }

    if (index > 0){
        // element found
        printf("Element %d found at node(s) : ", element);
        for (int position = 0; position < index; position++){
            printf("%d ", positions[position]);
        }
    } else{
        printf("Element %d not found", element);
    }
    
}

// -----------------------------------------------------------------

void insert_new_node(){

    int nodes = get_node_count();

    Node* head_node = linked_list;

    Node* new_node = (Node *) malloc(sizeof(Node));

    int element;
    printf("Enter element to insert :");
    scanf("%d", &element);

    new_node -> element = element;

    print_linked_list();
    int insert_node;
    printf("At what node do you want to insert the new node (1-%d): ", nodes + 1);
    scanf("%d", &insert_node);

    for (int node = 1; node < insert_node ; node++){
        linked_list = linked_list -> next;
    }

    Node* after = linked_list -> next;
    linked_list -> next  = new_node;
    new_node -> next = after;

    printf("After insertion :- \n");
    linked_list = head_node;
    print_linked_list();

}

// -----------------------------------------------------------------

void delete_node(){

    int nodes = get_node_count();

    Node* head_node = linked_list;

    print_linked_list();
    int deleted_node;
    printf("what node do you want to delete (1-%d): ", nodes);
    scanf("%d", &deleted_node);

    for (int node = 1; node < deleted_node ; node++){
        linked_list = linked_list -> next;
    }

    Node* before = linked_list;
    Node* after = (linked_list -> next) -> next;
    
    before -> next = after;

    printf("After deletion :- \n");
    linked_list = head_node;
    print_linked_list();

}

// -----------------------------------------------------------------

void print_menu(){
    printf(
        "SINGLY LINKED LIST : \n \
        Choose 0 to exit \n \
        Choose 1 to insert a new node \n \
        Choose 2 to Delete a node \n \
        Choose 3 to search for an element \n \
        Enter Choise : "
    );
}

int get_choise(){
    int choise;
    print_menu();
    scanf("%d", &choise);
    return choise;
}

void perform_dsa(){
    int choise = get_choise();
    switch (choise){
        case 0:
            exit(0);
            break;
        case 1:
            insert_new_node();
            break;
        case 2:
            delete_node();
            break;
        case 3:
            search();
            break;
        default:
            break;
    }
}

// -----------------------------------------------------------------

int main(){

    // CREATING A LINKED LIST
    int node_count; // length of linked list
    printf("Enter length of linked list : ");
    scanf("%d", &node_count);
    linked_list = create_linked_list(node_count);

    perform_dsa();

    return 0;

}