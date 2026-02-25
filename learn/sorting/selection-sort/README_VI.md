# Selection Sort

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Ý tưởng là chia mảng thành hai phần: một phần đã sắp xếp và một phần chưa sắp xếp. Ban đầu phần đã sắp xếp là rỗng. Ta sẽ lặp đi lặp lại việc tìm phần tử nhỏ nhất từ phần chưa sắp xếp và đẩy nó về cuối của phần đã sắp xếp.

## Phương pháp
1. Khởi tạo vòng lặp từ `0` đến `n-1`. Đây là ranh giới giữa phần đã duyệt và chưa duyệt.
2. Tìm chỉ số của phần tử nhỏ nhất trong đoạn chưa sắp xếp `[i, n-1]`.
3. Hoán đổi phần tử nhỏ nhất vừa tìm được với phần tử đầu tiên của đoạn chưa sắp xếp (tại chỉ số `i`).
4. Lặp lại quá trình này cho đến khi toàn bộ mảng được sắp.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tốt nhất: O(n^2)
  - Trung bình: O(n^2)
  - Xấu nhất: O(n^2) (Luôn phải quét qua phần còn lại của mảng để tìm giá trị nhỏ nhất)

- Độ phức tạp không gian:
  - O(1), do sắp xếp tại chỗ (in-place).
