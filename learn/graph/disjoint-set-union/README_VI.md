# DSU (Tập Hợp Tách Rời)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Disjoint Set Union (DSU) hay còn mệnh danh là Union-Find, là cỗ máy sinh ra để trị mảng quản lý quyền lực phe phái bè phái trong đồ thị. Thuật toán mạnh mẽ bám đuổi hạch toán xem đỉnh này đỉnh kia có cùng chung gốc rễ chui ra từ một tổ đội băng đảng hay không, và gom gộp tức tốc sáp nhập hai băng phái khác biệt chập làm một vương quốc nếu thấy cần thiết.

## Phương pháp
1. **Ban Sơ Chế:** Khai mở cấu trúc lập cho mỗi phần tử một cái mảng làm Vua (Parent). Khởi điểm sinh ra ai cũng làm trùm, tự thân vận động làm cha mẹ chính mình tản mác như bầy kiến tẻ tách. Đắp thêm mảng Ranh Kích Cỡ (`sz`) cấp vốn gốc 1 lính phụ trợ.
2. **Tuyệt kỹ Tìm trùm tóm gốc - Nén đường đi (`findSet` + Path Compression):** Đệ quy túm tóc truy dòng dõi gốc rễ móc từ đít cái nhánh xòe nốt leo dần lên con tổ tông. Điêu toa ở chỗ thuật nhảy cóc nén đường (Path Compression): Cứ khi nào vạch ra được mặt tổ tông trùm thì giật dây gắn thẳng trôn nút đang gọi trỏ bùm béo một nhát sang vị trí lật ngửa ngay tại ghế tổ tông, rút ngắn thời gian chui hầm dài dằng dặc cho tất cả bè cánh gọi lần kế tiếp. Quá đẳng cấp trí mạng.
3. **Kết minh - Nhập Sáp theo Cỡ (`unionSet` + Union By Size):** Chộp lấy mặt 2 cụ tổ của 2 thằng ranh con muốn gộp nối kết. Kiểm nếu máu mủ chung tông thì từ giã huề vốn. Còn khác hệ thì mang binh lính (`sz`) ra đong đếm. Thằng gốc rễ yếu thế hơn dập đầu bái bái nối kết đu bám cắm nốt vô thằng có binh tôm tướng cá bự khỏe hơn, thằng thắng gom hốt nuốt sáp nhập binh lực size vô người. Logic tối thu nhỏ rễ lỡ tọt leo mọc sâu. 

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tìm cha gốc, Nhập kết giao phái: O(α(N)). Hàm nghịch đảo Inverse Ackermann α(N) này trượt bay thần tốc lết tăng trưởng cực kỳ nhỏ giặt lắt lỏi siêu việt (lượng N bé tẹo mòn mỏi tới mức không vượt nổi con số 4 cho toàn vũ trụ điểm chạm), trên thực tế được giới lập trình thủ răn đe ca ngợi phong thánh là O(1) chạy tức thời như điện giật.

- Độ phức tạp không gian:
  - O(N) duy trì nuôi dưỡng sương sương tốn đúng hai sải tay mảng `parent` với `sz`. Khá nhẹ kí chóp bu.
