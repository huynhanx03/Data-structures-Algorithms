# Singly Linked List

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Danh sách liên kết đơn là một cấu trúc dữ liệu tuyến tính trong đó các phần tử không được lưu trữ tuần tự kề nhau trong bộ nhớ vật lý. Thay vào đó, mỗi phần tử (nút) chứa dữ liệu của nó và một con trỏ giữ địa chỉ của nút kế tiếp.

## Phương pháp
1. **Cấu trúc Nút (Node):** Mỗi nút lưu `data` và con trỏ `next`.
2. **Con trỏ Head:** Bản thân danh sách chỉ cần lưu lại con trỏ `head` (nút đầu tiên).
3. **Chèn:**
   - Ở đầu: Tạo nút mới, cho `next` của nút mới trỏ vào head hiện tại, rồi cập nhật lại `head`.
   - Ở cuối: Duyệt đến nút cuối cùng (có con trỏ `next` là null) và gán con trỏ next của nó vào nút mới.
4. **Xoá:** Duyệt dò tìm đến nút nằm ngay trước phần tử cần xoá, đổi con trỏ `next` bỏ qua nhảy cóc lên nút đăng sau nó. Cắt đứt và giải phóng bộ nhớ nút bị xoá khỏi danh sách.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Truy cập/Tìm kiếm: O(n)
  - Chèn đầu: O(1)
  - Chèn cuối: O(n) (vì phải duyệt lùng từ đầu tới đuôi do không lưu con trỏ đuôi)
  - Xoá: O(n)

- Độ phức tạp không gian:
  - O(n) dùng để chứa `n` nút.
