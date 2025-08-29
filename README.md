# 📘 Day 07 — Graphs Basics (Adjacency List + BFS + DFS)

This project covers the **fundamentals of Graphs** in Data Structures and Algorithms.  
We implement **Adjacency List Representation**, **Breadth-First Search (BFS)**, and **Depth-First Search (DFS)** in **C++** with clear examples.

---

## 📂 Project Structure

graphs_dfs_bfs.cpp # Main C++ program (Adjacency List + BFS + DFS)


---

## ✨ Features
- ✅ Graph representation using **Adjacency List**  
- ✅ Implementation of **BFS traversal**  
- ✅ Implementation of **DFS traversal (recursive + iterative)**  
- ✅ Example graph to demonstrate traversal order  

---

## 🚀 How to Run

### 1. Compile
```bash
g++ graphs_dfs_bfs.cpp -o graphs

2. Run

./graphs

🧩 Example Output

For a sample graph:
0 -- 1 -- 2
|         |
3 --------4

DFS Traversal (starting from node 0):
0 1 2 4 3

BFS Traversal (starting from node 0):
0 1 3 2 4

📖 Concepts Learned

Graphs: Vertices + Edges

Adjacency List representation

BFS → Level-order traversal using queue

DFS → Depth exploration using recursion/stack


🛠️ Tech Used

Language: C++ (STL: vector, queue, stack)

Compiler: g++ / clang++

📌 Next Steps

Add Directed Graph support

Add Weighted Graph support

Implement Topological Sort, Dijkstra’s Algorithm, and Connected Components


👨‍💻 Author: Shank312
