# Cấu Trúc Dữ Liệu & Giải Thuật

[VI](./README_VI.md) | [EN](./README.md)

Tổng hợp các cấu trúc dữ liệu và giải thuật kinh điển. Mỗi thuật toán nằm trong một thư mục riêng kèm giải thích chi tiết và mã nguồn.

## Nội Dung

| Chủ đề | Thuật toán | Mô tả |
|---|---|---|
| Sắp xếp | [Bubble Sort](./sorting/bubble-sort/README.md) | Đổi chỗ liên tiếp các phần tử kề nhau cho đến khi danh sách được sắp |
| Sắp xếp | [Selection Sort](./sorting/selection-sort/README.md) | Tìm phần tử nhỏ nhất và đặt lên đầu |
| Sắp xếp | [Insertion Sort](./sorting/insertion-sort/README.md) | Xây dựng danh sách đã sắp từng phần tử một |
| Sắp xếp | [Merge Sort](./sorting/merge-sort/README.md) | Chia đôi danh sách, sắp xếp từng nửa rồi trộn lại |
| Sắp xếp | [Quick Sort](./sorting/quick-sort/README.md) | Chọn phần tử chốt và phân hoạch các phần tử quanh nó |
| Tìm kiếm | [Binary Search](./searching/binary-search/README.md) | Tìm phần tử trong mảng đã sắp bằng cách chia đôi không gian tìm kiếm |
| Danh sách liên kết | [Singly Linked List](./linked-list/singly-linked-list/README.md) | Danh sách mà mỗi nút trỏ tới nút tiếp theo |
| Danh sách liên kết | [Doubly Linked List](./linked-list/doubly-linked-list/README.md) | Mỗi nút trỏ tới cả nút trước và nút sau |
| Danh sách liên kết | [Circular Linked List](./linked-list/circular-linked-list/README.md) | Nút cuối nối ngược lại nút đầu |
| Ngăn xếp & Hàng đợi | [Stack (Array)](./stack-and-queue/stack-array/README.md) | Cấu trúc LIFO cài bằng mảng |
| Ngăn xếp & Hàng đợi | [Stack (Linked List)](./stack-and-queue/stack-linked-list/README.md) | Cấu trúc LIFO cài bằng danh sách liên kết |
| Ngăn xếp & Hàng đợi | [Queue (Array)](./stack-and-queue/queue-array/README.md) | Cấu trúc FIFO cài bằng mảng |
| Ngăn xếp & Hàng đợi | [Queue (Linked List)](./stack-and-queue/queue-linked-list/README.md) | Cấu trúc FIFO cài bằng danh sách liên kết |
| Cây | [Binary Tree](./tree/binary-tree/README.md) | Cấu trúc phân cấp, mỗi nút có tối đa hai con |
| Cây | [Binary Search Tree](./tree/binary-search-tree/README.md) | Cây nhị phân với trái < gốc < phải |
| Cây | [AVL Tree](./tree/avl-tree/README.md) | Cây tìm kiếm nhị phân tự cân bằng |
| Cây | [Trie](./tree/trie/README.md) | Cây tiền tố dùng để tìm kiếm và lưu trữ chuỗi hiệu quả |
| Cây | [Segment Tree](./tree/segment-tree/README.md) | Cây dữ liệu cho truy vấn và cập nhật trên đoạn |
| Cây | [Fenwick Tree](./tree/fenwick-tree/README.md) | Cây dữ liệu cho truy vấn và cập nhật trên đoạn |
| Heap | [Max Heap](./heap/max-heap/README.md) | Cây nhị phân đầy đủ với nút cha luôn lớn hơn nút con |
| Heap | [Min Heap](./heap/min-heap/README.md) | Cây nhị phân đầy đủ với nút cha luôn nhỏ hơn nút con |
| Bảng băm | [Hash Table (Chaining)](./hashing/hash-table-chaining/README.md) | Xử lý xung đột bằng danh sách liên kết tại mỗi bucket |
| Bảng băm | [Hash Table (Linear Probing)](./hashing/hash-table-linear-probing/README.md) | Xử lý xung đột bằng cách dò tuyến tính |
| Bảng băm | [Double Hashing](./hashing/double-hashing/README.md) | Xử lý xung đột bằng hàm băm thứ hai làm bước nhảy |
| Bảng băm | [Rolling Hash](./hashing/rolling-hash/README.md) | Hàm băm đa thức cho bài toán so khớp chuỗi |
| Đồ thị | [BFS](./graph/bfs/README.md) | Duyệt theo chiều rộng, khám phá từng tầng một |
| Đồ thị | [DFS](./graph/dfs/README.md) | Duyệt theo chiều sâu, đi sâu nhất có thể rồi quay lui |
| Đồ thị | [Dijkstra](./graph/dijkstra/README.md) | Tìm đường đi ngắn nhất từ một đỉnh nguồn trong đồ thị có trọng số |
| Đồ thị | [Bellman-Ford](./graph/bellman-ford/README.md) | Tìm đường đi ngắn nhất, hỗ trợ cạnh có trọng số âm |
| Đồ thị | [Floyd-Warshall](./graph/floyd-warshall/README.md) | Tìm đường đi ngắn nhất giữa mọi cặp đỉnh |
| Đồ thị | [Prim](./graph/prim/README.md) | Xây cây khung nhỏ nhất bằng cách mở rộng từ một đỉnh |
| Đồ thị | [Disjoint Set Union](./graph/disjoint-set-union/README.md) | Quản lý các thành phần liên thông với phép hợp và tìm |
| Đồ thị | [LCA](./graph/lca/README.md) | Tìm tổ tiên chung gần nhất của hai nút trong cây |
| Quy hoạch động | [Digit DP](./dynamic-programming/digit-dp/README.md) | Đếm các số thỏa tính chất chữ số bằng DP trên từng chữ số |
| Toán học | [Big Number](./math/big-number/README.md) | Số học với số nguyên lớn tùy ý |
| Toán học | [Coordinate Compression](./math/coordinate-compression/README.md) | Nén miền giá trị lớn về không gian chỉ số nhỏ gọn |
