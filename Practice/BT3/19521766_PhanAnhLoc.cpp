

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using std::vector;
using std::reverse;


std::vector<int>::const_iterator MaxNhoHon( const vector<int> &v, 
                                              int value ) 
{
    auto first = v.begin();

    while ( first != v.end() && !( *first < value ) ) ++first;

    auto max = first;

    for ( ; first != v.end(); ++first )
    {
        if ( *first < value && *max < *first ) max = first;
    }

    return max;
}



int main(){
    int n, m, k, h;
    cin >> n >> m >> k;
    vector<int> M, res;
    vector<char> N;
    int i = 0, j = 0;
    char value(2);
    int value1;
    set<int>::iterator result;
    while (i++ < n && cin >> value)
    {
        N.push_back(value);
    }
    
    while (j++ < m && cin >> value1)
    {
        M.push_back(value1);
    }
    
    //Đảo chiều vector khách hàng để dễ tìm hơn
    reverse(N.begin(), N.end());
    
    
    
    for(auto x : N){
        if (x == 'E'){
            auto result = min_element(M.begin(), M.end());  //Tìm min trong M
            auto temp = find(M.begin(), M.end(), *result);  
            h = temp - M.begin() + 1;                       //Tìm index của min M
            res.push_back(h);                               //Thêm vào vector kết quả
            h -= 1;                                         
            M[h] += 1;                                      //tăng 1 lít cho vị trí chai vừa uống
        }
        else{
            auto result = MaxNhoHon(M, k);
            auto temp1 = find(M.begin(), M.end(), *result);
            h = temp1 - M.begin() + 1;
            res.push_back(h);
            h -= 1;
            M[h] += 1;
        }
    }
    
    reverse(res.begin(), res.end());                        //Do nãy đã đảo chiều M để xét nên phải đảo chiều res để in kết quả đúng
    for (auto X : res){
        cout << X << " ";
    }

    
}

