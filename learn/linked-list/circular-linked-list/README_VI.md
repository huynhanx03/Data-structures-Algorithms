# Circular Linked List

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Danh sách liên kết vòng là một biến thể trong đó mọi nút đều nằm trên một "vòng tròn" khép kín. Không có điểm kết thúc (`NULL`) ở đuôi mảng. Thay vào đó, con trỏ `next` của nút cuối cùng sẽ trỏ cuộn ngược lại vào nút đầu tiên.

## Phương pháp
1. **Cấu trúc:** Chỉ cần lưu duy nhất một con trỏ `tail` (đuôi) là đủ. Vì `tail->next` luôn là nút đầu tiên (head), ta có thể can thiệp vào cả hai đầu mảng cực nhanh với O(1).
2. **Chèn:**
   - Ở đầu: Chèn nút mới vào ngay sau nút `tail`. Lúc này nút mới nằm ở vị trí đầu tiên của vòng tròn.
   - Ở cuối: Chèn nút mới vào ngay sau nút `tail`, và thao tác cực kỳ quan trọng là dời mốc `tail` sang chỉ vào chính nút mới bọc thêm đó.
3. **Duyệt:** Vòng lặp `do-while` rất uy lực để duyệt loại cấu trúc này vì phải kiểm tra chốt chặn điểm dừng vòng lặp chính là quét đến khi lộn về lại điểm phát xuất ban đầu.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Truy cập/Tìm kiếm: O(n)
  - Chèn đầu: O(1)
  - Chèn cuối: O(1) (nhờ lợi thế sử dụng một con trỏ `tail`)
  - Xoá: O(n)

- Độ phức tạp không gian:
  - O(n) dùng để chứa `n` nút.
