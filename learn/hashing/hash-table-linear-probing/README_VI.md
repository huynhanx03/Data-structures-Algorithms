# Hash Table - Linear Probing (Bảng Băm - Thăm Dò Tuyến Tính)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Khi bóng ma đụng độ (collision) sờ gáy — tức là hai cái chìa khóa oái oăm băm chung ra xáp lá cà giành giật một ghế ngồi duy nhất — Thăm Dò Tuyến Tính (Linear Probing) ra oai dẹp loạn bằng mệnh lệnh: "Chỗ này kẹt rồi, vác xác cuốc bộ nhích sang gõ cửa ô nhà bên cạnh đi!". Cứ lẳng lặng cày cuốc thò mõm ngó từng ô liền kề đằng sau lưng mãi cho đến khi vớ được một vũng trống không người thì nhảy phốc tót vào chiếm tiện cư.

## Phương pháp
1. **Sườn Sống:** Dùng đúng một đường thẳng mảng đơn độc trần trụi (nói không với đeo bám danh sách liên kết phức tạp lủng lẳng). Treo một bộ theo dõi đèn đóm Boolean rà soát sát vách để phân bua rạch ròi ô nào "có chủ" ô nào "vườn không nhà trống".
2. **Nhét (Insert):** Băm ra tọa độ số nhà gốc. Nếu chuồng rỗng thì phi gót hạ phàm vào thẳng. Rủi bị đụng đầu trúng chủ xị đã lót ổ trước, lập tức rẽ ngang lết bộ mót từng bước nhích dần vòng quanh `(index + 1) % capacity` lùng rục cho tới chừng thò mặt trúng cái hố không đáy chưa bị đục lót thì tót vô định cư.
3. **Đào Mộ Tìm Trầm (Search):** Băm tra ra định vị địa chỉ ban đầu. Lết dọc hành lăng dò xét từng buồng củi tiếp nối. Cơn dò dẫm kết thúc ngay tức khắc nếu một là đập ngay vô mặt số liệu đúng hệ trúng phóc mục tiêu, hai là va trúng một chuồng trơ trọi đóng rong (rỗng thệch, chứng tỏ đồ đang lùng chưa vô trễ tới mức đùn dọc ra tới tận khúc này), ba là đi lạc vòng vo giẫm đúng dấu giày xuất phát tự quay cắn đuôi mình (hết bảng rồi).
4. **Thủ Tiêu (Delete):** Đi lùng sục kiếm y xì phọt trên, tìm thấy thì nạo rỗng ruột quét tàn dư xé bỏ nhãn đánh dấu lót ô cởi trói.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Hên (Trung Bình): Chèn, bới tìm: O(1) khi bảng rỗng trải chiếu mênh mông bạt ngàn mát mẻ chưa lún tụ đống dơ (Clustering) nhầy nhụa từng cục chen lấn xô đẩy.
  - Xui mạt vận (Worst): O(N) hễ cục diện bảng ngột ngạt cứng ngắc lấn đất ép người chặt nịch, gây nghẽn hụt hầm chạy lo le lê lết cạp cạp từng bậc cầu thang rà từ đầu tới xấp xỉ đuôi hẻm mới moi ra được hang luồn.

- Độ phức tạp không gian:
  - O(M) trói chặt bằng xiềng xích chết đanh ranh giới sức chứa mảng `M` trần trần không co giãn thít chật cấu trúc gốc cứng ngắt.
