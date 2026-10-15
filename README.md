# YÊU CẦU LAB 5 - COM108 (CẬP NHẬT 2026)

> [!NOTE] 
> **Môn học:** Nhập môn Lập trình với C (PRF192 / COM108)  
> **Thời lượng:** Thực hiện trong buổi học  
> **Hình thức nộp bài:** Sử dụng GitHub Template, đẩy mã nguồn (`git push`) và tự động kiểm thử.

---

## PHẦN 1: HƯỚNG DẪN BẮT ĐẦU VÀ NỘP BÀI (QUY TRÌNH MỚI)

### 1. Tải kho bài tập về máy (Clone)
1. Truy cập vào **đường link Repository** giảng viên cấp.
2. Nhấn nút màu xanh **"Use this template"** $\rightarrow$ **"Create a new repository"**.
3. Thiết lập: **Repository name:** `COM108-Lab5-<MaSinhVien>` | **Visibility:** `Public` $\rightarrow$ Bấm **Create repository**.
4. Lấy link HTTPS và chạy lệnh Terminal:
```bash
git clone <link_https_vua_copy>
cd COM108-Lab5-<MaSinhVien>
```

### 2. Quy trình làm từng bài & Đẩy lên GitHub (Push)

> [!TIP]
> Thực hiện tuần tự: **Hoàn thiện Bài 1 $\rightarrow$ Push & Nhận trạng thái $\rightarrow$ Ghi log $\rightarrow$ Xanh mới chuyển sang Bài 2.**

#### Bước 1: Code và Ghi Log
1. Viết code hoàn thiện các hàm trong file `.c`.
2. Ghi nhật ký vào `LOGBOOK.md` trước khi push.
3. Chạy lệnh nộp bài:
```bash
git add src LOGBOOK.md
git commit -m "Nop bai..."
git push origin main
```

#### Bước 2: Đọc trạng thái phản hồi từ GitHub
Ngay sau khi push, tải lại trang GitHub cá nhân:
* 🟡 **Đang chấm:** Đợi 15 – 30 giây.
* ✅ **Đạt (Pass):** Cập nhật `LOGBOOK.md` thành "Xanh", chuyển sang bài tiếp theo.
* ❌ **Lỗi (Failed):** 
  1. Bấm vào ❌ $\rightarrow$ **Details** đọc lỗi.
  2. Ghi lỗi vào `LOGBOOK.md`.
  3. Sửa code trên máy rồi push lại.

---

### Bảng tra cứu hành động

| Trạng thái | Ý nghĩa | Hành động tiếp theo |
| :---: | --- | --- |
| 🟡 | **Đang chấm** | Đợi 15 – 30s rồi F5 lại trang. |
| ✅ | **Pass** | Ghi Log "Xanh" $\rightarrow$ Làm bài tiếp theo. |
| ❌ | **Failed** | Bấm **Details** đọc lỗi $\rightarrow$ Ghi Log lỗi $\rightarrow$ Sửa code $\rightarrow$ Push lại. |
| ⛔ | **QUOTA EXCEEDED** | Khóa nộp bài do push quá số lần. Báo cáo giảng viên. |

---

## PHẦN 2: NỘI DUNG CHI TIẾT CÁC BÀI TẬP

### Quy tắc làm bài bắt buộc

> [!IMPORTANT]
> **QUY TẮC BẤT BIẾN:** Tuyệt đối không thay đổi tên hàm, kiểu dữ liệu trả về và thứ tự tham số trong các file mẫu (`src/bai1.c`, `bai2.c`, `bai3.c`).

* **Quy định lập trình:**
  * Được phép sử dụng AI (Cursor, Copilot, ChatGPT, Claude...) để hỗ trợ phân tích và viết code.
  * **Cấm biến toàn cục (`global variables`):** Toàn bộ dữ liệu trao đổi giữa các hàm phải thông qua tham số hoặc giá trị trả về (`return`).

> [!WARNING]
> **Hạn ngạch đẩy bài (Luật 10-Push):** Toàn bộ bài Lab 5 được cấp tối đa **10 lần push**.
> * **Bài 1:** Tối đa 3 lần push.
> * **Bài 2:** Tối đa 3 lần push.
> * **Bài 3:** Tối đa 4 lần push.
> * *Hệ thống sẽ tự động khóa kiểm tra nếu vượt quá hạn ngạch.*
> * *Mỗi lần đẩy bài (`push`) bắt buộc phải ghi nhận vào tệp `LOGBOOK.md`.*

---

## YÊU CẦU LAB 5

#### Bài 1: Module Kiểm Định Năng Lượng Trạm Sạc (`src/bai1.c`)
Một trạm sạc xe điện thông minh yêu cầu module xử lý dữ liệu sạc:
* **Hàm kiểm định sản lượng (đơn vị: Wh):** Sử dụng vòng lặp `do...while`: chỉ chấp nhận giá trị `Wh > 0`. Nếu sai (`<= 0`), yêu cầu nhập lại. Trả về `Wh` hợp lệ.
* **Hàm quy đổi điện năng:** Nhận số `Wh`, trả về số Kilowatt-giờ (`kWh`) tương ứng (`1 kWh = 1000 Wh`).
* **Hàm tính cước phí:** Nhận số `kWh` đã nạp và đơn giá, trả về tổng tiền.
* **Tại hàm `main()`:** Gọi 3 hàm trên và in ra màn hình: `Wh` đã sạc, `kWh` (2 chữ số thập phân), Tổng cước phí.

#### Bài 2: Hệ Thống Giao Dịch & Hoàn Tiền Ví Điện Tử (`src/bai2.c`)
* **Nghiệp vụ giao dịch:** Nhận số dư ví, số tiền hóa đơn, tỷ lệ hoàn tiền.
  * Nếu `soDu < tongTien`: Thất bại, trả về `0`. Tiền hoàn = 0.
  * Nếu đủ điều kiện: Trừ hóa đơn, cộng tiền cashback vào ví. Trả về `1`.

> [!IMPORTANT]
> **Ràng buộc:** Biến số dư ví và biến tiền hoàn khai báo tại `main()` **bắt buộc phải tự động cập nhật giá trị mới nhất** sau khi kết thúc hàm (Sử dụng tham chiếu/con trỏ).

#### Bài 3: Phân Phối Tiền Mặt ATM Tối Ưu Mệnh Giá (`src/bai3.c`)
* **Nghiệp vụ phân phối:** Nhập số tiền cần rút tại `main()`. Yêu cầu: Là bội số của 50.000 VNĐ.
* Hàm phân phối tiền (500k, 200k, 100k, 50k) sao cho **tổng số tờ tiền là ít nhất**. Ghi trực tiếp số lượng từng tờ vào 4 biến đếm tại `main()`. Trả về tổng số tờ.

> [!CAUTION]
> **Tuyệt đối không sử dụng lệnh in (`printf`) bên trong hàm tính toán phân phối tiền.** Mọi thao tác xuất số lượng tờ tiền phải nằm ở `main()`.
