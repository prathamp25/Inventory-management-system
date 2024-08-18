#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
// Define a struct to hold item information
struct Item {
 int quantity;
 double price;
};
// Define a map to hold the inventory
map<string, Item> inventory;
// Function to display the current inventory
void displayInventory() {
 cout << "Current Inventory:" << endl;
 for (auto const& item : inventory) {
 cout << item.first << " - " << item.second.quantity << " - " << item.second.price << endl;
 }
}
// Function to add items to the inventory
void addItem() {
 string itemName;
 int quantity;
 double price;
 cout << "Enter item name: ";
 cin >> itemName;
 cout << "Enter quantity: ";
 cin >> quantity;
 cout << "Enter price: ";
 cin >> price;
 inventory[itemName] = {quantity, price};
 cout << itemName << " added to inventory." << endl;
}
// Function to remove items from the inventory
void removeItem() {
 string itemName;
 int quantity;
 cout << "Enter item name: ";
 cin >> itemName;
 if (inventory.count(itemName) == 0) {
 cout << itemName << " not found in inventory." << endl;
 return;
 }
 cout << "Enter quantity: ";
 cin >> quantity;
 if (quantity > inventory[itemName].quantity) {
 cout << "Insufficient quantity!" << endl;
 return;
 }
 inventory[itemName].quantity -= quantity;
 cout << itemName << " removed from inventory." << endl;
}
// Function to update item price
void updatePrice() {
 string itemName;
 double price;
 cout << "Enter item name: ";
 cin >> itemName;
 if (inventory.count(itemName) == 0) {
 cout << itemName << " not found in inventory." << endl;
 return;
 }
 cout << "Enter price: ";
 cin >> price;
 inventory[itemName].price = price;
 cout << itemName << " price updated to " << price << "." << endl;
}
// Function to place an order
void placeOrder() {
 string itemName;
 int quantity;
 double total = 0;
 while (true) {
 cout << "Enter item name (or 'done' to finish order): ";
 cin >> itemName;
 if (itemName == "done") {
 break;
 }
 if (inventory.count(itemName) == 0) {
 cout << itemName << " not found in inventory." << endl;
 continue;
 }
 cout << "Enter quantity: ";
 cin >> quantity;
 if (quantity > inventory[itemName].quantity) {
 cout << "Insufficient quantity!" << endl;
 continue;
 }
 inventory[itemName].quantity -= quantity;
 total += quantity * inventory[itemName].price;
 }
 cout << "Order placed successfully! Total price: " << total << endl;
}
// Function to write the inventory data to a CSV file
void writeInventoryToCSV() {
 ofstream outfile;
 outfile.open("inventory.csv");
 outfile << "Item Name, Quantity, Price\n";
 for (auto const& item : inventory) {
 outfile << item.first << "," << item.second.quantity << "," << item.second.price << "\n";
 }
 outfile.close();
 cout << "Inventory data written to inventory.csv" << endl;
}
// Main function
int main() {
 int choice;
 ofstream inventoryFile("inventory.csv");
 while (true) {
 cout << endl;
 cout << "1. Display inventory" << endl;
 cout << "2. Add item to inventory" << endl;
 cout << "3. Remove item from inventory" << endl;
 cout << "4. Update item price" << endl;
 cout << "5. Place an order" << endl;
 cout << "6. Exit" << endl;
 cout << "Enter your choice (1-6): ";
 cin >> choice;
 if (choice == 1) {
 displayInventory();
 }
 else if (choice == 2) {
 addItem();
 inventoryFile.open("inventory.csv", ios::out | ios::trunc);
 inventoryFile << "Item Name, Quantity, Price\n";
 for (auto const& item : inventory) {
 inventoryFile << item.first << "," << item.second.quantity << "," << item.second.price << "\n";
 }
 inventoryFile.close();
 }
 else if (choice == 3) {
 removeItem();
 inventoryFile.open("inventory.csv", ios::out | ios::trunc);
 inventoryFile << "Item Name, Quantity, Price\n";
 for (auto const& item : inventory) {
 inventoryFile << item.first << "," << item.second.quantity << "," << item.second.price << "\n";
 }
 inventoryFile.close();
 }
 else if (choice == 4) {
 updatePrice();
 inventoryFile.open("inventory.csv", ios::out | ios::trunc);
 inventoryFile << "Item Name, Quantity, Price\n";
 for (auto const& item : inventory) {
 inventoryFile << item.first << "," << item.second.quantity << "," << item.second.price << "\n";
 }
 inventoryFile.close();
 }
 else if (choice == 5) {
 placeOrder();
 } else if (choice == 6) break; } } }