#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ADDRESSES 100
#define NICKNAME_LEN 11

/*
 * Structure type to represent an Internet address and nickname
 */
typedef struct {
    int xx;
    int yy;
    int zz;
    int mm;
    char nickname[NICKNAME_LEN];
} address_t;

/*
 * Function: scan_address
 * ----------------------
 * Reads an IP address in xx.yy.zz.mm format along with its nickname.
 * Returns:
 *   1 if a valid non-sentinel address is scanned,
 *   0 if sentinel (0.0.0.0 or nickname 'none') is encountered,
 *   EOF if end of input stream is reached.
 */
int scan_address(FILE *fp, address_t *addr) {
    int res = fscanf(fp, "%d.%d.%d.%d %10s",
                     &addr->xx, &addr->yy, &addr->zz, &addr->mm,
                     addr->nickname);

    if (res != 5) {
        return EOF;
    }

    // Check for sentinel address (0.0.0.0)
    if (addr->xx == 0 && addr->yy == 0 && addr->zz == 0 && addr->mm == 0) {
        return 0;
    }

    return 1;
}

/*
 * Function: print_address
 * -----------------------
 * Displays the IP address and nickname in formatted columns.
 */
void print_address(address_t addr) {
    printf("  %-16s %-12s\n",
           "", addr.nickname); // placeholder for clean alignment
}

/*
 * Formatted print function
 */
void display_address_entry(int idx, address_t addr) {
    char ip_str[30];
    snprintf(ip_str, sizeof(ip_str), "%d.%d.%d.%d", addr.xx, addr.yy, addr.zz, addr.mm);
    printf("  [%2d]  %-18s  %-12s\n", idx, ip_str, addr.nickname);
}

/*
 * Function: local_address
 * -----------------------
 * Determines whether two machines share the same local network.
 * Two addresses are local if their first two components (xx and yy) match.
 * Returns 1 (true) if on same local network, 0 (false) otherwise.
 */
int local_address(address_t a1, address_t a2) {
    if (a1.xx == a2.xx && a1.yy == a2.yy) {
        return 1;
    }
    return 0;
}

/*
 * Helper to ensure sample data file exists
 */
void create_sample_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp != NULL) {
        fprintf(fp, "111.22.3.44  platte\n");
        fprintf(fp, "555.66.7.88  wabash\n");
        fprintf(fp, "111.22.5.66  green\n");
        fprintf(fp, "0.0.0.0      none\n");
        fclose(fp);
    }
}

int main(int argc, char *argv[]) {
    printf("====================================================\n");
    printf("  PROGRAM 5: LOCAL NETWORK ADDRESS MATCHER (address_t)\n");
    printf("  Name: Rinaltra Nabasa Simanungkalit | NRP: 5025251024\n");
    printf("====================================================\n\n");

    const char *data_filename = "address_data.txt";
    create_sample_file(data_filename);

    FILE *fp = NULL;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Notice: Could not open %s. Using default %s\n", argv[1], data_filename);
            fp = fopen(data_filename, "r");
        }
    } else {
        fp = fopen(data_filename, "r");
    }

    if (fp == NULL) {
        printf("Error: Could not open input data source.\n");
        return 1;
    }

    address_t network_list[MAX_ADDRESSES];
    int count = 0;
    address_t temp;

    // Read list of up to 100 addresses terminated by sentinel
    int status;
    while (count < MAX_ADDRESSES && (status = scan_address(fp, &temp)) == 1) {
        network_list[count++] = temp;
    }

    fclose(fp);

    printf("1. Local Network Pair Detection:\n");
    printf("----------------------------------------------------\n");
    int match_found = 0;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (local_address(network_list[i], network_list[j])) {
                printf("Machines %s and %s are on the same local network.\n",
                       network_list[i].nickname, network_list[j].nickname);
                printf("  -> Matching Subnet Prefix: %d.%d.*.*\n\n",
                       network_list[i].xx, network_list[i].yy);
                match_found++;
            }
        }
    }

    if (match_found == 0) {
        printf("No machines from the same locality were found.\n\n");
    }

    // Display the full list of addresses and nicknames
    printf("2. Full Directory of Registered Machines:\n");
    printf("----------------------------------------------------\n");
    printf("   No.  IP Address          Nickname    \n");
    printf("  --------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        display_address_entry(i + 1, network_list[i]);
    }
    printf("  --------------------------------------------------\n");
    printf("  Total active machines registered: %d\n", count);

    return 0;
}
