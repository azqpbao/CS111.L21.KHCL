#include <iostream> 

using namespace std;

int main()
{ 
    long long n; 
    cin >> n; 
    
    long long a[1001]; 
    long long b[1001]; 
    
    for(int i = 1; i <= n; ++i) 
        cin >> a[i] >> b[i]; 
        
    long long c[1001][1001]; 
    for(int i = 0; i <= 1000; ++i) 
        for(int j = 0;  j <= 1000; ++j) 
            c[i][j] = 1e9; 
            
    c[0][0] = 0; 
    for(int i = 1; i <= n; ++i) 
        for(int j = 0; j <= (n >> 1); ++j) 
        { 
            c[i][j] = c[i-1][j] + b[i]; 
            if (j >= 1 && j * 2 <= i)
            { 
                c[i][j] = min(c[i-1][j-1] + a[i], c[i][j]); 
            }
        } 
    cout << c[n][(n >> 1)]; 
    return 0; 
}