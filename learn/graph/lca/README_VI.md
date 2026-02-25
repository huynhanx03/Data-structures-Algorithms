# LCA (Tổ Tiên Chung Gần Nhất - Kỹ thuật Nhảy Nhị Phân)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Ngự trị đồ thị cây, bài toán mò tìm mặt tổ tông LCA (Lowest Common Ancestor) đòi hỏi đào bới hạch lùng truy tông điểm đứt gãy cội nguồn chung nằm tầng thấp nhất vươn rễ che chở mọc đẻ trực tiếp cho hai điểm con chắt cụ thể bất kỳ vất vưởng đâu đó dưới tán cây. Chơi trò chạy lêu hêu nhích từng ô đi bộ bò lết ngược dòng lên chót vót là vô phương chịu trận hỏa ngục TLE. Hóa phép quy nạp Binary Lifting (Nhảy Cóc Nhị Phân) chắp cánh bay vèo vèo theo cấp số nhân lũy thừa 2 lướt mây leo đỉnh thần thông dẹp kẹt vướng bận tốc độ nhấp nháy O(log N).

## Phương pháp
1. **Luyện Đan Bước Nhảy Điện (Binary Lifting Precomputation):** Thả DFS cày xẻ rạch đồ thị, thu hoạch cất giữ độ sâu `depth` vạch rõ cấp bậc giai cấp thứ tự nhánh cây. Khai móng dựng giàn giáo mảng bảng 2 chiều `up[u][i]` bóp tréo vặn thuật lưu trữ gốc mặt "Tổ tiên đời thứ 2^i của nhánh u". Chiêu công thức vàng nắn bảng bồi lũy: `up[u][i] = up[up[u][i - 1]][i - 1]` (Tổ đời thứ 4 là cha của cụ Tổ đời thứ 2 của dòng nhánh này).
2. **Dàn Trận Cân Giai Cấp (Depth Alignment):** Nhận trát yêu cầu kiểm 2 điểm. Phải bắt thằng lặn chìm mọc sâu thẳm dưới đít nhảy rút cự ly bám cọc bật người ngoi ngược theo lũy thừa 2 bay xẹt lên vạch ngang hàng song le ép trơ cùng số độ sâu `depth` ngang chuẩn vạch đích với thằng cao hơn kia.
3. **Tuyệt Kĩ Song Hành Kẹp Nách Vượt Rào:** Hai thằng đã đứng ngang chuẩn mốc lơ lửng, giờ kẹp tay thi triển nhảy ngược vút chung tiếp lên mốc cao tầng chóp. Ép con bit lết từ to tới còi, hễ soi thấy hai ông cụ tổ nhảy dự kiến khác dòng nòi `up[u][i] != up[v][i]` (tức là chưa chạm đầu húc cái nốt ngã ba), thì lẹ làng sải bước nhảy xẹt cả đôi dời chân bám sụn tót lên đứng vào cái mốc tổ đó. Cứ chạy nát dọn nháp thế ắt chân chúng nó sẽ bám móng chầu rìa dừng ngay tắp tựa gối cắm thẳng sát vách gót chân ông tổ tông cần tìm con cái `up[u][0]`.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Cày bẫy lợp bảng nạp thuốc: O(N log N) bôi quét giăng mảng nhấc tầng vót chỉ thị kịch nóc Call Stack.
  - Test nọc độc bắn truy vấn: O(log N) búng lẩy lò xo giật nhảy cấp số nhân 2 phi thẳng lên nấc.

- Độ phức tạp không gian:
  - O(N log N) mảng bọng ôm no chứa căng 2 chiều `up[][]` bóc lột nhồi máu vắt kiệt RAM ôm tổ tông nhị phân. O(N) lo lót dọn dẹp biến duy trì chiều sâu độ kiếp vinh quang.
