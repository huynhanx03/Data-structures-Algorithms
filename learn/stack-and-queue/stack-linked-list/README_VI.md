# Stack (Linked List Implementation)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Ngăn xếp được cài đặt bằng danh sách liên kết có thể co giãn tuỳ thích, triệt tiêu được rủi ro bị trào mảng như cách làm trước. Ta dùng danh sách liên kết đơn, vị trí "đỉnh" luôn luôn là phần tử đứng đầu tiên (head) trong danh sách liên kết gốc.

## Phương pháp
1. **Push (Thêm):** Tạo nút mới, kéo con trỏ `next` của nút này về `top` hiện hành, cuối cùng là gán `top` thành nút vừa tạo. Rất giống hàm `chèn đầu` (insertAtHead).
2. **Pop (Rút):** Dữ liệu nằm ở điểm `top` hiện tại sẽ được trích ra, dời con trỏ `top` xuống nút đăng sau lưng nó (`top->next`), và giải phóng luôn nút đang chễm chệ ngay đỉnh kia. Rất giống thao tác `xoá phần tử ở đầu`.
3. **Peek (Nhìn):** Truy xuất và bắn ra dữ liệu tại nút đang được phong làm `top`.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Push, Rút, Nhìn đỉnh: O(1) (mọi thao tác đều thực hiện trên nút ngọn, khỏi mất công rà tìm gì cả).

- Độ phức tạp không gian:
  - O(N) tuỳ vào bao nhiêu khối đang đọng lại trong máy, danh sách chèn vào đến đâu mới cấp rác đến đấy, triệt tiêu vụ bỏ ngỏ lãng phí bộ nhớ.
