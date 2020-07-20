/*
By github.com/dev7060
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define max 9
using namespace std;
int grid[max][max]={0}, row, col, num;
int grid2[max][max]={{5, 3, 4, 6, 7, 8, 9, 1, 2}, {6, 7, 2, 1, 9, 5, 3, 4, 8}, {1, 9, 8, 3, 4, 2, 5, 6, 7},
{8, 5, 9, 7, 6, 1, 4, 2, 3}, {4, 2, 6, 8, 5, 3, 7, 9, 1}, {7, 1, 3, 9, 2, 4, 8, 5, 6},
{9, 6, 1, 5, 3, 7, 2, 8, 4}, {2, 8, 7, 4, 1, 9, 6, 3, 5}, {3, 4, 5, 2, 8, 6, 1, 7, 9}
};//win test
void createGrid(){
    int x3_row_counter=0;
    for(int i=0; i<9; i++){
        x3_row_counter=0;
        for(int j=0; j<9; j++){
            x3_row_counter++;
            if(grid[i][j]==0){
                cout<<"-";
            }else{
                cout<<grid[i][j];    
            }
            cout<<" ";
            if(x3_row_counter%3==0){
                cout<<"  ";
            }
        }
        cout<<endl;
        if(i==2||i==5){
            cout<<endl;
        }
    }
}
int inputs(){
    fflush(stdin);
    //cout<<"Row Col Num\n";
    cout<<endl;
    cin>>row>>col>>num;
    row--;
    col--;
    if(num>=0&&num<=9){
        return 1;
    }else{
        return 0;
    }
}
int check_row(int row){
    int arr[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int j=0; j<9; j++){
        arr[grid[row][j]]++; //no need for --, since considering array from 1 to 9
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    return 1;
}
int check_col(int col){
    int arr[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int j=0; j<9; j++){
        arr[grid[j][col]]++;
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    return 1;    
}
int check_box(){
    int arr[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=0; i<3; i++){
        for(int j=3; j<6; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=0; i<3; i++){
        for(int j=6; j<9; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    ////////////////////////////
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=3; i<6; i++){
        for(int j=0; j<3; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=3; i<6; i++){
        for(int j=3; j<6; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=3; i<6; i++){
        for(int j=6; j<9; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    ////////////////////////////////////////
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=6; i<9; i++){
        for(int j=0; j<3; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=6; i<9; i++){
        for(int j=3; j<6; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=6; i<9; i++){
        for(int j=6; j<9; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]!=1){
            return 0;
        }
    }
    return 1;
}
int check_box_random(){
    int arr[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=0; i<3; i++){
        for(int j=3; j<6; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=0; i<3; i++){
        for(int j=6; j<9; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    ////////////////////////////
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=3; i<6; i++){
        for(int j=0; j<3; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=3; i<6; i++){
        for(int j=3; j<6; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=3; i<6; i++){
        for(int j=6; j<9; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    ////////////////////////////////////////
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=6; i<9; i++){
        for(int j=0; j<3; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=6; i<9; i++){
        for(int j=3; j<6; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    arr[0]=0; arr[1]=0; arr[2]=0; arr[3]=0; arr[4]=0; arr[5]=0;
    arr[6]=0; arr[7]=0; arr[8]=0; arr[9]=0;
    for(int i=6; i<9; i++){
        for(int j=6; j<9; j++){
            arr[grid[i][j]]++;
        }
    }
    for(int k=1; k<10; k++){
        if(arr[k]>1){
            return 0;
        }
    }
    return 1;
}
void fill_random(){
    srand(time(0));
    int ran = (rand()%20)+5;
    for(int i=1; i<ran; i++){
        int digit=rand()%10;
        int r = rand()%10, c = rand()%10; //Note that % 10 yields a result from 0 to 9
        if(grid[r][c]==digit){
            continue;
        }else{
            //cout<<"entry";
            int count=0;
            grid[r][c]=digit;
            for(int i=0; i<9; i++){
                if(grid[r][i]==digit){
                    count++;
                }
            }
            if(count>1){
                grid[r][c]=0;
            }
            count=0;
            for(int i=0; i<9; i++){
                if(grid[i][c]==digit){
                    count++;
                }
            }
            if(count>1){
                grid[r][c]=0;
            }
            if(check_box_random()==0){
                grid[r][c]=0;
            }
        }
    }
}
int win_check(){
    for(int i=0; i<9; i++){
        if(check_row(i)==0){
            return 0;
        }
    }
    for(int i=0; i<9; i++){
        if(check_col(i)==0){
            return 0;
        }
    }
    if(check_box()==0){
        return 0;
    }
    return 1;
}
int main(int argc, char **argv)
{   fill_random();
    while(1){
        system("clear");
        if(win_check()==0){
            //cout<<"\nno win\n";
        }else{
            cout<<"Congratulations!\n";
            createGrid();
            break;
        }
        createGrid();
        while(inputs()==0){
        }
        grid[row][col]=num;

    }
    return 0;
}
