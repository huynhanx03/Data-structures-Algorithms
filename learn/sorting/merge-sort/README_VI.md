# Merge Sort

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Merge Sort là một giải thuật thuộc dạng Chia để trị (Divide and Conquer). Ý tưởng chính là chia mảng đầu vào thành hai nửa, sắp xếp đệ quy song song cả hai nửa, và cuối cùng thì trộn hai nửa đã xếp lại thành một mảng hoàn thiện.

## Phương pháp
1. **Chia (Divide):** Tìm điểm chính giữa (mid) để chia mảng thành 2 nửa: `left` và `right`.
2. **Trị (Conquer):** Đệ quy tiếp tục sắp xếp lặp lại cho hai nửa mảng trái - phải.
3. **Kết hợp (Combine - Merge):** Ráp hai nửa vừa được sắp xếp vào với nhau. Bước này được hiện thực bằng cách so thứ tự lần lượt phần tử của 2 phần từ ngoài vào trong và bốc dần phần tử nhỏ hơn đem gộp.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tốt nhất: O(n log n)
  - Trung bình: O(n log n)
  - Xấu nhất: O(n log n)

- Độ phức tạp không gian:
  - O(n), do luôn yêu cầu các mảng tạm phân chia để chép phần tử trong bước rã-hợp (merge).
