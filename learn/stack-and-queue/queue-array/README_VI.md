# Queue (Array Implementation)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Hàng đợi (Queue) là cấu trúc tuyến tính đi theo nguyên lý FIFO (vào trước, ra trước). Mường tượng tựa như hàng người xếp hàng đứng đợi, ai tới mua trước thì lấy được bill trước và ra về. Việc cài đặt thông qua mảng kết hợp cơ chế lặp vòng (circular-array) giúp mảng tự lặp không gian, đảm bảo khi chạy đến hết biên phải vẫn có thể vắt chéo quay ngược về xài lại khoảng thừa nhả ra ở biên trái.

## Phương pháp
1. Tạo một mảng cấp phát động khởi đầu chứa tất tần tật các biến quản đốc: (`front` phía trước chờ rút, `rear` phía sau chờ đẩy mồi vô, `capacity`, tổng `size`).
2. **Thêm (Enqueue):** Đẩy một đối tượng vô đằng sau theo công thức vòng lặp `rear = (rear + 1) % capacity`. Đồng thời nâng biến size đếm lên. Tất nhiên xem xét phòng thủ trạng thái đầy ứ mảng.
3. **Rút (Dequeue):** Kéo kết quả từ phía `front` văng ra khở queue rúc vô biến giá trị. Chuyển tịnh tiến front vòng tròn bằng `front = (front + 1) % capacity`. Trừ hạ biến size đếm đi một nấc. Ngăn chặn dưới ngưỡng rỗng mốc.
4. Kích hoạt logic phép chia vô dư `%` sẽ đảm bảo sau khi biến con trỏ nhảy tới đít mảng, nó hoàn toàn mượt mà nhảy dội đầu chạy ngược lại về index 0.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Nạp thêm, Rút giảm, Chiêm ngưỡng đỉnh điểm: O(1)

- Độ phức tạp không gian:
  - O(N) với N là rào cản `capacity` mảng cấu trúc tĩnh cho mảng vòng.
