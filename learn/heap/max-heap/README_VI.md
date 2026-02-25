# Max Heap (Đống Hóa Lớn Nhất)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Đống hóa (Max Heap) mang thân phận là một cây nhị phân Hoàn Chỉnh (Complete Binary Tree), bị xiềng xích dưới luật ép buộc: Nút cha lúc nào cũng phải to cao dũng mãnh hơn hoặc bằng các nút con của nó. Cấu trúc này phong vương cho phần tử bá đạo lớn nhất luôn hiên ngang ngự trị độc tôn rực rỡ ngay ở ngọn (root). Đặc sản của Heap là thay vì gầy dựng cây trổ nhánh bằng con trỏ cồng kềnh, người ta bóp bẹp dí ép cây vào thẳng một cái mảng (Array) một chiều đánh số xài siêu mượt tốc độ.

## Phương pháp
1. **Lưu trữ ngầm:** Bọc gọn lỏn cây bên trong một cái mảng `vector`. Chỉ số nút cha `i` thì có thể soi thẳng ra địa chỉ đứa con bên trái bằng `2 * i + 1`, và đứa con bên phải tại đích xác `2 * i + 2`.
2. **Nạp thêm (Insert / `heapifyUp`):** Ném phần tử mới thô bạo vào tít chót đuôi mảng. Ngay lập tức cho nó tự sủi bọt, thi triển thuật trèo tường (`heapifyUp`) đá đít hoán vị hất ngược với thằng cha của nó liên tục nếu lỡ nó bự con hơn ông ba nó, leo cho đến khi cam chịu an tọa.
3. **Bốc đỉnh (Delete Max / `heapifyDown`):** Cúp điện lột ngôi thằng bự nhất trên chóp râu, túm cổ ném thẳng hòn đá chót mảng (thằng bét nhất, yếu nhất) lên nhét thế chỗ vào ngai vàng, chém bỏ cành cụt đuôi mảng đó đi. Do thằng bét tự nhiên chễm chệ ngôi cao chót vót phạm thượng, nó phải tức tốc bị kéo tụt đánh rớt hạng (`heapifyDown`) bằng cách dò so kè với hai thằng con hai bên, con nào đô con hơn thì hoán vị nhường ngôi lại. 

## Độ phức tạp
- Độ phức tạp thời gian:
  - Bốc hoặc Sờ nắm giá trị Max: O(1)
  - Chèn nạp & Hạ bệ xóa đỉnh: O(log N) tuân thủ nghiêm ngặt chiều sâu của rễ cây hoàn chỉnh không mảy may xê dịch.

- Độ phức tạp không gian:
  - O(N) bám chặt sát bộ nhớ ôm bao nhiêu đấy phần tử cấu thành mảng ruột.
