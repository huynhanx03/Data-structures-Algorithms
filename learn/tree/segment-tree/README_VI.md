# Cây Phân Đoạn (Segment Tree)

[VI](./README_VI.md) | [EN](./README.md)

Cây Phân Đoạn (Segment Tree) là một cấu trúc dữ liệu linh hoạt được sử dụng để lưu trữ thông tin về các khoảng (hay đoạn) của một mảng. Nó cho phép truy vấn các khoảng một cách hiệu quả (như tính tổng, tìm giá trị nhỏ nhất/lớn nhất) trên một mảng, đồng thời hỗ trợ cập nhật các phần tử của mảng.

## Trực giác

Hãy tưởng tượng bạn có một mảng và cần thực hiện hai loại thao tác thường xuyên: cập nhật giá trị của một phần tử và tìm tổng (hoặc min/max) của các phần tử trong một khoảng cụ thể. Một cách tiếp cận ngây thơ sẽ mất $O(1)$ cho cập nhật nhưng $O(N)$ cho truy vấn (sử dụng mảng gốc) hoặc $O(N)$ cho cập nhật và $O(1)$ cho truy vấn (sử dụng mảng tổng tiền tố - prefix sum). Cây Phân Đoạn cân bằng các thao tác này, đạt $O(\log N)$ cho cả hai.

Nó thực hiện điều này bằng cách xây dựng một cây nhị phân trong đó các nút lá (leaf nodes) đại diện cho từng phần tử của mảng, và mỗi nút trong (internal node) đại diện cho một đoạn (một khoảng các phần tử) và lưu trữ giá trị tổng hợp (ví dụ: tổng, min, max) từ các đoạn con của nó.

## Cách tiếp cận

-   **Cấu trúc:** Là một cây nhị phân nơi mỗi nút đại diện cho một khoảng `[l, r]`.
    -   Nút gốc (root) đại diện cho toàn bộ mảng `[0, N-1]`.
    -   Nếu một nút đại diện cho `[l, r]` và $l \neq r$, nút con trái của nó đại diện cho `[l, mid]` và nút con phải đại diện cho `[mid+1, r]`, với $mid = (l+r)/2$.
    -   Nút lá đại diện cho một phần tử đơn lẻ `[i, i]`.
    -   Nó thường được cài đặt bằng một mảng kích thước $4N$ để đảm bảo đủ không gian lưu trữ các nút.
-   **Xây dựng (`build(node, start, end)`):** Đệ quy chia nhỏ mảng cho đến khi đạt đến các phần tử đơn lẻ (lá). Sau đó, khi đệ quy quay lui (unwind), tính toán giá trị của nút cha dựa trên các nút con của nó (ví dụ: `tree[node] = tree[left] + tree[right]`).
-   **Cập nhật Điểm (`update(node, start, end, idx, val)`):** Để cập nhật một phần tử tại vị trí `idx`, duyệt xuống cây đến lá đại diện cho `[idx, idx]`, cập nhật giá trị của nó, sau đó cập nhật tất cả tổ tiên của nó trên đường quay trở lại gốc.
-   **Truy vấn Đoạn (`query(node, start, end, l, r)`):** Để truy vấn một khoảng `[l, r]`:
    -   Nếu khoảng của nút hiện tại `[start, end]` hoàn toàn nằm ngoài `[l, r]`, trả về giá trị đơn vị (ví dụ: 0 cho tổng, $\infty$ cho min).
    -   Nếu khoảng của nút hiện tại `[start, end]` hoàn toàn nằm trong `[l, r]`, trả về giá trị của nút.
    -   Ngược lại, khoảng bị giao nhau một phần. Đệ quy truy vấn các nút con trái và phải rồi kết hợp kết quả của chúng.

## Độ phức tạp

-   **Thời gian:**
    -   Xây dựng (Build): $O(N)$ vì nó thăm mỗi nút trên cây đúng một lần.
    -   Cập nhật Điểm (Point Update): $O(\log N)$ do nó duyệt qua chiều cao của cây.
    -   Truy vấn Đoạn (Range Query): $O(\log N)$ do nó thăm tối đa 4 nút ở mỗi cấp độ của cây.
-   **Không gian:** $O(N)$. Cụ thể, một mảng kích thước $4N$ thường được sử dụng để biểu diễn cây.
