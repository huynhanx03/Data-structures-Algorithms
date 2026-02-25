# Prim (Thuật toán Prim - Cây Khung Nhỏ Nhất)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Nắm chóp giật cái hồn của cây khung nhỏ nhất (Minimum Spanning Tree - MST), Prim nổi rần rần dùng chiêu nẩy lở bồi đắp. Cứ hình dung bạn gieo một hạt giống gốc cây, cái mảng màng nhầy tơ nhện bắt đầu sùi bọt nở loang rỉ dần ra. Cứ tới đâu có cọng lông tơ bén rễ nào nhẹ kí đỡ hao tốn năng lượng (rẻ tiền nhất) nứt lột đồ thị là nó luồn lách ôm ngoạp, bám rễ vươn mầm nuốt trọn cục đó về làm thuộc địa vào rễ gốc khổng lồ. Tuốt luốt đến khi tóm cổ lột da gánh hết sạch sành sanh V cái nhụy (đỉnh) là xong cái cây gân guốc nhẹ nhàng nhất đồ sộ trên đời.

## Phương pháp
1. **Lọc Rây Bằng Túi Min-Heap:** Cũng lôi cái `priority_queue` Min-heap lủng lẳng lót hầu bao. Ưu tiên đút cồi rễ bóc trần (trọng lượng 0) vô túi nilon trước. Chuẩn bị cắm biển báo hiệu "Đã Mọc Rễ Thuộc Địa" vô ằng lằng mảng InMST (bool) để dẫu có tóm được chóp rẻ cũng coi cẩn thận đừng tham để rơi vô lỗ vòng tránh tạo lưới bẫy kẹt màng dây xích rễ.
2. **Loang Tơ Vét Máng Gọn Nhất:** Đào vớt vác xác cái cục tơ bọc có mác vé tiền hời ôi rẻ rách nhất ra khỏi thúng bao nilon. Tra mảng hỏi xoáy đáp xoay dòm coi thằng nốt lòi nhòi này bị nuốt vô cái cây khung chưa. Chóp rễ bị đánh dấu vội đã được gặm nuốt `inMST[u] = true`, lấy bao bố hốt tổng tiền chi phí `totalWeight += weight`.
3. **Câu Nhử Bọn Nhõi Xung Quanh:** Rà rẫm xung quanh cục mới lôi đó, quơ quào tất cả láng giềng bưng bít mớ dây ngoằn ngoèo kế cận, nhưng chỉ xới múc đưa bọn con hoang chưa dính rễ `!inMST[v]` trịch thượng nhét vào lại mảng Min-heap đặng tranh sủng luộc lại chờ phiên đấu tố mẻ lọc chao đảo sau cùng là vừa khéo lòi ra rễ khít. 

## Độ phức tạp
- Độ phức tạp thời gian:
  - O(E log V) mướt mát lả lướt vuốt đục chọc băm móc khoét đúng cái Min-Heap để cày nát từng cụm mớ mạng cạnh nhện nơm dây rễ (E) giăng mắc tủa đi. (Độ lớn cái priority bự V nên bào log V).
  
- Độ phức tạp không gian:
  - O(V + E) vác bao tải chở sọt mảng kề Adjacency List cồng kềnh đựng hết ngần ấy gốc chóp cọc nhọn V ròng dây nhợ E xâu xé đan xen dính dớp vào nhau. Thêm cái hàng chờ bé ti ti cỡ E nhốt thêm vào là tràn kho RAM.
