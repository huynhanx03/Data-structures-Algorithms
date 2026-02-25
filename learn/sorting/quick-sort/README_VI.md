# Quick Sort

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Quick Sort cũng là một thuật toán Chia để trị (Divide and Conquer). Điểm mấu chốt là chọn một phần tử nhất định để làm ngòi nổ "chốt" (pivot) và sau đó phân hoạch mảng theo cái chốt đó. Mọi phần tử nhỏ hơn sẽ đặt trước chốt, và mọi phần tử lớn hơn được tóm về đằng sau chốt.

## Phương pháp
1. Bốc một phần tử làm chốt (VD: luôn chọn phần tử ở vị trí cuối cùng).
2. Phân hoạch mảng sao cho tất cả những phần tử thuộc vế nhỏ hơn dồn hết sang trái chốt, và những cái to hơn dồn qua phải. Khi mảng xong một đợt vét, chốt sẽ nhảy thẳng về đúng "toạ độ" đã sắp xếp của nó.
3. Liên tục đệ quy phần logic y xì như vậy cho các mảng-con-phía-trước-chốt và các mảng-con-phía-sau-chốt.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tốt nhất: O(n log n)
  - Trung bình: O(n log n)
  - Xấu nhất: O(n^2) (đây là khi lỡ gặp mảng đã được sếp thứ tự rồi mà toàn gặp cái chốt bốc phải ngay cái số cực đại hoặc cực tiểu)

- Độ phức tạp không gian:
  - Trung bình cần O(log n) chỗ trống cho Call Stack trên đệ quy, tới O(n) lỡ xui rớt vô Worst Case.
