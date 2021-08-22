# [forward_list](http://www.cplusplus.com/reference/forward_list/forward_list/)

># 与vector比较
1. iterators： 无 rbegin、rend 方法
2. const iterators: 无 crbegin、crend 方法
3. capacity：无 size、shrink_to_fit、capacity、reseve 方法
4. element access: 无 back、operator []、at 方法
5. modifiers: 无emplace有emplace_after、 无insert有insert_after、无erase有erase_after、无emplace_back、push_back、pop_back、多 emplace_front、push_front、pop_front
6. list operatoins: 多 splice_after、remove、remove_if、unique、merge、sort、reverse
7. observers：无 data