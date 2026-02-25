# Cây Fenwick (Trục Tọa Độ Nhị Phân)

[VI](./README_VI.md) | [EN](./README.md)

Cây Fenwick, hay còn gọi là Binary Indexed Tree (BIT), là một cấu trúc dữ liệu cho phép cập nhật các phần tử và tính tổng tiền tố trong một mảng số một cách hiệu quả. Cấu trúc này hỗ trợ cả hai thao tác này với độ phức tạp thời gian $O(\log N)$.

## Trực giác

Cây Fenwick kết hợp ý tưởng của mảng tổng tiền tố (prefix sum array) và cây khoảng (interval tree). Thay vì lưu tổng các phần tử từ $0$ đến $i$, nó lưu tổng các phần tử từ $i - \text{lowbit}(i) + 1$ đến $i$. Hàm $\text{lowbit}(i)$ trích xuất bit 1 thấp nhất của $i$, qua đó phân chia mảng thành một hệ thống phân cấp các khoảng. Sự sắp xếp khéo léo này cho phép cả thao tác cập nhật và truy vấn đi qua nhiều nhất $\log N$ nút.

## Cách tiếp cận

-   **Cấu trúc:** Một mảng `bits` kích thước $N+1$ (chỉ số bắt đầu từ 1). Phần tử tại chỉ số `i` chứa tổng của các phần tử trong khoảng $[i - \text{lowbit}(i) + 1, i]$.
-   **`lowbit(i)`:** Được tính toán bằng các phép toán bit: `i & -i`. Trong biểu diễn bù 2 (two's complement), `-i` tương đương với `~i + 1`. Phép toán này giúp cô lập (isolate) bit có ý nghĩa thấp nhất (least significant bit) có giá trị bằng 1.
-   **Cập nhật Điểm (`update(i, x)`):** Để cộng thêm `x` vào phần tử thứ $i$, ta phải cập nhật tất cả các khoảng trong mảng `bits` chứa phần tử thứ $i$. Ta liên tục tăng `i` thêm một lượng bằng `lowbit(i)` cho đến khi vượt quá kích thước mảng.
-   **Truy vấn Tiền tố (`query(i)`):** Để tính tổng từ $1$ đến $i$, ta cộng khoảng hiện tại `bits[i]` rồi di chuyển đến khoảng liền trước không giao nhau bằng cách liên tục trừ `i` đi `lowbit(i)` cho đến khi `i` bằng $0$.
-   **Truy vấn Đoạn (`queryRange(l, r)`):** Để tính tổng từ $l$ đến $r$, ta lấy hiệu của hai truy vấn tiền tố: `query(r) - query(l - 1)`.

## Độ phức tạp

-   **Thời gian:**
    -   Xây dựng (Build): $O(N \log N)$ bằng cách cập nhật từng phần tử. (Có thể tối ưu xuống $O(N)$).
    -   Cập nhật Điểm (Point Update): $O(\log N)$
    -   Truy vấn Đoạn (Range Query): $O(\log N)$
-   **Không gian:** $O(N)$ cho mảng `bits`.
