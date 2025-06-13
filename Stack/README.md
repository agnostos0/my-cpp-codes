> **Note:**  
> STL containers like `vector`, `list`, and `stack` are passed **by value** by default in function calls, meaning a **copy** is made.  
> To modify the original container, pass it **by reference** using `&`.  
> 
> **Example:**
> ```cpp
> void fun(vector<int>& v) {
>     // Modifications here affect the original vector
> }
> ```
