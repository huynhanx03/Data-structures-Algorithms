# Queue (Linked List Implementation)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Hiện thực Hàng đợi bằng danh sách liên kết sẽ triệt tiêu hoàn toàn nỗi lo sợ bị trào hạn ngạch cứng cấu hình trong cách làm cũ bằng mảng tĩnh. Ta có thể thả lỏng cho dữ liệu cuồn cuộn đổ dồn thêm tới tấp mà không phải chật vật tính toán logic con trỏ vòng hoặc canh me đầy giới hạn.

## Phương pháp
1. Có thể sử dụng Danh Sách Liên Kết Đơn giữ chốt song hành cắm hai cái neo nhận dạng: Neo `front` canh giữ đầu ra của luồng đợi (chính xác hơn là head) và cái ghim `rear` chặn hứng các tác thể xông vào nối gót (tail phần cuối).
2. **Thêm (Enqueue):** Đắp nối mắt xích mới ở đúng trạm `rear`. Buộc nút `next` cuối hiện thời xâu chỉ châm qua nút mới này, song song đẩy mũi neo `rear` nhích trượt tiếp qua chiếm thân nút ta vừa gắn vào. Cục diện mảng khởi điểm đen tối sơ khai rỗng tuếch, thì một phần tử mọc lẻ loi được khoác áo xài một thể hai chức vô định `front` và `rear`.
3. **Rút (Dequeue):** Nhả tung giũ mắt xích rác rưởi mút đầu `front`. Giải phóng trút phần dư để nhấc `front` búng dời chạy tiếp đằng sau nhận quyền anh hùng thế mạng. Hễ cái cuối bị xóa tận diệt thì `rear` cũng phải chịu reset hoàn dương về tay không (null).
4. **Nhìn (Peek):** Moi hiển thị trần trụi thẳng dữ liệu chất trong neo `front`.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tất cả phép nội công (Nhét, Nhổ bỏ, Nghía qua, Check Empty) thuần là tức thời chuẩn O(1).
- Độ phức tạp không gian:
  - O(N) bộ nhớ tùy độ co giãn đẻ nở động lực tuân theo bấy nhiêu khúc nút dây cương bạn gài vào khối xích thực tại. Colection rỗng sẽ tự nhiên thu hẹp dọn sạch tuyệt không để chiếm lố bãi chứa.
