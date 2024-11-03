# Session 2024-11-3: Creating a random sequence to move on a cirsular graph

**Objective:** Create a graph with nodes connected in a cycle manner, and given an input from a stack, traverse.

Steps
- Create a list $$L$$ containing numbers [-3, -2, -1, 1, 2, 3]. Eeach number tells how many steps to traverse in the graph, the sign tell the direction in which to traverse.
- Create a graph $$G = (V,E)$$, where $$V$$ are the number of vertices and the $$E$$ the edge, that has $$n$$ nodes.
- Each vertex will have in its adjacency-list data structure `[0,1]` values,`0` representing the adjacent node to the left and `1` to the right.
- The node at each vertex represent a color, so depending on the input given by $$L$$, the graph $$G$$ will print a color.


