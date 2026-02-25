# Floyd-Warshall (Thuật toán Tìm Mọi Tuyến Cước Ngắn Nhất)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Dijkstra hay Bellman thì giỏi đi đẻ đường bắn gốc từ đúng một cái chóp rốn duy nhất tỏa đi tứ phía (Single-Source). Còn Floyd-Warshall là ông tổ của ngành quy hoạch động, mang tham vọng gánh cả bầu trời, thầu gọn múc trọn đánh bại giải pháp nhào lộn càn quét tìm con đường ngắn nhất móc nối giữa Tất Cả Mọi Cặp Nốt (All-Pairs) bất kỳ trong đồ thị, chả cần biết gốc gác. Quyền năng khét tiếng nhờ chơi chiêu đánh tráo thông cung qua các trạm trung chuyển trung gian.

## Phương pháp
1. **Luyện cốt Ma Trận Kề:** Rũ bỏ kiểu chứa danh sách mỏi mắt, thuật sắm cho mình một cái sa bàn kích thước VxV, trải đường lát ô lưới cự li thô. Khoảng cách móc vòng qua rốn mình về mình tự ăn số 0. Mố nối cụt chưa có dây ăn vô cực INF. Còn lại cắm số vô mảng xôi.
2. **Kẹp Ốc Nhồi Nhét Trạm Trung Chuyển (Transit):** Đập cốt nhão nhoẹt xối bằng ba lớp vòng lặp lồng gài xoáy ốc For (k, rồi tới i, rồi xuống j). Cái ý niệm rớt ra từ trời nằm ở cái nút k kia. Ta đứng trên nút i nhìn về nút j, lỡ mà ngậm hòm tính phí cự li trạm bắt nhảy cầu vòng vớt qua đảo nhỏ trạm trung chuyển nút k mà nó còn bèo bọt thóp hơn cái chi phí mua vé đi thẳng trực tiếp từ i->j xưa cũ kia, thì xé vé rẹt lấy vé nhảy qua nút trung chuyển k ghi bản cập nhật cự ly lẹ cho kịp nóng. Quét nát ba vòng là chín muồi hoàn mỹ toàn tập đồ thị.
3. **Phá án Âm Độ (Negative cycle):** Bọn ma mãnh này trốn kỹ chui hầm rất hăng. Sau khi luyện chảo quật V^3 lần tơi tả, ngó vô đường chéo cái mảng ma trận, nếu ô lật nhảy từ nút u về đúng nút u mà không phải số 0, lại lởm lòi rớt xuống ra tiền ÂM, báo động đỏ quăng còi thét ngay hố giun sập tiệm có Chu Trình Âm bủa lưới bao vây rồi đâm chết cự ly.

## Độ phức tạp
- Độ phức tạp thời gian:
  - O(V^3) nát bét não xoay vòng ba lớp dập khuôn đan máy móc chặt chẽ không tha một mốc cùi bắp thừa cặn nào kẹt dưới xô đá. Ăn cạp cục mỡ to kinh khủng chọi đồ thị phình phèo kẹo rễ mỡ nốt (số V to đùng). Tiện nhưng nuốt chửa thong thả lanh lẹ cho bọn đồ thị tí xíu.
  
- Độ phức tạp không gian:
  - O(V^2) căng cái lưới màng nhện bự hình vuông vuông chiềng chõng ngay bề ngang dọc bung phè chứa chật cái mảng hai chiều to tướng ngốn RAM chót vót vung sòng phẳng diện tích ma trận. Nóng não gánh sức nặng nhàn nhã code ngắn ngủn bá đạo.
