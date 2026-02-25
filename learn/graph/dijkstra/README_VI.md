# Dijkstra (Thuật toán Tìm Đường Đi Ngắn Nhất)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Thuật toán Dijkstra là ông hoàng xưng vương nắm trùm tuyệt kỷ dò tìm con đường đi ngắn nhất (Shortest Path) trên đồ thị có Trọng Số DƯƠNG (Positive Weights). Nó vươn vòi dựa trên não trạng Tham Lam (Greedy), tức là hở thấy từ tâm gốc rễ hiện tại quét mắt dòm rảo xung quanh, hễ nhánh nào có vẻ ít tốn kém tiền xe nạp xăng nhất thì lập tức vọt nhảy qua cưỡi liền nhánh đó ưu tiên càn quét trước. 

## Phương pháp
1. **Lưỡi hái Min-Heap:** Giắt lưng sẵn một rổ `priority_queue` chuyên chắt lọc moi thóp điểm có khoảng cách nhỏ nhất móc lộ diện ra trước cửa. Khởi chạy ụp giá trị điểm xuất phát bằng 0 vô mảng nhớ, phần lớn đồ thị còn lại tạm cho cự ly đi tới là tận Vô Cực.
2. **Siết chốt Tham Lam (Relaxation):** Rút gã có cự ly nhỏ nhất ra khỏi rổ. Lùng sục mớ bòng bong hàng xóm nối nhánh lân cận với gã. Dùng công thức: "Nếu quãng đường lội bộ chạy vòng qua gã mà rẻ mạt đỡ tốn công tốn sức hơn cái quãng đường kỉ lục hiện tại thu vào trước kia, thì đập nát cái khoảng cách hiện tại, ghi chèn bản ghi ngắn hơn mới tanh vào". Xong tóm cổ nạn nhân mới nhÉT lại vô rổ cho mẻ lọc lặp tiếp theo.
3. **Chặn xui rủi:** Vì bản tính nôn nóng vội vã đánh nhanh thắng nhanh, cấm kị đồ thị mang mầm mống Lưới nhện Cạnh Ấm (Negative edges), vì lúc đó sự đánh tráo đường tắt rẻ tiền bị sụp đổ toàn tập, thuật toán vấp ngã vỡ mặt đi lùi ngược về thời kỳ mù lòa.

## Độ phức tạp
- Độ phức tạp thời gian:
  - O((V + E) log V) cực độ sung mãn, với `E` mấu nối dây nhợ vướng lằng nhằng và `V` chóp tháp phải đào bới. `log V` là công sức bào hao phải trả để khuân vác đẽo gọt con mảng cái sàng `priority_queue`.
  
- Độ phức tạp không gian:
  - O(V) bao thầu cái rổ lọc với một rổ mảng dán nhãn khoảng cách, tiêu tốn vừa y bằng đúng số chóp phải xử lý, nói chung là thon thả chán so với sự phè phỡn của cái bảng xỏ hầm ngục ma trận.
