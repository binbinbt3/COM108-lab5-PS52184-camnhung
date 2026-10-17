#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int thanhToanHoaDon(float *soDuVi, float tongTien, float tyLeHoan, float *tienHoan);

#ifndef UNIT_TEST
int main() {
    float soDu = 500000.0;
    float hoaDon, tyLe;
    float tienDuocHoan = 0.0;

    printf("So du vi hien tai: %.2f VND\n", soDu);
    printf("Nhap so tien hoa don: ");
    scanf("%f", &hoaDon);
    printf("Nhap ty le cashback (%%): ");
    scanf("%f", &tyLe);

    int trangThai = thanhToanHoaDon(&soDu, hoaDon, tyLe, &tienDuocHoan);

    if (trangThai == 1) {
        printf("\n>> Giao dich THANH CONG!");
        printf("\nTien cashback nhan ve: %.2f VND", tienDuocHoan);
        printf("\nSo du vi sau cung: %.2f VND\n", soDu);
    } else {
        printf("\n>> Giao dich THAT BAI (So du khong du)!");
        printf("\nSo du giu nguyen: %.2f VND\n", soDu);
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int thanhToanHoaDon(float *soDuVi, float tongTien, float tyLeHoan, float *tienHoan) {
    // TODO: Viết code thanh toán và cập nhật số dư, tiền hoàn (dùng con trỏ)
    // Trả về 1 nếu thành công, 0 nếu thất bại (không đủ tiền)
    //Nghiệp vụ giao dịch: Nhận số dư ví, số tiền hóa đơn, tỷ lệ hoàn tiền.
    //Nếu soDu < tongTien: Thất bại, trả về 0. Tiền hoàn = 0.
    //Nếu đủ điều kiện: Trừ hóa đơn, cộng tiền cashback vào ví. Trả về 1.
    if(*soDuVi < tongTien) {
        *tienHoan = 0.0f;
        return 0; // Thất bại
    } else {
        *soDuVi -= tongTien; // Trừ tiền hóa đơn
        *tienHoan = (tyLeHoan / 100.0f) * tongTien; // Tính tiền hoàn
        *soDuVi += *tienHoan; // Cộng tiền hoàn vào ví
        return 1; // Thành công
    }
    return 0;
}
