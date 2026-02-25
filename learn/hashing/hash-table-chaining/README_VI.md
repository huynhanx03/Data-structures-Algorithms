# Hash Table - Chaining (Bảng Băm - Kỹ Thuật Chuỗi)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Bảng Băm (Hash Table) sở hữu siêu quyền năng bóp méo thời gian tìm kiếm mảng bằng cách dùng Hàm Băm toán học để biến tấu chìa khóa định danh giáng thẳng xuống một con số index chính xác tuyệt đối. Cơ mà ngặt nỗi, thỉnh thoảng sẽ có nhiều chìa khóa rủi ro băm ra cùng một gốc tọa độ, sinh ra "đụng độ" (Collision). Kỹ thuật Nối Chuỗi (Chaining) phá giải bế tắc vô cùng thanh lịch: cho phép mỗi ô lưu trữ trên mảng đóng vai trò làm điểm neo tóm rễ khởi tạo ra một cái danh sách liên kết kéo dài vô tận, đùm bọc hết bọn tranh giành đụng độ.

## Phương pháp
1. **Sườn Cấu Trúc:** Tạo ra một dãy Mảng, nhưng mỗi ô trong mảng không chứa cục giá trị trơ trọi mà lại nắm giữ nguyên một cuốn Danh Sách Liên Kết (Linked List). Gọi M là biên độ mảng.
2. **Hàm Băm:** Sinh index ném thẳng phần tử thông qua phép modulo nguyên thủy: `key % M`.
3. **Bơm Xài (Insert):** Băm nát cái khóa để moi ra được số nhà ô bucket. Đẩy tót phần tử vào lồng ngực danh sách liên kết rủ rỉ treo nhép sát ngay ô bucket đó.
4. **Bới Tìm / Thanh Trừng:** Băm khóa tra ra số nhà ổ bucket. Cắm đầu rà soát từng đốt mắt xích rác rãi bên trong cuốn danh sách liên kết treo lủng lẳng tại chuồng đó để xác thực hoặc rút dao bứng bỏ mục tiêu.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Hên (Trung Bình): Chèn, kiếm, xóa đều thần tốc O(1) giả dụ cụ tổ băm đều tăm tắp phủ khắp mảng.
  - Xui nhọ (Worst): O(N) chui vào khe cửa hẹp nhất khi mọi số băm vô tình tấp tót hết vào chung đúng một cái hố bucket duy nhất, khiến nguyên bảng băm biến tướng thoái hóa thành một nhúm dây xích ngoằn ngoèo.

- Độ phức tạp không gian:
  - O(N + M) nuôi sống hố bucket `M` nằm chình ình cố định, cộng hưởng dồn dập tốn kém nuôi `N` cục dữ liệu đẻ nhánh thòng lọng thêm vào đằng sau.
