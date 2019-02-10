
#include <stdio.h>
#include <iostream>

using namespace std;

class Matrix
{
public:
    friend ostream &operator<<(ostream &os, Matrix &obj);
    int row;
    int col;
    double **mat;
public:
    Matrix(int r, int c){
        int i, j;
        row = r;
        col = c;
        mat = new double*[row];
        for(i = 0; i < row; i++){
            mat[i] = new double[col];
        }
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                mat[i][j] = 0.0;
            }
        }
    }
    
    Matrix(const Matrix &other){
        int i, j;
        row = other.row;
        col = other.col;
        mat = new double *[row];
        for(i = 0; i < row; i++){
            mat[i] = new double[col];
        }
        for(i = 0; i < row; i++){
            for(j = 0; j < row; j++){
                mat[i][j] = other.mat[i][j];
            }
        }
        
    }
    
    double &operator()(int i, int j){
        return mat[i][j];
    }
    
    Matrix &operator+=(const Matrix &obj){

        int i, j;
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                mat[i][j] = mat[i][j] + obj.mat[i][j];
            }
        }
        
        return *this;
        
    }
    
    Matrix &operator=(const Matrix &obj){
        if(this == &obj){
            return *this;
        }
        int i, j;
        for(i = 0; i < row; i++){
            delete mat[i];
        }
        delete mat;
        
        row = obj.row;
        col = obj.col;
        mat = new double *[row];
        for(i = 0; i < row; i++){
            mat[i] = new double[col];
        }
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                mat[i][j] = obj.mat[i][j];
            }
        }
        
        return *this;
    }
    
    
    
    Matrix operator*=(const Matrix &obj){
        Matrix temp(row, obj.col);
        int i, j, k;
        for(i = 0; i < row; i++){
            for(j = 0; j < obj.col; j++){
                temp.mat[i][j] = 0;
                for(k = 0; k < col; k++){
                    temp.mat[i][j] = temp.mat[i][j] + mat[i][k] * obj.mat[k][j];
                }
            }
        }
        *this = temp;
        return *this;
    }
};

ostream &operator<<(ostream &os, Matrix &obj){
    int i, j;
    for(i = 0 ; i < obj.row; i++){
        for(j = 0; j < obj.col; j++){
            os << obj.mat[i][j] << " ";
            
        }
        os << endl;
    }
    
    return os;
    

    
}

istream &operator>>(istream &is, Matrix &obj){
    int i, j;
    for(i = 0; i < obj.row; i++){
        for(j = 0; j < obj.col; j++){
            is >> obj.mat[i][j];
        }
    }
    return is;
}

int main()
{
    int row1, col1;
    cin >> row1 >> col1;
    Matrix table1(row1, col1);
    cin >> table1;
    
    int row2, col2;
    cin >> row2 >> col2;
    Matrix table2(row2, col2);
    cin >> table2;
    
    cout << table1(row1 / 2, col1 / 2) << endl;
    cout << endl;
    
    if(table1.col == table2.row){
        table1 *= table2;
        cout << table1 << endl;
    }
    else{
        cout << "ERROR!" << endl;
        cout << endl;
    }
    
    if(table1.row == table2.row && table1.col == table2.col){
        table1 += table2;
        cout << table1 << endl;
        
    }
    else{
        cout << "ERROR!" << endl;
        cout << endl;
    }
    
    table1 = table2;
    cout << table1;
    
    
    
    
}



