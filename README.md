# 🏠 Real Estate Platform

---

## 👥 Team Members
- J.Syam Sundar Pavan Kumar Reddy
- T.Shashank
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

```
📊 Sample Output(screenshots)

--- Real Estate Platform ---
1. Add Property
<img width="302" height="280" alt="Screenshot 2026-04-06 190113" src="https://github.com/user-attachments/assets/7fb7880b-063c-40e7-be93-e157556437eb" />

2. Display Properties
<img width="368" height="339" alt="Screenshot 2026-04-06 190207" src="https://github.com/user-attachments/assets/43550027-a375-4042-ad16-02866008ede6" />

3. Search Property
<img width="541" height="340" alt="Screenshot 2026-04-06 190326" src="https://github.com/user-attachments/assets/fe3bcf08-63fa-4421-bc5e-a3d0faa7681c" />

4. Delete Property
<img width="452" height="310" alt="Screenshot 2026-04-06 190756" src="https://github.com/user-attachments/assets/0a173d50-ad98-4df8-9677-a06fca0df44b" />

5. Update Property
<img width="383" height="289" alt="Screenshot 2026-04-06 190827" src="https://github.com/user-attachments/assets/47b6f3d4-2772-41a9-b3b8-1e5041dabdba" />

6. Count Properties
<img width="310" height="295" alt="Screenshot 2026-04-06 190910" src="https://github.com/user-attachments/assets/581d98f4-ba94-41a1-82f6-7557a5880fdc" />

7. Display Above Price
<img width="550" height="335" alt="Screenshot 2026-04-06 190935" src="https://github.com/user-attachments/assets/c9ca8cba-c42b-40f2-8b23-5d4fd02fcf88" />

8. Tree Height
<img width="379" height="295" alt="Screenshot 2026-04-06 190950" src="https://github.com/user-attachments/assets/394ad7e1-58f0-4d4c-b6b9-92a21232c04a" />

9. Level Order Traversal
<img width="550" height="318" alt="Screenshot 2026-04-06 191008" src="https://github.com/user-attachments/assets/35f9e2c6-2358-4c31-b6af-c508bf29ccee" />

10. Exit
<img width="307" height="269" alt="Screenshot 2026-04-06 191021" src="https://github.com/user-attachments/assets/06f32db3-9f0e-4469-bd84-4edae98a7ae0" />



✅ Conclusion

The Real Estate Platform implemented using a Binary Search Tree (BST) provides an efficient way to manage and organize property data based on price. It ensures fast operations such as insertion, deletion, and searching while maintaining sorted order through inorder traversal. The system also supports advanced features like filtering, counting, and tree analysis, making it a practical demonstration of BST applications in real-world scenarios and easy to handle the properties.

⭐ Final Key Point:
Using price as the BST key enables efficient sorting, searching, and management of real estate data, making the system scalable and performance-friendly.
