# Stack (Array Implementation)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Ngăn xếp (Stack) là cấu trúc tuyến tính tuân thủ nghiêm ngặt nguyên tắc LIFO (vào sau, ra trước). Hãy tưởng tượng như một chồng dĩa: bạn chỉ có thể cất dĩa mới lên đỉnh và cũng chỉ có thể rút dĩa từ trên đỉnh. Tự viết cấu trúc này bằng mảng đòi hỏi ta cấp phát một mảng giới hạn kích thước trước, kèm theo một biến đếm vị trí "đỉnh" (top).

## Phương pháp
1. Khởi tạo một mảng cấp phát động và một biến `top = -1` để ám chỉ ngăn xếp đang rỗng.
2. **Push (Thêm):** Tăng biến tĩnh `top` lên một nấc sau đó gán dữ liệu vào mảng vị trí đó. Phải kiểm tra tràn (overflow) trước khi thao tác.
3. **Pop (Rút):** Trích xuất phần tử ngay tại `top`, sau đó giảm `top` xuống một nấc. Phải kiểm tra rỗng (underflow) trước khi thao tác.
4. **Peek (Nhìn):** Đơn giản chỉ xem dữ liệu nằm ở `top` mà không mảy may làm suy giảm `top`.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Thêm, Rút, Nhìn đỉnh, Sờ kiểm rỗng: O(1)

- Độ phức tạp không gian:
  - O(N) với N là dung lượng mảng cấu hình ban đầu, bộ nhớ sẽ bị choán chỗ mặc định không cần biết có bỏ phần tử nào vào hay chưa.
