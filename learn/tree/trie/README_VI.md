# Trie (Prefix Tree)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Trie (Cây Tiền Tố) là tổ chức cấu trúc bậc cao mài dũa độ bén thiết kế chuyên trị mảng truy vết rà soát tốc độ thần sầu các bộ chuỗi ký tự. Mỗi phân mảnh string chui vào lòng máy phân tách xé vụn ra nhốt riêng từng mẫu ký tự trượt dọc xuống tháp. Nó là linh hồn tối thượng thổi sức sống cho các ứng dụng auto-complete (gợi ý gõ phím) hoặc bói từ điển.

## Phương pháp
1. Giăng mạng Nút ngậm chặt một cấu trúc map (`unordered_map`) khóa dính từng mẫu ký tự con quăng nối cáp truyền xuống thế hệ nhánh. Quẹt thêm một mảng cờ Boolean phát tín hiệu kiểm định đây có phải điểm rơi kết thúc tạo ra từ vựng hợp lệ hay không.
2. **Chèn (Insert):** Mổ xẻ chuỗi móc từng ký tự ra đập vô vòng lặp. Thiếu chữ nào trên trục dò đẻ gọt nhánh phát sinh thêm chữ đó. Rơi trúng đáy chuỗi, quét sơn cắm cờ mốc `TRUE` để lưu lại vết thành tụ.
3. **Bới Tìm (Search):** Rà theo ống phễu, dập từng vết ký tự rọi bước xuống lòng cấu trúc. Pha tìm kiếm ăn điểm tuyệt đối khi lóp ngóp thò mặt chạm tới cuối cùng ngay cái chữ bắt gặp dán bùa cờ Boolean xác sống báo đúng điểm tụ dừng chữ.
4. **Hỏi thăm Tiền Tố (Prefix-matching):** Copy paste y xì cách đánh hơi trên, nhưng khoan hồng bỏ qua ải xét duyệt cờ Boolean kết liễu, chỉ cần chứng nhận không bị gẫy nhịp đứt gánh giữa đường đi là ném luôn kết quả True.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Nạp chữ, Vạch lá tìm sâu, Hay dò tiền tố cũng đều dẫm chân tại chỗ đóng đinh: O(L), L móc mộc mạc chính là độ dài thượt của cái chữ nhét vào. Nhanh vô song siêu phàm.
  
- Độ phức tạp không gian:
  - O(N * L * Bảng mã ký tự) nở nang phồng rộp cắn bộ nhớ cực khủng theo cấp số lượng vốn từ từ điển bơm vô hệ thống. Nặng đô phình chướng nếu không chơi chiêu kỹ thuật nén.
