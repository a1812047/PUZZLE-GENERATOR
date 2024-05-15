#include <vector>
template<typename T>
void shuffleItems(std::vector<T>& items){
    int n = items.size();
    srand(time(0));
    for(int i = 0; i < n; i++){
        /* get a random   number between n-i and n 
        and swap its positions */
        int rNum = rand()%(n-i)+i;
        std::swap(items[i], items[rNum]);
    }
}