#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UNIT_TEST
#include "../src/bai2.c"

int main() {
    printf("[CHAY TEST BAI 2: VI DIEN TU]\n");

    // Test 1: Đủ tiền thanh toán (500k trừ 200k hoàn 10% = 320k)
    float soDu = 500000.0;
    float tienHoan = 0.0;
    int kq = thanhToanHoaDon(&soDu, 200000.0, 10.0, &tienHoan);

    if (kq != 1) {
        printf("FAILED Test 1: Trang thai tra ve phai la 1 (Thanh cong)\n");
        return 1;
    }
    if (fabs(tienHoan - 20000.0) > 0.001) {
        printf("FAILED Test 1: Tien hoan sai -> Expected: 20000.00, Actual: %.2f\n", tienHoan);
        return 1;
    }
    if (fabs(soDu - 320000.0) > 0.001) {
        printf("FAILED Test 1: SO DU TAI MAIN KHONG DOI HOAC TINH SAI!\n");
        printf("--> Expected: 320000.00, Actual: %.2f\n", soDu);
        printf("--> NGUYEN NHAN: Ham chua dung con tro '*' de cap nhat vung nho goc (Call by Reference)!\n");
        return 1;
    }

    // Test 2: Không đủ tiền thanh toán (Ví 100k, Mua 200k)
    soDu = 100000.0;
    tienHoan = 0.0;
    kq = thanhToanHoaDon(&soDu, 200000.0, 10.0, &tienHoan);

    if (kq != 0) {
        printf("FAILED Test 2: Khong du tien nhung van bao thanh cong (Tra ve phai la 0)!\n");
        return 1;
    }
    if (fabs(soDu - 100000.0) > 0.001) {
        printf("FAILED Test 2: Giao dich that bai nhung so du vi van bi tru tien!\n");
        return 1;
    }

    printf(">>> BAI 2: PASS 100%% TEST CASES!\n");
    return 0;
}
