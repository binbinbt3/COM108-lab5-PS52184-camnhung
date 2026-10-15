#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
float nhapSanLuongWh();
float doiWhSangKwh(float wh);
float tinhTienDien(float kwh, float donGia);

#ifndef UNIT_TEST
int main() {
  float wh = nhapSanLuongWh();
  float kwh = doiWhSangKwh(wh);
  float donGia = 3000.0; // Đơn giá ví dụ: 3000 VNĐ/kWh
  float tongTien = tinhTienDien(kwh, donGia);

  printf("\n--- HOA DON SAC XE ---");
  printf("\nSan luong: %.2f Wh", wh);
  printf("\nSan luong quy doi: %.2f kWh", kwh);
  printf("\nTong tien: %.2f VND\n", tongTien);

  return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CÁC HÀM DƯỚI ĐÂY ---
float nhapSanLuongWh() {
  // TODO: Viết code nhập sản lượng sử dụng vòng lặp do...while (yêu cầu > 0)

  return 0.0;
}

float doiWhSangKwh(float wh) {
  // TODO: Viết code quy đổi (lưu ý tránh lỗi chia số nguyên)

  return 0.0;
}

float tinhTienDien(float kwh, float donGia) {
  // TODO: Tính tiền

  return 0.0;
}
