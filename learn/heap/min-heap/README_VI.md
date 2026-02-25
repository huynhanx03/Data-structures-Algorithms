# Min Heap (Đống Hóa Nhỏ Nhất)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Về thực thể, Min Heap giống y lột y xì đúc khuôn một cái Max Heap lộn ngược đầu đuôi. Bộ luật vặn vẹo áp đặt thắt ngặt buông xuống quy định: Bất kì lão làng nút cha nào thò chân ra cũng bắt buộc chứa giá trị trị số phải triệt để nhỏ bé, thua thiệt hoặc tệ lắm là ngang cơ bầy con nheo nhóc dưới đáy. Nhờ trò này, bé út còi cọc nhất lại chễm chệ trèo vinh dự leo tót lên an tọa chiếm đóng vương miệng Root (đỉnh cành).

## Phương pháp
1. **Lưu trữ ngầm Mảng:** Mượn tạm tấm áo giáp `vector` chèn dồn dập tống thẳng một cây nhị phân rễ dày khít khìn khịt dựa rập khuôn tính toán bằng các mốc số học thần kinh quen thuộc (trái `2*i+1`, phải `2*i+2`).
2. **Nạp thêm (Insert / `heapifyUp`):** Chích thêm đồ chơi giá trị vào tận đuôi mảng trễ nải nhất. Khởi động tên lửa đẩy sủi tăm bò lên từ dưới đất chui trồi (`heapifyUp`), đè ngửa ông già cha nó ra gọt nếu lỡ ngóng thấy cha còn béo, đô con lớn số hơn thân mình hòng đục đoạt ngôi trèo lên tước vị chính đáng.
3. **Bốc đỉnh (Delete Min / `heapifyDown`):** Nhấc ném giật xả thẳng cái rác bé lít nhít tận chóp ra khỏi hàng. Sau đó vớ nắm cổ thằng nhõi xui rủi chót vót đuôi mảng thay hồn đổi xác đập nhồi nó trám vô lỗ hổng của thằng đỉnh chóp. Chém bay đuôi đi. Con bù nhìn thế quèn trôi thế vai bị hất hủi bèn vướng phải luật rừng, bị trục xuất kéo chìm giáng cấp xô đẩy tọt xuống dưới (`heapifyDown`), liên tục thi thố lựa chọn giữa con cái dưới nhánh, bốc thằng nào còi xương nhỏ nhoi hơn đá đít nhô hoán ngôi ngược lên, đến khi xẹp xụi thì nằm im.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Truy vết Min: O(1)
  - Thêm thắt chèn & Rút hầm chóp nhọn: O(log N) do trói bịt chặt rào cản chiều sâu rễ.

- Độ phức tạp không gian:
  - O(N) giam lòng nhốt mảng array bao nhiêu ăn bấy nhiêu tấc diện tích.
