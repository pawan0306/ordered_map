# ordered_map (using AVL tree)

A generic ordered_map data structure for c++ implemented using AVL tree. Can perform all the basic ordered_map operations which are described below.

### Prerequisites:
* Source code must contain `iostream` header. 

### Declaration
`ordered_map <datatype, datatype> map_obj;`

### Operations:

1. `insert(key, value)` – Insert the key value pair. If the key is already
present, update it’s current value. [O(log n)]
2. `erase(key)` – Erase the given key from the map if it is present.
[O(log n)]
3. `find(key)` – returns true if key was found else return 0. [O(logn)]
4. `map_obj[key] (subscript operator)` – Access the element with the
given key(if it is present in the map). Also, it modifies the value at this key using this operator. If the value is not
present, then inserts this key with it’s corresponding assigned value. </br> [O(log n)]
5. `size()` – returns the number of keys present in the Map. [O(1)]
6. `clear()` – removes all the elements from the Map. [O(n)]

