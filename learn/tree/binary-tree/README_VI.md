# Binary Tree

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Cây Nhị Phân (Binary Tree) là một cấu trúc dữ liệu phân cấp, trong đó mỗi nút (node) con sẽ đẻ ra tối đa hai nhánh con: gọi nôm na là nhánh trái và nhánh phải. Cấu trúc này phá vỡ vòng vây tuyến tính thông thường, đóng vai trò bản lề nền tảng để bung lụa cho vô vàn những siêu hình thể phức tạp hơn ra đời (BST, AVL, Heap).

## Phương pháp
1. **Cấu trúc:** Mọi giá trị được bọc trong một Nút gồm `data`, cộng thêm hai cọng dây trỏ `left` và `right`.
2. **Chèn:** Khởi hành từ `root` (gốc). Nếu rỗng, nhét thẳng vào gốc. Ngược lại, tiếp tục lao xuống các tầng thấp hơn (thường định hướng rẽ trái/phải thông qua phép so sánh thô sơ) dò dẫm đến khi kiếm được một khe trống thì nạp nút mới vô.
3. **Xóa:** Việc xóa hơi rối rắm, yều cầu định vị nút mục tiêu, bứng nó đi và dùng một nút thế thân (thường đào ở dưới đáy mút tận cùng) đắp vào chỗ khuyết, cẩn thận móc nối lại mọi nhành con lủng lẳng bên dưới để không đứt ruột.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tìm kiếm, Chèn, Xóa: O(N) nếu xui rớt trúng cái cây mọc nghiêng một luồng dão tuột như danh sách, đạt O(log N) nếu cây tự mọc tỏa ra đều đặn.

- Độ phức tạp không gian:
  - O(N) tương đương dung lượng N nút. Call stack đệ quy ăn mòn vô đúng độ sâu của rễ cây.
