#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node
struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* current = NULL;  // Current page

// Visit a new page
void visitNewPage(char url[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;

    if (current != NULL) {
        current->next = newNode;
    }

    current = newNode;
    printf("Visited: %s\n", current->url);
}

// Go back to previous page
void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back. No previous page.\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

// Go forward to next page
void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward. No next page.\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

// Display current page
void displayCurrentPage() {
    if (current == NULL) {
        printf("No page visited yet.\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}

// Show full history
void showHistory() {
    if (current == NULL) {
        printf("History is empty.\n");
        return;
    }

    // Go to first node
    struct Node* temp = current;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }

    printf("Browsing History:\n");
    while (temp != NULL) {
        printf("%s\n", temp->url);
        temp = temp->next;
    }
}

// Clear all history
void clearHistory() {
    if (current == NULL) {
        printf("History is already empty.\n");
        return;
    }

    // Go to first node
    struct Node* temp = current;
    while (temp->prev != NULL) {
        temp = temp->prev;
    }

    // Free all nodes
    while (temp != NULL) {
        struct Node* del = temp;
        temp = temp->next;
        free(del);
    }

    current = NULL;
    printf("History cleared.\n");
}

int main() {
    int choice;
    char url[100];

    do {
        printf("\nMenu\n----\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Show History\n");
        printf("6. Clear History\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline after scanf

        switch(choice) {
            case 1:
                printf("Enter URL to visit: ");
                fgets(url, 100, stdin);
                url[strcspn(url, "\n")] = 0; // remove newline from fgets
                visitNewPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                showHistory();
                break;
            case 6:
                clearHistory();
                break;
            case 7:
                printf("Exiting Browser Simulation.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 7);

    return 0;
}
