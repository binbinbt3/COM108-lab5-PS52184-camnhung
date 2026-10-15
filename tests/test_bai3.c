#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_TEST
#include "../src/bai3.c"

int main() {
    printf("[CHAY TEST BAI 3: RUT TIEN ATM]\n");

    // Test kiểm tra xem sinh viên có dùng printf trong thân hàm không
    FILE *f = fopen("src/bai3.c", "r");
    if (f) {
        char line[256];
        int inHam = 0;
        while (fgets(line, sizeof(line), f)) {
            if (strstr(line, "SINH VIÊN VIẾT CODE")) inHam = 1;
            if (inHam && strstr(line, "printf")) {
                printf("FAILED Kien truc: Phat hien lenh 'printf' nam ben trong ham phanPhoiATM!\n");
                printf("--> YEU CAU: Ham chi thuc hien tinh toan va gan vao con tro, in an phai nam o main!\n");
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }

    // Test logic: Rút 1.850.000 VNĐ -> 3 tờ 500k, 1 tờ 200k, 1 tờ 100k, 1 tờ 50k (Tổng: 6 tờ)
    int to500 = 0, to200 = 0, to100 = 0, to50 = 0;
    int tong = phanPhoiATM(1850000, &to500, &to200, &to100, &to50);

    if (tong != 6 || to500 != 3 || to200 != 1 || to100 != 1 || to50 != 1) {
        printf("FAILED Test Logic (Rut 1.850.000 VND):\n");
        printf("Expected: 3 to 500k, 1 to 200k, 1 to 100k, 1 to 50k | Tong: 6 to\n");
        printf("Actual  : %d to 500k, %d to 200k, %d to 100k, %d to 50k | Tong: %d to\n",
               to500, to200, to100, to50, tong);
        return 1;
    }

    printf(">>> BAI 3: PASS 100%% TEST CASES!\n");
    return 0;
}
