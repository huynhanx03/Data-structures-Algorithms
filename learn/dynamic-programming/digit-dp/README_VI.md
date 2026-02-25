# Digit DP (Quy Hoạch Động Chữ Số)

[VI](./README_VI.md) | [EN](./README.md)

## Ý tưởng
Đối mặt mớ bài toán tìm đếm số lượng các con số thỏa mãn điều kiện kịch dị nào đó nằm vắt vẻo trong một khoảng kẹp khổng lồ từ `[L, R]` (ví dụ R lên tới `10^18`), lấy sức người chạy vòng `for` bò trườn là bể đầu gãy xương TLE (quá thời gian). Digit DP ra đời chơi bài chặt chém cái con số to đùng đấy thành từng mảng hạt lựu hạt nêm (từng chữ số). Nó luồn lách đi duyệt điền mò mẫm đệ quy lần lượt từng vị trí hàng chữ số từ Trái sang Phải (từ hàng Lớn nhất về hàng Đơn vị nhỏ nhất), mần dò số nào ráp vô nứt mầm ra kết quả đúng là nó cộng dồn nhét mảng nhớ, né đi lại đường cũ.

## Phương pháp
1. **Duyệt Cấu Trúc Khung Xương Đệ Quy (`solve(id, flag)`):** `id` nắm tọa độ rảo bước theo vị trí dãy số (vị trí đầu đang điền là 0). Thuật mớm đệ quy rải chữ số từ 0 đến 9 cho từng vị trí `id` rỗng, thả xuống nhích dần nấc thang về đích.
2. **Siết Gông Ngưỡng Max Biên Bước (`flag`):** Biến cờ `flag` (bool) cực trọng yếu sắm vai gác cổng: Nó cho biết cái mớ các số mình vừa thả vào trước đó có bò sát ôm khít rịt cái chuỗi kịch kim giá trị gốc của biên `R` hay không? Nếu ôm sát (`flag = true`), thì con số ở nấc hiện tại **tối đa** rớt xuống chỉ được leo đụng sàn chữ số của giá trị R hiện tại đó (tức `limit = s[id] - '0'`). Nếu lỡ thả số lọt nhẹ xuống (`flag = false`), thì từ đó về sau bứt gông chạy bung lụa xổ tự do tẹt ga vòng từ số `0` đến tít chữ số `9`.
3. **Mảng Nhớ Vét Chiêu (Memoization):** Lọt hầm `dp[id][flag]`. Nếu mốc này từng ghé vào, bưng tô cơm hâm lại ăn liền chứ chừa bụng chạy vô hàm đệ quy rẽ nhánh tung tóe y sì lúc trước làm tốn bộ nhớ hao giờ. Giúp vớt vát kéo rịt độ phức tạp từ số Mũ chót vót tụt xuống Tuyến Tính thon gọn lẹ làng.

## Độ phức tạp
- Độ phức tạp thời gian:
  - Tốc biến O(Length * Trạng Thái). Khum tay tốn chừng bóc mẻ xào nấu độ chừng 18 tới 20 số, độ phức tạp nhỏ tới mức giun dế búng lẩy không chớp mắt siêu tốc.
  
- Độ phức tạp không gian:
  - O(Length * Trạng Thái) mảng nhớ 2D tí teo tốn kém đúng số hàng kĩ thuật siêu chóp của độ bự max R (cỡ 18 x 2), gần như chả nhét đầy chân răng cái máy vi tính. Bé tí xíu.
