#include <stdio.h>
#include <stdlib.h>

/*
 * Structure type to represent an electrical battery
 */
typedef struct {
    double voltage;        // Voltage in volts (V)
    double max_energy;     // Maximum energy storage capacity in joules (J)
    double current_energy; // Current energy reserve in joules (J)
} battery_t;

/*
 * Function: scan_battery
 * ----------------------
 * Reads voltage, max energy capacity, and current energy reserve.
 * Returns 1 on success, EOF on failure.
 */
int scan_battery(battery_t *b) {
    if (scanf("%lf %lf %lf", &b->voltage, &b->max_energy, &b->current_energy) == 3) {
        return 1;
    }
    return EOF;
}

/*
 * Function: print_battery
 * -----------------------
 * Displays the current parameters and charge state of a battery.
 */
void print_battery(battery_t b) {
    double pct = (b.max_energy > 0.0) ? (b.current_energy / b.max_energy) * 100.0 : 0.0;
    printf("  +---------------------------------------------------\n");
    printf("  | Battery Voltage     : %.2f V\n", b.voltage);
    printf("  | Energy Capacity     : %.1f J (%.2f kJ)\n", b.max_energy, b.max_energy / 1000.0);
    printf("  | Current Reserve     : %.1f J (%.2f kJ)\n", b.current_energy, b.current_energy / 1000.0);
    printf("  | State of Charge     : %.2f%%\n", pct);
    printf("  +---------------------------------------------------\n");
}

/*
 * Function: power_device
 * ----------------------
 * Powers an electrical device drawing a specific current (amps)
 * for a duration (seconds).
 *
 * Physics formulas:
 *   p = v * i        (power in watts = voltage * current)
 *   w = p * t        (energy in joules = power * time)
 *
 * Parameters:
 *   current_amps - current drawn by device (A)
 *   time_sec     - operation duration (s)
 *   b            - pointer to battery structure (input/output)
 *
 * Returns:
 *   1 (true)  if energy reserve is adequate; subtracts consumed energy.
 *   0 (false) if energy reserve is inadequate; leaves battery unchanged.
 */
int power_device(double current_amps, double time_sec, battery_t *b) {
    double power_watts = b->voltage * current_amps;
    double energy_required = power_watts * time_sec;

    if (b->current_energy >= energy_required) {
        b->current_energy -= energy_required;
        return 1; // Success
    } else {
        return 0; // Insufficient energy
    }
}

/*
 * Function: max_time
 * ------------------
 * Calculates the maximum time (seconds) a battery can power a device
 * before being fully discharged. Does not modify battery values.
 *
 * Formula:
 *   t = w / (v * i)
 */
double max_time(battery_t b, double current_amps) {
    double power_watts = b.voltage * current_amps;
    if (power_watts <= 0.0) {
        return 0.0;
    }
    return b.current_energy / power_watts;
}

/*
 * Function: recharge
 * ------------------
 * Restores the battery's energy reserve to its maximum storage capacity.
 */
void recharge(battery_t *b) {
    b->current_energy = b->max_energy;
}

int main() {
    printf("====================================================\n");
    printf("  PROGRAM 9: BATTERY POWER SIMULATION (battery_t)   \n");
    printf("  Name: Rinaltra Nabasa Simanungkalit | NRP: 5025251024\n");
    printf("====================================================\n\n");

    // Initialize sample battery: 12.0 V, 5,000,000 J (5 MJ) capacity, currently at 4,000,000 J (80%)
    battery_t bat = {
        .voltage = 12.0,
        .max_energy = 5000000.0,
        .current_energy = 4000000.0
    };

    printf("1. Initial Battery State:\n");
    print_battery(bat);
    printf("\n");

    // Test max_time function
    double test_current = 4.0; // 4.0 Amperes
    double t_max = max_time(bat, test_current);
    printf("2. Maximum Operating Time Calculation:\n");
    printf("   Device Current Draw: %.2f A\n", test_current);
    printf("   Power Consumption  : %.2f W (12V * 4A)\n", bat.voltage * test_current);
    printf("   Max Runtime (sec)  : %.2f seconds\n", t_max);
    printf("   Max Runtime (hours): %.2f hours\n\n", t_max / 3600.0);

    // Test power_device: Test Case A (Successful operation)
    double time_a = 3600.0; // 1 hour
    double energy_a = bat.voltage * test_current * time_a;
    printf("3. Executing power_device (Test Case A - Normal Load):\n");
    printf("   Attempting to power device (%.1f A for %.1f s = %.1f J)...\n",
           test_current, time_a, energy_a);
    int status_a = power_device(test_current, time_a, &bat);
    if (status_a) {
        printf("   Result: SUCCESS (1) -> Energy deducted successfully.\n");
    } else {
        printf("   Result: FAILED (0) -> Insufficient energy.\n");
    }
    printf("   Updated Battery State:\n");
    print_battery(bat);
    printf("\n");

    // Test power_device: Test Case B (Excessive load exceeding reserve)
    double heavy_current = 200.0; // 200 A heavy motor
    double heavy_time = 7200.0;   // 2 hours -> needs 17.28 MJ
    double energy_b = bat.voltage * heavy_current * heavy_time;
    printf("4. Executing power_device (Test Case B - Overload Protection):\n");
    printf("   Attempting to power heavy load (%.1f A for %.1f s = %.1f J)...\n",
           heavy_current, heavy_time, energy_b);
    int status_b = power_device(heavy_current, heavy_time, &bat);
    if (status_b) {
        printf("   Result: SUCCESS (1) -> Energy deducted.\n");
    } else {
        printf("   Result: FAILED (0) -> Energy reserve inadequate! State preserved.\n");
    }
    printf("   Current Battery State (Should remain unchanged):\n");
    print_battery(bat);
    printf("\n");

    // Test recharge function
    printf("5. Executing recharge Function:\n");
    printf("   Recharging battery to maximum capacity...\n");
    recharge(&bat);
    printf("   Post-Recharge Battery State:\n");
    print_battery(bat);
    printf("\n");

    printf("Simulation completed successfully.\n");
    return 0;
}
