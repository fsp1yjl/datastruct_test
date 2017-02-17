#include <iostream>
using namespace std;

class Sort {
    private:
       int a[100];
       int current_length ;
       int sorted_arr[100];
    public:
        void set_arr(int temp[],int len);
        void show_arr();
        void bubble_sort();
        void select_sort();
        void insert_sort();
        //int * bubble_sort(int arr[],int len);
};

// 设置私有待排序数组
void Sort::set_arr(int temp[],int len){
    int i = 0;
    for( i = 0; i < len; i ++) {
        this->a[i] = temp[i];
    }
    this->current_length = len;
}

// 显示待排序数组
void Sort::show_arr(){
    int i;
    cout << "show arr :" << endl;
    for(i = 0 ; i < this->current_length; i ++) {
        cout <<  this->a[i] << "-";
    }
    cout << endl;

}

// 冒泡排序
void  Sort::bubble_sort() {
    cout << "the length of the array which is waiting for sort:" <<endl;
    cout << this->current_length << endl;
    this->show_arr();
    int i,j;
    for(i=0; i<this->current_length-1; i++) {
        for(j = 0; j < this->current_length-i-1;j++) {
            if(this->a[j] > this->a[j+1]) {
                int temp;
                temp = this->a[j];
                this->a[j] = this->a[j+1];
                this->a[j+1] = temp;
            }
        }
    }
    cout << "after bubble sort:" << endl;
    this->show_arr();
}

// 选择排序
void  Sort::select_sort(){
    cout << "the length of the array which is waiting for bubble sort:" <<endl;
    cout << this->current_length << endl;
    this->show_arr();
    int i,j;
    for(i=0; i < this->current_length-1; i++) {
        int min_index = i;
        int min = this->a[i];
        for(j = i+1; j < this->current_length; j++) {
            if(this->a[j] < min) {
                min = this->a[j];
                min_index = j;
            }
        }
        if(min_index != i) {
            int temp;
            temp = this->a[i];
            this->a[i] = this->a[min_index];
            this->a[min_index] = temp;
        }
    }
    cout << "after bubble sort:" << endl;
    this->show_arr();
}

//插入排序

void Sort::insert_sort(){
    int len = this->current_length;
    int temp[100] ;
    int sorted_count = 0;

    int i,j;
    for( i = 0; i < len; i++) {
        if(i == 0) {
            temp[i] = this->a[i];
            continue;
        }
        for(j = i -1; j>=0; j--) {
            if(this->a[i] < temp[j]) {
                temp[j+1] = temp[j];
                continue;
            } else {
               break;
            }
        }
        temp[j+1] = this->a[i];
    }
    cout << "insert sort:"<<endl;
    for( i = 0; i < len; i++) {
        this->a[i] = temp[i];
    }
}

int main(int argc, char* argv[]){
    
    Sort bubble,select;
    int temp[] = {1,2,4,5,3,9,7,2,1};
    bubble.set_arr(temp,9);
    bubble.bubble_sort();
    select.set_arr(temp,9);
    select.select_sort();

    Sort insert;
    insert.set_arr(temp,9);
    insert.insert_sort();

    
    return 0;
}