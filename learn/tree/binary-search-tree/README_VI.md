# Binary Search Tree

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Cây Tìm Kiếm Nhị Phân (BST) là một dạng cây nhị phân được rèn giũa dưới duy nhất một điều luật thép: Toàn bộ gia phả nằm bên trái của một nút BẮT BUỘC nhỏ hơn dữ liệu của nút đó, và toàn bộ gia phả cắm bên phải BẮT BUỘC lớn hơn. Thuộc tính tuyệt vời này đẻ ra tốc độ tìm kiếm truy lục, bứng và cắm rễ mới siêu phàm so với cây thường.

## Phương pháp
1. **Tìm kiếm (Search):** Áp giá trị cần tìm vô ngay gốc. Nếu khớp thì lụm. Nhỏ hơn thì vứt hết bên phải, rẽ gắt bẻ lái chạy tọt sang trái dò tiếp. Lớn hơn thì lật ngược về bên phải. Cứ thế.
2. **Chèn (Insert):** Thi triển y hệt xì-tai tìm kiếm cho đến khi té rớt bộp xuống một ngõ cụt trống không. Tại chỗ thủng đó, cắm cái nút mới vào là xong, bảo đảm luật lệ không mảy may xê dịch.
3. **Xoá (Delete):** Truy ra cái nút chướng gai mắt. Đứng trước 3 viễn cảnh:
   - Nó không có con cái bấu víu: Phá hủy, cắt dây.
   - Có 1 đứa nheo nhóc: Bứng nó, nối thẳng đứa con lên cha của nó, nhảy cóc 1 nấc.
   - Có mọc đủ 2 con gánh vế: Mò qua bên nhánh phải, lùng sục ra đứa nhỏ nhất. Bốc số liệu đứa đó đắp đè huề vốn lên nút sắp chặt, rồi tiến hành xóa thủ tiêu cái đứa nhỏ nhất bị dư thừa ấy đi.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Truy lục, Chèn, Chặt: Dễ dãi thì O(log N). Hắc ín xui cực điểm đưa vô một mảng xếp thẳng tắp từ sẵn, sẽ lệch cán thành list và thoái hoá bết dính mốc O(N).

- Độ phức tạp không gian:
  - O(N) cho từng phân mảnh sinh thái. Call stack tùy vào mức xui xẻo độ sâu cây.
