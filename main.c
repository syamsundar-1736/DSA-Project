#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Property (BST Node)
typedef struct Property {
    int id;                 // Unique ID
    char *location;         // Dynamic string
    float price;            // Price in crores (BST key)
    struct Property *left;
    struct Property *right;
} Property;

// Function to read a line dynamically
char* readLine() {
    char buffer[1000];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    char *str = (char*)malloc(strlen(buffer) + 1);
    strcpy(str, buffer);
    return str;
}

// Extract float from string like "34 crores"
float parsePrice(char *input) {
    float value;
    sscanf(input, "%f", &value);
    return value;
}

// Create new property node
Property* createProperty(int id, char *location, float price) {
    Property* newNode = (Property*)malloc(sizeof(Property));
    newNode->id = id;

    newNode->location = (char*)malloc(strlen(location) + 1);
    strcpy(newNode->location, location);

    newNode->price = price;
    newNode->left = newNode->right = NULL;

    return newNode;
}

// Insert node into BST (based on price)
Property* insert(Property* root, int id, char *location, float price) {
    // If tree is empty, create new node
    if (root == NULL)
        return createProperty(id, location, price);

    // Insert based on price (BST property)
    if (price <= root->price)   // Handles duplicate prices
        root->left = insert(root->left, id, location, price);
    else
        root->right = insert(root->right, id, location, price);

    // Return unchanged root pointer
    return root;
}

// Display properties in sorted order
void displayInorder(Property* root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("ID: %d | Location: %s | Price: %.2f Crores\n",
               root->id, root->location, root->price);
        displayInorder(root->right);
    }
}

// Search property by price
Property* search(Property* root, float price) {
    if (root == NULL || root->price == price)
        return root;

    if (price < root->price)
        return search(root->left, price);
    else
        return search(root->right, price);
}

// Find minimum node (used in deletion)
Property* findMin(Property* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a property by price
Property* deleteNode(Property* root, float price) {
    if (root == NULL)
        return NULL;

    if (price < root->price)
        root->left = deleteNode(root->left, price);
    else if (price > root->price)
        root->right = deleteNode(root->right, price);
    else {
        // Node found
        if (root->left == NULL) {
            Property* temp = root->right;
            free(root->location);
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Property* temp = root->left;
            free(root->location);
            free(root);
            return temp;
        }

        // Two children
        Property* temp = findMin(root->right);

        free(root->location);
        root->id = temp->id;
        root->price = temp->price;

        root->location = (char*)malloc(strlen(temp->location) + 1);
        strcpy(root->location, temp->location);

        root->right = deleteNode(root->right, temp->price);
    }
    return root;
}

// UPDATE operation (modify location and/or price)
Property* update(Property* root, float oldPrice) {
    Property* node = search(root, oldPrice);

    if (node == NULL) {
        printf("Property not found!\n");
        return root;
    }

    printf("Enter new location: ");
    getchar();
    char *newLocation = readLine();

    printf("Enter new price: ");
    char *priceStr = readLine();
    float newPrice = parsePrice(priceStr);

    int id = node->id;

    // Delete old node
    root = deleteNode(root, oldPrice);

    // Insert updated node
    root = insert(root, id, newLocation, newPrice);

    free(newLocation);
    free(priceStr);

    printf("Property updated successfully!\n");
    return root;
}

// Count total nodes
int countNodes(Property* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Display properties above given price
void displayAbovePrice(Property* root, float minPrice) {
    if (root != NULL) {
        displayAbovePrice(root->left, minPrice);

        if (root->price >= minPrice)
            printf("ID: %d | Location: %s | Price: %.2f Crores\n",
                   root->id, root->location, root->price);

        displayAbovePrice(root->right, minPrice);
    }
}

// Height of BST
int height(Property* root) {
    if (root == NULL)
        return -1;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

// Print nodes level-wise
void printLevel(Property* root, int level) {
    if (root == NULL) return;

    if (level == 0)
        printf("ID: %d | Location: %s | Price: %.2f Crores\n",
               root->id, root->location, root->price);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Level order traversal
void levelOrder(Property* root) {
    int h = height(root);
    for (int i = 0; i <= h; i++)
        printLevel(root, i);
}

// Free entire tree
void freeTree(Property* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->location);
        free(root);
    }
}

// Menu
void menu() {
    printf("\n--- Real Estate Platform ---\n");
    printf("1. Add Property\n");
    printf("2. Display Properties\n");
    printf("3. Search Property\n");
    printf("4. Delete Property\n");
    printf("5. Update Property\n");
    printf("6. Count Properties\n");
    printf("7. Display Above Price\n");
    printf("8. Tree Height\n");
    printf("9. Level Order Traversal\n");
    printf("10. Exit\n");
}

// Main function
int main() {
    Property* root = NULL;
    int choice, id;
    float price;

    while (1) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                printf("Enter ID: ");
                scanf("%d", &id);
                getchar();

                printf("Enter Location: ");
                char *location = readLine();

                printf("Enter Price: ");
                char *priceStr = readLine();
                price = parsePrice(priceStr);

                root = insert(root, id, location, price);

                free(location);
                free(priceStr);
                break;
            }

            case 2:
                displayInorder(root);
                break;

            case 3:
                printf("Enter price: ");
                scanf("%f", &price);
                Property* found = search(root, price);

                if (found)
                    printf("Found: ID %d | %s | %.2f Crores\n",
                           found->id, found->location, found->price);
                else
                    printf("Not found\n");
                break;

            case 4:
                printf("Enter price to delete: ");
                scanf("%f", &price);
                root = deleteNode(root, price);
                break;

            case 5:
                printf("Enter price of property to update: ");
                scanf("%f", &price);
                root = update(root, price);
                break;

            case 6:
                printf("Total Properties: %d\n", countNodes(root));
                break;

            case 7:
                printf("Enter minimum price: ");
                scanf("%f", &price);
                displayAbovePrice(root, price);
                break;

            case 8:
                printf("Tree Height: %d\n", height(root));
                break;

            case 9:
                levelOrder(root);
                break;

            case 10:
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}