#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class PhaseImbalanceDetector {
private:
    double phaseA;
    double phaseB;
    double phaseC;
    double imbalanceLimit;

public:
    PhaseImbalanceDetector(double limit) {
        imbalanceLimit = limit;
    }

    void setVoltages(double a, double b, double c) {
        phaseA = a;
        phaseB = b;
        phaseC = c;
    }

    void detectImbalance() {

        // Calculate average phase voltage
        double averageVoltage =
            (phaseA + phaseB + phaseC) / 3.0;

        // Calculate deviations
        double deviationA = abs(phaseA - averageVoltage);
        double deviationB = abs(phaseB - averageVoltage);
        double deviationC = abs(phaseC - averageVoltage);

        // Find maximum deviation
        double maximumDeviation =
            max(deviationA, max(deviationB, deviationC));

        // Percentage imbalance
        double imbalancePercentage =
            (maximumDeviation / averageVoltage) * 100.0;

        cout << fixed << setprecision(2);

        cout << "\n----- THREE-PHASE VOLTAGE ANALYSIS -----"
             << endl;

        cout << "Phase A Voltage : " << phaseA << " V" << endl;
        cout << "Phase B Voltage : " << phaseB << " V" << endl;
        cout << "Phase C Voltage : " << phaseC << " V" << endl;

        cout << "Average Voltage : "
             << averageVoltage << " V" << endl;

        cout << "Maximum Deviation : "
             << maximumDeviation << " V" << endl;

        cout << "Voltage Imbalance : "
             << imbalancePercentage << " %" << endl;

        cout << "Allowed Limit : "
             << imbalanceLimit << " %" << endl;

        if (imbalancePercentage > imbalanceLimit) {

            cout << "\nSTATUS: PHASE IMBALANCE DETECTED!"
                 << endl;

            cout << "WARNING: Check the three-phase load."
                 << endl;
        }
        else {

            cout << "\nSTATUS: BALANCED"
                 << endl;

            cout << "Three-phase voltage is within safe limits."
                 << endl;
        }
    }
};

int main() {

    double voltageA;
    double voltageB;
    double voltageC;
    double limit;

    cout << "========================================"
         << endl;
    cout << "       PHASE IMBALANCE DETECTOR"
         << endl;
    cout << "========================================"
         << endl;

    cout << "\nEnter Phase A voltage (V): ";
    cin >> voltageA;

    cout << "Enter Phase B voltage (V): ";
    cin >> voltageB;

    cout << "Enter Phase C voltage (V): ";
    cin >> voltageC;

    cout << "Enter allowed imbalance limit (%): ";
    cin >> limit;

    PhaseImbalanceDetector detector(limit);

    detector.setVoltages(voltageA, voltageB, voltageC);

    detector.detectImbalance();

    return 0;
}
