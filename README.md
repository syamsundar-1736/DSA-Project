# 🏠 Real Estate Platform

---

## 👥 Team Members
- Syam Sundar  
- Sashank

---

## 📌 Project Title
Real Estate Platform using Binary Search Tree (BST) in C

---

## ❓ Problem Statement
Design a menu-driven real estate management system that allows users to:

- Add new properties  
- Display properties sorted by price  
- Search, delete, and update properties  
- Count total properties  
- Display properties above a certain price  
- Check BST height and perform level order traversal  

All operations are implemented using a **Binary Search Tree (BST)** with **price as the key**.

---

## 🌳 Data Structure Used
**Binary Search Tree (BST)**

- Each node stores:
  - `ID` (integer)  
  - `Location` (dynamic string)  
  - `Price` (float in crores)  
- BST property:
  - Left child → price ≤ parent  
  - Right child → price > parent  

---

## ⚙️ Algorithm Explanation

### 1. Insert Property
- Compare the new property’s price with current node.  
- If price ≤ node price → move to left subtree.  
- Else → move to right subtree.  
- Repeat recursively until insertion point is found.  

### 2. Display Properties
- Inorder traversal ensures properties are displayed **sorted by price**.  

### 3. Search Property
- Compare the target price with node price.  
- Traverse left or right depending on comparison.  

### 4. Delete Property
- **Case 1:** Leaf node → delete directly  
- **Case 2:** Node with one child → replace node with child  
- **Case 3:** Node with two children → replace with **inorder successor** and delete successor  

### 5. Update Property
- Search property by price  
- Delete the old node  
- Insert a new node with updated location and/or price  

### 6. Other Operations
- Count total properties → recursive traversal counting nodes  
- Display properties above a given price → inorder traversal with condition  
- BST height → recursive computation of max depth  
- Level order traversal → print nodes level by level  

---

## 💻 Compilation Instructions

### 1. Save the file
Save your code as:

```
main.c

```
gcc main.c

```
./a.exe

📊 Sample Output(screenshots)



✅ Conclusion

The Real Estate Platform implemented using a Binary Search Tree (BST) provides an efficient way to manage and organize property data based on price. It ensures fast operations such as insertion, deletion, and searching while maintaining sorted order through inorder traversal. The system also supports advanced features like filtering, counting, and tree analysis, making it a practical demonstration of BST applications in real-world scenarios.

⭐ Final Key Point:
Using price as the BST key enables efficient sorting, searching, and management of real estate data, making the system scalable and performance-friendly.
