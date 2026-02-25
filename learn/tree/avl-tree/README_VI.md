# AVL Tree

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Vấn nạn lớn nhất của Binary Search Tree thô là hễ đút vô mảng đã rập khuôn đều tăm tắp thì nó rớt thành đường thẳng thoái hoá ngay mốc tồi tệ O(N). Nhằm hoá giải lời nguyền này, cấu trúc tự-cân-bằng (self-balancing) khai sinh. AVL lưu trữ răn đe thuộc tính "chiều cao", chủ mưu kích hoạt lốc xoáy xoay vặn thắt cục bộ xua tan mọi độ nghiêng lệch hễ ngửi thấy tháp đòn bẩy thọt quá nặng.

## Phương pháp
1. Mọi phép toán dọn cỗ cơ bản đúc nguyên xi từ lò BST sang.
2. **Bộ Nhận Diện Độ Cao & Chỉ Số Cán Cân (Balance Factor):** Lắp vào mỗi Nút con số `height`. Tính lệch qua phép trừ kinh điển: `cao(trái) - cao(phải)`.
3. **Tuyệt kĩ vặn mình (Rotations):** Rơi khỏi ngưỡng an toàn, lọt chênh vênh (> 1 hoặc < -1), phải gồng bẻ xoay cân lại:
   - Nghiêng tít Trái-Trái -> Quật văng vặn Phải (`rotateRight`).
   - Sập lề Phải-Phải -> Hất cổ bẻ căng Trái (`rotateLeft`).
   - Rớt hình Zig-zag Trái-Phải -> Sơ cứu quặn Trái đưa về mảng bự Trái-Trái, sau đó dứt điểm quét vặn Phải.
   - Trật nấc Zig-zag Phải-Trái -> Nắn xương Phải chuyển thể chuẩn, làm nhát kết liễu móc vòng Trái.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Lùng sục, Thêu dệt chèn, Bẻ rễ xoá: Đứng hiên ngang bảo kê không bao giờ vượt trần giới hạn siêu thanh O(log N).

- Độ phức tạp không gian:
  - Phủ diện tích vật lý O(N). Depth tầng ngăn xếp call stack bị bóp chết tại điểm cứng O(log N).
