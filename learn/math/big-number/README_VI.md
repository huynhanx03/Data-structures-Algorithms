# Big Int (Xử lý Số Lớn)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Ngôn ngữ C++ keo kiệt túng quẫn chỉ cấp cho lập trình viên trần giới hạn con số tới nóc `long long` (64 bit) tức khoét chừng 18 tới 19 chữ số là toang ngập lủng lụt báo lỗi tràn số (Overflow). Khi bài toán oái ăm quẳng vô mặt dãy số mập mạp nhồi béo xì hơi dài dằng dặc tới tận mút chỉ hàng ngàn, hàng trăm củ chữ số (thường rớt dạng chuỗi string), thì bộ ngầm máy lật ngửa hết đát. Big Int (Số lớn) mang tham vọng gồng gánh gom đúc sáp nhập chuỗi trần thô mộc đó thả vô xào nấu toán học thông qua con mảng (Array/Vector). Trói buộc ghép chặt lại xâu xé đan xen mô phỏng rập khuôn lại bài múa toán nhân chia cộng trừ mầm non lẹt đẹt của học sinh tiểu học đặt tính dọc mượn có nhớ đắp số.

## Phương pháp
1. **Lưới Sàn Kép Ép Cơ Số (Base Compression Array):** Để dành RAM và bơm ga cho CPU chạy đỡ xịt khói rát họng, Big Int chẳng thèm chẻ lẻ nhét đần độn cất từng nấc 1 chữ số cùi bắp vào một ô mảng. Thay vậy nó ép bóp móp méo ngốn dồn cục gom chung một nạm bốc trọn 9 chữ số gán xép ngét nhét cọ xát kẹp chung tọt vào một cái lồng ô duy nhất (chơi ngông dùng ngòi nổ cơ số `base = 1e9`). Cực kỳ bá đạo nén gọn thu nhỏ 9 lần kích cỡ mảng.
2. **Cộng Khứ Hồi Cấp Vốn (+ / -):** Quẩy toán cộng trừ thủ công dựng ngược theo trục dọc. Xỏ dây luồn xâu từ đít đuôi (các ô đựng đít hàng đơn vị gom 9 số) cuộn ngược trào lên trên. Hễ đập 2 nấc cộng lại lù lù lút trần sập khung cơ số `1e9` thì chẻ xéo thả dư ném rác lấy trúng phần nghêu ngao húp dư (`res % base`) cất riêng, còn vác cục xương chia lấy phần nạc (`res / base`) vắt lên óc móc đem quăng kẹp sang mâm tạ hàng tiếp theo làm gánh nợ có Nhớ (Carry).
3. **Phân Rã Vét Khô (Compare / Multi / Div):** Mô phỏng y đúc tay mơ vẽ nháp trên vở giấy. Nhân thì tách mảnh ghép đôi hai vòng chập nẹp đít đẩy dần mâm bù trọn gánh. So chiều dài (Size) lết dòm đầu lỏ dỏm xem ai xưng cụ tổ trước. Xén cụt lòi dòi dọn cỏ tận tay quét rác số 0 còi cọc ứa lừa mọc lùm xùm trên chóp đầu (Leading zeros).

## Độ phức tạp
- Độ phức tạp thời gian:
  - Cộng trừ thoăn thoắt tuyến tính bào hao chạy nhẹ O(N). Phép nhân 2 số bành ki trâu bò rớt dập phao câu O(N * M) ặc ạch (với N, M vóc dáng bự mảng ép của 2 con búp bê). Phép chia đày ải tàn gốc O(N^2).

- Độ phức tạp không gian:
  - O(N) giăng mảng Vector nuốt chửng độ trương phình chiều dài con số cợt nhả tốn chưa đầy vài muỗng RAM lẻ xé dọc xắt tư chéo.
