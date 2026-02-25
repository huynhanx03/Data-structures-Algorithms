# Rolling Hash (Polynomial Hash / Băm Cuốn Tiền Tố)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Tuyệt học Rolling Hash (bơm hồn vào sinh mệnh thuật toán Rabin-Karp) thổi bùng sức mạnh ma đạo bằng cơ chế trổ cửa sổ lướt trượt cuốn chiếu trơn tuột trên mảng chuỗi trần. Khi khung cửa kéo dịch qua vệt dài ký tự, hàm băm sẽ không hạch toán bò lê đần độn cộng dồn tính lại từ củ tới ngọn, mà nó vung gậy phù phép rẹt rẹt tước đoạt thẳng sức ép, xả bỏ năng lượng khúc rác ký tự đằng đuôi thò lòi rớt nài ngoài rìa và nuốt tóm gộp bù cấn đắp ngay liền ký tự lọt tõm rơi tươi rói vào khung, bảo lưu liền mạch hòn tuyết lăn cục trị số Hash, mượt lết hoàn mỹ tuyệt trần không giọt mồ hôi.

## Phương pháp
1. Thuật tung thủ thế dựng cờ Poly-Hash nặn bóp công thức toán đa thức nòng cốt: Cứ ứng một nấc chữ là lũy thừa số mũ giật nảy số thêm một tầng cơ sở base, ép nén phồng tôm nhồi vô rổ module chống tràn.
2. **Kĩ năng Cuốn Chóp Cửa Sổ (Sliding Window Math):** Mảng dịch tiến rụng hạt rơi chữ cũ hút chữ mới: `Hash(tương lai) = (Hash(hiện tại) * CƠSỐ - Chữ_văng_bỏ * CƠSỐ^ĐộDài + Chữ_vừa_nuốt) % MOD`. Lượn lờ chớp nhoáng không điểm mù.
3. **Hình thể Biến Dị Tiền Tố (Prefix Tracking Variant):** Đúc cái lò rèn Pre-Calculate chém ném sẵn trọn vạch chóp băm dọc từ A-Z một phát nhét sọt sẵn. Hễ ngứa ngáy cần xét nghiệm DNA một khúc ruột non chuỗi nội sinh cụ thể ở giữa tọa lạc tại `vị trí POS` bung trải `độ dài LEN`, máy xén đứt đuôi trừ khấu dội rớt nhổ phăng phần rìa thừa râu ria chập choạng đằng trước, đẻ dội bắn vọt lên màn hình y boong chóc con số băm trong độ xấp xỉ O(1).

## Độ phức tạp
- Độ phức tạp thời gian:
  - Giăng dây thép gai lợp móng tiền tố ươm mầm: O(N).
  - Bốc khói tỉa bắt xẻo lấy chuỗi đoạn dẫu dài muôn trùng điệp nẻo chăng nữa vẫn bất dính sượt chóp O(1).
  - Tìm rà vết chuỗi trích theo Rabin-Karp rảo bước nhẹ nhõm băng xuyên biên giới mảng bự: Trắng trợn dội chuẩn đép O(N + M).

- Độ phức tạp không gian:
  - O(N) lỉnh kỉnh ôm bao bố cõng mớ mảng chứa rác mã vạch tiền tố với cuốn bí kíp lũy thừa tích góp. Rất thảnh thơi mà tinh gọn diệu kỳ.
