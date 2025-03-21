/*
    Includes C++ Ordered Set (Lento, pode dar TLE)
    use less_equal pra multiset

    O(log(n))
    * order of key (int n) -  Number of items strictly smaller than k.

    O(log(n))
    * find_by_order (int n) - K-th element in a set (counting from zero).
*/

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
