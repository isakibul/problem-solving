#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define DATABASE_FILE "products.txt"

// Product structure definition
typedef struct {
    int id;
    char product_name[50];
    char brand[50];
    char category[30];
    float price;
    int quantity_in_stock;
} Product;

Product inventory[MAX_RECORDS];
int productCount = 0;
int nextId = 1;

// Function Prototypes
void loadInventory();
void saveInventory();
void insertProduct();
void viewProducts();
void updateProduct();
void deleteProduct();
void searchProducts();
void sellProduct();
int getValidIntInput();
float getValidFloatInput();
void clearInputBuffer();
void setNextId();

// Main function
int main() {
    int choice;

    // Load inventory from file
    loadInventory();

    do {
        printf("\n=>GadgetGear - Inventory==========\n");
        printf("1. Insert Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Products\n");
        printf("6. Sell Product\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        clearInputBuffer();

        switch (choice) {
            case 1: insertProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: searchProducts(); break;
            case 6: sellProduct(); break;
            case 7:
                printf("Saving inventory and exiting...\n");
                saveInventory();
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Load products from the text file into the in-memory inventory
void loadInventory() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("No existing inventory found. Starting fresh.\n");
        return;
    }

    productCount = 0;
    while (fscanf(file, "%d %49s %49s %29s %f %d", &inventory[productCount].id,
                  inventory[productCount].product_name,
                  inventory[productCount].brand, inventory[productCount].category,
                  &inventory[productCount].price, &inventory[productCount].quantity_in_stock) == 6) {
        if (inventory[productCount].id >= nextId) {
            nextId = inventory[productCount].id + 1;
        }
        productCount++;
        if (productCount >= MAX_RECORDS) {
            printf("Inventory file contains more records than the maximum allowed. Only the first %d records were loaded.\n", MAX_RECORDS);
            break;
        }
    }
    fclose(file);
    printf("Inventory loaded with %d products. Next ID: %d\n", productCount, nextId);
}

// Save the in-memory inventory to the text file
void saveInventory() {
    FILE *file = fopen(DATABASE_FILE, "w");
    if (file == NULL) {
        printf("Error saving inventory!\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        fprintf(file, "%d %s %s %s %.2f %d\n", inventory[i].id, inventory[i].product_name,
                inventory[i].brand, inventory[i].category, inventory[i].price, inventory[i].quantity_in_stock);
    }
    fclose(file);
    printf("Inventory saved successfully.\n");
}

// Get valid integer input from user
int getValidIntInput() {
    int value;
    while (scanf("%d", &value) != 1) {
        clearInputBuffer();
        printf("Invalid input! Please enter a valid integer: ");
    }
    return value;
}

// Get valid float input from user
float getValidFloatInput() {
    float value;
    while (scanf("%f", &value) != 1) {
        clearInputBuffer();
        printf("Invalid input! Please enter a valid float value: ");
    }
    return value;
}

// Clear the input buffer after an invalid input
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Set the next product ID based on the existing records in inventory
void setNextId() {
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id >= nextId) {
            nextId = inventory[i].id + 1;
        }
    }
}

// Insert a new product into the inventory
void insertProduct() {
    if (productCount >= MAX_RECORDS) {
        printf("Inventory is full!\n");
        return;
    }

    Product newProduct;
    newProduct.id = nextId++;

    printf("Generated ID: %d\n", newProduct.id);

    printf("Enter Product Name: ");
    fgets(newProduct.product_name, sizeof(newProduct.product_name), stdin);
    newProduct.product_name[strcspn(newProduct.product_name, "\n")] = '\0';

    printf("Enter Brand: ");
    fgets(newProduct.brand, sizeof(newProduct.brand), stdin);
    newProduct.brand[strcspn(newProduct.brand, "\n")] = '\0';

    printf("Enter Category: ");
    fgets(newProduct.category, sizeof(newProduct.category), stdin);
    newProduct.category[strcspn(newProduct.category, "\n")] = '\0';

    printf("Enter Price: ");
    newProduct.price = getValidFloatInput();

    printf("Enter Quantity in Stock: ");
    newProduct.quantity_in_stock = getValidIntInput();

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");

    // Save to file
    saveInventory();
}

// View all products in the inventory
void viewProducts() {
    if (productCount == 0) {
        printf("No products found in inventory!\n");
        return;
    }

    printf("\nAll Products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Brand: %s, Category: %s, Price: $%.2f, Quantity: %d\n",
                inventory[i].id, inventory[i].product_name, inventory[i].brand,
                inventory[i].category, inventory[i].price, inventory[i].quantity_in_stock);
    }
}

// Update a product by ID
void updateProduct() {
    int id;
    printf("Enter ID to update: ");
    id = getValidIntInput();

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new Product Name: ");
            fgets(inventory[i].product_name, sizeof(inventory[i].product_name), stdin);
            inventory[i].product_name[strcspn(inventory[i].product_name, "\n")] = '\0';

            printf("Enter new Brand: ");
            fgets(inventory[i].brand, sizeof(inventory[i].brand), stdin);
            inventory[i].brand[strcspn(inventory[i].brand, "\n")] = '\0';

            printf("Enter new Category: ");
            fgets(inventory[i].category, sizeof(inventory[i].category), stdin);
            inventory[i].category[strcspn(inventory[i].category, "\n")] = '\0';

            printf("Enter new Price: ");
            inventory[i].price = getValidFloatInput();

            printf("Enter new Quantity in Stock: ");
            inventory[i].quantity_in_stock = getValidIntInput();

            printf("Product updated successfully!\n");

            // Save to file
            saveInventory();
            return;
        }
    }

    printf("Product not found!\n");
}

// Delete a product by ID
void deleteProduct() {
    int id;
    printf("Enter ID to delete: ");
    id = getValidIntInput();

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");

            // Save to file
            saveInventory();
            return;
        }
    }

    printf("Product not found!\n");
}

// Search products by category or price range
void searchProducts() {
    char searchCategory[30];
    printf("Enter category to search for (or leave blank to skip): ");
    fgets(searchCategory, sizeof(searchCategory), stdin);
    searchCategory[strcspn(searchCategory, "\n")] = '\0';

    float minPrice = -1, maxPrice = -1;
    printf("Enter min price (or -1 to skip): ");
    minPrice = getValidFloatInput();
    printf("Enter max price (or -1 to skip): ");
    maxPrice = getValidFloatInput();

    printf("\nSearch Results:\n");
    for (int i = 0; i < productCount; i++) {
        int matchCategory = 1;
        if (strlen(searchCategory) > 0 && strcmp(inventory[i].category, searchCategory) != 0) {
            matchCategory = 0;
        }

        int matchPrice = 1;
        if (minPrice >= 0 && inventory[i].price < minPrice) {
            matchPrice = 0;
        }
        if (maxPrice >= 0 && inventory[i].price > maxPrice) {
            matchPrice = 0;
        }

        if (matchCategory && matchPrice) {
            printf("ID: %d, Name: %s, Brand: %s, Category: %s, Price: $%.2f, Quantity: %d\n",
                    inventory[i].id, inventory[i].product_name, inventory[i].brand,
                    inventory[i].category, inventory[i].price, inventory[i].quantity_in_stock);
        }
    }
}

// Function to update the quantity after selling a product
void sellProduct() {
    int id, quantitySold;
    printf("Enter ID of the product to sell: ");
    id = getValidIntInput();

    // Search for the product with the given ID
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter quantity sold: ");
            quantitySold = getValidIntInput();

            // Check if the quantity sold is less than or equal to the available stock
            if (quantitySold <= inventory[i].quantity_in_stock) {
                inventory[i].quantity_in_stock -= quantitySold;
                printf("Sale successful! Updated quantity: %d\n", inventory[i].quantity_in_stock);

                // Save the updated inventory to the file
                saveInventory();
                return;
            } else {
                printf("Error: Not enough stock to complete the sale.\n");
                return;
            }
        }
    }

    printf("Product with ID %d not found!\n", id);
}