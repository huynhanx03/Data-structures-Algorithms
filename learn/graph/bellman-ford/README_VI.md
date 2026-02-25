# Bellman-Ford (Thuật toán Bellman-Ford)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Nổi đình đám là khắc tinh dằn mặt đồ thị vướng "Trọng Số Âm" (Negative Weights) mà siêu cấp sát thủ Dijkstra còn phải ái ngại cúi đầu chào thua. Thuật toán Bellman-Ford thô bạo vét máng tát cạn đường bộ bằng cách trải quét liên tục và hạch toán siết chặt cự li của mọi cái đai dây thòng lọng mớ dây mơ rễ má bất kể dài ngắn ra sao. Chìa khóa độc chiêu để sống lay lắt quằn quại với bọn mang ma lực âm chính là bào nát rà soát đường cùng V-1 lần cho nó ráng ngấm thuốc sập tiệm hẳn về giá trị cự ly nhỏ nhất.

## Phương pháp
1. **Lộ Phí Vô Cực:** Tung hô ném phát dán điểm gốc bằng 0, quăng cục ngậm ngùi Vô cực (Vô định) cho đám nốt đen kịt khỉ ho cò gáy còn lại. Không bàng hoàng ưu tiên chắt lọc đồ thị phức tạp như Dijkstra, Bellman quất một nồi Edges nùi mù cùi list danh sách quẳng bừa vô sọt rác cho gọn tẹo múc ăn dần từng đùi.
2. **Kẹp Ốc Siết Vòng (Relaxation):** Trục đường V nốt thì nó lấy đúng V-1 hiệp rà nát cả mạt dây chuyền. Trong trọn một kỳ cọ (hiệp), chui thụt dò hạch hỏi từng dây leo một: Dây leo móc u -> v dài dằng dặc, mà quành lại rẻ mạc sút mất cự ly hơn đi cái đường cũ mục dập thì đập nát đường cũ, khắc đá lưu số kilomet mượt mà mới rượi (Relax). Rát rạt đi cho sạch bách nguyên thúng mảng E cái dây. Rà tuốt tận cùng cạn máu lặp vậy y sì 1 lượt xong đả tiếp lượt 2 ròng rã cày cuốc. 
3. **Cảnh Vệ Lương Tâm Âm Mưu Vòng Quay (Negative Cycle):** V - 1 trận đầm đìa đã ép sấy kiệt quệ hết cớ bóp cò của con mốc rút ngắn. Xoay thêm 1 lượt dư kén thứ V cuối cùng bóp vét chảo hòng thử bẫy, kì diệu thay nếu lỡ lấp ló lóe cái đèn có đứa rớt tụt xuống cự ly móc giảm rẻ chán chê nữa (mà đúng lý đã bị triệt cạn) thì hét toác còi báo cháy toang khoác lác bị lọt bẫy còng lẩn quẩn chu trình luẩn quẩn âm phủ (Negative weight cycle họng đen).

## Độ phức tạp
- Độ phức tạp thời gian:
  - O(V * E) lết xe cày thô bỉ lê lết từng nút ốc dập thẳng cả V chặng đường tốn một sấp E dây nối nhằng nhịt. Bào cuốc cực trâu bò xôi thịt trần truồng bạo lực. Chịu khó lọng cọng cày sâu quốc bặm mà đâm ra an tâm bao sầu nợ cõi âm.
  
- Độ phức tạp không gian:
  - O(V) bọc kén vỏn vẹn lủng lẳng một đường ống chứa lưu lượng ghi danh hố sâu kilomet cách xa trung tâm điều khiển (điểm start), sạch bong kin kít tối ưu thắt não gọn tẹo không dư hao ố dơ thêm mạt rác RAM bộ nhớ.
