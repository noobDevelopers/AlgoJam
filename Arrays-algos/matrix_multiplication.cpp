#include <iostream>
#include <vector>
// Naive method to multiply two matrics
// complexity = theta(n^3)
int multiply_naive(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B, std::vector<std::vector<int>> C)
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {   
            C[i][j]=0;
            for(int k=0;k<A.size();k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    return 0;
}

std::vector<std::vector<int>> devide_copy_matrix(std::vector<std::vector<int>> X, int r1, int r2, int c1, int c2)
{
    int n = X.size()/2;
    std::vector<std::vector<int>> res;
    res.resize(n, std::vector<int>(n, 0));
    for(int i=r1; i<=r2; i++)
    {
        for(int j=c1; j<=c2; j++)
        {
            res[i-r1][j-c1] = X[i][j];
        }
    }

    // for (int i = 0; i < res.size(); i++) 
    // { 
    //     for (int j = 0; j < res.size(); j++) 
    //     std::cout << res[i][j] << " "; 
    //     std::cout << "\n"; 
    // } 

    return res;


    
}

std::vector<std::vector<int>> join_matrix(std::vector<std::vector<int>> X11, std::vector<std::vector<int>> X12, std::vector<std::vector<int>> X21, std::vector<std::vector<int>> X22, int size)
{
    int n = size;
    std::vector<std::vector<int>> res;
    res.resize(n, std::vector<int>(n, 0));
    int r1_1=0;
    int r2_1 = n/2-1;
    int c1_1 = 0;
    int c2_1 = n/2-1;
    for(int i=r1_1; i<=r2_1; i++)
    {
        for(int j=c1_1; j<=c2_1; j++)
        {
            res[i][j] = X11[i][j];
        }
    }

    int r1_2=0;
    int r2_2 =n/2-1;
    int c1_2 = n/2;
    int c2_2 = n-1;
    for(int i=r1_2; i<=r2_2; i++)
    {
        for(int j=c1_2; j<=c2_2; j++)
        {
            res[i][j] = X12[i][j];
        }
    }

    // int r1_3=n/2;
    // int r2_3 = n-1;
    // int c1_3 = 0;
    // int c2_3 = n/2-1;
    // for(int i=r1_3; i<=r2_3; i++)
    // {
    //     for(int j=c1_3; j<=c2_3; j++)
    //     {
    //         res[i][j] = X21[i][j];
    //     }
    // }

    // int r1_4=n/2;
    // int r2_4 =n-1;
    // int c1_4 =n/2;
    // int c2_4 =n-1;
    // for(int i=r1_4; i<=r2_4; i++)
    // {
    //     for(int j=c1_4; j<=c2_4; j++)
    //     {
    //         res[i][j] = X22[i][j];
    //     }
    // }

    for (int i = 0; i < res.size(); i++) 
    { 
        for (int j = 0; j < res.size(); j++) 
        std::cout << res[i][j] << " "; 
        std::cout << "\n"; 
    } 

    return res;


    
}

std::vector<std::vector<int>> add_matrix(std::vector<std::vector<int>> X, std::vector<std::vector<int>> Y)
{   
    std::vector<std::vector<int>> res;
    res.resize(X.size(), std::vector<int>(X.size(), 0));

    for(int i=0; i<X.size(); i++)
    {
        for(int j=0; j<X.size(); j++)
        {
            res[i][j] = X[i][j] + Y[i][j];
        }
    }

    // for (int i = 0; i < res.size(); i++) 
    // {                                                                                   
    //     for (int j = 0; j < res.size(); j++) 
    //     std::cout << res[i][j] << " "; 
    //     std::cout << "\n"; 
    // } 

    return res;
}

// Multiply two matrices using Devide and Conquer
// approach.
// complexity = theta(n^3)
std::vector<std::vector<int>> multiply_Dev_Cnq(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B)
{   
    int n = A.size();
    std::vector<std::vector<int>> C;
    C.resize(n, std::vector<int>(n, 0));
    if(n==1)
    {
        C[0][0] = A[0][0]*B[0][0];
        // std::cout<<C[0][0]<<"\n";
    }
    else
    {
        std::vector<std::vector<int>> A11;
        A11.resize(n/2, std::vector<int>(n/2, 0));
        A11 = devide_copy_matrix(A, 0,(n/2-1), 0, (n/2-1));
        std::vector<std::vector<int>> A21;
        A21.resize(n/2, std::vector<int>(n/2, 0));
        A21 = devide_copy_matrix(A, (n/2),(n-1), 0, (n/2-1));
        std::vector<std::vector<int>> A12;
        A12.resize(n/2, std::vector<int>(n/2, 0));
        A12 = devide_copy_matrix(A, 0,(n/2-1), (n/2),(n-1));
        std::vector<std::vector<int>> A22;
        A22.resize(n/2, std::vector<int>(n/2, 0));
        A22 = devide_copy_matrix(A, (n/2),(n-1), (n/2),(n-1));

        std::vector<std::vector<int>> B11;
        B11.resize(n/2, std::vector<int>(n/2, 0));
        B11 = devide_copy_matrix(B, 0,(n/2-1), 0, (n/2-1));
        std::vector<std::vector<int>> B21;
        B21.resize(n/2, std::vector<int>(n/2, 0));
        B21 = devide_copy_matrix(B, (n/2),(n-1), 0, (n/2-1));
        std::vector<std::vector<int>> B12;
        B12.resize(n/2, std::vector<int>(n/2, 0));
        B12 = devide_copy_matrix(B, 0,(n/2-1), (n/2),(n-1));
        std::vector<std::vector<int>> B22;
        B22.resize(n/2, std::vector<int>(n/2, 0));
        B22 = devide_copy_matrix(B, (n/2),(n-1), (n/2),(n-1));

        std::vector<std::vector<int>> C11;
        C11.resize(n/2, std::vector<int>(n/2, 0));
        C11 = devide_copy_matrix(C, 0,(n/2-1), 0, (n/2-1));
        std::vector<std::vector<int>> C12;
        C12.resize(n/2, std::vector<int>(n/2, 0));
        C12 = devide_copy_matrix(C, (n/2),(n-1), 0, (n/2-1));
        std::vector<std::vector<int>> C21;
        C21.resize(n/2, std::vector<int>(n/2, 0));
        C21 = devide_copy_matrix(C, 0,(n/2-1), (n/2),(n-1));
        std::vector<std::vector<int>> C22;
        C22.resize(n/2, std::vector<int>(n/2, 0));
        C22 = devide_copy_matrix(C, (n/2),(n-1), (n/2),(n-1));



        
        C11 = add_matrix(multiply_Dev_Cnq(A11, B11), multiply_Dev_Cnq(A12, B21));
        C12 = add_matrix(multiply_Dev_Cnq(A11, B12), multiply_Dev_Cnq(A12, B22));
        C21 = add_matrix(multiply_Dev_Cnq(A21, B11), multiply_Dev_Cnq(A22, B21));
        C22 = add_matrix(multiply_Dev_Cnq(A21, B12), multiply_Dev_Cnq(A22, B22));

        join_matrix(C11, C12, C21, C22, C.size());



        
    }

    return C;
    


}


int main()
{
    std::vector<std::vector<int>> C;
    C.resize(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> A {{1, 2}, 
                                    {3, 4}}; 
                                 
    std::vector<std::vector<int>> B{{1, 0,}, 
                                    {0, 1}}; 
                                    
    // multiply_naive(A,B,C);

    C = multiply_Dev_Cnq(A,B);
    
    std::cout<<"Result=>\n";

   for (int i = 0; i < A.size(); i++) 
    { 
        for (int j = 0; j < A.size(); j++) 
        std::cout << C[i][j] << " "; 
        std::cout << "\n"; 
    } 

    return 0;
}