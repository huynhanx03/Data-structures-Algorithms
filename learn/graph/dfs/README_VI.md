# DFS (Thuật toán Tìm kiếm Theo Chiều Sâu)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Đối nghịch BFS, DFS (Depth-First Search) là chàng điệp viên liều mạng đâm xiên thủng lủng lún sâu ngoằn ngoèo cắm thẳng tắp cào xuống tận hốc kẹt sâu tít tắp đáy cùng của một nhánh lẻ loi. Tinh thần của DFS là nhắm mắt làm liều, chừng nào đâm sầm nổ đầu gãy cổ rớt vô đường cùng (Dead-end) bí lối mới chịu giật ngoắt lùi chân (Backtrack) chạy lùi lại cái ngã ba rẽ gần nhất hòng móc tiếp sang nhánh ngõ hẻm khác. Thuật toán là công thức chuẩn mực kinh điển để dò đường thoát khỏi mê cung.

## Phương pháp
1. **Động cơ Đệ Quy (Recursion):** Thay vì vác cái Queue dài thòng lọng như BFS, DFS quất thẳng đệ quy tận dụng cái cấu trúc máy Call Stack có sẵn để nhúng sâu dần xuống lòng đất.
2. **Cày Ải Mở Đường:** Chui qua chui lại từng cái nốt liền kề. Hễ chộp được con nốt láng giềng nào chưa dán tem bùa "đã thăm" thì chui tõm sáp vô ruột nó tự phát lặp lại điệp khúc bới tung chui rúc hệt như lúc đầu móc rộp đến lúc ngỏm thì quay đầu.
3. **Quay Đầu Bờ (Backtracking):** Vì là đệ quy ăn sâu cắm rễ, nên hễ rúc kẹt hang tối nấc đệ quy tự nhiên rụng sụp giúp thuật toán co giò lùi lội ngược trả lại rễ cha dễ dàng uyển chuyển chả tốn một giọt máu toán học nhân tạo dư thừa nào.

## Độ phức tạp
- Độ phức tạp thời gian:
  - O(V + E) lân la hạch sách trát đòi nợ chui lùng từng đỉnh, vuốt rờ sờ soát từng cuộn dây kết nối cặn kẽ vắt kệt.

- Độ phức tạp không gian:
  - O(V) chịu hao mòn rỉ sét mất dung lượng cấp cho call stack máy do nhúng chìm đệ quy lún lấp sâu nhất tương đương với độ dài tuyệt đối của con đường thọt dài cọc nhất trong cây. Cỡ O(V) cho con mảng cắm bảng chốt nốt điểm.
