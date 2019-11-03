#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main() {
    freopen("BookReading.in", "r",stdin); //输入重定向，输入数据将从D盘根目录下的in.txt文件中读取 
    // freopen("BookReading.out", "w",stdout); //输出重定向，输出数据将保存在D盘根目录下的out.txt文件中 
    int num, page_num, torn_page, reader;
    vector<int> torn_pages;
    vector<int> readers;
    int i = 0;
    cin >> num;
    int temp;
    while (i < num) {
        scanf("%d%d%D", &page_num, & torn_page, &reader);
        
        // 读取一行
        // getchar();
        while (cin.get() != '\n') {
            cin >> temp;
            torn_pages.push_back(temp);
        }
        while (cin.get() != '\n') {
            cin >> temp;
            readers.push_back(temp);
        }
        for (int k = 0; k < torn_pages.size(); k++) {
            cout << torn_pages[i] << " ";
        }
        cout << endl;
        torn_pages.clear();
        readers.clear();
        i++;
    }
}