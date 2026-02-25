# Binary Search

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Tìm kiếm nhị phân được dùng để tìm kiếm một giá trị cực nhanh trong một mảng đã được sắp xếp. Thay vì dò tuần tự từ đầu đến cuối, nó sẽ liên tục chia đôi không gian tìm kiếm bằng cách so sánh phần tử cần tìm với phần tử ở chính giữa.

## Phương pháp
1. Khởi tạo hai con trỏ: `low` ở đầu (0) và `high` ở cuối (`n-1`).
2. Trong khi `low` <= `high`, tìm vị trí chính giữa `mid`.
3. Nếu phần tử ở vị trí `mid` chính là giá trị cần tìm, trả về `mid`.
4. Nếu phần tử ở `mid` lớn hơn giá trị cần tìm, ta thu hẹp khoảng tìm kiếm về nửa bên trái (`high = mid - 1`).
5. Nếu phần tử ở `mid` nhỏ hơn, ta thu hẹp tìm kiếm về nửa bên phải (`low = mid + 1`).
6. Trả về `-1` nếu vòng lặp kết thúc mà vẫn không tìm thấy.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tốt nhất: O(1) (khi xui xẻo trúng ngay điểm giữa ở bước đầu tiên)
  - Trung bình: O(log n)
  - Xấu nhất: O(log n)

- Độ phức tạp không gian:
  - O(1) cho phân tích lặp.
