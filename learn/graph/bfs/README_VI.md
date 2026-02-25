# BFS (Thuật toán Tìm kiếm Theo Chiều Rộng)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
BFS đi càn quét đồ thị theo kiểu bung lụa sóng gợn lăn tăn lan từ từ ra bốn phương tám hướng (Level-by-level). Thay vì nhắm mắt lao cắm đầu đâm lún sâu tuột xuống dốc như DFS, thanh niên BFS tính cẩn trọng, ngó nghiêng thăm hỏi hết bà con hàng xóm sát vách xung quanh cho xong xuôi rồi mới dám cất bước đi xa thêm tầng nữa.

## Phương pháp
1. **Lõi Hàng Đợi (Queue):** Trái tim của BFS là hàng đợi Queue (vào trước ra trước FIFO) nhằm đảm bảo công lý: nốt nào bị phát hiện trước phải được ưu tiên lôi ra lấy cung xét hỏi trước.
2. **Loang sóng:** Thả nút đầu nguồn vô hàng đợi. Rút từng đứa ra, vạch lá lùng sục đám bạn bè nối dây trực tiếp với mạn sườn rễ mảng. Ai chưa bị rờ gáy thì dán nhãn "đã thăm", tóm cổ tống vô đuôi hàng đợi xếp lớp chờ ngày lên thớt.
3. **Truy Dấu:** Khôn ngoan tạo chừa sẵn mảng `parent` đánh dấu "thằng nào đẻ ra thằng nào" trong quá trình loang nhằm lỡ bắt được đích đến thì còn có dây rốn mà dò ngược truy tông đường lui. Do BFS bung đều, nếu đồ thị không có trọng số rắc rối, đường dò ra 100% đích xác là đường ngắn, tốn ít nhịp nhất.

## Độ phức tạp
- Độ phức tạp thời gian:
  - O(V + E) sòng phẳng rảo gót điểm danh đủ mặt từng cái đỉnh và vuốt trọn từng cái dây giăng mắc méo rớt cạnh nào.

- Độ phức tạp không gian:
  - O(V) xây rào cất kho nuôi cái danh sách hàng đợi với dàn nhãn cờ boolean đánh bóng trập trùng cắm móc nốt. Tiêu hao thuần thúy tối đa đúng kịch cỡ số bộ não nốt (Vertex).
