#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define UNIT_TEST
#include "../src/bai1.c"

int main() {
    printf("[CHAY TEST BAI 1: XE DIEN]\n");

    // Test 1: Đổi Wh sang kWh (kiểm tra lỗi chia nguyên int)
    float kwh = doiWhSangKwh(500.0);
    if (fabs(kwh - 0.50) > 0.001) {
        printf("FAILED Test 1: doiWhSangKwh(500.0) -> Expected: 0.50, Actual: %.2f (Co the do loi chia nguyen / 1000)\n", kwh);
        return 1;
    }

    // Test 2: Đổi 2500 Wh sang kWh
    kwh = doiWhSangKwh(2500.0);
    if (fabs(kwh - 2.50) > 0.001) {
        printf("FAILED Test 2: doiWhSangKwh(2500.0) -> Expected: 2.50, Actual: %.2f\n", kwh);
        return 1;
    }

    // Test 3: Tính tiền điện
    float tien = tinhTienDien(2.5, 3000.0);
    if (fabs(tien - 7500.0) > 0.001) {
        printf("FAILED Test 3: tinhTienDien(2.5, 3000.0) -> Expected: 7500.00, Actual: %.2f\n", tien);
        return 1;
    }

    printf(">>> BAI 1: PASS 100%% TEST CASES!\n");
    return 0;
}
