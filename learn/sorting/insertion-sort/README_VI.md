# Insertion Sort

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Ý tưởng tương tự như quá trình bạn sắp xếp các lá bài trên tay. Ta sẽ chia mảng ra làm phần đã sắp xếp và phần chưa sắp xếp. Giá trị từ phần chưa sắp xếp sẽ được nối đưa vào đúng vị trí tương ứng trong phần đã sắp xếp.

## Phương pháp
1. Duyệt mảng từ phần tử thứ 2 (`i = 1`) đến vị trí `n-1`.
2. So sánh phần tử hiện tại (`key`) với những phần tử nằm trước nó trong mảng con đã xếp `[0, i-1]`.
3. Đẩy tất cả những phần tử trong mảng con đã sắp xếp mà lớn hơn `key` lên một vị trí về phía bên phải.
4. Chèn phần tử `key` vào vị trí khoảng trống vừa được dời.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tốt nhất: O(n) (khi mảng đầu vào đã sẵn ở trạng thái sắp xếp)
  - Trung bình: O(n^2)
  - Xấu nhất: O(n^2)

- Độ phức tạp không gian:
  - O(1), do sắp xếp tại chỗ (in-place).
