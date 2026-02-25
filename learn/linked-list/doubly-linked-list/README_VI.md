# Doubly Linked List

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Danh sách liên kết đôi là phiên bản nâng cấp của danh sách liên kết đơn bằng cách thêm một con trỏ `prev` chỉ ngược về phía trước vào mỗi nút. Việc này cho phép duyệt danh sách theo cả hai chiều (tới và lui) và giúp thao tác xoá một nút linh hoạt hơn rất nhiều.

## Phương pháp
1. **Cấu trúc Nút (Node):** Mỗi nút lưu `data`, con trỏ `next` và con trỏ `prev`.
2. **Chèn:** 
   - Khi nối một nút mới, con trỏ `prev` của nó phải nối với phần tử đứng trước nó, và con trỏ `next` của nút đứng trước thì trỏ vào nó, tương tự với phía sau.
   - Nếu chèn đầu mảng, con trỏ `prev` của nút head cũ sẽ trỏ vào nút mới.
3. **Xoá:** Cắt bỏ một nút yêu cầu định tuyến lại bằng hai đường nối: cho nút đằng trước trỏ vượt cấp tới nút đằng sau, và nút đằng sau trỏ ngược (prev) vượt cấp về nút đằng trước. Xoá bỏ an toàn nút bị rớt ra.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Truy cập/Tìm kiếm: O(n)
  - Chèn đầu: O(1)
  - Chèn cuối: O(n) (hoặc O(1) nếu bạn chủ động bảo trì thêm một biến trỏ `tail`)
  - Xoá: O(n) (để tìm ra nút), O(1) (thao tác đổi con trỏ để xoá)

- Độ phức tạp không gian:
  - O(n), tiêu tốn nhiều bộ nhớ hơn danh sách liên kết đơn một chút vì phải gánh thêm con trỏ `prev` trong từng nút.
