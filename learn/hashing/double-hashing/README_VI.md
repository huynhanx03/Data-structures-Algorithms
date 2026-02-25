# Double Hashing (String Hashing / Băm Chuỗi Kép)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Hệ Băm mảng Chuỗi (String Hashing) hoá phép ma thuật biến thái toàn quyền rút gọn công chuyện nhọc nhằn nhai chữ khập khiễng lê lết thành bộ môn so kè độ lớn lùn cân não giữa hai con số bé cỏn con thoăn thoắt chớp nhoáng xẹt tia chớp. Đề phòng quỷ đội lốt tai bay vạ gió ác mộng đụng hàng băm nhầm băm lộn rập khuôn như đúc (khi dùng băm đơn), trò độ chế Double Hashing hai tay hai súng bọc hậu. Nó xay nghiền chữ chạy tuốt kẹp nắn nhào lộn xoay trục chia lấy dư liên tù tì trên đỉnh hai cái hố đen modulen khổng lồ hoàn toàn độc lập bất bại song song, dìm tỉ lệ rủi ro húc lọt khẽ dẫm chân lừa bịp về con số âm tuyệt đối vững chãi như bàn thạch.

## Phương pháp
1. **Kiến Trúc Nền:** Chấm nảy lẩy điểm bốc phét hai cục modulo nguyên tố cao vút tít tắp, trộn lẫn nhồi chung đập kẹp nhân bồi lũy thừa cơ số chém chia thớt lấy dư chặt chẻ kín mít.
2. **Luộc Chín Cuốn Theo Chiều Gió Pre-calculate:** Lướt rà cày quét chạy tuốt luốt một nhát một đi đường trượt từ trái sang phải, cuốn gói xát muối tẩm ướp tích luỹ dồn thu gom trọn cục trị số hash tiền tố nhồi ấn dính kẹp chặt lưu vô hai cục mảng 1 chiều riêng biệt 1-D (tốn O(N) xương cốt rải móng chuẩn bị xới đất gieo kho).
3. **Móc Họng Lấy Dấu Slicing (`getHash`):** Khi nổi hứng chọc ruột đoạt bắt lấy trích lọc mảng chuỗi con vắt khúc từ trạm `L` tới tận bến `R`, bộ máy xuất rập công thức trừ hao bạt quạt bay lượng hash rơm rác khúc dư gốc đuôi đứt gãy, nhồi lộn thêm tí toán học rút gọn nhấc kéo rẹt rẹt văng ra tận tay cặp đôi vé dấu vân tay nhận diện mã kép. Giờ so chữ dài ngoằn cởi truồng chỉ gom vô so hai hòn vé, ăn chắc kèo O(1), đả bại trò chạy O(K) còng lưng trỏ từng ngón soi kính lúp rọt rẹt tìm cọng chỉ.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Khởi công san lấp mặt bằng nạp năng lượng Pre-Computation: O(N) rà chậm cuộn tròn nuốt trọn băng cuốn dây chuyền nhồi một tua duy nhất.
  - Test nọc độc moi khoét nanh vuốt chuỗi con: Siêu tốc độ anh hùng quang minh chói loà O(1) chóp nhoáng giật điện bắn thẳng không gãy rụng.

- Độ phức tạp không gian:
  - O(N) xài cạn vắt đứt chứa gọn sương sương cất giữ một rổ 4 tấm chiếu mảng song hành vác nặng trữ lũy thừa và xâu nhồi nhét. Hoàn toàn vứt bỏ bốc hơi khái niệm phải chép lưu giữ cực kỳ thô thiển cục thịt chuỗi gốc.
