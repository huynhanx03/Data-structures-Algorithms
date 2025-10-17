#include "bits/stdc++.h"

using namespace std;

string s;

// id : vị trí của số đang xét bình thường bắt đầu từ trái sang phải (0 -> size - 1)
// flag: dấu hiệu để biết có lại giá trị max của vị trí trước đó chưa>
// nếu đã lấy thì chỉ có thể lấy giá trị từ 0 đến giá trị tại đó (0 -> s[i] - '0)
// chưa thì sẽ từ 0 -> 9
void dp_digit(int id, bool flag) 
{
    int cmp = s[id] - '0'; // giá trị tại id

    for (int i = 0; i <= flag ? cmp : 0; ++i) { // nếu thì 
        bool newflag = (i == cmp ? flag : 0); // nếu đã lấy tại cmp thì sẽ là 1 hoặc 0

        dp_digit(id + 1, newflag);
    }
}

int32_t maint()
{

}