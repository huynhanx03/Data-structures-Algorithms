# Coordinate Compression (Nén Tọa Độ / Rời Rạc Hóa)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Giả dụ vạn ngập trong một bài toán bưng dọn bắt mảng sừng sững gánh điểm giá trị khổng lồ xa lơ xa lắc (chọc thấu thiên trần `10^9` hoặc âm vô cực), quăng đống đó vô mảng làm địa chỉ Index thì chịu chết báo tràn RAM nổ máy tính. Nhưng xui oái thay, dù khoảng cách giữa bọn chúng rộng thênh thang, mà số lượng tổng nốt điểm thật sự đếm ra quanh quẩn chỉ có vài nhúm bé xíu lưa thưa `10^5`. Nén Tọa Độ (Coordinate Compression) bay xuống cứu rỗi bằng phép ma thuật: Ép xác co bóp lại những giá trị quái thai bốc mùi cồng kềnh thô thiển đó, dịch cấp lột xác hóa kiếp cho tụi nó dồn lại thành mớ chỉ số sạch bóng, sít rịt, thon gọn, liên tiếp sát vách ngay ngắn từ chóp `0, 1, 2, 3...`. Lừa tình ném tuốt luốt vào dùng làm Index truy mảng dễ như một trò đùa xơi kẹo.

## Phương pháp
1. **Lọc Xác Vứt Bỏ Phân Thân (Sort - Unique):** Hốt một bọc bản sao clone chép từ trọn mảng gốc. Vứt mẹ xổ vào cái nồi `sort` luộc lật đánh vần rạch ròi từ thấp lên cao vút. Đoạn chiêu kìm kẹp `unique` sáp văng tước bỏ ném trút đi nảy bung toàn bộ ba cái bọn đạo nhái rác bản sao sinh đôi y chang nhau trùng lặp bọc cọc lỏ. Rút gọn giữ lại tinh túy ròng duy nhất độc quyền. 
2. **Ép Số Sửa Bảng Đeo Thẻ (Lower Bound):** Quét quét vuốt lại cái mảng danh pháp xôi gốc. Thấy cái bóng ma tàng hình số khổng lồ bành ki nào thì táng nhét búa `lower_bound` gõ tuốt chui tọt dò kiếm móc truy lùng coi nó đang nằm ngả ngớn ở nhà trọ vị trí chốt thứ mấy trong căn hộ bảng chóp đã khử độc phân thân kia. Quắp tròng cái số đo thứ tự ghế ngồi Index rút gọn bé teo quắt đó ốp ngược dí dán tem dập số đè lên hất văng cắm cổ cái giá trị béo bụng khổng lồ cũ kia đi. Cóc kiện hoàn thiện dọn rác co ngót toàn bộ đám mây nát tan.

## Độ phức tạp
- Độ phức tạp thời gian:
  - O(N log N) mút mải mỏi mòn bóp nghẹt gánh vác đợt luộc mảng Sorting, đính kèm quả dập gõ tìm chặt nhị phân `lower_bound` xâu chuỗi chém dọc truy tháp Vị thứ cởi trói.

- Độ phức tạp không gian:
  - O(N) nhót hầu bao một vé trích máu chứa sương sương túp lều mảng phụ clone gác chóp nén độc bản rút gọn danh tính cọc rèn ma thuật. Túi đồ đeo nách siêu thon gọn mượt mướt không lình xình chật tủ đồ rác rến dư dả RAM bộ nhớ êm mượt phè phỡn bung lụa.
