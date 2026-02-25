# Bubble Sort

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Ý tưởng chính là duyệt qua danh sách nhiều lần, so sánh các phần tử kề nhau và hoán đổi chúng nếu chúng nằm sai thứ tự. Quá trình duyệt này được lặp lại cho đến khi danh sách được sắp xếp. Các phần tử lớn nhất sẽ "nổi" (bubble) lên cuối mảng đầu tiên.

## Phương pháp
1. Dùng một vòng lặp ngoài để duyệt qua mảng `n-1` lần.
2. Dùng vòng lặp trong để so sánh các phần tử kề nhau từ vị trí `0` đến `n-i-1`.
3. Nếu phần tử hiện tại lớn hơn phần tử tiếp theo, hoán đổi chúng.
4. Sau mỗi chu kỳ của vòng lặp ngoài, phần tử lớn nhất (trong đoạn chưa sắp xếp) sẽ được đưa về đúng vị trí ở cuối mảng.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tốt nhất: O(n) (nếu cài đặt cờ kiểm tra dừng sớm, ngược lại là O(n^2))
  - Trung bình: O(n^2)
  - Xấu nhất: O(n^2)

- Độ phức tạp không gian:
  - O(1), do sắp xếp tại chỗ (in-place).
